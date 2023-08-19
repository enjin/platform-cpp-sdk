#ifndef ENJINPLATFORMSDK_SERIALIZABLESTRING_HPP
#define ENJINPLATFORMSDK_SERIALIZABLESTRING_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
struct SerializableString;

/// \brief Definition for a pointer containing a SerializableString.
using SerializableStringPtr [[maybe_unused]] = std::shared_ptr<SerializableString>;

/// \brief Struct for serializable string.
struct ENJINPLATFORMSDK_EXPORT SerializableString : public ISerializable
{
    /// \brief The value of this instance.
    std::string value;

    /// \brief Constructs an instance of this struct.
    [[maybe_unused]]
    SerializableString();

    /// \brief Constructs an instance of this struct with the given value.
    /// \param value The value.
    [[maybe_unused]]
    explicit SerializableString(std::string value);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SerializableString(const SerializableString& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SerializableString(SerializableString&& other) noexcept;

    /// \brief Struct destructor.
    ~SerializableString() override;

    SerializableString& operator=(const SerializableString& rhs);

    SerializableString& operator=(SerializableString&& rhs) noexcept;

    bool operator==(const SerializableString& rhs) const;

    bool operator!=(const SerializableString& rhs) const;

    bool operator<(const SerializableString& rhs) const;

    bool operator>(const SerializableString& rhs) const;

    bool operator<=(const SerializableString& rhs) const;

    bool operator>=(const SerializableString& rhs) const;

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

#endif //ENJINPLATFORMSDK_SERIALIZABLESTRING_HPP
