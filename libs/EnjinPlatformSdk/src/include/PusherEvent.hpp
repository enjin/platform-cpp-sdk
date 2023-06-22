#ifndef ENJINPLATFORMSDK_PUSHEREVENT_HPP
#define ENJINPLATFORMSDK_PUSHEREVENT_HPP

#include "enjinplatformsdk_export.h"
#include <optional>
#include <string>

namespace pusher
{
/// \brief Class representing a Pusher event.
class ENJINPLATFORMSDK_EXPORT PusherEvent
{
    std::optional<std::string> _channelName;
    std::optional<std::string> _data;
    std::optional<std::string> _eventName;
    std::optional<std::string> _userId;

    static constexpr char ChannelKey[] = "channel";
    static constexpr char DataKey[] = "data";
    static constexpr char EventKey[] = "event";
    static constexpr char UserIdKey[] = "user_id";

public:
    PusherEvent() = delete;

    /// \brief Constructs an instance of this class from the given JSON string.
    [[maybe_unused]]
    explicit PusherEvent(const std::string& json);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PusherEvent(const PusherEvent& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PusherEvent(PusherEvent&& other) noexcept;

    /// \brief Class destructor.
    ~PusherEvent();

    /// \brief Returns the name of the channel this event was broadcasted on.
    /// \return The channel name.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetChannelName() const;

    /// \brief Returns the data of this event.
    /// \return The data.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetData() const;

    /// \brief Returns the name of this event.
    /// \return The event name.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetEventName() const;

    /// \brief Returns the user ID of this event.
    /// \return The user ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetUserId() const;

    PusherEvent& operator=(const PusherEvent& rhs);

    PusherEvent& operator=(PusherEvent&& rhs) noexcept;

    bool operator==(const PusherEvent& rhs) const;

    bool operator!=(const PusherEvent& rhs) const;

private:
    /// \brief Sets the fields of this event with the data in the given JSON.
    /// \param json The JSON string.
    void Deserialize(const std::string& json);
};
}

#endif //ENJINPLATFORMSDK_PUSHEREVENT_HPP
