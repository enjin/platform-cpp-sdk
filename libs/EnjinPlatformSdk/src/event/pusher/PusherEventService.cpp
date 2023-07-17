#include "EnjinPlatformSdk/PusherEventService.hpp"

#include "IPusherClient.hpp"
#include "IPusherEventServiceImpl.hpp"
#include "PusherClient.hpp"
#include "PusherConnectionState.hpp"
#include "PusherListener.hpp"
#include "PusherOptions.hpp"
#include "EnjinPlatformSdk/EventListenerRegistration.hpp"
#include "EnjinPlatformSdk/LogLevel.hpp"
#include <algorithm>
#include <chrono>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace enjin::platform::sdk;
using namespace pusher;
using Milliseconds = std::chrono::milliseconds;
using PusherEventServiceBuilder = PusherEventService::PusherEventServiceBuilder;
using RegistrationPtr = std::shared_ptr<EventListenerRegistration>;

// region PusherWrapper

class PusherEventService::PusherWrapper : virtual public IPusherClient
{
    std::unique_ptr<IPusherClient> _client;

public:
    PusherWrapper() = delete;

    /// \brief Constructs an instance of this class with the given application key and Pusher options.
    /// \param key The application key.
    /// \param options The Pusher options.
    /// \param onConnectedHandler The handler for when the client connects.
    /// \param onConnectionStateChangedHandler The handler for when the connection state of the client changes.
    /// \param onDisconnectedHandler The handler for when the client disconnects.
    /// \param onErrorHandler The handler for when the client encounters an error.
    /// \param onSubscribedHandler The handler for when the client subscribes to a channel.
    PusherWrapper(const std::string& key,
                  const PusherOptions& options,
                  PusherHandler onConnectedHandler,
                  PusherConnectionStateHandler onConnectionStateChangedHandler,
                  PusherHandler onDisconnectedHandler,
                  PusherErrorHandler onErrorHandler,
                  PusherSubscribedHandler onSubscribedHandler)
        : _client(std::make_unique<PusherClient>(key,
                                                 options,
                                                 std::move(onConnectedHandler),
                                                 std::move(onConnectionStateChangedHandler),
                                                 std::move(onDisconnectedHandler),
                                                 std::move(onErrorHandler),
                                                 std::move(onSubscribedHandler)))
    {
    }

    PusherWrapper(const PusherWrapper& other) = delete;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    PusherWrapper(PusherWrapper&& other) noexcept = default;

    /// \brief Class destructor.
    ~PusherWrapper() override = default;

    PusherWrapper& operator=(const PusherWrapper& rhs) = delete;

    PusherWrapper& operator=(PusherWrapper&& rhs) noexcept = default;

    // region IPusherClient

    void Bind(const std::string& eventName, SubscriptionListenerPtr listener) override
    {
        _client->Bind(eventName, std::move(listener));
    }

    std::future<void> ConnectAsync() override
    {
        return _client->ConnectAsync();
    }

    std::future<void> DisconnectAsync() override
    {
        return _client->DisconnectAsync();
    }

    [[nodiscard]]
    PusherConnectionState GetState() const override
    {
        return _client->GetState();
    }

    [[nodiscard]]
    bool IsSubscribed(const std::string& channelName) const override
    {
        return _client->IsSubscribed(channelName);
    }

    [[nodiscard]]
    bool IsSubscribedOrPending(const std::string& channelName) const override
    {
        return _client->IsSubscribedOrPending(channelName);
    }

    [[nodiscard]]
    bool IsSubscriptionPending(const std::string& channelName) const override
    {
        return _client->IsSubscriptionPending(channelName);
    }

    std::future<void> SubscribeAsync(std::string channelName) override
    {
        return _client->SubscribeAsync(channelName);
    }

    void Unbind(const std::string& eventName) override
    {
        _client->Unbind(eventName);
    }

    std::future<void> UnsubscribeAllAsync() override
    {
        return _client->UnsubscribeAllAsync();
    }

    std::future<void> UnsubscribeAsync(std::string channelName) override
    {
        return _client->UnsubscribeAsync(channelName);
    }

    // endregion IPusherClient
};

// endregion PusherWrapper

// region Impl

class PusherEventService::Impl : virtual public IPusherEventServiceImpl
{
    std::unique_ptr<PusherWrapper> _client;
    PusherListener _listener;
    std::vector<RegistrationPtr> _regs;

    // Mutexes
    mutable std::mutex _regsMutex;

    static constexpr Milliseconds DisconnectTimout = Milliseconds(20000); // 20 seconds

public:
    Impl() = delete;

    /// \brief Constructs an instance of this class with the given Pusher client.
    /// \param client The Pusher client.
    explicit Impl(std::unique_ptr<PusherWrapper> client)
        : _client(std::move(client)),
          _listener(*this)
    {
    }

    Impl(const Impl& other) = delete;

    Impl(Impl&& other) noexcept = delete;

    /// \brief Class destructor.
    ~Impl() override
    {
        Impl::DisconnectAsync().wait_for(DisconnectTimout);
    }

    Impl& operator=(const Impl& rhs) = delete;

    Impl& operator=(Impl&& rhs) noexcept = delete;

    // region IEventService

    std::future<void> ConnectAsync() override
    {
        return _client->ConnectAsync();
    }

    std::future<void> DisconnectAsync() override
    {
        return _client->DisconnectAsync();
    }

    bool IsConnected() const override
    {
        return _client->GetState() == PusherConnectionState::Connected;
    }

    EventListenerRegistrationPtr RegisterListener(EventListenerPtr listener) override
    {
        return RegisterListener(std::move(listener), EventListenerRegistration::AllowAllMatcher);
    }

    EventListenerRegistrationPtr RegisterListenerExcludingEvents(EventListenerPtr listener,
                                                                 std::set<std::string> events) override
    {
        return RegisterListener(std::move(listener), [events = std::move(events)](const std::string& evt) {
            return events.find(evt) == events.end();
        });
    }

    EventListenerRegistrationPtr RegisterListenerIncludingEvents(EventListenerPtr listener,
                                                                 std::set<std::string> events) override
    {
        return RegisterListener(std::move(listener), [events = std::move(events)](const std::string& evt) {
            return events.find(evt) != events.end();
        });
    }

    EventListenerRegistrationPtr RegisterListenerWithMatcher(EventListenerPtr listener, EventMatcher matcher) override
    {
        return RegisterListener(std::move(listener), std::move(matcher));
    }

    std::future<void> SubscribeAsync(const std::string& channelName) override
    {
        return _client->SubscribeAsync(channelName);
    }

    void UnregisterAllListeners() override
    {
        std::lock_guard<std::mutex> guard(_regsMutex);

        for (const RegistrationPtr& reg : _regs)
        {
            reg->SetIsRegistered(false);
        }

        _regs.clear();
    }

    void UnregisterListener(const IEventListener& listener) override
    {
        std::lock_guard<std::mutex> guard(_regsMutex);

        UnregisterListenerImpl(listener);
    }

    std::future<void> UnsubscribeAllAsync() override
    {
        return _client->UnsubscribeAllAsync();
    }

    std::future<void> UnsubscribeAsync(const std::string& channelName) override
    {
        return _client->UnsubscribeAsync(channelName);
    }

    // endregion IEventService

    // region IPusherEventServiceImpl

    std::vector<EventListenerRegistrationPtr> GetRegistrations() const override
    {
        std::lock_guard<std::mutex> guard(_regsMutex);

        return {_regs.begin(), _regs.end()};
    }

    // endregion IPusherEventServiceImpl

private:
    /// \brief Helper member-function for registering a listener for this service that is configured to filter for
    /// events against the given matcher.
    /// \param listener The listener.
    /// \param matcher The event matcher.
    /// \return The registration for the listener.
    EventListenerRegistrationPtr RegisterListener(EventListenerPtr listener, EventMatcher matcher)
    {
        if (listener == nullptr)
        {
            throw std::invalid_argument("Listener must not be a null-pointer");
        }

        std::lock_guard<std::mutex> guard(_regsMutex);

        UnregisterListenerImpl(*listener);

        auto* rawPtr = new EventListenerRegistration(std::move(listener), std::move(matcher));
        rawPtr->SetIsRegistered(true);

        RegistrationPtr reg = std::shared_ptr<EventListenerRegistration>(rawPtr);
        _regs.push_back(reg);

        return reg;
    }

    /// \brief Implementation of the member-function for unregistering listeners. Only call this after acquiring the
    /// lock for the registrations mutex.
    /// \param listener The reference to the listener.
    void UnregisterListenerImpl(const IEventListener& listener)
    {
        _regs.erase(std::remove_if(_regs.begin(), _regs.end(), [&](const RegistrationPtr& reg) {
            if (reg->GetListener().get() != &listener)
            {
                return false;
            }

            reg->SetIsRegistered(false);

            return true;
        }), _regs.end());
    }
};

// endregion Impl

// region PusherEventService

PusherEventService::PusherEventService(std::unique_ptr<PusherWrapper> client)
    : _pimpl(std::make_unique<Impl>(std::move(client)))
{
}

[[maybe_unused]]
PusherEventService::PusherEventService(PusherEventService&& other) noexcept = default;

PusherEventService::~PusherEventService() = default;

PusherEventService& PusherEventService::operator=(PusherEventService&& rhs) noexcept = default;

// Static

[[maybe_unused]]
PusherEventServiceBuilder PusherEventService::Builder()
{
    return {};
}

// region IEventService

[[maybe_unused]]
std::future<void> PusherEventService::ConnectAsync()
{
    return _pimpl->ConnectAsync();
}

[[maybe_unused]]
std::future<void> PusherEventService::DisconnectAsync()
{
    return _pimpl->DisconnectAsync();
}

[[maybe_unused]]
bool PusherEventService::IsConnected() const
{
    return _pimpl->IsConnected();
}

[[maybe_unused]]
EventListenerRegistrationPtr PusherEventService::RegisterListener(EventListenerPtr listener)
{
    return _pimpl->RegisterListener(std::move(listener));
}

[[maybe_unused]]
EventListenerRegistrationPtr PusherEventService::RegisterListenerExcludingEvents(EventListenerPtr listener,
                                                                                 std::set<std::string> events)
{
    return _pimpl->RegisterListenerExcludingEvents(std::move(listener), std::move(events));
}

[[maybe_unused]]
EventListenerRegistrationPtr PusherEventService::RegisterListenerIncludingEvents(EventListenerPtr listener,
                                                                                 std::set<std::string> events)
{
    return _pimpl->RegisterListenerIncludingEvents(std::move(listener), std::move(events));
}

[[maybe_unused]]
EventListenerRegistrationPtr PusherEventService::RegisterListenerWithMatcher(EventListenerPtr listener,
                                                                             EventMatcher matcher)
{
    return _pimpl->RegisterListenerWithMatcher(std::move(listener), std::move(matcher));
}

[[maybe_unused]]
std::future<void> PusherEventService::SubscribeAsync(const std::string& channelName)
{
    return _pimpl->SubscribeAsync(channelName);
}

[[maybe_unused]]
void PusherEventService::UnregisterAllListeners()
{
    _pimpl->UnregisterAllListeners();
}

[[maybe_unused]]
void PusherEventService::UnregisterListener(const IEventListener& listener)
{
    _pimpl->UnregisterListener(listener);
}

[[maybe_unused]]
std::future<void> PusherEventService::UnsubscribeAllAsync()
{
    return _pimpl->UnsubscribeAllAsync();
}

[[maybe_unused]]
std::future<void> PusherEventService::UnsubscribeAsync(const std::string& channelName)
{
    return _pimpl->UnsubscribeAsync(channelName);
}

// endregion IEventService

// endregion PusherEventService

// region PusherEventServiceBuilder

PusherHandler CreateConnHandler(std::function<void()> innerHandler)
{
    if (!innerHandler)
    {
        return []() {};
    }

    return [innerHandler = std::move(innerHandler)]() {
        innerHandler();
    };
}

PusherConnectionStateHandler CreateConnStateHandler(std::function<void(ConnectionState)> innerHandler)
{
    if (!innerHandler)
    {
        return [](PusherConnectionState) {};
    }

    return [innerHandler = std::move(innerHandler)](PusherConnectionState state) {
        switch (state)
        {
            case PusherConnectionState::Connecting:
                innerHandler(ConnectionState::Connecting);
                break;

            case PusherConnectionState::Connected:
                innerHandler(ConnectionState::Open);
                break;

            case PusherConnectionState::Disconnecting:
                innerHandler(ConnectionState::Closing);
                break;

            case PusherConnectionState::Disconnected:
                innerHandler(ConnectionState::Closed);
                break;

            default:
                break;
        }
    };
}

PusherErrorHandler CreateErrorHandler(LoggerPtr logger)
{
    if (logger == nullptr)
    {
        return [](const std::exception&) {};
    }

    return [logger = std::move(logger)](const std::exception& e) {
        logger->Log(LogLevel::Error, e, "Error in PusherEventService");
    };
}

PusherSubscribedHandler CreateSubHandler(std::function<void(const std::string&)> innerHandler)
{
    if (!innerHandler)
    {
        return [](const std::string&) {};
    }

    return [innerHandler = std::move(innerHandler)](const std::string& channelName) {
        innerHandler(channelName);
    };
}

PusherEventServiceBuilder::PusherEventServiceBuilder() = default;

PusherEventServiceBuilder::~PusherEventServiceBuilder() = default;

[[maybe_unused]]
std::unique_ptr<PusherEventService> PusherEventServiceBuilder::Build() const
{
    if (!_key.has_value())
    {
        throw std::logic_error("Cannot build PusherEventService without an app key");
    }

    if (_host.has_value() && _cluster.has_value())
    {
        throw std::logic_error("Cannot specify both cluster and host for Pusher options");
    }

    PusherOptions options;
    options.SetEncrypted(_isEncrypted.value_or(true));

    if (_host.has_value())
    {
        options.SetHost(_host.value());
    }
    else if (_cluster.has_value())
    {
        options.SetCluster(_cluster.value());
    }

    PusherHandler connHandler = CreateConnHandler(_onConnectedHandler);
    PusherHandler disconnectedHandler = CreateConnHandler(_disconnectedHandler);
    PusherConnectionStateHandler connStateHandler = CreateConnStateHandler(_connStateHandler);
    PusherSubscribedHandler subHandler = CreateSubHandler(_subHandler);
    PusherErrorHandler errHandler = CreateErrorHandler(_logger);

    std::unique_ptr<PusherWrapper> client = std::make_unique<PusherWrapper>(_key.value(),
                                                                            options,
                                                                            std::move(connHandler),
                                                                            std::move(connStateHandler),
                                                                            std::move(disconnectedHandler),
                                                                            std::move(errHandler),
                                                                            std::move(subHandler));

    return std::unique_ptr<PusherEventService>(new PusherEventService(std::move(client)));
}

[[maybe_unused]]
PusherEventServiceBuilder& PusherEventServiceBuilder::SetCluster(std::string cluster)
{
    _cluster = std::move(cluster);

    return *this;
}

[[maybe_unused]]
PusherEventServiceBuilder& PusherEventServiceBuilder::SetEncrypted(const bool isEncrypted)
{
    _isEncrypted = isEncrypted;

    return *this;
}

[[maybe_unused]]
PusherEventServiceBuilder& PusherEventServiceBuilder::SetHost(std::string host)
{
    _host = std::move(host);

    return *this;
}

[[maybe_unused]]
PusherEventServiceBuilder& PusherEventServiceBuilder::SetKey(std::string key)
{
    _key = std::move(key);

    return *this;
}

[[maybe_unused]]
PusherEventServiceBuilder& PusherEventServiceBuilder::SetLogger(LoggerPtr logger)
{
    _logger = std::move(logger);

    return *this;
}

[[maybe_unused]]
PusherEventServiceBuilder& PusherEventServiceBuilder::SetOnConnectedHandler(std::function<void()> handler)
{
    _onConnectedHandler = std::move(handler);

    return *this;
}

[[maybe_unused]]
PusherEventServiceBuilder&
PusherEventServiceBuilder::SetOnConnectionStateChangedHandler(std::function<void(ConnectionState)> handler)
{
    _connStateHandler = std::move(handler);

    return *this;
}

[[maybe_unused]]
PusherEventServiceBuilder& PusherEventServiceBuilder::SetOnDisconnectedHandler(std::function<void()> handler)
{
    _disconnectedHandler = std::move(handler);

    return *this;
}

[[maybe_unused]]
PusherEventServiceBuilder&
PusherEventServiceBuilder::SetSubscriptionHandler(std::function<void(const std::string&)> handler)
{
    _subHandler = std::move(handler);

    return *this;
}

// endregion PusherEventServiceBuilder
