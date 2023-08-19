#include "EnjinPlatformSdkFuelTanks/DispatchRuleInputType.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using ParameterType = GraphQlParameter<DispatchRuleInputType>;

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
    return ParameterType::SetParameter("whitelistedCallers", std::move(whitelistedCallers));
}

[[maybe_unused]]
DispatchRuleInputType& DispatchRuleInputType::SetRequireToken(MultiTokenIdInputPtr requireToken)
{
    return ParameterType::SetParameter("requireToken", std::move(requireToken));
}

[[maybe_unused]]
DispatchRuleInputType&
DispatchRuleInputType::SetWhitelistedCollections(SerializableStringArrayPtr whitelistedCollections)
{
    return ParameterType::SetParameter("whitelistedCollections", std::move(whitelistedCollections));
}

[[maybe_unused]]
DispatchRuleInputType&
DispatchRuleInputType::SetMaxFuelBurnPerTransactions(SerializableStringPtr maxFuelBurnPerTransaction)
{
    return ParameterType::SetParameter("maxFuelBurnPerTransaction", std::move(maxFuelBurnPerTransaction));
}

[[maybe_unused]]
DispatchRuleInputType& DispatchRuleInputType::SetUserFuelBudget(FuelBudgetInputTypePtr userFuelBudget)
{
    return ParameterType::SetParameter("userFuelBudget", std::move(userFuelBudget));
}

[[maybe_unused]]
DispatchRuleInputType& DispatchRuleInputType::SetTankFuelBudget(FuelBudgetInputTypePtr tankFuelBudget)
{
    return ParameterType::SetParameter("tankFuelBudget", std::move(tankFuelBudget));
}

DispatchRuleInputType& DispatchRuleInputType::operator=(const DispatchRuleInputType& rhs) = default;

DispatchRuleInputType& DispatchRuleInputType::operator=(DispatchRuleInputType&& rhs) noexcept = default;
