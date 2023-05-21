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

#ifndef ENJINPLATFORMSDK_COLLECTIONMUTATIONINPUT_HPP
#define ENJINPLATFORMSDK_COLLECTIONMUTATIONINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/MultiTokenIdInput.hpp"
#include "EnjinPlatformSdk/MutateRoyaltyInput.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class CollectionMutationInput;

/// \brief Definition for a pointer containing a collection mutation input.
using CollectionMutationInputPtr [[maybe_unused]] = std::shared_ptr<CollectionMutationInput>;

/// \brief Models a parameter for parameters that can be mutated for a collection.
class ENJINPLATFORMSDK_EXPORT CollectionMutationInput : public GraphQlParameter<CollectionMutationInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CollectionMutationInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CollectionMutationInput(const CollectionMutationInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CollectionMutationInput(CollectionMutationInput&& other) noexcept;

    /// \brief Class destructor.
    ~CollectionMutationInput() override;

    /// \brief Sets the new owner account of the collection.
    /// \param owner The owner account.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    CollectionMutationInput& SetOwner(SerializableStringPtr owner);

    /// \brief Sets the new royalty for the collection.
    /// \param royalty The new royalty.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    CollectionMutationInput& SetRoyalty(MutateRoyaltyInputPtr royalty);

    /// \brief Sets the explicit royalty currencies for the collection.
    /// \param explicitRoyaltyCurrencies The explicit royalty currencies.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    CollectionMutationInput& SetExplicitRoyaltyCurrencies(MultiTokenIdInputPtr explicitRoyaltyCurrencies);

    CollectionMutationInput& operator=(const CollectionMutationInput& rhs);

    CollectionMutationInput& operator=(CollectionMutationInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_COLLECTIONMUTATIONINPUT_HPP
