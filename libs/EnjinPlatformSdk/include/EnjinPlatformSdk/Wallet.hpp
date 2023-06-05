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

#ifndef ENJINPLATFORMSDK_WALLET_HPP
#define ENJINPLATFORMSDK_WALLET_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Account.hpp"
#include "EnjinPlatformSdk/Balances.hpp"
#include "EnjinPlatformSdk/Collection.hpp"
#include "EnjinPlatformSdk/CollectionAccountApproval.hpp"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/TokenAccount.hpp"
#include "EnjinPlatformSdk/TokenAccountApproval.hpp"
#include "EnjinPlatformSdk/Transaction.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
// region Forward declarations

class Account;

class Balances;

class Collection;

class CollectionAccount;

class CollectionAccountApproval;

class TokenAccount;

class TokenAccountApproval;

class Transaction;

// endregion Forward declarations

/// \brief Models a blockchain wallet.
class ENJINPLATFORMSDK_EXPORT Wallet : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Wallet();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Wallet(const Wallet& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Wallet(Wallet&& other) noexcept;

    /// \brief Class destructor.
    ~Wallet() override;

    /// \brief Returns the internal ID of this wallet.
    /// \return The ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetId() const;

    /// \brief Returns the account of this wallet.
    /// \return The account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Account>& GetAccount() const;

    /// \brief Returns the external ID associated with this wallet.
    /// \return The ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetExternalId() const;

    /// \brief Returns whether this is a managed wallet.
    /// \return Whether this wallet is managed.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetManaged() const;

    /// \brief Returns the blockchain network this wallet belongs to.
    /// \return The network.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetNetwork() const;

    /// \brief Returns the nonce of the account.
    /// \return The nonce.
    /// \remarks This property may be empty if this wallet does not exist on the blockchain.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetNonce() const;

    /// \brief Returns the EFI balance of the account.
    /// \return The balance.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Balances>& GetBalances() const;

    /// \brief Returns the collection accounts this Wallet has.
    /// \return The collection accounts.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<CollectionAccount>>& GetCollectionAccounts() const;

    /// \brief Returns the token accounts this wallet owns.
    /// \return The token accounts.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<TokenAccount>>& GetTokenAccounts() const;

    /// \brief Returns the collection account approvals this wallet has.
    /// \return The collection account approvals.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<CollectionAccountApproval>>& GetCollectionAccountApprovals() const;

    /// \brief Returns the token account approvals this wallet has.
    /// \return The token account approvals.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<TokenAccountApproval>>& GetTokenAccountApprovals() const;

    /// \brief Returns the transactions performed by this wallet.
    /// \return The transactions.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<Transaction>>& GetTransactions() const;

    /// \brief Returns the collections this wallet owns.
    /// \return The collections.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<Collection>>& GetOwnedCollections() const;

    Wallet& operator=(const Wallet& rhs);

    Wallet& operator=(Wallet&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_WALLET_HPP
