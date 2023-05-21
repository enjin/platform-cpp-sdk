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

#ifndef ENJINPLATFORMSDK_SERIALIZABLEFLOAT_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEFLOAT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
class SerializableFloat;

/// \brief Definition for a pointer containing a serializable floating-point number.
using SerializableFloatPtr [[maybe_unused]] = std::shared_ptr<SerializableFloat>;

/// \brief Struct for serializable floating point number.
struct ENJINPLATFORMSDK_EXPORT SerializableFloat : public ISerializable
{
    /// \brief The value of this instance.
    float value;

    /// \brief Constructs an instance of this struct.
    [[maybe_unused]]
    SerializableFloat();

    /// \brief Constructs an instance of this struct with the given value.
    /// \param value The value.
    [[maybe_unused]]
    explicit SerializableFloat(float value);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SerializableFloat(const SerializableFloat& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SerializableFloat(SerializableFloat&& other) noexcept;

    /// \brief Struct destructor.
    ~SerializableFloat() override;

    SerializableFloat& operator=(const SerializableFloat& rhs);

    SerializableFloat& operator=(SerializableFloat&& rhs) noexcept;

    bool operator==(const SerializableFloat& rhs) const;

    bool operator!=(const SerializableFloat& rhs) const;

    bool operator<(const SerializableFloat& rhs) const;

    bool operator>(const SerializableFloat& rhs) const;

    bool operator<=(const SerializableFloat& rhs) const;

    bool operator>=(const SerializableFloat& rhs) const;

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

#endif //ENJINPLATFORMSDK_SERIALIZABLEFLOAT_HPP