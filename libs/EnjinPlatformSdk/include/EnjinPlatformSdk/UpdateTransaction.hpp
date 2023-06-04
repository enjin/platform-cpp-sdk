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

#ifndef ENJINPLATFORMSDK_UPDATETRANSACTION_HPP
#define ENJINPLATFORMSDK_UPDATETRANSACTION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionState.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for updating a transaction with a new state, transaction ID, and transaction
/// hash.
class ENJINPLATFORMSDK_EXPORT UpdateTransaction : public GraphQlRequest<UpdateTransaction>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    UpdateTransaction();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    UpdateTransaction(const UpdateTransaction& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    UpdateTransaction(UpdateTransaction&& other) noexcept;

    /// \brief Class destructor.
    ~UpdateTransaction() override;

    /// \brief Sets the internal ID of the transaction.
    /// \param id The internal ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateTransaction& SetId(SerializableIntPtr id);

    /// \brief Sets the new state of the transaction.
    /// \param state The new state.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateTransaction& SetState(TransactionState state);

    /// \brief Sets the on-chain transaction ID.
    /// \param transactionId The transaction ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateTransaction& SetTransactionId(SerializableStringPtr transactionId);

    /// \brief Sets the on-chain transaction hash.
    /// \param transactionHash The transaction hash.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateTransaction& SetTransactionHash(SerializableStringPtr transactionHash);

    UpdateTransaction& operator=(const UpdateTransaction& rhs);

    UpdateTransaction& operator=(UpdateTransaction&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_UPDATETRANSACTION_HPP
