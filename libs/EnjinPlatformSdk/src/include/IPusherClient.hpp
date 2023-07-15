#ifndef ENJINPLATFORMSDK_IPUSHERCLIENT_HPP
#define ENJINPLATFORMSDK_IPUSHERCLIENT_HPP

#include "ISubscriptionListener.hpp"
#include "PusherConnectionState.hpp"
#include <functional>
#include <future>
#include <string>

namespace pusher
{
/// \brief Definition for a function wrapper which receives a PusherConnectionState.
typedef std::function<void(PusherConnectionState)> PusherConnectionStateHandler;

/// \brief Definition for a function wrapper which receives an exception.
typedef std::function<void(const std::exception&)> PusherErrorHandler;

/// \brief Definition for a function wrapper which receives no arguments.
typedef std::function<void()> PusherHandler;

/// \brief Definition for a function wrapper which receives a string.
typedef std::function<void(const std::string&)> PusherSubscribedHandler;

/// \brief Interface for Pusher clients.
class IPusherClient
{
public:
    /// \brief Class destructor.
    virtual ~IPusherClient() = default;

    /// \brief Binds a listener to the given event.
    /// \param eventName The event name.
    /// \param listener The listener.
    [[maybe_unused]]
    virtual void Bind(const std::string& eventName, SubscriptionListenerPtr listener) = 0;

    /// \brief Connects this client to the server.
    /// \return The future for this operation.
    /// \return The future for this operation.
    [[maybe_unused]]
    virtual std::future<void> ConnectAsync() = 0;

    /// \brief Disconnects this client from server.
    /// \return The future for this operation.
    /// \return The future for this operation.
    [[maybe_unused]]
    virtual std::future<void> DisconnectAsync() = 0;

    /// \brief Returns the connection state of this client.
    /// \return The connection state.
    [[maybe_unused]]
    [[nodiscard]]
    virtual PusherConnectionState GetState() const = 0;

    /// \brief Determines if this client is subscribed to the given channel.
    /// \param channelName The name of the channel.
    /// \return Whether this client is subscribed.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool IsSubscribed(const std::string& channelName) const = 0;

    /// \brief Determines whether this client is subscribed to or has a pending subscription for the given channel.
    /// \param channelName The name of the channel.
    /// \return Whether this client is subscribed or has a pending subscription.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool IsSubscribedOrPending(const std::string& channelName) const = 0;

    /// \brief Determines whether this client has a pending subscription for the given channel.
    /// \param channelName The name of the channel.
    /// \return Whether this client has a pending subscription.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool IsSubscriptionPending(const std::string& channelName) const = 0;

    /// \brief Unsets the handler for when this client connects to a server.
    [[maybe_unused]]
    virtual void RemoveOnConnectedHandler() = 0;

    /// \brief Unsets the handler for when the connection state of this client changes.
    [[maybe_unused]]
    virtual void RemoveOnConnectionStateChangedHandler() = 0;

    /// \brief Unsets the handler for when this client is disconnected.
    [[maybe_unused]]
    virtual void RemoveOnDisconnectedHandler() = 0;

    /// \brief Unsets the handler for when this client encounters an error.
    [[maybe_unused]]
    virtual void RemoveOnErrorHandler() = 0;

    /// \brief Unsets the handler for when this client successfully subscribes to a channel.
    [[maybe_unused]]
    virtual void RemoveOnSubscribedHandler() = 0;

    /// \brief Sets the handler for when this client connects to a server.
    /// \param handler The handler.
    [[maybe_unused]]
    virtual void SetOnConnectedHandler(PusherHandler handler) = 0;

    /// \brief Sets the handler for when the connection state of this client changes.
    /// \param handler The handler.
    [[maybe_unused]]
    virtual void SetOnConnectionStateChangedHandler(PusherConnectionStateHandler handler) = 0;

    /// \brief Sets the handler for when this client is disconnected.
    /// \param handler The handler.
    [[maybe_unused]]
    virtual void SetOnDisconnectedHandler(PusherHandler handler) = 0;

    /// \brief Sets the handler for when this client encounters an error.
    /// \param handler The handler.
    [[maybe_unused]]
    virtual void SetOnErrorHandler(PusherErrorHandler handler) = 0;

    /// \brief Sets the handler for when this client successfully subscribes to a channel.
    /// \param handler The handler.
    [[maybe_unused]]
    virtual void SetOnSubscribedHandler(PusherSubscribedHandler handler) = 0;

    /// \brief Subscribes this client to the given channel to start receiving events for it.
    /// \param channelName The name of the channel.
    [[maybe_unused]]
    virtual std::future<void> SubscribeAsync(std::string channelName) = 0;

    /// \brief Unbinds all listeners from the given event.
    /// \param eventName The name of the channel.
    /// \return The future for this operation.
    [[maybe_unused]]
    virtual void Unbind(const std::string& eventName) = 0;

    /// \brief Unsubscribes this client from currently subscribed and pending channels.
    /// \return The future for this operation.
    virtual std::future<void> UnsubscribeAllAsync() = 0;

    /// \brief Unsubscribes this client from the given channel.
    /// \param channelName The name of the channel.
    /// \return The future for this operation.
    [[maybe_unused]]
    virtual std::future<void> UnsubscribeAsync(std::string channelName) = 0;
};
}

#endif //ENJINPLATFORMSDK_IPUSHERCLIENT_HPP
