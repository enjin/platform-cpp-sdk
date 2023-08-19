#ifndef ENJINPLATFORMSDK_PUSHERCLIENT_HPP
#define ENJINPLATFORMSDK_PUSHERCLIENT_HPP

#include "enjinplatformsdk_export.h"
#include "IPusherClient.hpp"
#include "PusherConnectionState.hpp"
#include "PusherOptions.hpp"
#include <functional>
#include <memory>
#include <stdexcept>

namespace pusher
{
/// \brief Definition for a function wrapper which receives a PusherConnectionState.
using PusherConnectionStateHandler = std::function<void(PusherConnectionState)>;

/// \brief Definition for a function wrapper which receives an exception.
using PusherErrorHandler = std::function<void(const std::exception&)>;

/// \brief Definition for a function wrapper which receives no arguments.
using PusherHandler = std::function<void()>;

/// \brief Definition for a function wrapper which receives a string.
using PusherSubscribedHandler = std::function<void(const std::string&)>;

/// \brief Pusher client for subscribing to Pusher channels and binding to events.
class ENJINPLATFORMSDK_EXPORT PusherClient : public virtual IPusherClient
{
    /// \brief Implementation for this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    PusherClient() = delete;

    /// \brief Constructs an instance of this class.
    /// \param key The application key.
    /// \param options The Pusher options.
    [[maybe_unused]]
    PusherClient(const std::string& key, const PusherOptions& options);

    /// \brief Constructs an instance of this class.
    /// \param key The application key.
    /// \param options The Pusher options.
    /// \param onConnectedHandler The handler for when the client connects.
    /// \param onConnectionStateChangedHandler The handler for when the connection state of the client changes.
    /// \param onDisconnectedHandler The handler for when the client disconnects.
    /// \param onErrorHandler The handler for when the client encounters an error.
    /// \param onSubscribedHandler The handler for when the client subscribes to a channel.
    [[maybe_unused]]
    PusherClient(const std::string& key,
                 const PusherOptions& options,
                 PusherHandler onConnectedHandler,
                 PusherConnectionStateHandler onConnectionStateChangedHandler,
                 PusherHandler onDisconnectedHandler,
                 PusherErrorHandler onErrorHandler,
                 PusherSubscribedHandler onSubscribedHandler);

    PusherClient(const PusherClient& other) = delete;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    PusherClient(PusherClient&& other) noexcept;

    /// \brief Class destructor.
    ~PusherClient() override;

    PusherClient& operator=(const PusherClient& rhs) = delete;

    PusherClient& operator=(PusherClient&& rhs) noexcept;

    // region IPusherClient

    [[maybe_unused]]
    void Bind(const std::string& eventName, SubscriptionListenerPtr listener) override;

    [[maybe_unused]]
    std::future<void> ConnectAsync() override;

    [[maybe_unused]]
    std::future<void> DisconnectAsync() override;

    [[maybe_unused]]
    [[nodiscard]]
    PusherConnectionState GetState() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsSubscribed(const std::string& channelName) const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsSubscribedOrPending(const std::string& channelName) const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsSubscriptionPending(const std::string& channelName) const override;

    [[maybe_unused]]
    std::future<void> SubscribeAsync(std::string channelName) override;

    [[maybe_unused]]
    void Unbind(const std::string& eventName) override;

    [[maybe_unused]]
    std::future<void> UnsubscribeAllAsync() override;

    [[maybe_unused]]
    std::future<void> UnsubscribeAsync(std::string channelName) override;

    // endregion IPusherClient
};
}

#endif //ENJINPLATFORMSDK_PUSHERCLIENT_HPP
