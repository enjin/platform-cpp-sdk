#ifndef ENJINPLATFORMSDK_WEBSOCKETMESSAGE_HPP
#define ENJINPLATFORMSDK_WEBSOCKETMESSAGE_HPP

#include "WebSocketMessageType.hpp"
#include <vector>

/// \brief A WebSocket message.
struct WebSocketMessage
{
    /// \brief The payload of the message.
    std::vector<unsigned char> payload;

    /// \brief The message type.
    WebSocketMessageType type;

    /// \brief Constructs an instance of this struct.
    [[maybe_unused]]
    WebSocketMessage();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    WebSocketMessage(const WebSocketMessage& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    WebSocketMessage(WebSocketMessage&& other) noexcept;

    /// \brief Class destructor.
    ~WebSocketMessage();

    WebSocketMessage& operator=(const WebSocketMessage& rhs);

    WebSocketMessage& operator=(WebSocketMessage&& rhs) noexcept;
};

#endif //ENJINPLATFORMSDK_WEBSOCKETMESSAGE_HPP
