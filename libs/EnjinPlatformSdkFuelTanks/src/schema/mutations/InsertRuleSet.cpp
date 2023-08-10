#include "EnjinPlatformSdkFuelTanks/InsertRuleSet.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTanksTypes.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<InsertRuleSet, TransactionFragment>;

[[maybe_unused]]
InsertRuleSet::InsertRuleSet()
    : RequestType("InsertRuleSet", GraphQlRequestType::Mutation),
      HasIdempotencyKey<InsertRuleSet>()
{
}

[[maybe_unused]]
InsertRuleSet::InsertRuleSet(const InsertRuleSet& other) = default;

[[maybe_unused]]
InsertRuleSet::InsertRuleSet(InsertRuleSet&& other) noexcept = default;

InsertRuleSet::~InsertRuleSet() = default;

[[maybe_unused]]
InsertRuleSet& InsertRuleSet::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
InsertRuleSet& InsertRuleSet::SetRuleSetId(SerializableStringPtr ruleSetId)
{
    return RequestType::SetVariable("ruleSetId", CoreTypes::BigInt, std::move(ruleSetId));
}

[[maybe_unused]]
InsertRuleSet& InsertRuleSet::SetDispatchRules(std::shared_ptr<SerializableArray<DispatchRuleInputType>> dispatchRules)
{
    return RequestType::SetVariable("dispatchRules",
                                    FuelTanksTypes::DispatchRuleInputTypeArray,
                                    std::move(dispatchRules));
}

InsertRuleSet& InsertRuleSet::operator=(const InsertRuleSet& rhs) = default;

InsertRuleSet& InsertRuleSet::operator=(InsertRuleSet&& rhs) noexcept = default;
