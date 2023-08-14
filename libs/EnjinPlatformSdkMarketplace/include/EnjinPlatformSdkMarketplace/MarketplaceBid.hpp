#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEBID_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEBID_HPP

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

/// \brief Models an auction bid.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceBid : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarketplaceBid();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarketplaceBid(const MarketplaceBid& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarketplaceBid(MarketplaceBid&& other) noexcept;

    /// \brief Class destructor.
    ~MarketplaceBid() override;

    /// \brief Returns the internal ID of this bid.
    /// \return The internal ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetId() const;

    /// \brief Returns the minimum bid price for each unit.
    /// \return The minimum bid price.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetPrice() const;

    /// \brief Returns the block height.
    /// \return The block height.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int>& GetHeight() const;

    /// \brief Returns the account that placed the bid.
    /// \return The account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetBidder() const;

    /// \brief Returns the marketplace listing detail.
    /// \return The marketplace listing.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<MarketplaceListing>& GetListing() const;

    MarketplaceBid& operator=(const MarketplaceBid& rhs);

    MarketplaceBid& operator=(MarketplaceBid&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEBID_HPP
