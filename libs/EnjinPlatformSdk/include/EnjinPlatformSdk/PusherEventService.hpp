#ifndef ENJINPLATFORMSDK_PUSHEREVENTSERVICE_HPP
#define ENJINPLATFORMSDK_PUSHEREVENTSERVICE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IEventListener.hpp"
#include "EnjinPlatformSdk/IEventListenerRegistration.hpp"
#include "EnjinPlatformSdk/IEventService.hpp"
#include "EnjinPlatformSdk/ILogger.hpp"
#include <functional>
#include <future>
#include <memory>
#include <optional>
#include <set>
#include <string>

namespace enjin::platform::sdk
{
class PusherEventService;

/// \brief Definition for a pointer containing a PusherEventService.
using PusherEventServicePtr = std::unique_ptr<PusherEventService>;

/// \brief Implementation for an event service utilizing Pusher.
class ENJINPLATFORMSDK_EXPORT PusherEventService final : public virtual IEventService
{
    /// \brief Implementation for this class.
    class Impl;

    /// \brief Wrapper class for a Pusher client to be used in the implementation of this event service..
    class PusherWrapper;

    std::unique_ptr<Impl> _pimpl;

public:
    class PusherEventServiceBuilder;

    PusherEventService(const PusherEventService& other) = delete;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    PusherEventService(PusherEventService&& other) noexcept;

    /// \brief Class destructor.
    ~PusherEventService() override;

    PusherEventService& operator=(const PusherEventService& rhs) = delete;

    PusherEventService& operator=(PusherEventService&& rhs) noexcept;

    /// \brief Creates a builder instance to be used for creating an instance of this class.
    /// \return The builder instance.
    static PusherEventServiceBuilder Builder();

    // region IEventService

    [[maybe_unused]]
    [[nodiscard]]
    std::future<void> ConnectAsync() override;

    [[maybe_unused]]
    [[nodiscard]]
    std::future<void> DisconnectAsync() override;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsConnected() const override;

    [[maybe_unused]]
    [[nodiscard]]
    EventListenerRegistrationPtr RegisterListener(EventListenerPtr listener) override;

    [[maybe_unused]]
    [[nodiscard]]
    EventListenerRegistrationPtr RegisterListenerExcludingEvents(EventListenerPtr listener,
                                                                 std::set<std::string> events) override;

    [[maybe_unused]]
    [[nodiscard]]
    EventListenerRegistrationPtr RegisterListenerIncludingEvents(EventListenerPtr listener,
                                                                 std::set<std::string> events) override;

    [[maybe_unused]]
    [[nodiscard]]
    EventListenerRegistrationPtr RegisterListenerWithMatcher(EventListenerPtr listener, EventMatcher matcher) override;

    [[maybe_unused]]
    [[nodiscard]]
    std::future<void> SubscribeAsync(const std::string& channelName) override;

    [[maybe_unused]]
    void UnregisterAllListeners() override;

    [[maybe_unused]]
    void UnregisterListener(const IEventListener& listener) override;

    [[maybe_unused]]
    [[nodiscard]]
    std::future<void> UnsubscribeAllAsync() override;

    [[maybe_unused]]
    [[nodiscard]]
    std::future<void> UnsubscribeAsync(const std::string& channelName) override;

    // endregion IEventService

    /// \brief The builder class for defining and creating a new instance of the PusherEventService class.
    class ENJINPLATFORMSDK_EXPORT PusherEventServiceBuilder final
    {
        std::optional<std::string> _cluster;
        std::optional<std::string> _host;
        std::optional<bool> _isEncrypted;
        std::optional<std::string> _key;
        LoggerPtr _logger;

        // Handlers
        std::function<void()> _onConnectedHandler;
        std::function<void(ConnectionState)> _connStateHandler;
        std::function<void()> _disconnectedHandler;
        std::function<void(const std::string&)> _subHandler;

    public:
        /// \brief Class destructor.
        ~PusherEventServiceBuilder();

        /// \brief Builds an instance of PusherEventService using the set parameters.
        /// \return The service instance.
        /// \throws std::logic_error Thrown if the key is not set or if both the host and cluster are set at the time
        /// this method is called.
        /// \remarks If host is not set, then the service will default to `ws-{cluster}.pusher.com` and if the cluster
        /// is not set, then the cluster will default to `mt1`. If encryption is not set, then encryption will default
        /// to true.
        [[maybe_unused]]
        [[nodiscard]]
        PusherEventServicePtr Build() const;

        /// \brief Sets the cluster to be used within the Pusher network.
        /// \param cluster The cluster.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PusherEventServiceBuilder& SetCluster(std::string cluster);

        /// \brief Sets whether to use encryption for sending and receiving messages.
        /// \param isEncrypted Whether to use encryption.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PusherEventServiceBuilder& SetEncrypted(bool isEncrypted);

        /// \brief Sets the Pusher host.
        /// \param host The host.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PusherEventServiceBuilder& SetHost(std::string host);

        /// \brief Sets the key of the application on the Pusher network.
        /// \param key The application key.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PusherEventServiceBuilder& SetKey(std::string key);

        /// \brief Sets the logger for the event service to use.
        /// \param logger The logger.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PusherEventServiceBuilder& SetLogger(LoggerPtr logger);

        /// \brief Sets the handler for when the service connects.
        /// \param handler The handler.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PusherEventServiceBuilder& SetOnConnectedHandler(std::function<void()> handler);

        /// \brief Sets the handler for when the connection state of the service changes.
        /// \param handler The handler.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PusherEventServiceBuilder& SetOnConnectionStateChangedHandler(std::function<void(ConnectionState)> handler);

        /// \brief Sets the handler for when the service disconnects.
        /// \param handler The handler.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PusherEventServiceBuilder& SetOnDisconnectedHandler(std::function<void()> handler);

        /// \brief Sets the handler for when the service subscribes to a channel.
        /// \param handler The handler.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PusherEventServiceBuilder& SetOnSubscribedHandler(std::function<void(const std::string&)> handler);

    private:
        /// \brief Constructs an instance of this class.
        PusherEventServiceBuilder();

        friend PusherEventServiceBuilder PusherEventService::Builder();
    };

private:
    /// \brief Constructs an instance of this class with the given Pusher client.
    /// \param client The Pusher client.
    explicit PusherEventService(std::unique_ptr<PusherWrapper> client);
};
}

#endif //ENJINPLATFORMSDK_PUSHEREVENTSERVICE_HPP
