#ifndef ENJINPLATFORMSDK_IEVENTSERVICE_HPP
#define ENJINPLATFORMSDK_IEVENTSERVICE_HPP

#include "EnjinPlatformSdk/ConnectionState.hpp"
#include "EnjinPlatformSdk/IEventListener.hpp"
#include "EnjinPlatformSdk/IEventListenerRegistration.hpp"
#include <functional>
#include <future>
#include <set>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Interface to be implemented by platform event services for registering listeners and subscribing for events.
class IEventService
{
public:
    /// \brief Class destructor.
    virtual ~IEventService() = default;

    /// \brief Connects this service asynchronously to receive events.
    /// \return The future for this operation.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::future<void> ConnectAsync() = 0;

    /// \brief Disconnects this service asynchronously to stop receiving events.
    /// \return The future for this operation.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::future<void> DisconnectAsync() = 0;

    /// \brief Determines whether this service is connected and may receive events.
    /// \return Whether this service is connected.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool IsConnected() const = 0;

    /// \brief Registers a listener for this service. The listener may accept all events.
    /// \param listener The listener.
    /// \return The registration for the listener.
    /// \throws std::invalid_argument If listener is a null-pointer.
    [[maybe_unused]]
    [[nodiscard]]
    virtual EventListenerRegistrationPtr RegisterListener(EventListenerPtr listener) = 0;

    /// \brief Registers a listener for this service that is configured to filter out the specified events.
    /// \param listener The listener.
    /// \param events The events to filter out.
    /// \return The registration for the listener.
    /// \throws std::invalid_argument If listener is a null-pointer.
    [[maybe_unused]]
    [[nodiscard]]
    virtual EventListenerRegistrationPtr RegisterListenerExcludingEvents(EventListenerPtr listener,
                                                                         std::set<std::string> events) = 0;

    /// \brief Registers a listener for this service that is configured to filter for the specified events.
    /// \param listener The listener.
    /// \param events The events to filter for.
    /// \return The registration for the listener.
    /// \throws std::invalid_argument If listener is a null-pointer.
    [[maybe_unused]]
    [[nodiscard]]
    virtual EventListenerRegistrationPtr RegisterListenerIncludingEvents(EventListenerPtr listener,
                                                                         std::set<std::string> events) = 0;

    /// \brief Registers a listener for this service that is configured to filter for events against the given matcher.
    /// \param listener The listener.
    /// \param matcher The event matcher.
    /// \return The registration for the listener.
    /// \throws std::invalid_argument If listener is a null-pointer.
    [[maybe_unused]]
    [[nodiscard]]
    virtual EventListenerRegistrationPtr RegisterListenerWithMatcher(EventListenerPtr listener,
                                                                     EventMatcher matcher) = 0;

    /// \brief Unsets the handler for when this service connects to a server.
    [[maybe_unused]]
    virtual void RemoveOnConnectedHandler() = 0;

    /// \brief Unsets the handler for when the connection state of this service changes.
    [[maybe_unused]]
    virtual void RemoveOnConnectionStateChangedHandler() = 0;

    /// \brief Unsets the handler for when this service is disconnected.
    [[maybe_unused]]
    virtual void RemoveOnDisconnectedHandler() = 0;

    /// \brief Unsets the handler for when this service successfully subscribes to a channel.
    [[maybe_unused]]
    virtual void RemoveOnSubscribedHandler() = 0;

    /// \brief Sets the handler for when this service connects to a server.
    /// \param handler The handler.
    [[maybe_unused]]
    virtual void SetOnConnectedHandler(std::function<void()> handler) = 0;

    /// \brief Sets the handler for when the connection state of this service changes.
    /// \param handler The handler.
    [[maybe_unused]]
    virtual void SetOnConnectionStateChangedHandler(std::function<void(ConnectionState)> handler) = 0;

    /// \brief Sets the handler for when this service is disconnected.
    /// \param handler The handler.
    [[maybe_unused]]
    virtual void SetOnDisconnectedHandler(std::function<void()> handler) = 0;

    /// \brief Sets the handler for when this service successfully subscribes to a channel.
    /// \param handler The handler.
    [[maybe_unused]]
    virtual void SetOnSubscribedHandler(std::function<void()> handler) = 0;

    /// \brief Subscribes this service to the given event channel asynchronously.
    /// \param channelName The name of the event channel.
    /// \return The future for this operation.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::future<void> SubscribeAsync(const std::string& channelName) = 0;

    /// \brief Unregisters all listeners from this service.
    [[maybe_unused]]
    virtual void UnregisterAllListeners() = 0;

    /// \brief Unregisters the given listener from this service.
    /// \param listener The listener.
    [[maybe_unused]]
    virtual void UnregisterListener(const IEventListener& listener) = 0;

    /// \brief Unsubscribes this service from all subscribed channels asynchronously.
    /// \return The future for this operation.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::future<void> UnsubscribeAllAsync() = 0;

    /// \brief Unsubscribes this service from the given event channel asynchronously.
    /// \param channelName The name of the event channel.
    /// \return The future for this operation.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::future<void> UnsubscribeAsync(const std::string& channelName) = 0;
};
}

#endif //ENJINPLATFORMSDK_IEVENTSERVICE_HPP
