#include "EnjinPlatformSdkMarketplace/CancelListing.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<CancelListing, TransactionFragment>;

[[maybe_unused]]
CancelListing::CancelListing()
    : RequestType("CancelListing", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
CancelListing::CancelListing(const CancelListing& other) = default;

[[maybe_unused]]
CancelListing::CancelListing(CancelListing&& other) noexcept = default;

CancelListing::~CancelListing() = default;

[[maybe_unused]]
CancelListing& CancelListing::SetListingId(SerializableStringPtr listingId)
{
    return RequestType::SetVariable("listingId", CoreTypes::String, std::move(listingId));
}

CancelListing& CancelListing::operator=(const CancelListing& rhs) = default;

CancelListing& CancelListing::operator=(CancelListing&& rhs) noexcept = default;
