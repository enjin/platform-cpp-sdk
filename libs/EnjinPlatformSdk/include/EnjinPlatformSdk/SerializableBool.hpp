#ifndef ENJINPLATFORMSDK_SERIALIZABLEBOOL_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEBOOL_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
struct SerializableBool;

/// \brief Definition for a pointer containing a SerializableBool.
using SerializableBoolPtr [[maybe_unused]] = std::shared_ptr<SerializableBool>;

/// \brief Struct for serializable boolean.
struct ENJINPLATFORMSDK_EXPORT SerializableBool : public ISerializable
{
    /// \brief The value of this instance.
    bool value;

    /// \brief Constructs an instance of this struct.
    [[maybe_unused]]
    SerializableBool();

    /// \brief Constructs an instance of this struct with the given value.
    /// \param value The value.
    [[maybe_unused]]
    explicit SerializableBool(bool value);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SerializableBool(const SerializableBool& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SerializableBool(SerializableBool&& other) noexcept;

    /// \brief Struct destructor.
    ~SerializableBool() override;

    SerializableBool& operator=(const SerializableBool& rhs);

    SerializableBool& operator=(SerializableBool&& rhs) noexcept;

    bool operator==(const SerializableBool& rhs) const;

    bool operator!=(const SerializableBool& rhs) const;

    bool operator<(const SerializableBool& rhs) const;

    bool operator>(const SerializableBool& rhs) const;

    bool operator<=(const SerializableBool& rhs) const;

    bool operator>=(const SerializableBool& rhs) const;

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

#endif //ENJINPLATFORMSDK_SERIALIZABLEBOOL_HPP
