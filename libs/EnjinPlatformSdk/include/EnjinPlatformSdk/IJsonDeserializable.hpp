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

#ifndef ENJINPLATFORMSDK_IJSONDESERIALIZABLE_HPP
#define ENJINPLATFORMSDK_IJSONDESERIALIZABLE_HPP

#include "EnjinPlatformSdk/JsonValue.hpp"

namespace enjin::platform::sdk
{
/// \brief Interface for JSON deserializable types.
class IJsonDeserializable
{
public:
    /// \brief Class destructor.
    virtual ~IJsonDeserializable() = default;

    /// \brief Sets member-fields on this object using the given JSON value.
    /// \param json The JSON value.
    [[maybe_unused]]
    virtual void Deserialize(const JsonValue& json) = 0;

    bool operator==(const IJsonDeserializable& rhs) const = default;

    bool operator!=(const IJsonDeserializable& rhs) const = default;
};
}

#endif //ENJINPLATFORMSDK_IJSONDESERIALIZABLE_HPP
