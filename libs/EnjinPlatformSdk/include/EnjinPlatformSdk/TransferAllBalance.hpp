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

#ifndef ENJINPLATFORMSDK_TRANSFERALLBALANCE_HPP
#define ENJINPLATFORMSDK_TRANSFERALLBALANCE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for transferring all balances of one account to another.
/// \remarks The parameter set through the SetKeepAlive method may be passed to check if the account will be left with
/// at least the existential deposit.
class ENJINPLATFORMSDK_EXPORT TransferAllBalance : public GraphQlRequest<TransferAllBalance, TransactionFragment>,
                                                   public HasIdempotencyKey<TransferAllBalance>,
                                                   public HasSkipValidation<TransferAllBalance>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TransferAllBalance();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TransferAllBalance(const TransferAllBalance& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TransferAllBalance(TransferAllBalance&& other) noexcept;

    /// \brief Class destructor.
    ~TransferAllBalance() override;

    /// \brief Sets the recipient account that will receive the transfer.
    /// \param recipient The recipient account.
    /// \return This request for chaining.
    [[maybe_unused]]
    TransferAllBalance& SetRecipient(SerializableStringPtr recipient);

    /// \brief Sets whether the transaction will be kept from failing if the balance drops below the minimum
    /// requirement.
    /// \param keepAlive Whether the transaction will be kept from failing.
    /// \return This request for chaining.
    /// \remarks The parameter defaults to false if not set.
    [[maybe_unused]]
    TransferAllBalance& SetKeepAlive(SerializableBoolPtr keepAlive);

    /// \brief Sets the signing wallet for the transaction.
    /// \param signingAccount The signing wallet account.
    /// \return This request for chaining.
    /// \remarks The account defaults to wallet daemon if not specified.
    [[maybe_unused]]
    TransferAllBalance& SetSigningAccount(SerializableStringPtr signingAccount);

    TransferAllBalance& operator=(const TransferAllBalance& rhs);

    TransferAllBalance& operator=(TransferAllBalance&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_TRANSFERALLBALANCE_HPP
