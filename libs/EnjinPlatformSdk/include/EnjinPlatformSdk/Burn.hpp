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

#ifndef ENJINPLATFORMSDK_BURN_HPP
#define ENJINPLATFORMSDK_BURN_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/BurnParamsInput.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for deleting a collection and get its reserved value back.
/// \remarks A collection can only be destroyed after all tokens have been burned.
class ENJINPLATFORMSDK_EXPORT Burn : public GraphQlRequest<Burn, TransactionFragment>,
                                     public HasIdempotencyKey<Burn>,
                                     public HasSkipValidation<Burn>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Burn();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Burn(const Burn& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Burn(Burn&& other) noexcept;

    /// \brief Class destructor.
    ~Burn() override;

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    Burn& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the parameters required to burn a token.
    /// \param params The parameters.
    /// \return This request for chaining.
    [[maybe_unused]]
    Burn& SetParams(BurnParamsInputPtr params);

    Burn& operator=(const Burn& rhs);

    Burn& operator=(Burn&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_BURN_HPP
