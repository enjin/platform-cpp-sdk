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

#ifndef ENJINPLATFORMSDK_CREATETOKEN_HPP
#define ENJINPLATFORMSDK_CREATETOKEN_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CreateTokenParams.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for creating a new token in a collection.
/// \remarks The new token will be automatically transferred to the specified recipient account.
class ENJINPLATFORMSDK_EXPORT CreateToken : public GraphQlRequest<CreateToken, TransactionFragment>,
                                            public HasIdempotencyKey<CreateToken>,
                                            public HasSkipValidation<CreateToken>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CreateToken();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CreateToken(const CreateToken& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CreateToken(CreateToken&& other) noexcept;

    /// \brief Class destructor.
    ~CreateToken() override;

    /// \brief Sets the recipient account of the tokens for the initial mint.
    /// \param recipient The recipient account.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateToken& SetRecipient(SerializableStringPtr recipient);

    /// \brief Sets the collection ID to create this token in.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateToken& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the parameters to create the token.
    /// \param params The parameters.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateToken& SetParams(CreateTokenParamsPtr params);

    CreateToken& operator=(const CreateToken& rhs);

    CreateToken& operator=(CreateToken&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_CREATETOKEN_HPP
