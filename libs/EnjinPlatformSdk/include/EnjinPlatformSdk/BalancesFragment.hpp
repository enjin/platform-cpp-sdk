#ifndef ENJINPLATFORMSDK_BALANCESFRAGMENT_HPP
#define ENJINPLATFORMSDK_BALANCESFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class BalancesFragment;

/// \brief Definition for a pointer containing a BalancesFragment.
using BalancesFragmentPtr [[maybe_unused]] = std::shared_ptr<BalancesFragment>;

/// \brief Definition for a ConnectionFragment containing a BalancesFragment.
using BalancesConnectionFragment [[maybe_unused]] = ConnectionFragment<BalancesFragment>;

/// \brief Definition for a pointer containing a BalancesConnectionFragment.
using BalancesConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<BalancesConnectionFragment>;

/// \brief A fragment for requesting properties of balances returned by the platform.
class ENJINPLATFORMSDK_EXPORT BalancesFragment : public IGraphQlFragment<BalancesFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BalancesFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BalancesFragment(const BalancesFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BalancesFragment(BalancesFragment&& other) noexcept;

    /// \brief Class destructor.
    ~BalancesFragment() override;

    /// \brief
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BalancesFragment& WithFree(bool isIncluded = true);

    /// \brief
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BalancesFragment& WithReserved(bool isIncluded = true);

    /// \brief Sets whether the balances is to be returned with its miscFrozen property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BalancesFragment& WithMiscFrozen(bool isIncluded = true);

    /// \brief Sets whether the balances is to be returned with its feeFrozen property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BalancesFragment& WithFeeFrozen(bool isIncluded = true);

    BalancesFragment& operator=(const BalancesFragment& rhs);

    BalancesFragment& operator=(BalancesFragment&& rhs) noexcept;

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
    BalancesFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    BalancesFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    BalancesFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    BalancesFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_BALANCESFRAGMENT_HPP
