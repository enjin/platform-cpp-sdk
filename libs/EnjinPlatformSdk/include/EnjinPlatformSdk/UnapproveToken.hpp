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

#ifndef ENJINPLATFORMSDK_UNAPPROVETOKEN_HPP
#define ENJINPLATFORMSDK_UNAPPROVETOKEN_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for removing the approval of any specific account to make transfers from a
/// token account.
class ENJINPLATFORMSDK_EXPORT UnapproveToken : public GraphQlRequest<UnapproveToken, TransactionFragment>,
                                               public HasEncodableTokenId<UnapproveToken>,
                                               public HasIdempotencyKey<UnapproveToken>,
                                               public HasSkipValidation<UnapproveToken>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    UnapproveToken();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    UnapproveToken(const UnapproveToken& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    UnapproveToken(UnapproveToken&& other) noexcept;

    /// \brief Class destructor.
    ~UnapproveToken() override;

    /// \brief Sets the ID of the collection that the token belongs to.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UnapproveToken& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the account that token approval will be removed from.
    /// \param op The account.
    /// \return This request for chaining.
    [[maybe_unused]]
    UnapproveToken& SetOperator(SerializableStringPtr op);

    UnapproveToken& operator=(const UnapproveToken& rhs);

    UnapproveToken& operator=(UnapproveToken&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_UNAPPROVETOKEN_HPP
