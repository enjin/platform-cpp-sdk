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

#ifndef ENJINPLATFORMSDK_MULTITOKENIDINPUT_HPP
#define ENJINPLATFORMSDK_MULTITOKENIDINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class MultiTokenIdInput;

using MultiTokenIdInputPtr [[maybe_unused]] = std::shared_ptr<MultiTokenIdInput>;

/// \brief Models a parameter for setting the unique identifier for a token. Composed using a collection ID and a token
/// ID.
class ENJINPLATFORMSDK_EXPORT MultiTokenIdInput : public GraphQlParameter<MultiTokenIdInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MultiTokenIdInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MultiTokenIdInput(const MultiTokenIdInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MultiTokenIdInput(MultiTokenIdInput&& other) noexcept;

    /// \brief Class destructor.
    ~MultiTokenIdInput() override;

    /// \brief Sets the collection ID of a multi-token.
    /// \param collectionId The collection ID.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MultiTokenIdInput& SetCollectionId(SerializableStringPtr collectionId);

    MultiTokenIdInput& operator=(const MultiTokenIdInput& rhs);

    MultiTokenIdInput& operator=(MultiTokenIdInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MULTITOKENIDINPUT_HPP
