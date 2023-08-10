#include "EnjinPlatformSdkFuelTanks/RemoveRuleSet.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<RemoveRuleSet, TransactionFragment>;

[[maybe_unused]]
RemoveRuleSet::RemoveRuleSet()
    : RequestType("RemoveRuleSet", GraphQlRequestType::Mutation),
      HasIdempotencyKey<RemoveRuleSet>()
{
}

[[maybe_unused]]
RemoveRuleSet::RemoveRuleSet(const RemoveRuleSet& other) = default;

[[maybe_unused]]
RemoveRuleSet::RemoveRuleSet(RemoveRuleSet&& other) noexcept = default;

RemoveRuleSet::~RemoveRuleSet() = default;

[[maybe_unused]]
RemoveRuleSet& RemoveRuleSet::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
RemoveRuleSet& RemoveRuleSet::SetRuleSetId(SerializableStringPtr ruleSetId)
{
    return RequestType::SetVariable("ruleSetId", CoreTypes::BigInt, std::move(ruleSetId));
}

RemoveRuleSet& RemoveRuleSet::operator=(const RemoveRuleSet& rhs) = default;

RemoveRuleSet& RemoveRuleSet::operator=(RemoveRuleSet&& rhs) noexcept = default;
