#include "EnjinPlatformSdk/PusherEventService.hpp"

#include "IPusherClient.hpp"
#include "IPusherEventServiceImpl.hpp"
#include "PusherClient.hpp"
#include "PusherConnectionState.hpp"
#include "PusherListener.hpp"
#include "PusherOptions.hpp"
#include "EnjinPlatformSdk/EventListenerRegistration.hpp"
#include <mutex>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace enjin::platform::sdk;
using namespace pusher;
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
    PusherWrapper(const std::string& key, const PusherOptions& options)
        : _client(std::make_unique<PusherClient>(key, options))
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

    std::future<void> Connect() override
    {
        return _client->Connect();
    }

    std::future<void> Disconnect() override
    {
        return _client->Disconnect();
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

    void Subscribe(const std::string& channelName) override
    {
        _client->Subscribe(channelName);
    }

    void Unbind(const std::string& eventName) override
    {
        _client->Unbind(eventName);
    }

    void Unsubscribe(const std::string& channelName) override
    {
        _client->Unsubscribe(channelName);
    }

    // endregion IPusherClient
};

// endregion PusherWrapper

// region Impl

class PusherEventService::Impl : virtual public IPusherEventServiceImpl
{
    std::unique_ptr<PusherWrapper> _client;
    PusherListener _listener;
    std::vector<RegistrationPtr> _registrations;

    // Mutexes
    mutable std::mutex _registrationsMutex;

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
    ~Impl() override = default;

    Impl& operator=(const Impl& rhs) = delete;

    Impl& operator=(Impl&& rhs) noexcept = delete;

    // region IEventService

    std::future<void> ConnectAsync() override
    {
        return std::future<void>();
    }

    std::future<void> DisconnectAsync() override
    {
        return std::future<void>();
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

    void SetOnConnectedHandler(std::function<void()> handler) override
    {

    }

    void SetOnConnectionStateChangedHandler(std::function<void(ConnectionState)> handler) override
    {

    }

    void SetOnDisconnectedHandler(std::function<void()> handler) override
    {

    }

    void SetOnSubscribedHandler(std::function<void()> handler) override
    {

    }

    std::future<void> SubscribeAsync(const std::string& channelName) override
    {
        return std::future<void>();
    }

    void UnregisterAllListeners() override
    {
        std::lock_guard<std::mutex> guard(_registrationsMutex);

        for (const RegistrationPtr& reg : _registrations)
        {
            reg->SetIsRegistered(false);
        }

        _registrations.clear();
    }

    void UnregisterListener(const IEventListener& listener) override
    {
        std::lock_guard<std::mutex> guard(_registrationsMutex);

        UnregisterListenerImpl(listener);
    }

    std::future<void> UnsubscribeAllAsync() override
    {
        return std::future<void>();
    }

    std::future<void> UnsubscribeAsync(const std::string& channelName) override
    {
        return std::future<void>();
    }

    // endregion IEventService

    // region IPusherEventServiceImpl

    std::vector<EventListenerRegistrationPtr> GetRegistrations() const override
    {
        std::lock_guard<std::mutex> guard(_registrationsMutex);

        return std::vector<EventListenerRegistrationPtr>(_registrations.begin(), _registrations.end());
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

        std::lock_guard<std::mutex> guard(_registrationsMutex);

        UnregisterListenerImpl(*listener);

        auto* rawPtr = new EventListenerRegistration(std::move(listener), std::move(matcher));
        rawPtr->SetIsRegistered(true);

        RegistrationPtr reg = std::shared_ptr<EventListenerRegistration>(rawPtr);
        _registrations.push_back(reg);

        return reg;
    }

    /// \brief Implementation of the member-function for unregistering listeners. Only call this after acquiring the
    /// lock for the registrations mutex.
    /// \param listener The reference to the listener.
    void UnregisterListenerImpl(const IEventListener& listener)
    {
        for (auto iter = _registrations.begin(); iter != _registrations.end(); ++iter)
        {
            const RegistrationPtr& reg = *iter;
            if (reg->GetListener().get() == &listener)
            {
                reg->SetIsRegistered(false);

                _registrations.erase(iter--);
            }
        }
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
void PusherEventService::SetOnConnectedHandler(std::function<void()> handler)
{
    _pimpl->SetOnConnectedHandler(std::move(handler));
}

[[maybe_unused]]
void PusherEventService::SetOnConnectionStateChangedHandler(std::function<void(ConnectionState)> handler)
{
    _pimpl->SetOnConnectionStateChangedHandler(std::move(handler));
}

[[maybe_unused]]
void PusherEventService::SetOnDisconnectedHandler(std::function<void()> handler)
{
    _pimpl->SetOnDisconnectedHandler(std::move(handler));
}

[[maybe_unused]]
void PusherEventService::SetOnSubscribedHandler(std::function<void()> handler)
{
    _pimpl->SetOnSubscribedHandler(std::move(handler));
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

    std::unique_ptr<PusherWrapper> client = std::make_unique<PusherWrapper>(_key.value(), options);
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

// endregion PusherEventServiceBuilder
