#include "EnjinPlatformSdkMarketplace/MarketplaceMutations.hpp"

#include "MarketplaceUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendTransaction(PlatformClient& client, const IGraphQlRequest<>& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(MarketplaceUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::marketplace::SendCancelListing(
    PlatformClient& client, const CancelListing& request)
{
    return SendTransaction(client, request);
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::marketplace::SendCreateListing(
    PlatformClient& client, const CreateListing& request)
{
    return SendTransaction(client, request);
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::marketplace::SendFillListing(
    PlatformClient& client, const FillListing& request)
{
    return SendTransaction(client, request);
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::marketplace::SendFinalizeAuction(
    PlatformClient& client, const FinalizeAuction& request)
{
    return SendTransaction(client, request);
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::marketplace::SendPlaceBid(
    PlatformClient& client, const PlaceBid& request)
{
    return SendTransaction(client, request);
}
