#ifndef ENJINPLATFORMSDK_INTEGERRANGE_HPP
#define ENJINPLATFORMSDK_INTEGERRANGE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
class IntegerRange;

/// \brief Definition for a pointer containing an IntegerRange.
using IntegerRangePtr [[maybe_unused]] = std::shared_ptr<IntegerRange>;

/// \brief Represents an inclusive range between two BigInt values.
class ENJINPLATFORMSDK_EXPORT IntegerRange : public virtual ISerializable
{
    std::string _value;

public:
    IntegerRange() = delete;

    /// \brief Initializes a new instance of this class with the given value.
    /// \param value The value representing the whole range.
    [[maybe_unused]]
    explicit IntegerRange(const std::string& value);

    /// \brief Initializes a new instance of this class with the given starting and ending values.
    /// \param start The starting value.
    /// \param end The ending value.
    [[maybe_unused]]
    IntegerRange(const std::string& start, const std::string& end);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    IntegerRange(const IntegerRange& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    IntegerRange(IntegerRange&& other) noexcept;

    /// \brief class destructor.
    ~IntegerRange() override;

    IntegerRange& operator=(const IntegerRange& rhs);

    IntegerRange& operator=(IntegerRange&& rhs) noexcept;

    // region ISerializable

    [[maybe_unused]]
    [[nodiscard]]
    JsonValue ToJson() const override;

    /// \brief Converts this serializable into a string.
    /// \return The string representation of this class.
    /// \remarks If the start and end values are not equal, then the returned string will be the two values separated by
    /// two periods. For example, if the starting value is 3 and the ending value is 8, then the string will be returned
    /// as "3..8".
    [[maybe_unused]]
    [[nodiscard]]
    std::string ToString() const override;

    // endregion ISerializable
};
}

#endif //ENJINPLATFORMSDK_INTEGERRANGE_HPP
