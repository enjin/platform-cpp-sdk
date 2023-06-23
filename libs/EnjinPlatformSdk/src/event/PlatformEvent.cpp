#include "EnjinPlatformSdk/PlatformEvent.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
PlatformEvent::PlatformEvent(std::string eventName, std::string channelName, std::string message)
    : _channelName(std::move(channelName)),
      _eventName(std::move(eventName)),
      _message(std::move(message))
{
}

[[maybe_unused]]
PlatformEvent::PlatformEvent(const PlatformEvent& other) = default;

[[maybe_unused]]
PlatformEvent::PlatformEvent(PlatformEvent&& other) noexcept = default;

PlatformEvent::~PlatformEvent() = default;

[[maybe_unused]]
const std::string& PlatformEvent::GetChannelName() const
{
    return _channelName;
}

[[maybe_unused]]
const JsonValue& PlatformEvent::GetData()
{
    if (!_data.has_value())
    {
        _data = JsonValue::FromJson(_message);
    }

    return _data.value();
}

[[maybe_unused]]
const std::string& PlatformEvent::GetEventName() const
{
    return _eventName;
}

[[maybe_unused]]
const std::string& PlatformEvent::GetMessage() const
{
    return _message;
}

PlatformEvent& PlatformEvent::operator=(const PlatformEvent& rhs) = default;

PlatformEvent& PlatformEvent::operator=(PlatformEvent&& rhs) noexcept = default;
