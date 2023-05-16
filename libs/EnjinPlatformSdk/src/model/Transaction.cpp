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

#include "EnjinPlatformSdk/Transaction.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Transaction::Impl : public JsonDeserializableBase
{
public:
    std::optional<int32_t> id;
    std::optional<std::string> transactionId;
    std::optional<std::string> transactionHash;
    std::optional<TransactionMethod> method;
    std::optional<TransactionState> state;
    std::optional<TransactionResult> result;
    std::optional<std::string> encodedData;
    std::optional<Wallet> wallet;
    std::optional<std::string> idempotencyKey;
    std::optional<Connection<Event>> events;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&&) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<int32_t>& GetId() const
    {
        return id;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetTransactionId() const
    {
        return transactionId;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetTransactionHash() const
    {
        return transactionHash;
    }

    [[nodiscard]]
    const std::optional<TransactionMethod>& GetMethod() const
    {
        return method;
    }

    [[nodiscard]]
    const std::optional<TransactionState>& GetState() const
    {
        return state;
    }

    [[nodiscard]]
    const std::optional<TransactionResult>& GetResult() const
    {
        return result;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetEncodedData() const
    {
        return encodedData;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const
    {
        return wallet;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetIdempotencyKey() const
    {
        return idempotencyKey;
    }

    [[nodiscard]]
    const std::optional<Connection<Event>>& GetEvents() const
    {
        return events;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "id", id);
        JsonUtil::TryGetField(json, "transactionId", transactionId);
        JsonUtil::TryGetField(json, "transactionHash", transactionHash);
        TryGetField(json, "method", method);
        TryGetField(json, "state", state);
        TryGetField(json, "result", result);
        JsonUtil::TryGetField(json, "encodedData", encodedData);
        JsonUtil::TryGetField(json, "wallet", wallet);
        JsonUtil::TryGetField(json, "idempotencyKey", idempotencyKey);
        JsonUtil::TryGetField(json, "events", events);
    }

    // endregion IJsonDeserializable
};

// region Impl

// region Transaction

[[maybe_unused]]
Transaction::Transaction()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Transaction::Transaction(const Transaction& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Transaction::Transaction(Transaction&&) noexcept = default;

Transaction::~Transaction() = default;

[[maybe_unused]]
const std::optional<int32_t>& Transaction::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<std::string>& Transaction::GetTransactionId() const
{
    return _pimpl->GetTransactionId();
}

[[maybe_unused]]
const std::optional<std::string>& Transaction::GetTransactionHash() const
{
    return _pimpl->GetTransactionHash();
}

[[maybe_unused]]
const std::optional<TransactionMethod>& Transaction::GetMethod() const
{
    return _pimpl->GetMethod();
}

[[maybe_unused]]
const std::optional<TransactionState>& Transaction::GetState() const
{
    return _pimpl->GetState();
}

[[maybe_unused]]
const std::optional<TransactionResult>& Transaction::GetResult() const
{
    return _pimpl->GetResult();
}

[[maybe_unused]]
const std::optional<std::string>& Transaction::GetEncodedData() const
{
    return _pimpl->GetEncodedData();
}

[[maybe_unused]]
const std::optional<Wallet>& Transaction::GetWallet() const
{
    return _pimpl->GetWallet();
}

[[maybe_unused]]
const std::optional<std::string>& Transaction::GetIdempotencyKey() const
{
    return _pimpl->GetIdempotencyKey();
}

[[maybe_unused]]
const std::optional<Connection<Event>>& Transaction::GetEvents() const
{
    return _pimpl->GetEvents();
}

Transaction& Transaction::operator=(const Transaction& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Transaction& Transaction::operator=(Transaction&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Transaction::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Transaction
