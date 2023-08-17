#ifndef ENJINPLATFORMSDK_TOKENACCOUNTFRAGMENT_HPP
#define ENJINPLATFORMSDK_TOKENACCOUNTFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CollectionFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/TokenAccountApprovalFragment.hpp"
#include "EnjinPlatformSdk/TokenAccountNamedReserveFragment.hpp"
#include "EnjinPlatformSdk/TokenFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class CollectionFragment;

using CollectionFragmentPtr = std::shared_ptr<CollectionFragment>;

class TokenAccountApprovalFragment;

using TokenAccountApprovalFragmentPtr = std::shared_ptr<TokenAccountApprovalFragment>;

class TokenAccountNamedReserveFragment;

using TokenAccountNamedReserveFragmentPtr = std::shared_ptr<TokenAccountNamedReserveFragment>;

class TokenFragment;

using TokenFragmentPtr = std::shared_ptr<TokenFragment>;

class WalletFragment;

using WalletFragmentPtr = std::shared_ptr<WalletFragment>;

// endregion Forward declarations

class TokenAccountFragment;

/// \brief Definition for a pointer containing a token account fragment.
using TokenAccountFragmentPtr [[maybe_unused]] = std::shared_ptr<TokenAccountFragment>;

/// \brief Definition for a token account connection fragment.
using TokenAccountConnectionFragment [[maybe_unused]] = ConnectionFragment<TokenAccountFragment>;

/// \brief Definition for a pointer containing a token account connection fragment.
using TokenAccountConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<TokenAccountConnectionFragment>;

class ENJINPLATFORMSDK_EXPORT TokenAccountFragment : public IGraphQlFragment<TokenAccountFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenAccountFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenAccountFragment(const TokenAccountFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenAccountFragment(TokenAccountFragment&& other) noexcept;

    /// \brief Class destructor.
    ~TokenAccountFragment() override;

    /// \brief Sets whether the token account is to be returned with its balance property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountFragment& WithBalance(bool isIncluded = true);

    /// \brief Sets whether the token account is to be returned with its reservedBalance property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountFragment& WithReservedBalance(bool isIncluded = true);

    /// \brief Sets whether the token account is to be returned with its isFrozen property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountFragment& WithIsFrozen(bool isIncluded = true);

    /// \brief Sets the collection fragment to be used for getting the collection property of the token account.
    /// \param fragment The <see cref="Collection"/> fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountFragment& WithCollection(CollectionFragmentPtr fragment);

    /// \brief Sets the wallet fragment to be used for getting the wallet property of the token account.
    /// \param fragment The wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountFragment& WithWallet(WalletFragmentPtr fragment);

    /// \brief Sets the token fragment to be used for getting the token property of token account.
    /// \param fragment The token fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountFragment& WithToken(TokenFragmentPtr fragment);

    /// \brief Sets the token account approval fragment to be used for getting the approvals property of the token
    /// account.
    /// \param fragment The token account approval fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountFragment& WithApprovals(TokenAccountApprovalFragmentPtr fragment);

    /// \brief Sets the token account named reserve fragment to be used for getting the named reserves property of the
    /// token account.
    /// \param fragment The token account named reserve fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountFragment& WithNamedReserves(TokenAccountNamedReserveFragmentPtr fragment);

    TokenAccountFragment& operator=(const TokenAccountFragment& rhs);

    TokenAccountFragment& operator=(TokenAccountFragment&& rhs) noexcept;

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
    TokenAccountFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    TokenAccountFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    TokenAccountFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    TokenAccountFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_TOKENACCOUNTFRAGMENT_HPP
