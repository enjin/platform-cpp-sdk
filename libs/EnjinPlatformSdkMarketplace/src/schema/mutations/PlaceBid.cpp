#include "EnjinPlatformSdkMarketplace/PlaceBid.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<PlaceBid, TransactionFragment>;

[[maybe_unused]]
PlaceBid::PlaceBid()
    : RequestType("PlaceBid", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
PlaceBid::PlaceBid(const PlaceBid& other) = default;

[[maybe_unused]]
PlaceBid::PlaceBid(PlaceBid&& other) noexcept = default;

PlaceBid::~PlaceBid() = default;

[[maybe_unused]]
PlaceBid& PlaceBid::SetListingId(SerializableStringPtr listingId)
{
    return RequestType::SetVariable("listingId", CoreTypes::String, std::move(listingId));
}

[[maybe_unused]]
PlaceBid& PlaceBid::SetPrice(SerializableStringPtr price)
{
    return RequestType::SetVariable("price", CoreTypes::BigInt, std::move(price));
}

PlaceBid& PlaceBid::operator=(const PlaceBid& rhs) = default;

PlaceBid& PlaceBid::operator=(PlaceBid&& rhs) noexcept = default;
