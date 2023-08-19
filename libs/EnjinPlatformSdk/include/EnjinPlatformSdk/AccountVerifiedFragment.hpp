#ifndef ENJINPLATFORMSDK_ACCOUNTVERIFIEDFRAGMENT_HPP
#define ENJINPLATFORMSDK_ACCOUNTVERIFIEDFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AccountFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class AccountFragment;

using AccountFragmentPtr = std::shared_ptr<AccountFragment>;

// endregion Forward declarations

class AccountVerifiedFragment;

/// \brief Definition for a pointer containing an AccountVerifiedFragment.
using AccountVerifiedFragmentPtr [[maybe_unused]] = std::shared_ptr<AccountVerifiedFragment>;

/// \brief Definition for a ConnectionFragment containing an AccountVerifiedFragment.
using AccountVerifiedConnectionFragment [[maybe_unused]] = ConnectionFragment<AccountVerifiedFragment>;

/// \brief Definition for a pointer containing an AccountVerifiedConnectionFragment.
using AccountVerifiedConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<AccountVerifiedConnectionFragment>;

/// \brief A fragment for requesting properties of an account verified returned by the platform.
class ENJINPLATFORMSDK_EXPORT AccountVerifiedFragment : public IGraphQlFragment<AccountVerifiedFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AccountVerifiedFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AccountVerifiedFragment(const AccountVerifiedFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AccountVerifiedFragment(AccountVerifiedFragment&& other) noexcept;

    /// \brief Class destructor.
    ~AccountVerifiedFragment() override;

    /// \brief Sets whether the account verified is to be returned with its verified property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AccountVerifiedFragment& WithVerified(bool isIncluded = true);

    /// \brief Sets the account fragment to be used for getting the account property of the account verified.
    /// \param fragment The account fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AccountVerifiedFragment& WithAccount(AccountFragmentPtr fragment);

    AccountVerifiedFragment& operator=(const AccountVerifiedFragment& rhs);

    AccountVerifiedFragment& operator=(AccountVerifiedFragment&& rhs) noexcept;

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
    AccountVerifiedFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    AccountVerifiedFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    AccountVerifiedFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    AccountVerifiedFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_ACCOUNTVERIFIEDFRAGMENT_HPP
