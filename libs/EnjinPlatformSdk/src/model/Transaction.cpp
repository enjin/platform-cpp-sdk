#include "EnjinPlatformSdk/Transaction.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Transaction::Impl : public JsonDeserializableBase
{
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

public:
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
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Transaction::Transaction(const Transaction& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
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
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Transaction& Transaction::operator=(Transaction&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Transaction::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Transaction
