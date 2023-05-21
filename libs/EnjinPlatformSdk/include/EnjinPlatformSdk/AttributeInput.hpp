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

#ifndef ENJINPLATFORMSDK_ATTRIBUTEINPUT_HPP
#define ENJINPLATFORMSDK_ATTRIBUTEINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class AttributeInput;

/// \brief Definition for a pointer containing an attribute input.
using AttributeInputPtr [[maybe_unused]] = std::shared_ptr<AttributeInput>;

/// \brief Models a parameter for setting the attribute of a collection or token.
class ENJINPLATFORMSDK_EXPORT AttributeInput : public GraphQlParameter<AttributeInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AttributeInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AttributeInput(const AttributeInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AttributeInput(AttributeInput&& other) noexcept;

    /// \brief Class destructor.
    ~AttributeInput() override;

    /// \brief Sets the attribute key.
    /// \param key The key.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    AttributeInput& SetKey(SerializableStringPtr key);

    /// \brief Sets the attribute value.
    /// \param value The value.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    AttributeInput& SetValue(SerializableStringPtr value);

    AttributeInput& operator=(const AttributeInput& rhs);

    AttributeInput& operator=(AttributeInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_ATTRIBUTEINPUT_HPP
