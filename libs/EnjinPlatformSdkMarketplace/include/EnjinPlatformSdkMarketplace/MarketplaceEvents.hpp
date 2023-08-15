#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEEVENTS_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEEVENTS_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include <string>

namespace enjin::platform::sdk::marketplace
{
/// \brief Static class which contains members representing the name of each marketplace based event on the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceEvents final
{
public:
    /// \brief The name of the event for when an auction has been finalized.
    static inline const std::string AuctionFinalized = "platform:auction-finalized";

    /// \brief The name of the event for when a bid has been placed.
    static inline const std::string BidPlaced = "platform:bid-placed";

    /// \brief The name of the event for when a listing has been cancelled.
    static inline const std::string ListingCancelled = "platform:listing-cancelled";

    /// \brief The name of the event for when a listing has been created.
    static inline const std::string ListingCreated = "platform:listing-created";

    /// \brief The name of the event for when a listing has been filled.
    static inline const std::string ListingFilled = "platform:listing-filled";

    MarketplaceEvents() = delete;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEEVENTS_HPP
