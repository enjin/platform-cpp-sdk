#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEMUTATIONS_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEMUTATIONS_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include "EnjinPlatformSdk/Transaction.hpp"
#include "EnjinPlatformSdkMarketplace/CancelListing.hpp"
#include "EnjinPlatformSdkMarketplace/CreateListing.hpp"
#include "EnjinPlatformSdkMarketplace/FillListing.hpp"
#include "EnjinPlatformSdkMarketplace/FinalizeAuction.hpp"
#include "EnjinPlatformSdkMarketplace/PlaceBid.hpp"
#include <future>

namespace enjin::platform::sdk::marketplace
{
/// \brief Sends a CancelListing request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendCancelListing(
    PlatformClient& client, const CancelListing& request);

/// \brief Sends a CreateListing request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendCreateListing(
    PlatformClient& client, const CreateListing& request);

/// \brief Sends a FillListing request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendFillListing(
    PlatformClient& client, const FillListing& request);

/// \brief Sends a FinalizeAuction request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendFinalizeAuction(
    PlatformClient& client, const FinalizeAuction& request);

/// \brief Sends a PlaceBid request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendPlaceBid(
    PlatformClient& client, const PlaceBid& request);
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEMUTATIONS_HPP
