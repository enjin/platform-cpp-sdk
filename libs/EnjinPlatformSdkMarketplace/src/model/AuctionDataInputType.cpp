#include "EnjinPlatformSdkMarketplace/AuctionDataInputType.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using ParameterType = GraphQlParameter<AuctionDataInputType>;

[[maybe_unused]]
AuctionDataInputType::AuctionDataInputType() = default;

[[maybe_unused]]
AuctionDataInputType::AuctionDataInputType(const AuctionDataInputType& other) = default;

[[maybe_unused]]
AuctionDataInputType::AuctionDataInputType(AuctionDataInputType&& other) noexcept = default;

AuctionDataInputType::~AuctionDataInputType() = default;

[[maybe_unused]]
AuctionDataInputType& AuctionDataInputType::SetStartBlock(SerializableIntPtr startBlock)
{
    return ParameterType::SetParameter("startBlock", std::move(startBlock));
}

[[maybe_unused]]
AuctionDataInputType& AuctionDataInputType::SetEndBlock(SerializableIntPtr endBlock)
{
    return ParameterType::SetParameter("endBlock", std::move(endBlock));
}

AuctionDataInputType& AuctionDataInputType::operator=(const AuctionDataInputType& rhs) = default;

AuctionDataInputType& AuctionDataInputType::operator=(AuctionDataInputType&& rhs) noexcept = default;
