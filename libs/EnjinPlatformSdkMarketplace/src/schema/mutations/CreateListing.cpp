#include "EnjinPlatformSdkMarketplace/CreateListing.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceTypes.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using RequestType = GraphQlRequest<CreateListing, TransactionFragment>;

[[maybe_unused]]
CreateListing::CreateListing()
    : RequestType("CreateListing", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
CreateListing::CreateListing(const CreateListing& other) = default;

[[maybe_unused]]
CreateListing::CreateListing(CreateListing&& other) noexcept = default;

CreateListing::~CreateListing() = default;

[[maybe_unused]]
CreateListing& CreateListing::SetAccount(SerializableStringPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

[[maybe_unused]]
CreateListing& CreateListing::SetMakeAssetId(MultiTokenIdInputPtr makeAssetId)
{
    return RequestType::SetVariable("makeAssetId", CoreTypes::MultiTokenIdInput, std::move(makeAssetId));
}

[[maybe_unused]]
CreateListing& CreateListing::SetTakeAssetId(MultiTokenIdInputPtr takeAsset)
{
    return RequestType::SetVariable("takeAsset", CoreTypes::MultiTokenIdInput, std::move(takeAsset));
}

[[maybe_unused]]
CreateListing& CreateListing::SetAmount(SerializableStringPtr amount)
{
    return RequestType::SetVariable("amount", CoreTypes::BigInt, std::move(amount));
}

[[maybe_unused]]
CreateListing& CreateListing::SetPrice(SerializableStringPtr price)
{
    return RequestType::SetVariable("price", CoreTypes::BigInt, std::move(price));
}

[[maybe_unused]]
CreateListing& CreateListing::SetSalt(SerializableStringPtr salt)
{
    return RequestType::SetVariable("salt", CoreTypes::String, std::move(salt));
}

[[maybe_unused]]
CreateListing& CreateListing::SetAuctionData(AuctionDataInputTypePtr auctionData)
{
    return RequestType::SetVariable("auctionData", MarketplaceTypes::AuctionDataInputType, std::move(auctionData));
}

CreateListing& CreateListing::operator=(const CreateListing& rhs) = default;

CreateListing& CreateListing::operator=(CreateListing&& rhs) noexcept = default;
