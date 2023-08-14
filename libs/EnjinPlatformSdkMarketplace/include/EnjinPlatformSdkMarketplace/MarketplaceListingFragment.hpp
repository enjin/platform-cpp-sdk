#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACELISTINGFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACELISTINGFRAGMENT_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include "EnjinPlatformSdkMarketplace/AssetFragment.hpp"
#include "EnjinPlatformSdkMarketplace/ListingDataFragment.hpp"
#include "EnjinPlatformSdkMarketplace/ListingStateFragment.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceBidFragment.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceSaleFragment.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceStateFragment.hpp"
#include <memory>
#include <type_traits>
#include <utility>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlFragmentORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
// region Forward declarations

class AssetFragment;

using AssetFragmentPtr = std::shared_ptr<AssetFragment>;

class MarketplaceBidFragment;

using MarketplaceBidConnectionFragment = ConnectionFragment<MarketplaceBidFragment>;
using MarketplaceBidConnectionFragmentPtr = std::shared_ptr<MarketplaceBidConnectionFragment>;

class MarketplaceSaleFragment;

using MarketplaceSaleConnectionFragment = ConnectionFragment<MarketplaceSaleFragment>;
using MarketplaceSaleConnectionFragmentPtr = std::shared_ptr<MarketplaceSaleConnectionFragment>;

class MarketplaceStateFragment;

using MarketplaceStateFragmentPtr = std::shared_ptr<MarketplaceStateFragment>;

// endregion Forward declarations

class MarketplaceListingFragment;

/// \brief Definition for a pointer containing a MarketplaceListingFragment.
using MarketplaceListingFragmentPtr [[maybe_unused]] = std::shared_ptr<MarketplaceListingFragment>;

/// \brief Definition for a ConnectionFragment containing a MarketplaceListingFragment.
using MarketplaceListingConnectionFragment [[maybe_unused]] = ConnectionFragment<MarketplaceListingFragment>;

/// \brief Definition for a pointer containing a MarketplaceListingConnectionFragment.
using MarketplaceListingConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<MarketplaceListingConnectionFragment>;

/// \brief A fragment for requesting properties of a MarketplaceListing returned by the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceListingFragment
    : public virtual IGraphQlFragment<MarketplaceListingFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarketplaceListingFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarketplaceListingFragment(const MarketplaceListingFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarketplaceListingFragment(MarketplaceListingFragment&& other) noexcept;

    /// \brief Class destructor.
    ~MarketplaceListingFragment() override;

    /// \brief Sets whether the MarketplaceListing is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithId(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceListing is to be returned with its listingId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithListingId(bool isIncluded = true);

    /// \brief Sets the Asset fragment to be used for getting the makeAssetId property of the MarketplaceListing.
    /// \param fragment The Asset fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithMakeAssetId(AssetFragmentPtr fragment);

    /// \brief Sets the Asset fragment to be used for getting the takeAssetId property of the MarketplaceListing.
    /// \param fragment The Asset fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithTakeAssetId(AssetFragmentPtr fragment);

    /// \brief Sets whether the MarketplaceListing is to be returned with its amount property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithAmount(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceListing is to be returned with its price property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithPrice(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceListing is to be returned with its minTakeValue property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithMinTakeValue(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceListing is to be returned with its feeSide property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithFeeSide(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceListing is to be returned with its creationBlock property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithCreationBlock(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceListing is to be returned with its deposit property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithDeposit(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceListing is to be returned with its salt property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithSalt(bool isIncluded = true);

    /// \brief Sets the ListingState fragment to be used for getting the state property of the MarketplaceListing.
    /// \tparam TFragment The specific type of the state fragment.
    /// \param fragment The ListingState fragment.
    /// \return This fragment for chaining.
    template<class TFragment>
    [[maybe_unused]]
    MarketplaceListingFragment& WithState(std::shared_ptr<ListingStateFragment<TFragment>> fragment)
    {
        static_assert(std::is_base_of<ListingStateFragment<TFragment>, TFragment>::value,
                      "Type TFragment does not implement ListingStateFragment<TFragment>");

        return WithField("state", std::move(fragment));
    }

    /// \brief Sets the ListingData fragment to be used for getting the data property of the MarketplaceListing.
    /// \tparam TFragment The specific type of the data fragment.
    /// \param fragment The ListingData fragment.
    /// \return This fragment for chaining.
    template<class TFragment>
    [[maybe_unused]]
    MarketplaceListingFragment& WithData(std::shared_ptr<ListingDataFragment<TFragment>> fragment)
    {
        static_assert(std::is_base_of<ListingStateFragment<TFragment>, TFragment>::value,
                      "Type TFragment does not implement ListingStateFragment<TFragment>");

        return WithField("data", std::move(fragment));
    }

    /// \brief Sets the Wallet fragment to be used for getting the seller property of the MarketplaceListing.
    /// \param fragment The Wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithSeller(WalletFragmentPtr fragment);

    /// \brief Sets the Connection fragment, which uses MarketplaceSale, to be used for getting the sales property of
    /// the MarketplaceListing.
    /// \param fragment The Connection fragment, which uses MarketplaceSale.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithSales(MarketplaceSaleConnectionFragmentPtr fragment);

    /// \brief Sets the Connection fragment, which uses MarketplaceBid, to be used for getting the bids property of the
    /// MarketplaceListing.
    /// \param fragment The Connection fragment, which uses MarketplaceBid.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithBids(MarketplaceBidConnectionFragmentPtr fragment);

    /// \brief Sets the MarketplaceState fragment to be used for getting the states property of the MarketplaceListing.
    /// \param fragment The MarketplaceState fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceListingFragment& WithStates(MarketplaceStateFragmentPtr fragment);

    MarketplaceListingFragment& operator=(const MarketplaceListingFragment& rhs);

    MarketplaceListingFragment& operator=(MarketplaceListingFragment&& rhs) noexcept;

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
    MarketplaceListingFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    MarketplaceListingFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    MarketplaceListingFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    MarketplaceListingFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACELISTINGFRAGMENT_HPP
