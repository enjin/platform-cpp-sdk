#ifndef ENJINPLATFORMSDK_SERIALIZABLEDOUBLE_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEDOUBLE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
struct SerializableDouble;

/// \brief Definition for a pointer containing a SerializableDouble.
using SerializableDoublePtr [[maybe_unused]] = std::shared_ptr<SerializableDouble>;

/// \brief Struct for serializable double-precision floating-point number.
struct ENJINPLATFORMSDK_EXPORT SerializableDouble : public ISerializable
{
    /// \brief The value of this instance.
    double value;

    /// \brief Constructs an instance of this struct.
    [[maybe_unused]]
    SerializableDouble();

    /// \brief Constructs an instance of this struct with the given value.
    /// \param value The value.
    [[maybe_unused]]
    explicit SerializableDouble(double value);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SerializableDouble(const SerializableDouble& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SerializableDouble(SerializableDouble&& other) noexcept;

    /// \brief Struct destructor.
    ~SerializableDouble() override;

    SerializableDouble& operator=(const SerializableDouble& rhs);

    SerializableDouble& operator=(SerializableDouble&& rhs) noexcept;

    bool operator==(const SerializableDouble& rhs) const;

    bool operator!=(const SerializableDouble& rhs) const;

    bool operator<(const SerializableDouble& rhs) const;

    bool operator>(const SerializableDouble& rhs) const;

    bool operator<=(const SerializableDouble& rhs) const;

    bool operator>=(const SerializableDouble& rhs) const;

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

#endif //ENJINPLATFORMSDK_SERIALIZABLEDOUBLE_HPP
