#ifndef ENJINPLATFORMSDK_IMOCKWEBSOCKETSERVER_HPP
#define ENJINPLATFORMSDK_IMOCKWEBSOCKETSERVER_HPP

#include "WebSocketMessage.hpp"
#include "WebSocketMessageType.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <string>

/// \brief Definition for a function wrapper which receives a WebSocket message.
using WebSocketMessageHandler = std::function<void(WebSocketMessage)>;

class IMockWebSocketServer
{
public:
    /// \brief Class destructor.
    virtual ~IMockWebSocketServer() = default;

    /// \brief Closes the connection with all connected clients.
    [[maybe_unused]]
    virtual void Close() = 0;

    /// \brief Closes the connection with all connected clients with the given code and reason.
    /// \param code The close code.
    /// \param reason The close reason.
    [[maybe_unused]]
    virtual void Close(uint16_t code, const std::string& reason) = 0;

    /// \brief Returns the host address of this server.
    /// \return The host address.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::string GetHost() const = 0;

    /// \brief Returns the port number this server is on.
    /// \return The port number.
    [[maybe_unused]]
    [[nodiscard]]
    virtual int GetPort() const = 0;

    /// \brief Returns whether this server has queued WebSocket message handlers waiting for messages to handle.
    /// \return Whether there are queued message handlers.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasQueuedMessageHandlers() const = 0;

    /// \brief Returns whether this server has unhandled WebSocket messages waiting for a message handler.
    /// \return Whether there are unhandled messages.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasUnhandledMessages() const = 0;

    /// \brief Sets this server to ignore the given WebSocket message type for its queued message handlers.
    /// \param type The message type.
    /// \return This server for chaining.
    [[maybe_unused]]
    virtual IMockWebSocketServer& IgnoreMessageType(WebSocketMessageType type) = 0;

    /// \brief Determines whether the given WebSocket message type is ignored by this server for its queued message
    /// handlers
    /// \param type The message type.
    /// \return Whether the message type is ignored.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool IsMessageTypeIgnored(WebSocketMessageType type) const = 0;

    /// \brief Adds the given WebSocket message handler to the queue of handlers for this server. Intended for stubbing
    /// or setting expectations.
    /// \param handler The message handler.
    [[maybe_unused]]
    virtual void NextMessage(WebSocketMessageHandler handler) = 0;

    /// \brief Resets message stubbing and message handling for this server.
    [[maybe_unused]]
    virtual void Reset() = 0;

    /// \brief Sends a WebSocket message to the connected clients.
    /// \param message The message.
    [[maybe_unused]]
    virtual void SendWebSocketMessage(const WebSocketMessage& message) = 0;

    /// \brief Closes all connections and stops this server.
    [[maybe_unused]]
    virtual void Shutdown() = 0;

    /// \brief Waits for all the queued message handlers to receive messages or until the timeout expires.
    /// \param timeout The timeout period.
    [[maybe_unused]]
    virtual void WaitForQueuedMessageHandlers(std::chrono::milliseconds timeout) = 0;
};

#endif //ENJINPLATFORMSDK_IMOCKWEBSOCKETSERVER_HPP
