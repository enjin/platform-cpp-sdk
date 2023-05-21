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

#ifndef ENJINPLATFORMSDK_SERIALIZABLEDOUBLE_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEDOUBLE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
class SerializableDouble;

/// \brief Definition for a pointer containing a serializable double-precision floating-point number.
using SerializableDoublePtr [[maybe_unused]] = std::shared_ptr<SerializableDouble>;

/// \brief Struct for serializable double precision floating point number.
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
