#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESALE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESALE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceListing.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk::marketplace
{
// region Forward declarations

class MarketplaceListing;

// endregion Forward declarations

/// \brief Models a listing sale.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceSale : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarketplaceSale();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarketplaceSale(const MarketplaceSale& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarketplaceSale(MarketplaceSale&& other) noexcept;

    /// \brief Class destructor.
    ~MarketplaceSale() override;

    /// \brief Returns the internal ID for this sale.
    /// \return The internal ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetId() const;

    /// \brief Returns the price each unit was sold at.
    /// \return The price.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetPrice() const;

    /// \brief Returns the number of units sold.
    /// \return The amount sold.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetAmount() const;

    /// \brief Returns the account that placed the bid.
    /// \return The account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetBidder() const;

    /// \brief Returns the marketplace listing detail.
    /// \return The listing.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<MarketplaceListing>& GetListing() const;

    MarketplaceSale& operator=(const MarketplaceSale& rhs);

    MarketplaceSale& operator=(MarketplaceSale&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESALE_HPP
