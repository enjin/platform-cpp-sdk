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

#ifndef ENJINPLATFORMSDK_SERIALIZABLEINT_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEINT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
class SerializableInt;

/// \brief Definition for a pointer containing a serializable 32-bit integer.
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
