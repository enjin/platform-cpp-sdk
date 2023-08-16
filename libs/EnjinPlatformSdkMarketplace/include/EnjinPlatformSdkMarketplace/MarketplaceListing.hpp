#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACELISTING_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACELISTING_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdkMarketplace/Asset.hpp"
#include "EnjinPlatformSdkMarketplace/FeeSide.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceBid.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceSale.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceState.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk::marketplace
{
// region Forward declarations

class Asset;

class MarketplaceBid;

class MarketplaceSale;

class MarketplaceState;

// endregion Forward declarations

/// \brief Models the details of a marketplace listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceListing : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarketplaceListing();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarketplaceListing(const MarketplaceListing& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarketplaceListing(MarketplaceListing&& other) noexcept;

    /// \brief Class destructor.
    ~MarketplaceListing() override;

    /// \brief Returns the internal ID of this listing.
    /// \return The internal ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetId() const;

    /// \brief Returns the ID of this listing.
    /// \return The ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetListingId() const;

    /// \brief Returns the collection and token ID of the asset being sold.
    /// \return The asset data.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Asset>& GetMakeAssetId() const;

    /// \brief Returns the collection and token ID of the asset being requested.
    /// \return The asset data.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Asset>& GetTakeAssetId() const;

    /// \brief Returns the number of units being sold.
    /// \return The amount.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetAmount() const;

    /// \brief Returns the requested price for each unit. If this listing is an auction, then this value is the minimum
    /// bid.
    /// \return The requested price.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetPrice() const;

    /// \brief Returns the minimum value of the take asset received for the sale to be a success.
    /// \return The minimum value.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetMinTakeValue() const;

    /// \brief Returns the side that is considered money and is used to pay fees for this listing.
    /// \return The side used to pay fees.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<FeeSide>& GetFeeSide() const;

    /// \brief Returns the block number this listing was created on.
    /// \return The block number.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int>& GetCreationBlock() const;

    /// \brief Returns the deposit that was reserved for this listing.
    /// \return The deposit.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetDeposit() const;

    /// \brief Returns the salt that may be used to differentiate this listing from others.
    /// \return The salt.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetSalt() const;

    /// \brief Returns the mutable state for this listing.
    /// \return The state.
    /// \remarks The type of this value is ambiguous and ought to be deserialized into either an AuctionState or a
    /// FixedPriceState once its type is determined.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<JsonValue>& GetState() const;

    /// \brief Returns the specialized data for this listing.
    /// \return The data.
    /// \remarks The type of this value is ambiguous and ought to be deserialized into either an AuctionData or a
    /// FixedPriceData once its type is determined.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<JsonValue>& GetData() const;

    /// \brief Returns the account making the sale for this listing.
    /// \return The account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetSeller() const;

    /// \brief Returns the sales of this listing.
    /// \return The sales.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<MarketplaceSale>>& GetSales() const;

    /// \brief Returns the auction bids of this listing.
    /// \return The bids.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<MarketplaceBid>>& GetBids() const;

    /// \brief Returns the states of this listing.
    /// \return The states.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<MarketplaceState>>& GetStates() const;

    MarketplaceListing& operator=(const MarketplaceListing& rhs);

    MarketplaceListing& operator=(MarketplaceListing&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACELISTING_HPP
