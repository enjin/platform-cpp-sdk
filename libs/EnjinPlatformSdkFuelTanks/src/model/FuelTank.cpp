#include "EnjinPlatformSdkFuelTanks/FuelTank.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

// region Impl

class FuelTank::Impl : public JsonDeserializableBase
{
    std::optional<Account> tankId;
    std::optional<std::string> name;
    std::optional<bool> reserveExistentialDeposit;
    std::optional<bool> reserveAccountCreationDeposit;
    std::optional<bool> providedDeposit;
    std::optional<bool> isFrozen;
    std::optional<int> accountCount;
    std::optional<Wallet> owner;
    std::optional<std::vector<Wallet>> accounts;
    std::optional<std::vector<AccountRule>> accountRules;
    std::optional<std::vector<DispatchRule>> dispatchRules;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<Account>& GetTankId() const
    {
        return tankId;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetName() const
    {
        return name;
    }

    [[nodiscard]]
    const std::optional<bool>& GetReserveExistentialDeposit() const
    {
        return reserveExistentialDeposit;
    }

    [[nodiscard]]
    const std::optional<bool>& GetReserveAccountCreationDeposit() const
    {
        return reserveAccountCreationDeposit;
    }

    [[nodiscard]]
    const std::optional<bool>& GetProvidesDeposit() const
    {
        return providedDeposit;
    }

    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const
    {
        return isFrozen;
    }

    [[nodiscard]]
    const std::optional<int>& GetAccountCount() const
    {
        return accountCount;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetOwner() const
    {
        return owner;
    }

    [[nodiscard]]
    const std::optional<std::vector<Wallet>>& GetAccounts() const
    {
        return accounts;
    }

    [[nodiscard]]
    const std::optional<std::vector<AccountRule>>& GetAccountRules() const
    {
        return accountRules;
    }

    [[nodiscard]]
    const std::optional<std::vector<DispatchRule>>& GetDispatchRules() const
    {
        return dispatchRules;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "tankId", tankId);
        JsonUtil::TryGetField(json, "name", name);
        JsonUtil::TryGetField(json, "reserveExistentialDeposit", reserveExistentialDeposit);
        JsonUtil::TryGetField(json, "reserveAccountCreationDeposit", reserveAccountCreationDeposit);
        JsonUtil::TryGetField(json, "providedDeposit", providedDeposit);
        JsonUtil::TryGetField(json, "isFrozen", isFrozen);
        JsonUtil::TryGetField(json, "accountCount", accountCount);
        JsonUtil::TryGetField(json, "owner", owner);
        JsonUtil::TryGetField(json, "accounts", accounts);
        JsonUtil::TryGetField(json, "accountRules", accountRules);
        JsonUtil::TryGetField(json, "dispatchRules", dispatchRules);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region FuelTank

[[maybe_unused]]
FuelTank::FuelTank()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
FuelTank::FuelTank(const FuelTank& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
FuelTank::FuelTank(FuelTank&& other) noexcept = default;

FuelTank::~FuelTank() = default;

[[maybe_unused]]
const std::optional<Account>& FuelTank::GetTankId() const
{
    return _pimpl->GetTankId();
}

[[maybe_unused]]
const std::optional<std::string>& FuelTank::GetName() const
{
    return _pimpl->GetName();
}

[[maybe_unused]]
const std::optional<bool>& FuelTank::GetReserveExistentialDeposit() const
{
    return _pimpl->GetReserveExistentialDeposit();
}

[[maybe_unused]]
const std::optional<bool>& FuelTank::GetReserveAccountCreationDeposit() const
{
    return _pimpl->GetReserveAccountCreationDeposit();
}

[[maybe_unused]]
const std::optional<bool>& FuelTank::GetProvidesDeposit() const
{
    return _pimpl->GetProvidesDeposit();
}

[[maybe_unused]]
const std::optional<bool>& FuelTank::GetIsFrozen() const
{
    return _pimpl->GetIsFrozen();
}

[[maybe_unused]]
const std::optional<int>& FuelTank::GetAccountCount() const
{
    return _pimpl->GetAccountCount();
}

[[maybe_unused]]
const std::optional<Wallet>& FuelTank::GetOwner() const
{
    return _pimpl->GetOwner();
}

[[maybe_unused]]
const std::optional<std::vector<Wallet>>& FuelTank::GetAccounts() const
{
    return _pimpl->GetAccounts();
}

[[maybe_unused]]
const std::optional<std::vector<AccountRule>>& FuelTank::GetAccountRules() const
{
    return _pimpl->GetAccountRules();
}

[[maybe_unused]]
const std::optional<std::vector<DispatchRule>>& FuelTank::GetDispatchRules() const
{
    return _pimpl->GetDispatchRules();
}

FuelTank& FuelTank::operator=(const FuelTank& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

FuelTank& FuelTank::operator=(FuelTank&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void FuelTank::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion FuelTank
