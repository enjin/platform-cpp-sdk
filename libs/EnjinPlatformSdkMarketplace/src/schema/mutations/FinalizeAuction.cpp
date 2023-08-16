#include "EnjinPlatformSdkMarketplace/FinalizeAuction.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<FinalizeAuction, TransactionFragment>;

[[maybe_unused]]
FinalizeAuction::FinalizeAuction()
    : RequestType("FinalizeAuction", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
FinalizeAuction::FinalizeAuction(const FinalizeAuction& other) = default;

[[maybe_unused]]
FinalizeAuction::FinalizeAuction(FinalizeAuction&& other) noexcept = default;

FinalizeAuction::~FinalizeAuction() = default;

[[maybe_unused]]
FinalizeAuction& FinalizeAuction::SetListing(SerializableStringPtr listingId)
{
    return RequestType::SetVariable("listingId", CoreTypes::String, std::move(listingId));
}

FinalizeAuction& FinalizeAuction::operator=(const FinalizeAuction& rhs) = default;

FinalizeAuction& FinalizeAuction::operator=(FinalizeAuction&& rhs) noexcept = default;
