#ifndef ENJINPLATFORMSDK_ROYALTYFRAGMENT_HPP
#define ENJINPLATFORMSDK_ROYALTYFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class WalletFragment;

using WalletFragmentPtr = std::shared_ptr<WalletFragment>;

// endregion Forward declarations

class RoyaltyFragment;

/// \brief Definition for a pointer containing a RoyaltyFragment.
using RoyaltyFragmentPtr [[maybe_unused]] = std::shared_ptr<RoyaltyFragment>;

/// \brief Definition for a ConnectionFragment containing a RoyaltyFragment.
using RoyaltyConnectionFragment [[maybe_unused]] = ConnectionFragment<RoyaltyFragment>;

/// \brief Definition for a pointer containing a RoyaltyConnectionFragment.
using RoyaltyConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<RoyaltyConnectionFragment>;

/// \brief A fragment for requesting properties of a royalty returned by the platform.
class ENJINPLATFORMSDK_EXPORT RoyaltyFragment : public IGraphQlFragment<RoyaltyFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RoyaltyFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RoyaltyFragment(const RoyaltyFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RoyaltyFragment(RoyaltyFragment&& other) noexcept;

    /// \brief Class destructor.
    ~RoyaltyFragment() override;

    /// \brief Sets the wallet fragment to be used for getting the beneficiary property of the royalty.
    /// \param fragment The wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    RoyaltyFragment& WithBeneficiary(WalletFragmentPtr fragment);

    /// \brief Sets whether the royalty is to be returned with its percentage property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    RoyaltyFragment& WithPercentage(bool isIncluded = true);

    RoyaltyFragment& operator=(const RoyaltyFragment& rhs);

    RoyaltyFragment& operator=(RoyaltyFragment&& rhs) noexcept;

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
    RoyaltyFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    RoyaltyFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    RoyaltyFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    RoyaltyFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_ROYALTYFRAGMENT_HPP
