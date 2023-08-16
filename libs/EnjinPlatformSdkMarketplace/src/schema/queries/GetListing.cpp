#include "EnjinPlatformSdkMarketplace/GetListing.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<GetListing, MarketplaceListingFragment>;

[[maybe_unused]]
GetListing::GetListing()
    : RequestType("GetListing", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetListing::GetListing(const GetListing& other) = default;

[[maybe_unused]]
GetListing::GetListing(GetListing&& other) noexcept = default;

GetListing::~GetListing() = default;

[[maybe_unused]]
GetListing& GetListing::SetId(SerializableStringPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::BigInt, std::move(id));
}

[[maybe_unused]]
GetListing& GetListing::SetListingId(SerializableStringPtr listingId)
{
    return RequestType::SetVariable("listingId", CoreTypes::String, std::move(listingId));
}

GetListing& GetListing::operator=(const GetListing& rhs) = default;

GetListing& GetListing::operator=(GetListing&& rhs) noexcept = default;
