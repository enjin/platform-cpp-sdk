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

#ifndef ENJINPLATFORMSDK_MUTATETOKEN_HPP
#define ENJINPLATFORMSDK_MUTATETOKEN_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TokenMutationInput.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for changing the default values of a token.
class ENJINPLATFORMSDK_EXPORT MutateToken : public GraphQlRequest<MutateToken, TransactionFragment>,
                                            public HasEncodableTokenId<MutateToken>,
                                            public HasIdempotencyKey<MutateToken>,
                                            public HasSkipValidation<MutateToken>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MutateToken();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MutateToken(const MutateToken& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MutateToken(MutateToken&& other) noexcept;

    /// \brief Class destructor.
    ~MutateToken() override;

    /// \brief Sets the ID of the collection that will be mutated.
    /// \param collectionId The ID of the collection.
    /// \return This request for chaining.
    [[maybe_unused]]
    MutateToken& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the parameters that will be mutated.
    /// \param mutation The parameters.
    /// \return This request for chaining.
    [[maybe_unused]]
    MutateToken& SetMutation(TokenMutationInputPtr mutation);

    MutateToken& operator=(const MutateToken& rhs);

    MutateToken& operator=(MutateToken&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MUTATETOKEN_HPP
