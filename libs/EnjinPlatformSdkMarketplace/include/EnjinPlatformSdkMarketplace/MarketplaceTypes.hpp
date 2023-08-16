#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACETYPES_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACETYPES_HPP

#include "enjinplatformsdkmarketplace_export.h"

namespace enjin::platform::sdk::marketplace
{
/// \brief Contains fields describing variable types used in the platform's Marketplace API.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceTypes final
{
public:
    // AssetInputType

    /// \brief String for <c>AssetInputType</c> type.
    [[maybe_unused]]
    static constexpr char AssetInputType[] = "AssetInputType!";

    /// \brief String for an array of <c>AssetInputType</c> type.
    [[maybe_unused]]
    static constexpr char AssetInputTypeArray[] = "[AssetInputType!]!";

    // AuctionDataInputType

    /// \brief String for <c>AuctionDataInputType</c> type.
    [[maybe_unused]]
    static constexpr char AuctionDataInputType[] = "AuctionDataInputType!";

    /// \brief String for an array of <c>AuctionDataInputType</c> type.
    [[maybe_unused]]
    static constexpr char AuctionDataInputTypeArray[] = "[AuctionDataInputType!]!";

    MarketplaceTypes() = delete;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACETYPES_HPP
