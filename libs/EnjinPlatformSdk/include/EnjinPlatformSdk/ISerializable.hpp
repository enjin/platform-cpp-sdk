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

#ifndef ENJINPLATFORMSDK_ISERIALIZABLE_HPP
#define ENJINPLATFORMSDK_ISERIALIZABLE_HPP

#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
class ISerializable;

/// \brief Definition for a pointer containing a serializable type.
using SerializablePtr [[maybe_unused]] = std::shared_ptr<ISerializable>;

/// \brief Interface for serializable types.
class ISerializable
{
public:
    /// \brief Class destructor.
    virtual ~ISerializable() = default;

    /// \brief Converts this serializable to a JSON value.
    /// \return The JSON representation of this class.
    [[maybe_unused]]
    [[nodiscard]]
    virtual JsonValue ToJson() const = 0;

    /// \brief Converts this serializable into a string.
    /// \return The string representation of this class.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::string ToString() const = 0;
};
}

#endif //ENJINPLATFORMSDK_ISERIALIZABLE_HPP
