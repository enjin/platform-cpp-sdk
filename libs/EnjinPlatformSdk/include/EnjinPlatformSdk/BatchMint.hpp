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

#ifndef ENJINPLATFORMSDK_BATCHMINT_HPP
#define ENJINPLATFORMSDK_BATCHMINT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasContinueOnFailure.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/MintRecipient.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for minting multiple tokens in one transaction.
/// \remarks The create token and mint token params of MintRecipient may be mixed and matched. The continueOnFailure
/// flag may be used to skip mints which fail on-chain so that they may be fixed later.
class ENJINPLATFORMSDK_EXPORT BatchMint : public GraphQlRequest<BatchMint, TransactionFragment>,
                                          public HasContinueOnFailure<BatchMint>,
                                          public HasIdempotencyKey<BatchMint>,
                                          public HasSkipValidation<BatchMint>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BatchMint();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BatchMint(const BatchMint& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BatchMint(BatchMint&& other) noexcept;

    /// \brief Class destructor.
    ~BatchMint() override;

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchMint& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the recipients.
    /// \param recipients The recipients.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchMint& SetRecipients(std::shared_ptr<SerializableArray<MintRecipient>> recipients);

    BatchMint& operator=(const BatchMint& rhs);

    BatchMint& operator=(BatchMint&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_BATCHMINT_HPP
