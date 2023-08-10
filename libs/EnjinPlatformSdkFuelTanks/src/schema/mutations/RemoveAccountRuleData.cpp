#include "EnjinPlatformSdkFuelTanks/RemoveAccountRuleData.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTanksTypes.hpp"
#include <memory>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<RemoveAccountRuleData, TransactionFragment>;

[[maybe_unused]]
RemoveAccountRuleData::RemoveAccountRuleData()
    : RequestType("RemoveAccountRuleData", GraphQlRequestType::Mutation),
      HasIdempotencyKey<RemoveAccountRuleData>()
{
}

[[maybe_unused]]
RemoveAccountRuleData::RemoveAccountRuleData(const RemoveAccountRuleData& other) = default;

[[maybe_unused]]
RemoveAccountRuleData::RemoveAccountRuleData(RemoveAccountRuleData&& other) noexcept = default;

RemoveAccountRuleData::~RemoveAccountRuleData() = default;

[[maybe_unused]]
RemoveAccountRuleData& RemoveAccountRuleData::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
RemoveAccountRuleData& RemoveAccountRuleData::SetUserId(SerializableStringPtr userId)
{
    return RequestType::SetVariable("userId", CoreTypes::String, std::move(userId));
}

[[maybe_unused]]
RemoveAccountRuleData& RemoveAccountRuleData::SetRuleSetId(SerializableStringPtr ruleSetId)
{
    return RequestType::SetVariable("ruleSetId", CoreTypes::BigInt, std::move(ruleSetId));
}

[[maybe_unused]]
RemoveAccountRuleData& RemoveAccountRuleData::SetRule(const DispatchRuleEnum rule)
{
    std::string s = enjin::platform::sdk::fuelTanks::ToString(rule);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return RequestType::SetVariable("rule", FuelTanksTypes::DispatchRuleEnum, std::move(sPtr));
}

RemoveAccountRuleData& RemoveAccountRuleData::operator=(const RemoveAccountRuleData& rhs) = default;

RemoveAccountRuleData& RemoveAccountRuleData::operator=(RemoveAccountRuleData&& rhs) noexcept = default;
