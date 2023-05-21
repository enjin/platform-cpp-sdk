//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef ENJINPLATFORMSDK_INTEGERRANGE_HPP
#define ENJINPLATFORMSDK_INTEGERRANGE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
struct IntegerRange;

/// \brief Definition for a pointer containing an integer range.
using IntegerRangePtr [[maybe_unused]] = std::shared_ptr<IntegerRange>;

/// \brief Represents an inclusive range between two BigInt values.
struct ENJINPLATFORMSDK_EXPORT IntegerRange : public ISerializable
{
private:
    std::string _value;

public:
    IntegerRange() = delete;

    /// \brief Initializes a new instance of this struct with the given value.
    /// \param value The value representing the whole range.
    [[maybe_unused]]
    explicit IntegerRange(const std::string& value);

    /// \brief Initializes a new instance of this struct with the given starting and ending values.
    /// \param start The starting value.
    /// \param end The ending value.
    [[maybe_unused]]
    IntegerRange(const std::string& start, const std::string& end);

    /// \brief Struct destructor.
    ~IntegerRange() override;

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
