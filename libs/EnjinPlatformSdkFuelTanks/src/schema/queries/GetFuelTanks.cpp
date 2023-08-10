#include "EnjinPlatformSdkFuelTanks/GetFuelTanks.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<GetFuelTanks, FuelTankConnectionFragment>;

[[maybe_unused]]
GetFuelTanks::GetFuelTanks()
    : RequestType("GetFuelTanks", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetFuelTanks::GetFuelTanks(const GetFuelTanks& other) = default;

[[maybe_unused]]
GetFuelTanks::GetFuelTanks(GetFuelTanks&& other) noexcept = default;

GetFuelTanks::~GetFuelTanks() = default;

[[maybe_unused]]
GetFuelTanks& GetFuelTanks::SetNames(SerializableStringArrayPtr names)
{
    return RequestType::SetVariable("names", CoreTypes::StringArray, std::move(names));
}

[[maybe_unused]]
GetFuelTanks& GetFuelTanks::SetTankIds(SerializableStringArrayPtr tankIds)
{
    return RequestType::SetVariable("tankIds", CoreTypes::StringArray, std::move(tankIds));
}

GetFuelTanks& GetFuelTanks::operator=(const GetFuelTanks& rhs) = default;

GetFuelTanks& GetFuelTanks::operator=(GetFuelTanks&& rhs) noexcept = default;
