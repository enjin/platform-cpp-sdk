#include "EnjinPlatformSdkFuelTanks/DispatchAndTouch.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTanksTypes.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<DispatchAndTouch, TransactionFragment>;

[[maybe_unused]]
DispatchAndTouch::DispatchAndTouch()
    : RequestType("DispatchAndTouch", GraphQlRequestType::Mutation),
      HasIdempotencyKey<DispatchAndTouch>()
{
}

[[maybe_unused]]
DispatchAndTouch::DispatchAndTouch(const DispatchAndTouch& other) = default;

[[maybe_unused]]
DispatchAndTouch::DispatchAndTouch(DispatchAndTouch&& other) noexcept = default;

DispatchAndTouch::~DispatchAndTouch() = default;

[[maybe_unused]]
DispatchAndTouch& DispatchAndTouch::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
DispatchAndTouch& DispatchAndTouch::SetRuleSetId(SerializableStringPtr ruleSetId)
{
    return RequestType::SetVariable("ruleSetId", CoreTypes::BigInt, std::move(ruleSetId));
}

[[maybe_unused]]
DispatchAndTouch& DispatchAndTouch::SetDispatch(DispatchInputTypePtr dispatch)
{
    return RequestType::SetVariable("dispatch", FuelTanksTypes::DispatchInputType, std::move(dispatch));
}

[[maybe_unused]]
DispatchAndTouch& DispatchAndTouch::SetPaysRemainingFee(SerializableBoolPtr paysRemainingFee)
{
    return RequestType::SetVariable("paysRemainingFee", CoreTypes::Boolean, std::move(paysRemainingFee));
}

DispatchAndTouch& DispatchAndTouch::operator=(const DispatchAndTouch& rhs) = default;

DispatchAndTouch& DispatchAndTouch::operator=(DispatchAndTouch&& rhs) noexcept = default;
