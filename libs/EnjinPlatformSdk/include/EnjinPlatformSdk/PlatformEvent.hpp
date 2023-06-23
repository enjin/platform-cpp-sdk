#ifndef ENJINPLATFORMSDK_PLATFORMEVENT_HPP
#define ENJINPLATFORMSDK_PLATFORMEVENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Represents an event received from the platform.
class ENJINPLATFORMSDK_EXPORT PlatformEvent
{
    std::string _channelName;
    std::string _eventName;
    std::string _message;

    // Lazy loaded
    std::optional<JsonValue> _data;

public:
    PlatformEvent() = delete;

    /// \brief Constructs an instance of this class with the given event fields.
    /// \param eventName The name of the event.
    /// \param channelName The name of the channel the event was broadcasted on.
    /// \param message The serialized message of the event.
    [[maybe_unused]]
    PlatformEvent(std::string eventName, std::string channelName, std::string message);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PlatformEvent(const PlatformEvent& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PlatformEvent(PlatformEvent&& other) noexcept;

    /// \brief Class destructor.
    ~PlatformEvent();

    /// \brief Returns the name of the channel this event was broadcasted on.
    /// \return The name of the channel.
    [[maybe_unused]]
    [[nodiscard]]
    const std::string& GetChannelName() const;

    /// \brief Returns the deserialized message of this event. Lazy loaded.
    /// \return The message data.
    [[maybe_unused]]
    [[nodiscard]]
    const JsonValue& GetData();

    /// \brief Returns the name of this event.
    /// \return The name.
    [[maybe_unused]]
    [[nodiscard]]
    const std::string& GetEventName() const;

    /// \brief Returns the serialized message of this event.
    /// \return The message.
    [[maybe_unused]]
    [[nodiscard]]
    const std::string& GetMessage() const;

    PlatformEvent& operator=(const PlatformEvent& rhs);

    PlatformEvent& operator=(PlatformEvent&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_PLATFORMEVENT_HPP
