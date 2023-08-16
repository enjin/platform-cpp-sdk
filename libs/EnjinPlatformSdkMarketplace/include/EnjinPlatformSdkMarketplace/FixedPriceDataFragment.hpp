#ifndef ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICEDATAFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICEDATAFRAGMENT_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdkMarketplace/ListingDataFragment.hpp"
#include <memory>

namespace enjin::platform::sdk::marketplace
{
class FixedPriceDataFragment;

/// \brief Definition for a pointer containing a FixedPriceDataFragment.
using FixedPriceDataFragmentPtr [[maybe_unused]] = std::shared_ptr<FixedPriceDataFragment>;

/// \brief Definition for a ConnectionFragment containing a FixedPriceDataFragment.
using FixedPriceDataConnectionFragment [[maybe_unused]] = ConnectionFragment<FixedPriceDataFragment>;

/// \brief Definition for a pointer containing a FixedPriceDataConnectionFragment.
using FixedPriceDataConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<FixedPriceDataConnectionFragment>;

/// \brief A fragment for requesting properties of a FixedPriceData returned by the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT FixedPriceDataFragment : public ListingDataFragment<FixedPriceDataFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FixedPriceDataFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FixedPriceDataFragment(const FixedPriceDataFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FixedPriceDataFragment(FixedPriceDataFragment&& other) noexcept;

    /// \brief Class destructor.
    ~FixedPriceDataFragment() override;

    /// \brief Sets whether the FixedPriceData is to be returned with its type property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    FixedPriceDataFragment& WithType(bool isIncluded = true);

    FixedPriceDataFragment& operator=(const FixedPriceDataFragment& rhs);

    FixedPriceDataFragment& operator=(FixedPriceDataFragment&& rhs) noexcept;

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
    FixedPriceDataFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    FixedPriceDataFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    FixedPriceDataFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    FixedPriceDataFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICEDATAFRAGMENT_HPP
