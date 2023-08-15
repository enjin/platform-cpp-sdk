#include "EnjinPlatformSdkMarketplace/GetBid.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<GetBid, MarketplaceBidFragment>;

[[maybe_unused]]
GetBid::GetBid()
    : RequestType("GetBid", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetBid::GetBid(const GetBid& other) = default;

[[maybe_unused]]
GetBid::GetBid(GetBid&& other) noexcept = default;

GetBid::~GetBid() = default;

[[maybe_unused]]
GetBid& GetBid::SetId(SerializableStringPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::BigInt, std::move(id));
}

GetBid& GetBid::operator=(const GetBid& rhs) = default;

GetBid& GetBid::operator=(GetBid&& rhs) noexcept = default;
