#ifndef ENJINPLATFORMSDK_SERIALIZABLEJSONVALUE_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEJSONVALUE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>

namespace enjin::platform::sdk
{
struct SerializableJsonValue;

/// \brief Definition for a pointer containing a serializable JSON value.
using SerializableJsonValuePtr [[maybe_unused]] = std::shared_ptr<SerializableJsonValue>;

/// \brief Struct for serializable JSON value.
struct ENJINPLATFORMSDK_EXPORT SerializableJsonValue : public ISerializable
{
    /// \brief The value of this instance.
    JsonValue value;

    /// \brief Constructs an instance of this struct.
    [[maybe_unused]]
    SerializableJsonValue();

    /// \brief Constructs an instance of this struct with the given value.
    /// \param value The value.
    [[maybe_unused]]
    explicit SerializableJsonValue(JsonValue value);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SerializableJsonValue(const SerializableJsonValue& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SerializableJsonValue(SerializableJsonValue&& other) noexcept;

    /// \brief Struct destructor.
    ~SerializableJsonValue() override;

    SerializableJsonValue& operator=(const SerializableJsonValue& rhs);

    SerializableJsonValue& operator=(SerializableJsonValue&& rhs) noexcept;

    bool operator==(const SerializableJsonValue& rhs) const;

    bool operator!=(const SerializableJsonValue& rhs) const;

    // region ISerializable

    [[maybe_unused]]
    [[nodiscard]]
    JsonValue ToJson() const override;

    [[maybe_unused]]
    [[nodiscard]]
    std::string ToString() const override;

    // endregion ISerializable
};
}

#endif //ENJINPLATFORMSDK_SERIALIZABLEJSONVALUE_HPP
