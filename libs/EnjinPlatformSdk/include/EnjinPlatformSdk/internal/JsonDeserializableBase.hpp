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

#ifndef ENJINPLATFORMSDK_JSONDESERIALIZABLEBASE_HPP
#define ENJINPLATFORMSDK_JSONDESERIALIZABLEBASE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"

namespace enjin::platform::sdk
{
/// \brief Abstract base class for JSON deserializable types to extend from.
class ENJINPLATFORMSDK_EXPORT JsonDeserializableBase : public IJsonDeserializable
{
    bool _hasBeenDeserialized = false;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    JsonDeserializableBase();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    JsonDeserializableBase(const JsonDeserializableBase& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    JsonDeserializableBase(JsonDeserializableBase&& other) noexcept;

    /// \brief Class destructor.
    ~JsonDeserializableBase() override;

    JsonDeserializableBase& operator=(const JsonDeserializableBase& rhs);

    JsonDeserializableBase& operator=(JsonDeserializableBase&& rhs) noexcept;

    bool operator==(const JsonDeserializableBase& rhs) const;

    bool operator!=(const JsonDeserializableBase& rhs) const;

    // region IJsonDeserializable

    /// \brief Sets member-fields on this object using the given JSON value.
    /// \param json The JSON value.
    /// \throws std::runtime_error If this member-function has already been called.
    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_JSONDESERIALIZABLEBASE_HPP
