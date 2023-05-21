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

#include "EnjinPlatformSdk/Collection.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Collection::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> collectionId;
    std::optional<int32_t> maxTokenCount;
    std::optional<std::string> maxTokenSupply;
    std::optional<bool> forceSingleMint;
    std::optional<bool> frozen;
    std::optional<Royalty> royalty;
    std::optional<std::string> network;
    std::optional<Wallet> owner;
    std::optional<std::vector<Attribute>> attributes;
    std::optional<Connection<CollectionAccount>> accounts;
    std::optional<Connection<Token>> tokens;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetCollectionId() const
    {
        return collectionId;
    }

    [[nodiscard]]
    const std::optional<int32_t>& GetMaxTokenCount() const
    {
        return maxTokenCount;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetMaxTokenSupply() const
    {
        return maxTokenSupply;
    }

    [[nodiscard]]
    const std::optional<bool>& GetForceSingleMint() const
    {
        return forceSingleMint;
    }

    [[nodiscard]]
    const std::optional<bool>& GetFrozen() const
    {
        return frozen;
    }

    [[nodiscard]]
    const std::optional<Royalty>& GetRoyalty() const
    {
        return royalty;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetNetwork() const
    {
        return network;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetOwner() const
    {
        return owner;
    }

    [[nodiscard]]
    const std::optional<std::vector<Attribute>>& GetAttributes() const
    {
        return attributes;
    }

    [[nodiscard]]
    const std::optional<Connection<CollectionAccount>>& GetAccounts() const
    {
        return accounts;
    }

    [[nodiscard]]
    const std::optional<Connection<Token>>& GetTokens() const
    {
        return tokens;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "collectionId", collectionId);
        JsonUtil::TryGetField(json, "maxTokenCount", maxTokenCount);
        JsonUtil::TryGetField(json, "maxTokenSupply", maxTokenSupply);
        JsonUtil::TryGetField(json, "forceSingleMint", forceSingleMint);
        JsonUtil::TryGetField(json, "frozen", frozen);
        JsonUtil::TryGetField(json, "royalty", royalty);
        JsonUtil::TryGetField(json, "network", network);
        JsonUtil::TryGetField(json, "owner", owner);
        JsonUtil::TryGetField(json, "attributes", attributes);
        JsonUtil::TryGetField(json, "accounts", accounts);
        JsonUtil::TryGetField(json, "tokens", tokens);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Collection

[[maybe_unused]]
Collection::Collection()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Collection::Collection(const Collection& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Collection::Collection(Collection&& other) noexcept = default;

Collection::~Collection() = default;

[[maybe_unused]]
const std::optional<std::string>& Collection::GetCollectionId() const
{
    return _pimpl->GetCollectionId();
}

[[maybe_unused]]
const std::optional<int32_t>& Collection::GetMaxTokenCount() const
{
    return _pimpl->GetMaxTokenCount();
}

[[maybe_unused]]
const std::optional<std::string>& Collection::GetMaxTokenSupply() const
{
    return _pimpl->GetMaxTokenSupply();
}

[[maybe_unused]]
const std::optional<bool>& Collection::GetForceSingleMint() const
{
    return _pimpl->GetForceSingleMint();
}

[[maybe_unused]]
const std::optional<bool>& Collection::GetFrozen() const
{
    return _pimpl->GetFrozen();
}

[[maybe_unused]]
const std::optional<Royalty>& Collection::GetRoyalty() const
{
    return _pimpl->GetRoyalty();
}

[[maybe_unused]]
const std::optional<std::string>& Collection::GetNetwork() const
{
    return _pimpl->GetNetwork();
}

[[maybe_unused]]
const std::optional<Wallet>& Collection::GetOwner() const
{
    return _pimpl->GetOwner();
}

[[maybe_unused]]
const std::optional<std::vector<Attribute>>& Collection::GetAttributes() const
{
    return _pimpl->GetAttributes();
}

[[maybe_unused]]
const std::optional<Connection<CollectionAccount>>& Collection::GetAccounts() const
{
    return _pimpl->GetAccounts();
}

[[maybe_unused]]
const std::optional<Connection<Token>>& Collection::GetTokens() const
{
    return _pimpl->GetTokens();
}

Collection& Collection::operator=(const Collection& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Collection& Collection::operator=(Collection&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Collection::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Collection