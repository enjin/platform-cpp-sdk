#include "EnjinPlatformSdkFuelTanks/GetAccounts.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<GetAccounts, WalletConnectionFragment>;

[[maybe_unused]]
GetAccounts::GetAccounts()
    : RequestType("GetAccounts", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetAccounts::GetAccounts(const GetAccounts& other) = default;

[[maybe_unused]]
GetAccounts::GetAccounts(GetAccounts&& other) noexcept = default;

GetAccounts::~GetAccounts() = default;

[[maybe_unused]]
GetAccounts& GetAccounts::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

GetAccounts& GetAccounts::operator=(const GetAccounts& rhs) = default;

GetAccounts& GetAccounts::operator=(GetAccounts&& rhs) noexcept = default;
