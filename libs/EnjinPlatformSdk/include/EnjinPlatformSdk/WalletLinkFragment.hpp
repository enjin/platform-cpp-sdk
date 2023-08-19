#ifndef ENJINPLATFORMSDK_WALLETLINKFRAGMENT_HPP
#define ENJINPLATFORMSDK_WALLETLINKFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class WalletLinkFragment;

/// \brief Definition for a pointer containing a WalletLinkFragment.
using WalletLinkFragmentPtr [[maybe_unused]] = std::shared_ptr<WalletLinkFragment>;

/// \brief Definition for a ConnectionFragment containing a WalletLinkFragment.
using WalletLinkConnectFragment [[maybe_unused]] = ConnectionFragment<WalletLinkFragment>;

/// \brief Definition for a pointer containing a WalletLinkConnectFragment.
using WalletLinkConnectFragmentPtr [[maybe_unused]] = std::shared_ptr<WalletLinkConnectFragment>;

/// \brief A fragment for requesting properties of a wallet link returned by the platform.
class ENJINPLATFORMSDK_EXPORT WalletLinkFragment : public IGraphQlFragment<WalletLinkFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    WalletLinkFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    WalletLinkFragment(const WalletLinkFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    WalletLinkFragment(WalletLinkFragment&& other) noexcept;

    /// \brief Class destructor.
    ~WalletLinkFragment() override;

    /// \brief Sets whether the wallet link is to be returned with its code property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletLinkFragment& WithCode(bool isIncluded = true);

    WalletLinkFragment& operator=(const WalletLinkFragment& rhs);

    WalletLinkFragment& operator=(WalletLinkFragment&& rhs) noexcept;

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
    WalletLinkFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    WalletLinkFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    bool HasParameters() const override;

    [[maybe_unused]]
    WalletLinkFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    WalletLinkFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_WALLETLINKFRAGMENT_HPP
