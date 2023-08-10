#include "EnjinPlatformSdkFuelTanks/ScheduleMutateFreeze.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<ScheduleMutateFreeze, TransactionFragment>;

[[maybe_unused]]
ScheduleMutateFreeze::ScheduleMutateFreeze()
    : RequestType("ScheduleMutateFreeze", GraphQlRequestType::Mutation),
      HasIdempotencyKey<ScheduleMutateFreeze>()
{
}

[[maybe_unused]]
ScheduleMutateFreeze::ScheduleMutateFreeze(const ScheduleMutateFreeze& other) = default;

[[maybe_unused]]
ScheduleMutateFreeze::ScheduleMutateFreeze(ScheduleMutateFreeze&& other) noexcept = default;

ScheduleMutateFreeze::~ScheduleMutateFreeze() = default;

[[maybe_unused]]
ScheduleMutateFreeze& ScheduleMutateFreeze::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
ScheduleMutateFreeze& ScheduleMutateFreeze::SetIsFrozen(SerializableBoolPtr isFrozen)
{
    return RequestType::SetVariable("isFrozen", CoreTypes::Boolean, std::move(isFrozen));
}

[[maybe_unused]]
ScheduleMutateFreeze& ScheduleMutateFreeze::SetRuleSetId(SerializableStringPtr ruleSetId)
{
    return RequestType::SetVariable("ruleSetId", CoreTypes::BigInt, std::move(ruleSetId));
}

ScheduleMutateFreeze& ScheduleMutateFreeze::operator=(const ScheduleMutateFreeze& rhs) = default;

ScheduleMutateFreeze& ScheduleMutateFreeze::operator=(ScheduleMutateFreeze&& rhs) noexcept = default;
