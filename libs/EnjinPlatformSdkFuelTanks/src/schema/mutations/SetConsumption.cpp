#include "EnjinPlatformSdkFuelTanks/SetConsumption.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<SetConsumption, TransactionFragment>;

[[maybe_unused]]
SetConsumption::SetConsumption()
    : RequestType("SetConsumption", GraphQlRequestType::Mutation),
      HasIdempotencyKey<SetConsumption>()
{
}

[[maybe_unused]]
SetConsumption::SetConsumption(const SetConsumption& other) = default;

[[maybe_unused]]
SetConsumption::SetConsumption(SetConsumption&& other) noexcept = default;

SetConsumption::~SetConsumption() = default;

[[maybe_unused]]
SetConsumption& SetConsumption::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
SetConsumption& SetConsumption::SetRuleSetId(SerializableStringPtr ruleSetIf)
{
    return RequestType::SetVariable("ruleSetIf", CoreTypes::BigInt, std::move(ruleSetIf));
}

[[maybe_unused]]
SetConsumption& SetConsumption::SetUserId(SerializableStringPtr userId)
{
    return RequestType::SetVariable("userId", CoreTypes::String, std::move(userId));
}

[[maybe_unused]]
SetConsumption& SetConsumption::SetTotalConsumed(SerializableStringPtr totalConsumed)
{
    return RequestType::SetVariable("totalConsumed", CoreTypes::BigInt, std::move(totalConsumed));
}

[[maybe_unused]]
SetConsumption& SetConsumption::SetLastResetBlock(SerializableIntPtr lastResetBlock)
{
    return RequestType::SetVariable("lastResetBlock", CoreTypes::Int, std::move(lastResetBlock));
}

SetConsumption& SetConsumption::operator=(const SetConsumption& rhs) = default;

SetConsumption& SetConsumption::operator=(SetConsumption&& rhs) noexcept = default;
