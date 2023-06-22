#ifndef ENJINPLATFORMSDK_WEBSOCKETMESSAGETYPE_HPP
#define ENJINPLATFORMSDK_WEBSOCKETMESSAGETYPE_HPP

/// \brief Enums representing the type of a WebSocket message.
enum class WebSocketMessageType
{
    Unknown,
    Utf8Message,
    BinaryMessage,
    Open,
    Close,
    Error,
    Ping,
    Pong,
    Utf8Fragment,
    BinaryFragment,
};

#endif //ENJINPLATFORMSDK_WEBSOCKETMESSAGETYPE_HPP
