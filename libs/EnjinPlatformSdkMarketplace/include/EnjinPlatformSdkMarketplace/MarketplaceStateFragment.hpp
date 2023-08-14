#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESTATEFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESTATEFRAGMENT_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
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

class MarketplaceStateFragment;

/// \brief Definition for a pointer containing a MarketplaceStateFragment.
using MarketplaceStateFragmentPtr [[maybe_unused]] = std::shared_ptr<MarketplaceStateFragment>;

/// \brief Definition for a ConnectionFragment containing a MarketplaceStateFragment.
using MarketplaceStateConnectionFragment [[maybe_unused]] = ConnectionFragment<MarketplaceStateFragment>;

/// \brief Definition for a pointer containing a MarketplaceStateConnectionFragment.
using MarketplaceStateConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<MarketplaceStateConnectionFragment>;

/// \brief A fragment for requesting properties of a MarketplaceState returned by the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceStateFragment
    : public virtual IGraphQlFragment<MarketplaceStateFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarketplaceStateFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarketplaceStateFragment(const MarketplaceStateFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarketplaceStateFragment(MarketplaceStateFragment&& other) noexcept;

    /// \brief Class destructor.
    ~MarketplaceStateFragment() override;

    /// \brief Sets whether the MarketplaceState is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceStateFragment& WithId(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceState is to be returned with its state property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceStateFragment& WithState(bool isIncluded = true);

    /// \brief Sets whether the MarketplaceState is to be returned with its height property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceStateFragment& WithHeight(bool isIncluded = true);

    /// \brief Sets the MarketplaceListing fragment to be used for getting the listing property of the MarketplaceState.
    /// \param fragment The MarketplaceListing fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    MarketplaceStateFragment& WithListing(MarketplaceListingFragmentPtr fragment);

    MarketplaceStateFragment& operator=(const MarketplaceStateFragment& rhs);

    MarketplaceStateFragment& operator=(MarketplaceStateFragment&& rhs) noexcept;

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
    MarketplaceStateFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    MarketplaceStateFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    MarketplaceStateFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    MarketplaceStateFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACESTATEFRAGMENT_HPP
