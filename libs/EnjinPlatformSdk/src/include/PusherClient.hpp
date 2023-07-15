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
    void RemoveOnConnectedHandler() override;

    [[maybe_unused]]
    void RemoveOnConnectionStateChangedHandler() override;

    [[maybe_unused]]
    void RemoveOnDisconnectedHandler() override;

    [[maybe_unused]]
    void RemoveOnErrorHandler() override;

    [[maybe_unused]]
    void RemoveOnSubscribedHandler() override;

    [[maybe_unused]]
    void SetOnConnectedHandler(PusherHandler handler) override;

    [[maybe_unused]]
    void SetOnConnectionStateChangedHandler(PusherConnectionStateHandler handler) override;

    [[maybe_unused]]
    void SetOnDisconnectedHandler(PusherHandler handler) override;

    [[maybe_unused]]
    void SetOnErrorHandler(PusherErrorHandler handler) override;

    [[maybe_unused]]
    void SetOnSubscribedHandler(PusherSubscribedHandler handler) override;

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
