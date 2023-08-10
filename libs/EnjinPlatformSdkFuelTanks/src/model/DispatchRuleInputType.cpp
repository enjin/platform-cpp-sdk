#include "EnjinPlatformSdkFuelTanks/DispatchRuleInputType.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

[[maybe_unused]]
DispatchRuleInputType::DispatchRuleInputType() = default;

[[maybe_unused]]
DispatchRuleInputType::DispatchRuleInputType(const DispatchRuleInputType& other) = default;

[[maybe_unused]]
DispatchRuleInputType::DispatchRuleInputType(DispatchRuleInputType&& other) noexcept = default;

DispatchRuleInputType::~DispatchRuleInputType() = default;

[[maybe_unused]]
DispatchRuleInputType& DispatchRuleInputType::SetWhitelistedCallers(SerializableStringArrayPtr whitelistedCallers)
{
    return SetParameter("whitelistedCallers", std::move(whitelistedCallers));
}

[[maybe_unused]]
DispatchRuleInputType& DispatchRuleInputType::SetRequireToken(MultiTokenIdInputPtr requireToken)
{
    return SetParameter("requireToken", std::move(requireToken));
}

[[maybe_unused]]
DispatchRuleInputType&
DispatchRuleInputType::SetWhitelistedCollections(SerializableStringArrayPtr whitelistedCollections)
{
    return SetParameter("whitelistedCollections", std::move(whitelistedCollections));
}

[[maybe_unused]]
DispatchRuleInputType&
DispatchRuleInputType::SetMaxFuelBurnPerTransactions(SerializableStringPtr maxFuelBurnPerTransaction)
{
    return SetParameter("maxFuelBurnPerTransaction", std::move(maxFuelBurnPerTransaction));
}

[[maybe_unused]]
DispatchRuleInputType& DispatchRuleInputType::SetUserFuelBudget(FuelBudgetInputTypePtr userFuelBudget)
{
    return SetParameter("userFuelBudget", std::move(userFuelBudget));
}

[[maybe_unused]]
DispatchRuleInputType& DispatchRuleInputType::SetTankFuelBudget(FuelBudgetInputTypePtr tankFuelBudget)
{
    return SetParameter("tankFuelBudget", std::move(tankFuelBudget));
}

DispatchRuleInputType& DispatchRuleInputType::operator=(const DispatchRuleInputType& rhs) = default;

DispatchRuleInputType& DispatchRuleInputType::operator=(DispatchRuleInputType&& rhs) noexcept = default;
