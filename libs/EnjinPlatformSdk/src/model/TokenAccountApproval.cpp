#include "EnjinPlatformSdk/TokenAccountApproval.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class TokenAccountApproval::Impl : public JsonDeserializableBase
{
    std::optional<std::string> amount;
    std::optional<int32_t> expiration;
    std::optional<TokenAccount> account;
    std::optional<Wallet> wallet;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetAmount() const
    {
        return amount;
    }

    [[nodiscard]]
    const std::optional<int32_t>& GetExpiration() const
    {
        return expiration;
    }

    [[nodiscard]]
    const std::optional<TokenAccount>& GetAccount() const
    {
        return account;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const
    {
        return wallet;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "amount", amount);
        JsonUtil::TryGetField(json, "expiration", expiration);
        JsonUtil::TryGetField(json, "account", account);
        JsonUtil::TryGetField(json, "wallet", wallet);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region TokenAccountApproval

[[maybe_unused]]
TokenAccountApproval::TokenAccountApproval()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
TokenAccountApproval::TokenAccountApproval(const TokenAccountApproval& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
TokenAccountApproval::TokenAccountApproval(TokenAccountApproval&& other) noexcept = default;

TokenAccountApproval::~TokenAccountApproval() = default;

[[maybe_unused]]
const std::optional<std::string>& TokenAccountApproval::GetAmount() const
{
    return _pimpl->GetAmount();
}

[[maybe_unused]]
const std::optional<int32_t>& TokenAccountApproval::GetExpiration() const
{
    return _pimpl->GetExpiration();
}

[[maybe_unused]]
const std::optional<TokenAccount>& TokenAccountApproval::GetAccount() const
{
    return _pimpl->GetAccount();
}

[[maybe_unused]]
const std::optional<Wallet>& TokenAccountApproval::GetWallet() const
{
    return _pimpl->GetWallet();
}

TokenAccountApproval& TokenAccountApproval::operator=(const TokenAccountApproval& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

TokenAccountApproval& TokenAccountApproval::operator=(TokenAccountApproval&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void TokenAccountApproval::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion TokenAccountApproval
