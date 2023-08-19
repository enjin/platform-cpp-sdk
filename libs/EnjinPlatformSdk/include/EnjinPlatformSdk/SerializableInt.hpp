#ifndef ENJINPLATFORMSDK_SERIALIZABLEINT_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEINT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
struct SerializableInt;

/// \brief Definition for a pointer containing a SerializableInt.
using SerializableIntPtr [[maybe_unused]] = std::shared_ptr<SerializableInt>;

/// \brief Struct for serializable 32-bit integers.
struct ENJINPLATFORMSDK_EXPORT SerializableInt : public ISerializable
{
    /// \brief The value of this instance.
    int32_t value;

    /// \brief Constructs an instance of this struct.
    [[maybe_unused]]
    SerializableInt();

    /// \brief Constructs an instance of this struct with the given value.
    /// \param value The value.
    [[maybe_unused]]
    explicit SerializableInt(int32_t value);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SerializableInt(const SerializableInt& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SerializableInt(SerializableInt&& other) noexcept;

    /// \brief Struct destructor.
    ~SerializableInt() override;

    SerializableInt& operator=(const SerializableInt& rhs);

    SerializableInt& operator=(SerializableInt&& rhs) noexcept;

    bool operator==(const SerializableInt& rhs) const;

    bool operator!=(const SerializableInt& rhs) const;

    bool operator<(const SerializableInt& rhs) const;

    bool operator>(const SerializableInt& rhs) const;

    bool operator<=(const SerializableInt& rhs) const;

    bool operator>=(const SerializableInt& rhs) const;

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

#endif //ENJINPLATFORMSDK_SERIALIZABLEINT_HPP
