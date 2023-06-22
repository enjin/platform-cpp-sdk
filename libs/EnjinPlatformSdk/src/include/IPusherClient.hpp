#ifndef ENJINPLATFORMSDK_IPUSHERCLIENT_HPP
#define ENJINPLATFORMSDK_IPUSHERCLIENT_HPP

#include "ISubscriptionListener.hpp"
#include "PusherConnectionState.hpp"
#include <functional>
#include <future>
#include <string>

namespace pusher
{
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
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::future<void> Connect() = 0;

    /// \brief Disconnects this client from server.
    /// \return The future for this operation.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::future<void> Disconnect() = 0;

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

    /// \brief Subscribes this client to the given channel to start receiving events for it.
    /// \param channelName The name of the channel.
    [[maybe_unused]]
    virtual void Subscribe(const std::string& channelName) = 0;

    /// \brief Unbinds all listeners from the given event.
    /// \param eventName The name of the channel.
    [[maybe_unused]]
    virtual void Unbind(const std::string& eventName) = 0;

    /// \brief Unsubscribes this client from the given channel.
    /// \param channelName The name of the channel.
    [[maybe_unused]]
    virtual void Unsubscribe(const std::string& channelName) = 0;
};
}

#endif //ENJINPLATFORMSDK_IPUSHERCLIENT_HPP
