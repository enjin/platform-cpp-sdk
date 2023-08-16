#include "EnjinPlatformSdkMarketplace/GetSales.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<GetSales, MarketplaceSaleConnectionFragment>;

[[maybe_unused]]
GetSales::GetSales()
    : RequestType("GetSales", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetSales::GetSales(const GetSales& other) = default;

[[maybe_unused]]
GetSales::GetSales(GetSales&& other) noexcept = default;

GetSales::~GetSales() = default;

[[maybe_unused]]
GetSales& GetSales::SetIds(SerializableStringArrayPtr ids)
{
    return RequestType::SetVariable("ids", CoreTypes::BigIntArray, std::move(ids));
}

[[maybe_unused]]
GetSales& GetSales::SetAccounts(SerializableStringArrayPtr accounts)
{
    return RequestType::SetVariable("accounts", CoreTypes::StringArray, std::move(accounts));
}

[[maybe_unused]]
GetSales& GetSales::SetListingIds(SerializableStringArrayPtr listingIds)
{
    return RequestType::SetVariable("listingIds", CoreTypes::StringArray, std::move(listingIds));
}

GetSales& GetSales::operator=(const GetSales& rhs) = default;

GetSales& GetSales::operator=(GetSales&& rhs) noexcept = default;
