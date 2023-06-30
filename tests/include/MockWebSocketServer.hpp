#ifndef ENJINPLATFORMSDK_MOCKWEBSOCKETSERVER_HPP
#define ENJINPLATFORMSDK_MOCKWEBSOCKETSERVER_HPP

#include "IMockWebSocketServer.hpp"
#include "WebSocketMessage.hpp"
#include "WebSocketMessageType.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <string>

/// \brief Definition for a function wrapper which receives a WebSocket message.
using WebSocketMessageHandler = std::function<void(WebSocketMessage)>;

/// \brief A mock WebSocket server used for testing connections and messages.
class MockWebSocketServer final : public virtual IMockWebSocketServer
{
    /// \brief Implementation for this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MockWebSocketServer();

    MockWebSocketServer(const MockWebSocketServer& other) = delete;

    MockWebSocketServer(MockWebSocketServer&& other) noexcept = delete;

    /// \brief Class destructor.
    ~MockWebSocketServer() override;

    MockWebSocketServer& operator=(const MockWebSocketServer& rhs) = delete;

    MockWebSocketServer& operator=(MockWebSocketServer&& rhs) noexcept = delete;

    // region IMockWebSocketServer

    [[maybe_unused]]
    void Close() override;

    [[maybe_unused]]
    void Close(uint16_t code, const std::string& reason) override;

    [[maybe_unused]]
    [[nodiscard]]
    std::string GetHost() const override;

    [[maybe_unused]]
    [[nodiscard]]
    int GetPort() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasQueuedMessageHandlers() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasUnhandledMessages() const override;

    [[maybe_unused]]
    IMockWebSocketServer& IgnoreMessageType(WebSocketMessageType type) override;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsMessageTypeIgnored(WebSocketMessageType type) const override;

    [[maybe_unused]]
    void NextMessage(WebSocketMessageHandler handler) override;

    [[maybe_unused]]
    void Reset() override;

    [[maybe_unused]]
    void SendWebSocketMessage(const WebSocketMessage& message) override;

    [[maybe_unused]]
    void Shutdown() override;

    [[maybe_unused]]
    void WaitForQueuedMessageHandlers(std::chrono::milliseconds timeout) override;

    // endregion IMockWebSocketServer
};

#endif //ENJINPLATFORMSDK_MOCKWEBSOCKETSERVER_HPP
