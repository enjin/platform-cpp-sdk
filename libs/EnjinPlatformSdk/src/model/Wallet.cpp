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

#include "EnjinPlatformSdk/Wallet.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Wallet::Impl : public JsonDeserializableBase
{
public:
    std::optional<int32_t> id;
    std::optional<Account> account;
    std::optional<std::string> externalId;
    std::optional<bool> managed;
    std::optional<std::string> network;
    std::optional<int32_t> nonce;
    std::optional<Balances> balances;
    std::optional<Connection<CollectionAccount>> collectionAccounts;
    std::optional<Connection<TokenAccount>> tokenAccounts;
    std::optional<Connection<CollectionAccountApproval>> collectionAccountApprovals;
    std::optional<Connection<TokenAccountApproval>> tokenAccountApprovals;
    std::optional<Connection<Transaction>> transactions;
    std::optional<Connection<Collection>> ownedCollections;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<int32_t>& GetId() const
    {
        return id;
    }

    [[nodiscard]]
    const std::optional<Account>& GetAccount() const
    {
        return account;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetExternalId() const
    {
        return externalId;
    }

    [[nodiscard]]
    const std::optional<bool>& GetManaged() const
    {
        return managed;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetNetwork() const
    {
        return network;
    }

    [[nodiscard]]
    const std::optional<int32_t>& GetNonce() const
    {
        return nonce;
    }

    [[nodiscard]]
    const std::optional<Balances>& GetBalances() const
    {
        return balances;
    }

    [[nodiscard]]
    const std::optional<Connection<CollectionAccount>>& GetCollectionAccounts() const
    {
        return collectionAccounts;
    }

    [[nodiscard]]
    const std::optional<Connection<TokenAccount>>& GetTokenAccounts() const
    {
        return tokenAccounts;
    }

    [[nodiscard]]
    const std::optional<Connection<CollectionAccountApproval>>& GetCollectionAccountApprovals() const
    {
        return collectionAccountApprovals;
    }

    [[nodiscard]]
    const std::optional<Connection<TokenAccountApproval>>& GetTokenAccountApprovals() const
    {
        return tokenAccountApprovals;
    }

    [[nodiscard]]
    const std::optional<Connection<Transaction>>& GetTransactions() const
    {
        return transactions;
    }

    [[nodiscard]]
    const std::optional<Connection<Collection>>& GetOwnedCollections() const
    {
        return ownedCollections;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "id", id);
        JsonUtil::TryGetField(json, "account", account);
        JsonUtil::TryGetField(json, "externalId", externalId);
        JsonUtil::TryGetField(json, "managed", managed);
        JsonUtil::TryGetField(json, "network", network);
        JsonUtil::TryGetField(json, "nonce", nonce);
        JsonUtil::TryGetField(json, "balances", balances);
        JsonUtil::TryGetField(json, "collectionAccounts", collectionAccounts);
        JsonUtil::TryGetField(json, "tokenAccounts", tokenAccounts);
        JsonUtil::TryGetField(json, "collectionAccountApprovals", collectionAccountApprovals);
        JsonUtil::TryGetField(json, "tokenAccountApprovals", tokenAccountApprovals);
        JsonUtil::TryGetField(json, "transactions", transactions);
        JsonUtil::TryGetField(json, "ownedCollections", ownedCollections);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Wallet

[[maybe_unused]]
Wallet::Wallet()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Wallet::Wallet(const Wallet& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Wallet::Wallet(Wallet&& other) noexcept = default;

Wallet::~Wallet() = default;

[[maybe_unused]]
const std::optional<int32_t>& Wallet::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<Account>& Wallet::GetAccount() const
{
    return _pimpl->GetAccount();
}

[[maybe_unused]]
const std::optional<std::string>& Wallet::GetExternalId() const
{
    return _pimpl->GetExternalId();
}

[[maybe_unused]]
const std::optional<bool>& Wallet::GetManaged() const
{
    return _pimpl->GetManaged();
}

[[maybe_unused]]
const std::optional<std::string>& Wallet::GetNetwork() const
{
    return _pimpl->GetNetwork();
}

[[maybe_unused]]
const std::optional<int32_t>& Wallet::GetNonce() const
{
    return _pimpl->GetNonce();
}

[[maybe_unused]]
const std::optional<Balances>& Wallet::GetBalances() const
{
    return _pimpl->GetBalances();
}

[[maybe_unused]]
const std::optional<Connection<CollectionAccount>>& Wallet::GetCollectionAccounts() const
{
    return _pimpl->GetCollectionAccounts();
}

[[maybe_unused]]
const std::optional<Connection<TokenAccount>>& Wallet::GetTokenAccounts() const
{
    return _pimpl->GetTokenAccounts();
}

[[maybe_unused]]
const std::optional<Connection<CollectionAccountApproval>>& Wallet::GetCollectionAccountApprovals() const
{
    return _pimpl->GetCollectionAccountApprovals();
}

[[maybe_unused]]
const std::optional<Connection<TokenAccountApproval>>& Wallet::GetTokenAccountApprovals() const
{
    return _pimpl->GetTokenAccountApprovals();
}

[[maybe_unused]]
const std::optional<Connection<Transaction>>& Wallet::GetTransactions() const
{
    return _pimpl->GetTransactions();
}

[[maybe_unused]]
const std::optional<Connection<Collection>>& Wallet::GetOwnedCollections() const
{
    return _pimpl->GetOwnedCollections();
}

Wallet& Wallet::operator=(const Wallet& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Wallet& Wallet::operator=(Wallet&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Wallet::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Wallet
