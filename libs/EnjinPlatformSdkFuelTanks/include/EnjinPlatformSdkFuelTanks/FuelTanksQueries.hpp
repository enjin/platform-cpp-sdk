#ifndef ENJINPLATFORMSDKFUELTANKS_FUELTANKSQUERIES_HPP
#define ENJINPLATFORMSDKFUELTANKS_FUELTANKSQUERIES_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTank.hpp"
#include "EnjinPlatformSdkFuelTanks/GetAccounts.hpp"
#include "EnjinPlatformSdkFuelTanks/GetFuelTank.hpp"
#include "EnjinPlatformSdkFuelTanks/GetFuelTanks.hpp"
#include <future>

namespace enjin::platform::sdk::fuelTanks
{
/// \brief Sends a GetAccounts request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Wallet>>>> SendGetAccounts(
    PlatformClient& client, const GetAccounts& request);

/// \brief Sends a GetFuelTank request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<FuelTank>>> SendGetFuelTank(
    PlatformClient& client, const GetFuelTank& request);

/// \brief Sends a GetFuelTanks request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<FuelTank>>>> SendGetFuelTanks(
    PlatformClient& client, const GetFuelTanks& request);
}

#endif //ENJINPLATFORMSDKFUELTANKS_FUELTANKSQUERIES_HPP
