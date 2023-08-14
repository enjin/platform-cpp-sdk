#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESALEFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESALEFRAGMENT_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceListingFragment.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlFragmentORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
// region Forward declarations

class MarketplaceListingFragment;

using MarketplaceListingFragmentPtr = std::shared_ptr<MarketplaceListingFragment>;

// endregion Forward declarations

class MarketplaceSaleFragment;

/// \brief Definition for a pointer containing a MarketplaceSaleFragment.
using MarketplaceSaleFragmentPtr [[maybe_unused]] = std::shared_ptr<MarketplaceSaleFragment>;

/// \brief Definition for a ConnectionFragment containing a MarketplaceSaleFragment.
using MarketplaceSaleConnectionFragment [[maybe_unused]] = ConnectionFragment<MarketplaceSaleFragment>;

/// \brief Definition for a pointer containing a MarketplaceSaleConnectionFragment.
using MarketplaceSaleConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<MarketplaceSaleConnectionFragment>;

/// \brief A fragment for requesting properties of a MarketplaceSale returned by the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceSaleFragment
    : public virtual IGraphQlFragment<MarketplaceSaleFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarketplaceSaleFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarketplaceSaleFragment(const MarketplaceSaleFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarketplaceSaleFragment(MarketplaceSaleFragment&& other) noexcept;

    /// \brief Class destructor.
    ~MarketplaceSaleFragment() override;

    /// \brief Sets whether the MarketplaceSale is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceSaleFragment& WithId(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceSale is to be returned with its price property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceSaleFragment& WithPrice(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceSale is to be returned with its amount property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceSaleFragment& WithAmount(bool isIncluded = true);

    /// \brief Sets the Wallet fragment to be used for getting the bidder property of the MarketplaceSale.
    /// \param fragment The Wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceSaleFragment& WithBidder(WalletFragmentPtr fragment);

    /// \brief Sets the MarketplaceListing fragment to be used for getting the listing property of the MarketplaceSale.
    /// \param fragment The MarketplaceListing fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceSaleFragment& WithListing(MarketplaceListingFragmentPtr fragment);

    MarketplaceSaleFragment& operator=(const MarketplaceSaleFragment& rhs);

    MarketplaceSaleFragment& operator=(MarketplaceSaleFragment&& rhs) noexcept;

    // region IGraphQlFragment

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileFields() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasField(const std::string& name) const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasFields() const override;

    [[maybe_unused]]
    MarketplaceSaleFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    MarketplaceSaleFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

    // endregion IGraphQlFragment

    // region IGraphQlParameterHolder

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, SerializablePtr>& GetParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameter(const std::string& key) const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override;

    [[maybe_unused]]
    MarketplaceSaleFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    MarketplaceSaleFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESALEFRAGMENT_HPP
