#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEQUERIES_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEQUERIES_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include "EnjinPlatformSdkMarketplace/GetBid.hpp"
#include "EnjinPlatformSdkMarketplace/GetBids.hpp"
#include "EnjinPlatformSdkMarketplace/GetListing.hpp"
#include "EnjinPlatformSdkMarketplace/GetListings.hpp"
#include "EnjinPlatformSdkMarketplace/GetSale.hpp"
#include "EnjinPlatformSdkMarketplace/GetSales.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceBid.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceListing.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceSale.hpp"
#include <future>

namespace enjin::platform::sdk::marketplace
{
/// \brief Sends a GetBid request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<MarketplaceBid>>> SendGetBid(
    PlatformClient& client, const GetBid& request);

/// \brief Sends a GetBids request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<MarketplaceBid>>>> SendGetBids(
    PlatformClient& client, const GetBids& request);

/// \brief Sends a GetListing request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<MarketplaceListing>>> SendGetListing(
    PlatformClient& client, const GetListing& request);

/// \brief Sends a GetListings request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<MarketplaceListing>>>> SendGetListings(
    PlatformClient& client, const GetListings& request);

/// \brief Sends a GetSale request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<MarketplaceSale>>> SendGetSale(
    PlatformClient& client, const GetSale& request);

/// \brief Sends a GetSales request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<MarketplaceSale>>>> SendGetSales(
    PlatformClient& client, const GetSales& request);
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEQUERIES_HPP
