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

#ifndef ENJINPLATFORMSDK_SERIALIZABLEBOOL_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEBOOL_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <string>

namespace enjin::platform::sdk
{
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
