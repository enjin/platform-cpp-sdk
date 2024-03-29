#include "EnjinPlatformSdk/TokenAccount.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class TokenAccount::Impl : public JsonDeserializableBase
{
    std::optional<std::string> balance;
    std::optional<std::string> reservedBalance;
    std::optional<bool> isFrozen;
    std::optional<Collection> collection;
    std::optional<Wallet> wallet;
    std::optional<Token> token;
    std::optional<std::vector<TokenAccountApproval>> approvals;
    std::optional<std::vector<TokenAccountNamedReserve>> namedReserves;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetBalance() const
    {
        return balance;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetReservedBalance() const
    {
        return reservedBalance;
    }

    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const
    {
        return isFrozen;
    }

    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const
    {
        return collection;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const
    {
        return wallet;
    }

    [[nodiscard]]
    const std::optional<Token>& GetToken() const
    {
        return token;
    }

    [[nodiscard]]
    const std::optional<std::vector<TokenAccountApproval>>& GetApprovals() const
    {
        return approvals;
    }

    [[nodiscard]]
    const std::optional<std::vector<TokenAccountNamedReserve>>& GetNamedReserves() const
    {
        return namedReserves;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "balance", balance);
        JsonUtil::TryGetField(json, "reservedBalance", reservedBalance);
        JsonUtil::TryGetField(json, "isFrozen", isFrozen);
        JsonUtil::TryGetField(json, "collection", collection);
        JsonUtil::TryGetField(json, "wallet", wallet);
        JsonUtil::TryGetField(json, "token", token);
        JsonUtil::TryGetField(json, "approvals", approvals);
        JsonUtil::TryGetField(json, "namedReserves", namedReserves);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region TokenAccount

[[maybe_unused]]
TokenAccount::TokenAccount()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
TokenAccount::TokenAccount(const TokenAccount& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
TokenAccount::TokenAccount(TokenAccount&& other) noexcept = default;

TokenAccount::~TokenAccount() = default;

[[maybe_unused]]
const std::optional<std::string>& TokenAccount::GetBalance() const
{
    return _pimpl->GetBalance();
}

[[maybe_unused]]
const std::optional<std::string>& TokenAccount::GetReservedBalance() const
{
    return _pimpl->GetReservedBalance();
}

[[maybe_unused]]
const std::optional<bool>& TokenAccount::GetIsFrozen() const
{
    return _pimpl->GetIsFrozen();
}

[[maybe_unused]]
const std::optional<Collection>& TokenAccount::GetCollection() const
{
    return _pimpl->GetCollection();
}

[[maybe_unused]]
const std::optional<Wallet>& TokenAccount::GetWallet() const
{
    return _pimpl->GetWallet();
}

[[maybe_unused]]
const std::optional<Token>& TokenAccount::GetToken() const
{
    return _pimpl->GetToken();
}

[[maybe_unused]]
const std::optional<std::vector<TokenAccountApproval>>& TokenAccount::GetApprovals() const
{
    return _pimpl->GetApprovals();
}

[[maybe_unused]]
const std::optional<std::vector<TokenAccountNamedReserve>>& TokenAccount::GetNamedReserves() const
{
    return _pimpl->GetNamedReserves();
}

TokenAccount& TokenAccount::operator=(const TokenAccount& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

TokenAccount& TokenAccount::operator=(TokenAccount&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void TokenAccount::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion TokenAccount
