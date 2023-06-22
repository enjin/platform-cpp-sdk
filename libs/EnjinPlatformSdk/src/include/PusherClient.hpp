#ifndef ENJINPLATFORMSDK_PUSHERCLIENT_HPP
#define ENJINPLATFORMSDK_PUSHERCLIENT_HPP

#include "enjinplatformsdk_export.h"
#include "IPusherClient.hpp"
#include "PusherOptions.hpp"
#include <memory>

namespace pusher
{
/// \brief Definition for a function wrapper which receives a PusherConnectionState.
using PusherClientConnectionHandler = std::function<void(PusherConnectionState)>;

/// \brief Definition for a function wrapper which receives an exception.
using PusherClientErrorHandler = std::function<void(const std::exception&)>;

/// \brief Pusher client for subscribing to Pusher channels and binding to events.
class ENJINPLATFORMSDK_EXPORT PusherClient : virtual public IPusherClient
{
    /// \brief Implementation for this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    PusherClient() = delete;

    /// \brief Constructs an instance of this class with the given application key and options.
    /// \param key The application key.
    /// \param options The Pusher options.
    [[maybe_unused]]
    PusherClient(const std::string& key, const PusherOptions& options);

    /// \brief Constructs an instance of this class with the given application key, options, and handlers.
    /// \param key The application key.
    /// \param options The Pusher options.
    /// \param onConnectionHandler The handler for when connection state changes.
    /// \param onErrorHandler The handler for when errors occur within the client.
    [[maybe_unused]]
    PusherClient(const std::string& key,
                 const PusherOptions& options,
                 PusherClientConnectionHandler onConnectionHandler,
                 PusherClientErrorHandler onErrorHandler);

    PusherClient(const PusherClient& other) = delete;

    PusherClient(PusherClient&& other) noexcept = delete;

    /// \brief Class destructor.
    ~PusherClient() override;

    PusherClient& operator=(const PusherClient& rhs) = delete;

    PusherClient& operator=(PusherClient&& rhs) noexcept = delete;

    // region IPusherClient

    [[maybe_unused]]
    void Bind(const std::string& eventName, SubscriptionListenerPtr listener) override;

    [[maybe_unused]]
    [[nodiscard]]
    std::future<void> Connect() override;

    [[maybe_unused]]
    [[nodiscard]]
    std::future<void> Disconnect() override;

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
    void Subscribe(const std::string& channelName) override;

    [[maybe_unused]]
    void Unbind(const std::string& eventName) override;

    [[maybe_unused]]
    void Unsubscribe(const std::string& channelName) override;

    // endregion IPusherClient
};
}

#endif //ENJINPLATFORMSDK_PUSHERCLIENT_HPP
