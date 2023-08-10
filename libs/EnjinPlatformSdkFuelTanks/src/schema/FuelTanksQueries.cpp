#include "EnjinPlatformSdkFuelTanks/FuelTanksQueries.hpp"

#include "FuelTanksUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Wallet>>>>
enjin::platform::sdk::fuelTanks::SendGetAccounts(
    PlatformClient& client, const GetAccounts& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Wallet>>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<FuelTank>>>
enjin::platform::sdk::fuelTanks::SendGetFuelTank(
    PlatformClient& client, const GetFuelTank& request)
{
    return client.SendRequest<GraphQlResponse<FuelTank>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<FuelTank>>>>
enjin::platform::sdk::fuelTanks::SendGetFuelTanks(
    PlatformClient& client, const GetFuelTanks& request)
{
    return client.SendRequest<GraphQlResponse<Connection<FuelTank>>>(FuelTanksUtil::CreateRequest(request));
}
