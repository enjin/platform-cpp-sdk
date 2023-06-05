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

#ifndef ENJINPLATFORMSDK_ATTRIBUTE_HPP
#define ENJINPLATFORMSDK_ATTRIBUTE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models an attribute attached to a type.
class ENJINPLATFORMSDK_EXPORT Attribute : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Attribute();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Attribute(const Attribute& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Attribute(Attribute&& other) noexcept;

    /// \brief Class destructor.
    ~Attribute() override;

    /// \brief Returns the attribute Key.
    /// \return The attribute Key.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetKey() const;

    /// \brief Returns the attribute value.
    /// \return The attribute value.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetValue() const;

    Attribute& operator=(const Attribute& rhs);

    Attribute& operator=(Attribute&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_ATTRIBUTE_HPP
