#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESTATE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESTATE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkMarketplace/ListingStateEnum.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceListing.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk::marketplace
{
// region Forward declarations

class MarketplaceListing;

// endregion Forward declarations

/// \brief Models the state of a marketplace listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceState : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarketplaceState();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarketplaceState(const MarketplaceState& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarketplaceState(MarketplaceState&& other) noexcept;

    /// \brief Class destructor.
    ~MarketplaceState() override;

    /// \brief Returns the internal ID for this state.
    /// \return The internal ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetId() const;

    /// \brief Returns the mutable state of the listing.
    /// \return The state.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<ListingStateEnum>& GetState() const;

    /// \brief Returns the block height.
    /// \return The height.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int>& GetHeight() const;

    /// \brief Returns the marketplace listing detail.
    /// \return The listing.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<MarketplaceListing>& GetListing() const;

    MarketplaceState& operator=(const MarketplaceState& rhs);

    MarketplaceState& operator=(MarketplaceState&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESTATE_HPP
