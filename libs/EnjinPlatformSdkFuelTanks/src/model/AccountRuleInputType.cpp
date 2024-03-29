#include "EnjinPlatformSdkFuelTanks/AccountRuleInputType.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using ParameterType = GraphQlParameter<AccountRuleInputType>;

[[maybe_unused]]
AccountRuleInputType::AccountRuleInputType() = default;

[[maybe_unused]]
AccountRuleInputType::AccountRuleInputType(const AccountRuleInputType& other) = default;

[[maybe_unused]]
AccountRuleInputType::AccountRuleInputType(AccountRuleInputType&& other) noexcept = default;

AccountRuleInputType::~AccountRuleInputType() = default;

[[maybe_unused]]
AccountRuleInputType& AccountRuleInputType::SetWhitelistedCallers(SerializableStringArrayPtr whitelistedCallers)
{
    return ParameterType::SetParameter("whitelistedCallers", std::move(whitelistedCallers));
}

[[maybe_unused]]
AccountRuleInputType& AccountRuleInputType::SetRequireToken(MultiTokenIdInputPtr requireToken)
{
    return ParameterType::SetParameter("requireToken", std::move(requireToken));
}

AccountRuleInputType& AccountRuleInputType::operator=(const AccountRuleInputType& rhs) = default;

AccountRuleInputType& AccountRuleInputType::operator=(AccountRuleInputType&& rhs) noexcept = default;
