#include "EnjinPlatformSdkFuelTanks/MutateFuelTank.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTanksTypes.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<MutateFuelTank, TransactionFragment>;

[[maybe_unused]]
MutateFuelTank::MutateFuelTank()
    : RequestType("MutateFuelTank", GraphQlRequestType::Mutation),
      HasIdempotencyKey<MutateFuelTank>()
{
}

[[maybe_unused]]
MutateFuelTank::MutateFuelTank(const MutateFuelTank& other) = default;

[[maybe_unused]]
MutateFuelTank::MutateFuelTank(MutateFuelTank&& other) noexcept = default;

MutateFuelTank::~MutateFuelTank() = default;

[[maybe_unused]]
MutateFuelTank& MutateFuelTank::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
MutateFuelTank& MutateFuelTank::SetMutation(FuelTankMutationInputTypePtr mutation)
{
    return RequestType::SetVariable("mutation", FuelTanksTypes::FuelTankMutationInputType, std::move(mutation));
}

MutateFuelTank& MutateFuelTank::operator=(const MutateFuelTank& rhs) = default;

MutateFuelTank& MutateFuelTank::operator=(MutateFuelTank&& rhs) noexcept = default;
