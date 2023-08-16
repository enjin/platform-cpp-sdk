#ifndef ENJINPLATFORMSDKMARKETPLACE_AUCTIONSTATE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_AUCTIONSTATE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkMarketplace/ListingState.hpp"
#include "EnjinPlatformSdkMarketplace/ListingType.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceBid.hpp"
#include <memory>

namespace enjin::platform::sdk::marketplace
{
// region Forward declarations

class MarketplaceBid;

// endregion Forward declarations

/// \brief Models the state of an auction listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT AuctionState : public ListingState
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AuctionState();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AuctionState(const AuctionState& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AuctionState(AuctionState&& other) noexcept;

    /// \brief Class destructor.
    ~AuctionState() override;

    /// \brief Returns the type of the listing.
    /// \return The type.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<ListingType>& GetType() const;

    /// \brief Returns the highest bid for the listing.
    /// \return The highest bid.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<MarketplaceBid>& GetHighestBid() const;

    AuctionState& operator=(const AuctionState& rhs);

    AuctionState& operator=(AuctionState&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_AUCTIONSTATE_HPP
