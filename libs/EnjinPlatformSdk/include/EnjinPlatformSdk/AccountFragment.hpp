#ifndef ENJINPLATFORMSDK_ACCOUNTFRAGMENT_HPP
#define ENJINPLATFORMSDK_ACCOUNTFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class AccountFragment;

/// \brief Definition for a pointer containing an AccountFragment.
using AccountFragmentPtr [[maybe_unused]] = std::shared_ptr<AccountFragment>;

/// \brief Definition for a ConnectionFragment containing an AccountFragment.
using AccountConnectFragment [[maybe_unused]] = ConnectionFragment<AccountFragment>;

/// \brief Definition for a pointer containing an AccountConnectFragment.
using AccountConnectFragmentPtr [[maybe_unused]] = std::shared_ptr<AccountConnectFragment>;

/// \brief A fragment for requesting properties of an account returned by the platform.
class ENJINPLATFORMSDK_EXPORT AccountFragment : public IGraphQlFragment<AccountFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AccountFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AccountFragment(const AccountFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AccountFragment(AccountFragment&& other) noexcept;

    /// \brief Class destructor.
    ~AccountFragment() override;

    /// \brief Sets whether the account is to be returned with its publicKey property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AccountFragment& WithPublicKey(bool isIncluded = true);

    /// \brief Sets whether the account is to be returned with its address property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AccountFragment& WithAddress(bool isIncluded = true);

    AccountFragment& operator=(const AccountFragment& rhs);

    AccountFragment& operator=(AccountFragment&& rhs) noexcept;

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
    AccountFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    AccountFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    AccountFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    AccountFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_ACCOUNTFRAGMENT_HPP
