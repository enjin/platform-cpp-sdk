#include "WebSocketMessage.hpp"

[[maybe_unused]]
WebSocketMessage::WebSocketMessage()
    : type(WebSocketMessageType::Unknown)
{
}

[[maybe_unused]]
WebSocketMessage::WebSocketMessage(const WebSocketMessage& other) = default;

[[maybe_unused]]
WebSocketMessage::WebSocketMessage(WebSocketMessage&& other) noexcept = default;

WebSocketMessage::~WebSocketMessage() = default;

WebSocketMessage& WebSocketMessage::operator=(const WebSocketMessage& rhs) = default;

WebSocketMessage& WebSocketMessage::operator=(WebSocketMessage&& rhs) noexcept = default;
