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

#ifndef ENJINPLATFORMSDK_GETTRANSACTION_HPP
#define ENJINPLATFORMSDK_GETTRANSACTION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying a transaction using its database ID, on-chain transaction ID, or transaction hash.
class ENJINPLATFORMSDK_EXPORT GetTransaction : public GraphQlRequest<GetTransaction, TransactionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetTransaction();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetTransaction(const GetTransaction& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetTransaction(GetTransaction&& other) noexcept;

    /// \brief Class destructor.
    ~GetTransaction() override;

    /// \brief Sets the internal ID of the transaction.
    /// \param id The internal ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransaction& SetId(SerializableStringPtr id);

    /// \brief Sets the idempotency key to filter to.
    /// \param idempotencyKey The idempotency key.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransaction& SetIdempotencyKey(SerializableStringPtr idempotencyKey);

    /// \brief Sets the blockchain transaction ID.
    /// \param transactionId The transaction ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransaction& SetTransactionId(SerializableStringPtr transactionId);

    /// \brief Sets the blockchain transaction hash.
    /// \param transactionHash The transaction hash.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransaction& SetTransactionHash(SerializableStringPtr transactionHash);

    GetTransaction& operator=(const GetTransaction& rhs);

    GetTransaction& operator=(GetTransaction&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETTRANSACTION_HPP
