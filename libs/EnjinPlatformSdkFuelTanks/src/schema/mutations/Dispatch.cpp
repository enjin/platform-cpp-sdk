#include "EnjinPlatformSdkFuelTanks/Dispatch.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTanksTypes.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<Dispatch, TransactionFragment>;

[[maybe_unused]]
Dispatch::Dispatch()
    : RequestType("Dispatch", GraphQlRequestType::Mutation),
      HasIdempotencyKey<Dispatch>()
{
}

[[maybe_unused]]
Dispatch::Dispatch(const Dispatch& other) = default;

[[maybe_unused]]
Dispatch::Dispatch(Dispatch&& other) noexcept = default;

Dispatch::~Dispatch() = default;

[[maybe_unused]]
Dispatch& Dispatch::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
Dispatch& Dispatch::SetRuleSetId(SerializableStringPtr ruleSetId)
{
    return RequestType::SetVariable("ruleSetId", CoreTypes::BigInt, std::move(ruleSetId));
}

[[maybe_unused]]
Dispatch& Dispatch::SetDispatch(DispatchInputTypePtr dispatch)
{
    return RequestType::SetVariable("dispatch", FuelTanksTypes::DispatchRuleInputType, std::move(dispatch));
}

[[maybe_unused]]
Dispatch& Dispatch::SetPaysRemainingFee(SerializableBoolPtr paysRemainingFee)
{
    return RequestType::SetVariable("paysRemainingFee", CoreTypes::Boolean, std::move(paysRemainingFee));
}

Dispatch& Dispatch::operator=(const Dispatch& rhs) = default;

Dispatch& Dispatch::operator=(Dispatch&& rhs) noexcept = default;
