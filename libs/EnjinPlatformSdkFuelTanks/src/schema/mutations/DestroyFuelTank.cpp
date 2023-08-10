#include "EnjinPlatformSdkFuelTanks/DestroyFuelTank.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<DestroyFuelTank, TransactionFragment>;

[[maybe_unused]]
DestroyFuelTank::DestroyFuelTank()
    : RequestType("DestroyFuelTank", GraphQlRequestType::Mutation),
      HasIdempotencyKey<DestroyFuelTank>()
{
}

[[maybe_unused]]
DestroyFuelTank::DestroyFuelTank(const DestroyFuelTank& other) = default;

[[maybe_unused]]
DestroyFuelTank::DestroyFuelTank(DestroyFuelTank&& other) noexcept = default;

DestroyFuelTank::~DestroyFuelTank() = default;

[[maybe_unused]]
DestroyFuelTank& DestroyFuelTank::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

DestroyFuelTank& DestroyFuelTank::operator=(const DestroyFuelTank& rhs) = default;

DestroyFuelTank& DestroyFuelTank::operator=(DestroyFuelTank&& rhs) noexcept = default;
