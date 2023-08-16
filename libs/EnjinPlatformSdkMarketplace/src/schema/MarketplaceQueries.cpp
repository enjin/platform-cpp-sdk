#include "EnjinPlatformSdkMarketplace/MarketplaceQueries.hpp"

#include "MarketplaceUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<MarketplaceBid>>>
enjin::platform::sdk::marketplace::SendGetBid(
    PlatformClient& client, const GetBid& request)
{
    return client.SendRequest<GraphQlResponse<MarketplaceBid>>(MarketplaceUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<MarketplaceBid>>>>
enjin::platform::sdk::marketplace::SendGetBids(
    PlatformClient& client, const GetBids& request)
{
    return client.SendRequest<GraphQlResponse<Connection<MarketplaceBid>>>(MarketplaceUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<MarketplaceListing>>>
enjin::platform::sdk::marketplace::SendGetListing(
    PlatformClient& client, const GetListing& request)
{
    return client.SendRequest<GraphQlResponse<MarketplaceListing>>(MarketplaceUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<MarketplaceListing>>>>
enjin::platform::sdk::marketplace::SendGetListings(
    PlatformClient& client, const GetListings& request)
{
    return client.SendRequest<GraphQlResponse<Connection<MarketplaceListing>>>(MarketplaceUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<MarketplaceSale>>>
enjin::platform::sdk::marketplace::SendGetSale(
    PlatformClient& client, const GetSale& request)
{
    return client.SendRequest<GraphQlResponse<MarketplaceSale>>(MarketplaceUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<MarketplaceSale>>>>
enjin::platform::sdk::marketplace::SendGetSales(
    PlatformClient& client, const GetSales& request)
{
    return client.SendRequest<GraphQlResponse<Connection<MarketplaceSale>>>(MarketplaceUtil::CreateRequest(request));
}
