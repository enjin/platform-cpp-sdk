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

#include "MockWebSocketServer.hpp"

#include "ixwebsocket/IXConnectionState.h"
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXWebSocketCloseConstants.h"
#include "ixwebsocket/IXWebSocketMessage.h"
#include "ixwebsocket/IXWebSocketServer.h"
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <set>
#include <stdexcept>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

#ifdef WIN32

#include "ixwebsocket/IXNetSystem.h"

#endif

// Do not use ix namespace to avoid ambiguous references
using Clock = std::chrono::high_resolution_clock;
using Milliseconds = std::chrono::milliseconds;

// region Impl

class MockWebSocketServer::Impl : public virtual IMockWebSocketServer
{
    std::unique_ptr<ix::WebSocketServer> _server;

    std::set<WebSocketMessageType> _ignoredMessageTypes;
    std::queue<WebSocketMessageHandler> _messageHandlers;
    std::queue<WebSocketMessage> _unhandledMessages;

    // Mutexes
    mutable std::mutex _messagesMutex;

    // Condition variables
    std::condition_variable _messagesCv;

    static constexpr int PortMin = 8000;
    static constexpr int PortMax = 8080;

public:
    Impl()
    {
        Init();
    }

    Impl(const Impl& other) = delete;

    Impl(Impl&& other) noexcept = delete;

    ~Impl() override
    {
        Impl::Shutdown();

#ifdef WIN32
        ix::uninitNetSystem();
#endif
    }

    Impl& operator=(const Impl& rhs) = delete;

    Impl& operator=(Impl&& rhs) noexcept = delete;

    // region IMockWebSocketServer

    void Close() override
    {
        Close(ix::WebSocketCloseConstants::kNormalClosureCode, ix::WebSocketCloseConstants::kNormalClosureMessage);
    }

    void Close(const uint16_t code, const std::string& reason) override
    {
        for (const std::shared_ptr<ix::WebSocket>& client : _server->getClients())
        {
            client->close(code, reason);
        }
    }

    [[nodiscard]]
    std::string GetHost() const override
    {
        return _server->getHost();
    }

    [[nodiscard]]
    int GetPort() const override
    {
        return _server->getPort();
    }

    [[nodiscard]]
    bool HasQueuedMessageHandlers() const override
    {
        std::lock_guard<std::mutex> guard(_messagesMutex);

        return !_messageHandlers.empty();
    }

    [[nodiscard]]
    bool HasUnhandledMessages() const override
    {
        std::lock_guard<std::mutex> guard(_messagesMutex);

        return !_unhandledMessages.empty();
    }

    IMockWebSocketServer& IgnoreMessageType(const WebSocketMessageType type) override
    {
        std::lock_guard<std::mutex> guard(_messagesMutex);

        _ignoredMessageTypes.emplace(type);

        return *this;
    }

    [[nodiscard]]
    bool IsMessageTypeIgnored(const WebSocketMessageType type) const override
    {
        std::lock_guard<std::mutex> guard(_messagesMutex);

        return _ignoredMessageTypes.find(type) != _ignoredMessageTypes.end();
    }

    void NextMessage(WebSocketMessageHandler handler) override
    {
        std::lock_guard<std::mutex> guard(_messagesMutex);

        if (_unhandledMessages.empty())
        {
            _messageHandlers.push(std::move(handler));
        }
        else
        {
            WebSocketMessage msg = _unhandledMessages.front();
            _unhandledMessages.pop();

            handler(msg);
        }
    }

    void Reset() override
    {
        std::lock_guard<std::mutex> guard(_messagesMutex);

        _ignoredMessageTypes.clear();

        std::queue<WebSocketMessageHandler> messageHandlers;
        _messageHandlers.swap(messageHandlers);

        std::queue<WebSocketMessage> unhandledMessages;
        _unhandledMessages.swap(unhandledMessages);
    }

    void SendWebSocketMessage(const WebSocketMessage& msg) override
    {
        std::string data(msg.payload.begin(), msg.payload.end());
        const std::set<std::shared_ptr<ix::WebSocket>> clients = _server->getClients();

        switch (msg.type)
        {
            case WebSocketMessageType::Utf8Message:
                for (const std::shared_ptr<ix::WebSocket>& client : clients)
                {
                    client->sendText(data);
                }

                break;

            case WebSocketMessageType::BinaryMessage:
                for (const std::shared_ptr<ix::WebSocket>& client : clients)
                {
                    client->sendBinary(data);
                }

                break;

            case WebSocketMessageType::Close:
                Close(ix::WebSocketCloseConstants::kNormalClosureCode, data);
                break;

            case WebSocketMessageType::Open:
                throw std::invalid_argument("WebSocket message cannot be an open message");

            case WebSocketMessageType::Ping:
            case WebSocketMessageType::Pong:
            case WebSocketMessageType::Utf8Fragment:
            case WebSocketMessageType::BinaryFragment:
                throw std::invalid_argument("Given WebSocket message has an invalid message type");

            default:
                throw std::invalid_argument("Given WebSocket message has unknown message type");
        }
    }

    void Shutdown() override
    {
        Close(ix::WebSocketCloseConstants::kNormalClosureCode, ix::WebSocketCloseConstants::kNormalClosureMessage);
        _server->stop();
    }

    void WaitForQueuedMessageHandlers(Milliseconds timeout) override
    {
        std::unique_lock<std::mutex> lock(_messagesMutex);

        while (!_messageHandlers.empty() && timeout > Milliseconds::zero())
        {
            const auto start = Clock::now();
            _messagesCv.wait_for(lock, timeout);
            const auto end = Clock::now();

            timeout -= std::chrono::duration_cast<Milliseconds>(end - start);
        }
    }

    // endregion IMockWebSocketServer

private:
    /// \brief Creates a mock WebSocket message for a connection being closed and attempts to pass it to the message
    /// handler queue.
    void HandleClose()
    {
        if (IsMessageTypeIgnored(WebSocketMessageType::Close))
        {
            return;
        }

        WebSocketMessage msg;
        msg.type = WebSocketMessageType::Close;

        HandleOrQueueMessage(std::move(msg));
    }

    /// \brief Processes an incoming message.
    void HandleMessage(const ix::WebSocketMessagePtr& msgPtr)
    {
        const WebSocketMessageType msgType = GetWebSocketMessageType(msgPtr);
        if (!IsMessageTypeIgnored(msgType))
        {
            HandleOrQueueMessage(GetWebSocketMessage(msgPtr));
        }
    }

    /// \brief Creates a mock WebSocket message for a connection being opened and attempts to pass it to the message
    /// handler queue.
    void HandleOpen()
    {
        if (IsMessageTypeIgnored(WebSocketMessageType::Open))
        {
            return;
        }

        WebSocketMessage msg;
        msg.type = WebSocketMessageType::Open;

        HandleOrQueueMessage(std::move(msg));
    }

    /// \brief Processes the given WebSocket message and either passes it to the handler at the front of the queue or
    /// queues the message itself to be handled later by a newly queued handler.
    /// \param msg The message.
    void HandleOrQueueMessage(WebSocketMessage msg)
    {
        std::lock_guard<std::mutex> guard(_messagesMutex);

        if (_messageHandlers.empty())
        {
            _unhandledMessages.push(std::move(msg));
            return;
        }

        _messageHandlers.front()(msg);
        _messageHandlers.pop();
    }

    /// \brief Initializes this server.
    void Init()
    {
#ifdef WIN32
        ix::initNetSystem();
#endif

        int port = PortMin;
        bool isValid = false;

        while (!isValid)
        {
            if (port > PortMax)
            {
                throw std::runtime_error("No available ports for mock WebSocket server");
            }

            _server = std::make_unique<ix::WebSocketServer>(port++);
            SetClientMessageCallback();

            isValid = _server->listen().first;
        }

        _server->disablePerMessageDeflate();
        _server->start();
    }

    /// \brief Sets the WebSocket message callback handler for this server.
    void SetClientMessageCallback()
    {
        _server->setOnClientMessageCallback([this](const std::shared_ptr<ix::ConnectionState>& conn,
                                                   ix::WebSocket& ws,
                                                   const ix::WebSocketMessagePtr& msg) {
            switch (msg->type)
            {
                case ix::WebSocketMessageType::Message:
                    HandleMessage(msg);
                    break;

                case ix::WebSocketMessageType::Open:
                    HandleOpen();
                    break;

                case ix::WebSocketMessageType::Close:
                    HandleClose();
                    break;

                default:
                    break;
            }
        });
    }

    /// \brief Returns the mock message for the given IXWebSocket message.
    /// \param msg The IXWebSocket message.
    /// \return The mock message.
    static WebSocketMessage GetWebSocketMessage(const ix::WebSocketMessagePtr& msg)
    {
        WebSocketMessage newMsg;
        newMsg.payload = std::vector<unsigned char>(msg->str.begin(), msg->str.end());
        newMsg.type = GetWebSocketMessageType(msg);

        return newMsg;
    }

    /// \brief Returns the mock message type for the given IXWebSocket message type.
    /// \param msg The IXWebSocket message type.
    /// \return The mock message type.
    static WebSocketMessageType GetWebSocketMessageType(const ix::WebSocketMessagePtr& msg)
    {
        switch (msg->type)
        {
            case ix::WebSocketMessageType::Message:
                return msg->binary ? WebSocketMessageType::BinaryMessage : WebSocketMessageType::Utf8Message;

            case ix::WebSocketMessageType::Open:
                return WebSocketMessageType::Open;

            case ix::WebSocketMessageType::Close:
                return WebSocketMessageType::Close;

            case ix::WebSocketMessageType::Error:
                return WebSocketMessageType::Error;

            case ix::WebSocketMessageType::Ping:
                return WebSocketMessageType::Ping;

            case ix::WebSocketMessageType::Pong:
                return WebSocketMessageType::Pong;

            case ix::WebSocketMessageType::Fragment:
                return msg->binary ? WebSocketMessageType::BinaryFragment : WebSocketMessageType::Utf8Fragment;

            default:
                return WebSocketMessageType::Unknown;
        }
    }
};

// endregion Impl

// region MockWebSocketServer

[[maybe_unused]]
MockWebSocketServer::MockWebSocketServer()
    : _pimpl(std::make_unique<Impl>())
{
}

MockWebSocketServer::~MockWebSocketServer() = default;

// region IMockWebSocketServer

[[maybe_unused]]
void MockWebSocketServer::Close()
{
    _pimpl->Close();
}

[[maybe_unused]]
void MockWebSocketServer::Close(const uint16_t code, const std::string& reason)
{
    _pimpl->Close(code, reason);
}

[[maybe_unused]]
std::string MockWebSocketServer::GetHost() const
{
    return _pimpl->GetHost();
}

[[maybe_unused]]
int MockWebSocketServer::GetPort() const
{
    return _pimpl->GetPort();
}

[[maybe_unused]]
bool MockWebSocketServer::HasQueuedMessageHandlers() const
{
    return _pimpl->HasQueuedMessageHandlers();
}

[[maybe_unused]]
bool MockWebSocketServer::HasUnhandledMessages() const
{
    return _pimpl->HasUnhandledMessages();
}

[[maybe_unused]]
IMockWebSocketServer& MockWebSocketServer::IgnoreMessageType(const WebSocketMessageType type)
{
    _pimpl->IgnoreMessageType(type);

    return *this;
}

[[maybe_unused]]
bool MockWebSocketServer::IsMessageTypeIgnored(const WebSocketMessageType type) const
{
    return _pimpl->IsMessageTypeIgnored(type);
}

[[maybe_unused]]
void MockWebSocketServer::NextMessage(WebSocketMessageHandler handler)
{
    _pimpl->NextMessage(std::move(handler));
}

[[maybe_unused]]
void MockWebSocketServer::Reset()
{
    _pimpl->Reset();
}

[[maybe_unused]]
void MockWebSocketServer::SendWebSocketMessage(const WebSocketMessage& message)
{
    _pimpl->SendWebSocketMessage(message);
}

[[maybe_unused]]
void MockWebSocketServer::Shutdown()
{
    _pimpl->Shutdown();
}

[[maybe_unused]]
void MockWebSocketServer::WaitForQueuedMessageHandlers(const Milliseconds timeout)
{
    _pimpl->WaitForQueuedMessageHandlers(timeout);
}

// endregion IMockWebSocketServer

// endregion MockWebSocketServer
