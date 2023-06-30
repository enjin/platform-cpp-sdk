//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "PusherClient.hpp"

#include "PusherConstants.hpp"
#include "PusherErrorCodes.hpp"
#include "PusherEvent.hpp"
#include "PusherException.hpp"
#include "RapidJsonUtil.hpp"
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXWebSocketErrorInfo.h"
#include "ixwebsocket/IXWebSocketMessage.h"
#include "rapidjson/document.h"
#include <condition_variable>
#include <map>
#include <mutex>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <utility>

#ifdef WIN32

#include "ixwebsocket/IXNetSystem.h"

#endif

using namespace enjin::platform::sdk;
using namespace ix;
using namespace pusher;
using namespace rapidjson;
using Clock = std::chrono::steady_clock;
using Milliseconds = std::chrono::milliseconds;

// region Impl

class PusherClient::Impl : virtual public IPusherClient
{
    struct PusherChannel
    {
        bool isSubscribed = false;
    };

    std::unique_ptr<WebSocket> _ws;

    // State
    PusherConnectionState _conn = PusherConnectionState::Disconnected;
    std::optional<WebSocketErrorInfo> _connErrorInfo;
    const std::string _url;

    // Channels & Listeners
    std::map<std::string, PusherChannel> _channels;
    std::map<std::string, std::set<SubscriptionListenerPtr>> _listeners;

    // Handlers
    const std::optional<PusherClientConnectionHandler> _onConnectionStateChangedHandler;
    const std::optional<PusherClientErrorHandler> _onErrorHandler;

    // Mutexes
    mutable std::mutex _connMutex;
    mutable std::mutex _listenerMutex;

    // Condition variables
    std::condition_variable _connCv;

    static constexpr Milliseconds MessageTimeout = Milliseconds(5000);
    static constexpr int PingInterval = 120;

    // Message keys
    static constexpr char ChannelKey[] = "channel";
    static constexpr char DataKey[] = "data";
    static constexpr char EventKey[] = "event";

public:
    Impl() = delete;

    Impl(const std::string& key, const PusherOptions& options)
        : _url(CreateUrl(key, options))
    {
        Init();
    }

#ifdef __clang__

#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-throw-keyword-missing"

#endif

    Impl(const std::string& key,
         const PusherOptions& options,
         PusherClientConnectionHandler onConnectionHandler,
         PusherClientErrorHandler onErrorHandler)
        : _url(CreateUrl(key, options)),
          _onConnectionStateChangedHandler(std::move(onConnectionHandler)),
          _onErrorHandler(std::move(onErrorHandler))
    {
        Init();
    }

#ifdef __clang__

#pragma clang diagnostic pop

#endif

    Impl(const Impl& other) = delete;

    Impl(Impl&& other) noexcept = delete;

    ~Impl() override
    {
        Impl::DisconnectAsync().get();

        _ws.reset();

#ifdef WIN32
        ix::uninitNetSystem();
#endif
    }

    Impl& operator=(const Impl& rhs) = delete;

    Impl& operator=(Impl&& rhs) noexcept = delete;

    // region IPusherClient

    void Bind(const std::string& eventName, SubscriptionListenerPtr listener) override
    {
        if (listener == nullptr)
        {
            return;
        }

        std::lock_guard<std::mutex> guard(_listenerMutex);

        if (_listeners.contains(eventName))
        {
            _listeners[eventName].emplace(std::move(listener));
        }
        else
        {
            std::set<SubscriptionListenerPtr> entries({std::move(listener)});
            _listeners.emplace(eventName, std::move(entries));
        }
    }

    [[nodiscard]]
    std::future<void> ConnectAsync() override
    {
        return std::async([this]() {
            _ws->enableAutomaticReconnection();
            _ws->setUrl(_url);
            _ws->start();

            std::unique_lock<std::mutex> lock(_connMutex);

            _conn = PusherConnectionState::Connecting;

            while (_conn == PusherConnectionState::Connecting)
            {
                _connCv.wait(lock, [&]() {
                    if (_connErrorInfo.has_value())
                    {
                        WebSocketErrorInfo errorInfo = _connErrorInfo.value();
                        _connErrorInfo.reset();

                        throw std::runtime_error(errorInfo.reason);
                    }

                    return _conn != PusherConnectionState::Connecting;
                });
            }
        });
    }

    [[nodiscard]]
    std::future<void> DisconnectAsync() override
    {
        return std::async([this]() {
            {
                std::lock_guard<std::mutex> guard(_connMutex);

                if (_conn == PusherConnectionState::Disconnected || _conn == PusherConnectionState::Disconnecting)
                {
                    return;
                }

                _conn = PusherConnectionState::Disconnecting;
                _connCv.notify_all();
            }

            OnConnectionStateChanged(PusherConnectionState::Disconnecting);

            _ws->stop();

            {
                std::lock_guard<std::mutex> guard(_connMutex);

                _conn = PusherConnectionState::Disconnected;
                _connCv.notify_all();
            }

            OnConnectionStateChanged(PusherConnectionState::Disconnected);
        });
    }

    [[nodiscard]]
    PusherConnectionState GetState() const override
    {
        std::lock_guard<std::mutex> guard(_connMutex);

        return _conn;
    }

    [[nodiscard]]
    bool IsSubscribed(const std::string& channelName) const override
    {
        std::lock_guard<std::mutex> guard(_connMutex);

        return IsSubscribedImpl(channelName);
    }

    [[nodiscard]]
    bool IsSubscribedOrPending(const std::string& channelName) const override
    {
        std::lock_guard<std::mutex> guard(_connMutex);

        return IsSubscribedOrPendingImpl(channelName);
    }

    [[nodiscard]]
    bool IsSubscriptionPending(const std::string& channelName) const override
    {
        std::lock_guard<std::mutex> guard(_connMutex);

        return IsSubscriptionPendingImpl(channelName);
    }

    std::future<void> SubscribeAsync(std::string channelName) override
    {
        std::lock_guard<std::mutex> guard(_connMutex);

        // Ignore if already subscribed or pending
        if (IsSubscribedOrPendingImpl(channelName))
        {
            return std::async([]() {});
        }

        _channels.emplace(channelName, PusherChannel());

        return std::async([this, channelName = std::move(channelName)]() {
            std::unique_lock<std::mutex> lock(_connMutex);

            if (IsConnected() && IsSubscriptionPendingImpl(channelName))
            {
                Milliseconds timeout = MessageTimeout;

                _ws->sendText(SubscribeMessage(channelName));

                // Goes until the channel is either successfully subscribed to or removed
                while (IsConnected() && IsSubscriptionPendingImpl(channelName) && timeout > Milliseconds::zero())
                {
                    const auto start = Clock::now();

                    _connCv.wait_for(lock, MessageTimeout, [&]() {
                        return !IsConnected() || !IsSubscriptionPendingImpl(channelName);
                    });

                    const auto end = Clock::now();
                    timeout -= std::chrono::duration_cast<Milliseconds>(end - start);
                }
            }
        });
    }

    void Unbind(const std::string& eventName) override
    {
        std::lock_guard<std::mutex> guard(_listenerMutex);

        _listeners.erase(eventName);
    }

    std::future<void> UnsubscribeAllAsync() override
    {
        return std::async([this]() {
            std::lock_guard<std::mutex> guard(_connMutex);

            if (IsConnected())
            {
                for (const auto& [channelName, pusherChannel] : _channels)
                {
                    _ws->sendText(UnsubscribeMessage(channelName));
                }
            }

            _channels.clear();
            _connCv.notify_all();
        });
    }

    std::future<void> UnsubscribeAsync(std::string channelName) override
    {
        std::lock_guard<std::mutex> guard(_connMutex);

        if (!IsSubscribedOrPendingImpl(channelName))
        {
            return std::async([]() {});
        }

        return std::async([this, channelName = std::move(channelName)]() {
            std::lock_guard<std::mutex> guard(_connMutex);

            auto loc = _channels.find(channelName);

            if (loc == _channels.end())
            {
                return;
            }

            _channels.erase(loc);

            if (IsConnected())
            {
                _ws->sendText(UnsubscribeMessage(channelName));
            }

            _connCv.notify_all();
        });
    }

    // endregion IPusherClient

private:
    /// \brief Emits events to the subscribed listeners that are mapped to it.
    /// \param evt The event.
    void EmitEvent(const PusherEvent& evt)
    {
        if (!evt.GetEventName().has_value())
        {
            return;
        }

        // Get a copy of the listeners set to allow the listeners to make calls back to this client
        std::set<SubscriptionListenerPtr> listeners;
        {
            std::lock_guard<std::mutex> guard(_listenerMutex);

            auto loc = _listeners.find(evt.GetEventName().value());
            if (loc != _listeners.end())
            {
                listeners = loc->second;
            }
        }

        // Emit the event to the necessary listeners
        for (const SubscriptionListenerPtr& listener : listeners)
        {
            listener->OnEvent(evt);
        }
    }

    /// \brief Handles a Pusher error.
    /// \param code The error code.
    void HandlePusherError(const uint16_t code)
    {
        if (code >= 4000 && code < 4100)
        {
            _ws->disableAutomaticReconnection();

            SetState(PusherConnectionState::Disconnected);

            return;
        }

        /* If IXWebSocket ever enables us to listen for successful reconnection, then we will want to set our connection
         * state to Reconnecting here while we wait for reconnection.
         */

        if (code >= 4100 && code < 4200)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    /// \brief Handles a close message.
    /// \param msg The message.
    void HandleWebSocketClosed(const WebSocketMessagePtr& msg)
    {
        const uint16_t closeCode = msg->closeInfo.code;
        if (closeCode >= 4000 && closeCode < 4400)
        {
            HandlePusherError(closeCode);
        }
        else
        {
            DisconnectAsync().get();
        }
    }

    /// \brief Handles an error message.
    /// \param msg The error message.
    void HandleWebSocketError(const WebSocketMessagePtr& msg)
    {
        // Pusher error codes sit within the range from 4000 (inclusive) to 4400 (exclusive)
        const uint16_t closeCode = msg->closeInfo.code;
        if (closeCode >= 4000 && closeCode < 4400)
        {
            HandlePusherError(closeCode);
            return;
        }
    }

    /// \brief Handles an open message.
    void HandleWebSocketOpened(const WebSocketMessagePtr&)
    {
        SetState(PusherConnectionState::Connected);

        std::lock_guard<std::mutex> guard(_connMutex);

        for (auto& [channelName, pusherChannel] : _channels)
        {
            pusherChannel.isSubscribed = false;

            _ws->sendText(SubscribeMessage(channelName));
        }
    }

    /// \brief Handles a WebSocket message.
    /// \param msg The message.
    void HandleWebSocketMessage(const WebSocketMessagePtr& msg)
    {
        Document document;
        document.Parse(msg->str.c_str());

        if (!document.IsObject())
        {
            return;
        }
        else if (document.HasMember(DataKey) && document[DataKey].IsObject())
        {
            RapidJsonUtil::SetDocumentMember(document, DataKey, document);
        }

        PusherEvent evt(msg->str);
        EmitEvent(evt);

        if (!evt.GetEventName().has_value())
        {
            OnError(std::runtime_error("Pusher event has undefined event name"));
            return;
        }

        const std::string evtName = evt.GetEventName().value();

        if (evtName.find(PusherConstants::PusherMessagePrefix) != 0)
        {
            return;
        }

        if (evtName == PusherConstants::ChannelSubscriptionSucceeded)
        {
            if (evt.GetChannelName().has_value())
            {
                SubscriptionSucceeded(evt.GetChannelName().value());
            }
            else
            {
                OnError(std::runtime_error("Subscription success event has undefined channel"));
            }
        }
        else if (evtName == PusherConstants::ChannelSubscriptionError)
        {
            OnError(PusherException((int) PusherErrorCodes::SubscriptionError,
                                    "Error received on channel subscription: " + msg->str));
        }
    }

    /// \brief Initializes this client.
    void Init()
    {
#ifdef WIN32
        ix::initNetSystem();
#endif

        // Set up the client
        _ws = std::make_unique<WebSocket>();
        _ws->enablePong();
        _ws->setPingInterval(PingInterval);

        _ws->setOnMessageCallback([this](const WebSocketMessagePtr& msg) {
            switch (msg->type)
            {
                case WebSocketMessageType::Message:
                    HandleWebSocketMessage(msg);
                    break;

                case WebSocketMessageType::Open:
                    HandleWebSocketOpened(msg);
                    break;

                case WebSocketMessageType::Close:
                    HandleWebSocketClosed(msg);
                    break;

                case WebSocketMessageType::Error:
                    HandleWebSocketError(msg);
                    break;

                default:
                    break;
            }
        });
    }

    /// \brief Determines if this client is connected.
    bool IsConnected() const
    {
        return _conn == PusherConnectionState::Connected;
    }

    /// \brief Implementation for determining if this client is subscribed to the given channel.
    /// \param channelName The channel name.
    /// \return Whether this client is subscribed to the channel.
    /// \remarks Only call this when holding the lock for the connection mutex.
    bool IsSubscribedImpl(const std::string& channelName) const
    {
        const auto loc = _channels.find(channelName);

        return loc != _channels.end() && loc->second.isSubscribed;
    }

    /// \brief Implementation for determining if this client is subscribed to or has a pending subscription to the given
    /// channel.
    /// \param channelName The channel name.
    /// \return Whether this client is subscribed to or has a pending subscription to the channel.
    /// \remarks Only call this when holding the lock for the connection mutex.
    bool IsSubscribedOrPendingImpl(const std::string& channelName) const
    {
        return _channels.contains(channelName);
    }

    /// \brief Implementation for determining if this client has a pending subscription to the given channel.
    /// \param channelName The channel name.
    /// \return Whether this client has a pending subscription to the channel.
    /// \remarks Only call this when holding the lock for the connection mutex.
    bool IsSubscriptionPendingImpl(const std::string& channelName) const
    {
        const auto loc = _channels.find(channelName);

        return loc != _channels.end() && !loc->second.isSubscribed;
    }

    /// \brief Calls the handler for connection state change if it is set.
    /// \param state The connection state.
    void OnConnectionStateChanged(const PusherConnectionState state)
    {
        if (_onConnectionStateChangedHandler.has_value())
        {
            _onConnectionStateChangedHandler.value()(state);
        }
    }

    /// \brief Calls the handler for errors if it is set.
    /// \param e The exception.
    void OnError(const std::exception& e)
    {
        if (_onErrorHandler.has_value())
        {
            _onErrorHandler.value()(e);
        }
    }

    /// \brief Sets the connection state of this client.
    /// \param state The connection state.
    void SetState(const PusherConnectionState state)
    {
        {
            std::lock_guard<std::mutex> guard(_connMutex);

            _conn = state;
            _connCv.notify_all();
        }

        OnConnectionStateChanged(state);
    }

    /// \brief Processes a successful channel subscription message from the server.
    /// \param channelName The channel name.
    void SubscriptionSucceeded(const std::string& channelName)
    {
        std::lock_guard<std::mutex> guard(_connMutex);

        auto loc = _channels.find(channelName);
        if (loc != _channels.end())
        {
            loc->second.isSubscribed = true;
        }

        _connCv.notify_all();
    }

    /// \brief Creates a URL to a server based on the given application key and options.
    /// \param key The application key.
    /// \param options The Pusher options.
    /// \return The URL.
    [[nodiscard]]
    static std::string CreateUrl(const std::string& key, const PusherOptions& options)
    {
        const std::string schema = options.IsEncrypted()
                                   ? PusherConstants::SecureSchema
                                   : PusherConstants::InsecureSchema;

        std::stringstream urlStream;

        urlStream << schema << options.GetHost() << "/app/" << key << "?protocol=5&client=enjin-cpp-pusher-client";

#ifdef ENJINPLATFORMSDK_VERSION
        urlStream << "&version=" << ENJINPLATFORMSDK_VERSION;
#endif

        return urlStream.str();
    }

    /// \brief Creates the payload of a subscription message to a server for subscribing to a channel.
    /// \param channelName The channel name.
    /// \return The message payload.
    [[nodiscard]]
    static std::string SubscribeMessage(const std::string& channelName)
    {
        Document document(kObjectType);
        Document::AllocatorType& allocator = document.GetAllocator();

        RapidJsonUtil::SetStringMember(document, EventKey, PusherConstants::ChannelSubscribe);

        Value vChannel(channelName.c_str(), allocator);
        Value vData(kObjectType);

        vData.AddMember(ChannelKey, vChannel.Move(), allocator);
        document.AddMember(DataKey, vData.Move(), allocator);

        return RapidJsonUtil::DocumentToString(document);
    }

    /// \brief Creates the payload of an unsubscription message to a server for unsubscribing from a channel.
    /// \param channelName The channel name.
    /// \return The message payload.
    [[nodiscard]]
    static std::string UnsubscribeMessage(const std::string& channelName)
    {
        Document document(kObjectType);
        Document::AllocatorType& allocator = document.GetAllocator();

        RapidJsonUtil::SetStringMember(document, EventKey, PusherConstants::ChannelUnsubscribe);

        Value vChannel(channelName.c_str(), allocator);
        Value vData(kObjectType);

        vData.AddMember(ChannelKey, vChannel.Move(), allocator);
        document.AddMember(DataKey, vData.Move(), allocator);

        return RapidJsonUtil::DocumentToString(document);
    }
};

// endregion Impl

// region PusherClient

[[maybe_unused]]
PusherClient::PusherClient(const std::string& key, const PusherOptions& options)
    : _pimpl(std::make_unique<Impl>(key, options))
{
}

[[maybe_unused]]
PusherClient::PusherClient(const std::string& key,
                           const PusherOptions& options,
                           PusherClientConnectionHandler onConnectionHandler,
                           PusherClientErrorHandler onErrorHandler)
    : _pimpl(std::make_unique<Impl>(key, options, std::move(onConnectionHandler), std::move(onErrorHandler)))
{
}

PusherClient::~PusherClient() = default;

// region IPusherClient

[[maybe_unused]]
void PusherClient::Bind(const std::string& eventName, SubscriptionListenerPtr listener)
{
    _pimpl->Bind(eventName, std::move(listener));
}

[[maybe_unused]]
std::future<void> PusherClient::ConnectAsync()
{
    return _pimpl->ConnectAsync();
}

[[maybe_unused]]
std::future<void> PusherClient::DisconnectAsync()
{
    return _pimpl->DisconnectAsync();
}

[[maybe_unused]]
PusherConnectionState PusherClient::GetState() const
{
    return _pimpl->GetState();
}

[[maybe_unused]]
bool PusherClient::IsSubscribed(const std::string& channelName) const
{
    return _pimpl->IsSubscribed(channelName);
}

[[maybe_unused]]
bool PusherClient::IsSubscribedOrPending(const std::string& channelName) const
{
    return _pimpl->IsSubscribedOrPending(channelName);
}

[[maybe_unused]]
bool PusherClient::IsSubscriptionPending(const std::string& channelName) const
{
    return _pimpl->IsSubscriptionPending(channelName);
}

[[maybe_unused]]
std::future<void> PusherClient::SubscribeAsync(std::string channelName)
{
    return _pimpl->SubscribeAsync(channelName);
}

[[maybe_unused]]
void PusherClient::Unbind(const std::string& eventName)
{
    _pimpl->Unbind(eventName);
}

[[maybe_unused]]
std::future<void> PusherClient::UnsubscribeAllAsync()
{
    return _pimpl->UnsubscribeAllAsync();
}

[[maybe_unused]]
std::future<void> PusherClient::UnsubscribeAsync(std::string channelName)
{
    return _pimpl->UnsubscribeAsync(channelName);
}

// endregion IPusherClient

// endregion PusherClient
