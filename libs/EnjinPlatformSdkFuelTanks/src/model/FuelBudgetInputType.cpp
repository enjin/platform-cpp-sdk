#include "EnjinPlatformSdkFuelTanks/FuelBudgetInputType.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using ParameterType = GraphQlParameter<FuelBudgetInputType>;

[[maybe_unused]]
FuelBudgetInputType::FuelBudgetInputType() = default;

[[maybe_unused]]
FuelBudgetInputType::FuelBudgetInputType(const FuelBudgetInputType& other) = default;

[[maybe_unused]]
FuelBudgetInputType::FuelBudgetInputType(FuelBudgetInputType&& other) noexcept = default;

FuelBudgetInputType::~FuelBudgetInputType() = default;

[[maybe_unused]]
FuelBudgetInputType& FuelBudgetInputType::SetAmount(SerializableStringPtr amount)
{
    return ParameterType::SetParameter("amount", std::move(amount));
}

[[maybe_unused]]
FuelBudgetInputType& FuelBudgetInputType::SetResetPeriod(SerializableIntPtr resetPeriod)
{
    return ParameterType::SetParameter("resetPeriod", std::move(resetPeriod));
}

FuelBudgetInputType& FuelBudgetInputType::operator=(const FuelBudgetInputType& rhs) = default;

FuelBudgetInputType& FuelBudgetInputType::operator=(FuelBudgetInputType&& rhs) noexcept = default;
