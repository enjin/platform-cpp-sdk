#include "EnjinPlatformSdkMarketplace/GetListings.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceTypes.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<GetListings, MarketplaceListingConnectionFragment>;

[[maybe_unused]]
GetListings::GetListings()
    : RequestType("GetListings", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetListings::GetListings(const GetListings& other) = default;

[[maybe_unused]]
GetListings::GetListings(GetListings&& other) noexcept = default;

GetListings::~GetListings() = default;

[[maybe_unused]]
GetListings& GetListings::SetIds(SerializableStringArrayPtr ids)
{
    return RequestType::SetVariable("ids", CoreTypes::BigIntArray, std::move(ids));
}

[[maybe_unused]]
GetListings& GetListings::SetListingIds(SerializableStringArrayPtr listingIds)
{
    return RequestType::SetVariable("listingIds", CoreTypes::StringArray, std::move(listingIds));
}

[[maybe_unused]]
GetListings& GetListings::SetAccount(SerializableStringPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

[[maybe_unused]]
GetListings& GetListings::SetMakeAssetId(AssetInputTypePtr makeAssetId)
{
    return RequestType::SetVariable("makeAssetId", MarketplaceTypes::AssetInputType, std::move(makeAssetId));
}

[[maybe_unused]]
GetListings& GetListings::SetTakeAssetId(AssetInputTypePtr takeAssetId)
{
    return RequestType::SetVariable("takeAssetId", MarketplaceTypes::AssetInputType, std::move(takeAssetId));
}

GetListings& GetListings::operator=(const GetListings& rhs) = default;

GetListings& GetListings::operator=(GetListings&& rhs) noexcept = default;
