#include "EnjinPlatformSdkMarketplace/FillListing.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<FillListing, TransactionFragment>;

[[maybe_unused]]
FillListing::FillListing()
    : RequestType("FillListing", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
FillListing::FillListing(const FillListing& other) = default;

[[maybe_unused]]
FillListing::FillListing(FillListing&& other) noexcept = default;

FillListing::~FillListing() = default;

[[maybe_unused]]
FillListing& FillListing::SetListing(SerializableStringPtr listingIds)
{
    return RequestType::SetVariable("listingIds", CoreTypes::String, std::move(listingIds));
}

[[maybe_unused]]
FillListing& FillListing::SetAmount(SerializableStringPtr amount)
{
    return RequestType::SetVariable("amount", CoreTypes::BigInt, std::move(amount));
}

FillListing& FillListing::operator=(const FillListing& rhs) = default;

FillListing& FillListing::operator=(FillListing&& rhs) noexcept = default;
