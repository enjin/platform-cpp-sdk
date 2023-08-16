#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEBIDFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEBIDFRAGMENT_HPP

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

class MarketplaceBidFragment;

/// \brief Definition for a pointer containing a MarketplaceBidFragment.
using MarketplaceBidFragmentPtr [[maybe_unused]] = std::shared_ptr<MarketplaceBidFragment>;

/// \brief Definition for a ConnectionFragment containing a MarketplaceBidFragment.
using MarketplaceBidConnectionFragment [[maybe_unused]] = ConnectionFragment<MarketplaceBidFragment>;

/// \brief Definition for a pointer containing a MarketplaceBidConnectionFragment.
using MarketplaceBidConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<MarketplaceBidConnectionFragment>;

/// \brief A fragment for requesting properties of a MarketplaceBid returned by the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceBidFragment
    : public virtual IGraphQlFragment<MarketplaceBidFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarketplaceBidFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarketplaceBidFragment(const MarketplaceBidFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarketplaceBidFragment(MarketplaceBidFragment&& other) noexcept;

    /// \brief Class destructor.
    ~MarketplaceBidFragment() override;

    /// \brief Sets whether the MarketplaceBid is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceBidFragment& WithId(bool isIncluded);

    /// \brief Sets whether the MarketplaceBid is to be returned with its price property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceBidFragment& WithPrice(bool isIncluded);

    /// \brief Sets whether the MarketplaceBid is to be returned with its height property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceBidFragment& WithHeight(bool isIncluded);

    /// \brief Sets the Wallet fragment to be used for getting the bidder property of the MarketplaceBid.
    /// \param fragment The Wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceBidFragment& WithBidder(WalletFragmentPtr fragment);

    /// \brief Sets the MarketplaceListing fragment to be used for getting the listing property of the MarketplaceBid.
    /// \param fragment The MarketplaceListing fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceBidFragment& WithListing(MarketplaceListingFragmentPtr fragment);

    MarketplaceBidFragment& operator=(const MarketplaceBidFragment& rhs);

    MarketplaceBidFragment& operator=(MarketplaceBidFragment&& rhs) noexcept;

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
    MarketplaceBidFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    MarketplaceBidFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    MarketplaceBidFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    MarketplaceBidFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEBIDFRAGMENT_HPP
