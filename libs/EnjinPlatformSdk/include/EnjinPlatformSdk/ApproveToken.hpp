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

#ifndef ENJINPLATFORMSDK_APPROVETOKEN_HPP
#define ENJINPLATFORMSDK_APPROVETOKEN_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for approving another account to make transfers from a token account.
/// \remarks The block number where this approval will expire and the amount of tokens this account will be able to
/// transfer may be specified.
class ENJINPLATFORMSDK_EXPORT ApproveToken : public GraphQlRequest<ApproveToken, TransactionFragment>,
                                             public HasEncodableTokenId<ApproveToken>,
                                             public HasIdempotencyKey<ApproveToken>,
                                             public HasSkipValidation<ApproveToken>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ApproveToken();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ApproveToken(const ApproveToken& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ApproveToken(ApproveToken&& other) noexcept;

    /// \brief Class destructor.
    ~ApproveToken() override;

    /// \brief Sets the ID of the collection that the token being approved belongs to.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    ApproveToken& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the account that will be approved to operate the token.
    /// \param op The account to become an operator.
    /// \return This request for chaining.
    [[maybe_unused]]
    ApproveToken& SetOperator(SerializableStringPtr op);

    /// \brief Sets the amount of tokens that will be approved to operate.
    /// \param amount The amount to approve.
    /// \return This request for chaining.
    [[maybe_unused]]
    ApproveToken& SetAmount(SerializableStringPtr amount);

    /// \brief Sets the current amount of tokens the operator has.
    /// \param currentAmount The current amount approved.
    /// \return This request for chaining.
    [[maybe_unused]]
    ApproveToken& SetCurrentAmount(SerializableStringPtr currentAmount);

    /// \brief Sets the block number where the approval will expire.
    /// \param expiration The block number.
    /// \return This request for chaining.
    /// \remarks If this parameter is null or otherwise unspecified, then the approval will not expire.
    [[maybe_unused]]
    ApproveToken& SetExpiration(SerializableIntPtr expiration);

    ApproveToken& operator=(const ApproveToken& rhs);

    ApproveToken& operator=(ApproveToken&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_APPROVETOKEN_HPP
