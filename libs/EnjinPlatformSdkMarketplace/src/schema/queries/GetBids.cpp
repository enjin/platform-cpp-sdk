#include "EnjinPlatformSdkMarketplace/GetBids.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<GetBids, MarketplaceBidConnectionFragment>;

[[maybe_unused]]
GetBids::GetBids()
    : RequestType("GetBids", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetBids::GetBids(const GetBids& other) = default;

[[maybe_unused]]
GetBids::GetBids(GetBids&& other) noexcept = default;

GetBids::~GetBids() = default;

[[maybe_unused]]
GetBids& GetBids::SetIds(SerializableStringArrayPtr ids)
{
    return RequestType::SetVariable("ids", CoreTypes::BigIntArray, std::move(ids));
}

[[maybe_unused]]
GetBids& GetBids::SetAccounts(SerializableStringArrayPtr accounts)
{
    return RequestType::SetVariable("accounts", CoreTypes::StringArray, std::move(accounts));
}

[[maybe_unused]]
GetBids& GetBids::SetListingIds(SerializableStringArrayPtr listingIds)
{
    return RequestType::SetVariable("listingIds", CoreTypes::StringArray, std::move(listingIds));
}

GetBids& GetBids::operator=(const GetBids& rhs) = default;

GetBids& GetBids::operator=(GetBids&& rhs) noexcept = default;
