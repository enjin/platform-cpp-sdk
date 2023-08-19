#include "EnjinPlatformSdkFuelTanks/FuelTankMutationInputType.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using ParameterType = GraphQlParameter<FuelTankMutationInputType>;

[[maybe_unused]]
FuelTankMutationInputType::FuelTankMutationInputType() = default;

[[maybe_unused]]
FuelTankMutationInputType::FuelTankMutationInputType(const FuelTankMutationInputType& other) = default;

[[maybe_unused]]
FuelTankMutationInputType::FuelTankMutationInputType(FuelTankMutationInputType&& other) noexcept = default;

FuelTankMutationInputType::~FuelTankMutationInputType() = default;

[[maybe_unused]]
FuelTankMutationInputType&
FuelTankMutationInputType::SetReservesExistentialDeposit(SerializableBoolPtr reservesExistentialDeposit)
{
    return ParameterType::SetParameter("reservesExistentialDeposit", std::move(reservesExistentialDeposit));
}

[[maybe_unused]]
FuelTankMutationInputType&
FuelTankMutationInputType::SetReservesAccountCreationDeposit(SerializableBoolPtr reservesAccountCreationDeposit)
{
    return ParameterType::SetParameter("reservesAccountCreationDeposit", std::move(reservesAccountCreationDeposit));
}

[[maybe_unused]]
FuelTankMutationInputType& FuelTankMutationInputType::SetProvidesDeposit(SerializableBoolPtr providesDeposit)
{
    return ParameterType::SetParameter("providesDeposit", std::move(providesDeposit));
}

[[maybe_unused]]
FuelTankMutationInputType& FuelTankMutationInputType::SetAccountRules(AccountRuleInputTypePtr accountRules)
{
    return ParameterType::SetParameter("accountRules", std::move(accountRules));
}

FuelTankMutationInputType& FuelTankMutationInputType::operator=(const FuelTankMutationInputType& rhs) = default;

FuelTankMutationInputType& FuelTankMutationInputType::operator=(FuelTankMutationInputType&& rhs) noexcept = default;
