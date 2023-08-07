#include "EnjinPlatformSdkFuelTanks/GetFuelTank.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<GetFuelTank, FuelTankFragment>;

[[maybe_unused]]
GetFuelTank::GetFuelTank()
: RequestType("GetFuelTank", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetFuelTank::GetFuelTank(const GetFuelTank& other) = default;

[[maybe_unused]]
GetFuelTank::GetFuelTank(GetFuelTank&& other) noexcept = default;

GetFuelTank::~GetFuelTank() = default;

[[maybe_unused]]
GetFuelTank& GetFuelTank::SetName(SerializableStringPtr name)
{
    return RequestType::SetVariable("name", CoreTypes::String, std::move(name));
}

[[maybe_unused]]
GetFuelTank& GetFuelTank::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

GetFuelTank& GetFuelTank::operator=(const GetFuelTank& rhs) = default;

GetFuelTank& GetFuelTank::operator=(GetFuelTank&& rhs) noexcept = default;
