#ifndef ENJINPLATFORMSDKMARKETPLACE_AUCTIONSTATEFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_AUCTIONSTATEFRAGMENT_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdkMarketplace/ListingStateFragment.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceBidFragment.hpp"
#include <memory>

namespace enjin::platform::sdk::marketplace
{
// region Forward declarations

class MarketplaceBidFragment;

using MarketplaceBidFragmentPtr = std::shared_ptr<MarketplaceBidFragment>;

// endregion Forward declarations

class AuctionStateFragment;

/// \brief Definition for a pointer containing an AuctionStateFragment.
using AuctionStateFragmentPtr [[maybe_unused]] = std::shared_ptr<AuctionStateFragment>;

/// \brief Definition for a ConnectionFragment containing an AuctionStateFragment.
using AuctionStateConnectionFragment [[maybe_unused]] = ConnectionFragment<AuctionStateFragment>;

/// \brief Definition for a pointer containing an AuctionStateConnectionFragment.
using AuctionStateConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<AuctionStateConnectionFragment>;

/// \brief A fragment for requesting properties of an AuctionState returned by the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT AuctionStateFragment : public ListingStateFragment<AuctionStateFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AuctionStateFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AuctionStateFragment(const AuctionStateFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AuctionStateFragment(AuctionStateFragment&& other) noexcept;

    /// \brief Class destructor.
    ~AuctionStateFragment() override;

    /// \brief Sets whether the MarketplaceListing is to be returned with its listingId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AuctionStateFragment& WithType(bool isIncluded = true);

    /// \brief Sets the MarketplaceBid fragment to be used for getting the highestBid property of the AuctionState.
    /// \param fragment The MarketplaceBid fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AuctionStateFragment& WithHighestBid(MarketplaceBidFragmentPtr fragment);

    AuctionStateFragment& operator=(const AuctionStateFragment& rhs);

    AuctionStateFragment& operator=(AuctionStateFragment&& rhs) noexcept;

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
    AuctionStateFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    AuctionStateFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    AuctionStateFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    AuctionStateFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_AUCTIONSTATEFRAGMENT_HPP
