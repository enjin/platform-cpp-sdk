#ifndef ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICESTATEFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICESTATEFRAGMENT_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdkMarketplace/ListingStateFragment.hpp"
#include <memory>

namespace enjin::platform::sdk::marketplace
{
class FixedPriceStateFragment;

/// \brief Definition for a pointer containing a FixedPriceStateFragment.
using FixedPriceStateFragmentPtr [[maybe_unused]] = std::shared_ptr<FixedPriceStateFragment>;

/// \brief Definition for a ConnectionFragment containing a FixedPriceStateFragment.
using FixedPriceStateConnectionFragment [[maybe_unused]] = ConnectionFragment<FixedPriceStateFragment>;

/// \brief Definition for a pointer containing a FixedPriceStateConnectionFragment.
using FixedPriceStateConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<FixedPriceStateConnectionFragment>;

/// \brief A fragment for requesting properties of a FixedPriceState returned by the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT FixedPriceStateFragment : public ListingStateFragment<FixedPriceStateFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FixedPriceStateFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FixedPriceStateFragment(const FixedPriceStateFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FixedPriceStateFragment(FixedPriceStateFragment&& other) noexcept;

    /// \brief Class destructor.
    ~FixedPriceStateFragment() override;

    /// \brief Sets whether the FixedPriceState is to be returned with its type property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    FixedPriceStateFragment& WithType(bool isIncluded = true);

    /// \brief Sets whether the FixedPriceState is to be returned with its amountFilled property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    FixedPriceStateFragment& WithAmountFilled(bool isIncluded = true);

    FixedPriceStateFragment& operator=(const FixedPriceStateFragment& rhs);

    FixedPriceStateFragment& operator=(FixedPriceStateFragment&& rhs) noexcept;

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
    FixedPriceStateFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    FixedPriceStateFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    FixedPriceStateFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    FixedPriceStateFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICESTATEFRAGMENT_HPP
