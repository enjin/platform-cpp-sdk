#include "EnjinPlatformSdkMarketplace/GetSale.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<GetSale, MarketplaceSaleFragment>;

[[maybe_unused]]
GetSale::GetSale()
    : RequestType("GetSale", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetSale::GetSale(const GetSale& other) = default;

[[maybe_unused]]
GetSale::GetSale(GetSale&& other) noexcept = default;

GetSale::~GetSale() = default;

[[maybe_unused]]
GetSale& GetSale::SetId(SerializableStringPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::BigInt, std::move(id));
}

GetSale& GetSale::operator=(const GetSale& rhs) = default;

GetSale& GetSale::operator=(GetSale&& rhs) noexcept = default;
