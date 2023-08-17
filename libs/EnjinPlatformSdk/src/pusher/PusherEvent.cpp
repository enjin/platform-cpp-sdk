#include "PusherEvent.hpp"

#include "rapidjson/document.h"

using namespace pusher;
using namespace rapidjson;

[[maybe_unused]]
PusherEvent::PusherEvent(const std::string& json)
{
    Deserialize(json);
}

[[maybe_unused]]
PusherEvent::PusherEvent(const PusherEvent& other) = default;

[[maybe_unused]]
PusherEvent::PusherEvent(PusherEvent&& other) noexcept = default;

PusherEvent::~PusherEvent() = default;

[[maybe_unused]]
const std::optional<std::string>& PusherEvent::GetChannelName() const
{
    return _channelName;
}

[[maybe_unused]]
const std::optional<std::string>& PusherEvent::GetData() const
{
    return _data;
}

[[maybe_unused]]
const std::optional<std::string>& PusherEvent::GetEventName() const
{
    return _eventName;
}

[[maybe_unused]]
const std::optional<std::string>& PusherEvent::GetUserId() const
{
    return _userId;
}

PusherEvent& PusherEvent::operator=(const PusherEvent& rhs) = default;

PusherEvent& PusherEvent::operator=(PusherEvent&& rhs) noexcept = default;

bool PusherEvent::operator==(const PusherEvent& rhs) const
{
    return _channelName == rhs._channelName
           && _data == rhs._data
           && _eventName == rhs._eventName
           && _userId == rhs._userId;
}

bool PusherEvent::operator!=(const PusherEvent& rhs) const
{
    return !(rhs == *this);
}

void PusherEvent::Deserialize(const std::string& json)
{
    Document document;
    document.Parse(json.c_str());

    if (!document.IsObject())
    {
        return;
    }

    if (document.HasMember(UserIdKey) && document[UserIdKey].IsString())
    {
        _userId = document[UserIdKey].GetString();
    }

    if (document.HasMember(ChannelKey) && document[ChannelKey].IsString())
    {
        _channelName = document[ChannelKey].GetString();
    }

    if (document.HasMember(EventKey) && document[EventKey].IsString())
    {
        _eventName = document[EventKey].GetString();
    }

    if (document.HasMember(DataKey) && document[DataKey].IsString())
    {
        _data = document[DataKey].GetString();
    }
}
