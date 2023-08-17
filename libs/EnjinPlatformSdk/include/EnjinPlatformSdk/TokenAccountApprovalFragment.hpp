#ifndef ENJINPLATFORMSDK_TOKENACCOUNTAPPROVALFRAGMENT_HPP
#define ENJINPLATFORMSDK_TOKENACCOUNTAPPROVALFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/TokenAccountFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class TokenAccountFragment;

using TokenAccountFragmentPtr = std::shared_ptr<TokenAccountFragment>;

class WalletFragment;

using WalletFragmentPtr = std::shared_ptr<WalletFragment>;

// endregion Forward declarations

class TokenAccountApprovalFragment;

/// \brief Definition for a pointer containing a token account approval fragment.
using TokenAccountApprovalFragmentPtr [[maybe_unused]] = std::shared_ptr<TokenAccountApprovalFragment>;

/// \brief Definition for a token account approval connection fragment.
using TokenAccountApprovalConnectionFragment [[maybe_unused]] = ConnectionFragment<TokenAccountApprovalFragment>;

/// \brief Definition for a pointer containing a token account approval connection fragment.
using TokenAccountApprovalConnectionFragmentPtr = std::shared_ptr<TokenAccountApprovalConnectionFragment>;

/// \brief A fragment for requesting properties of a token account approval returned by the platform.
class ENJINPLATFORMSDK_EXPORT TokenAccountApprovalFragment : public IGraphQlFragment<TokenAccountApprovalFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenAccountApprovalFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenAccountApprovalFragment(const TokenAccountApprovalFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenAccountApprovalFragment(TokenAccountApprovalFragment&& other) noexcept;

    /// \brief Class destructor.
    ~TokenAccountApprovalFragment() override;

    /// \brief Sets whether the token account approval is to be returned with its amount property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountApprovalFragment& WithAmount(bool isIncluded = true);

    /// \brief Sets whether the token account approval is to be returned with its expiration property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountApprovalFragment& WithExpiration(bool isIncluded = true);

    /// \brief Sets the token account fragment to be used for getting the account property of the token account
    /// approval.
    /// \param fragment The token account fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountApprovalFragment& WithAccount(TokenAccountFragmentPtr fragment);

    /// \brief Sets the wallet fragment to be used for getting the wallet property of the token account approval.
    /// \param fragment The wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountApprovalFragment& WithWallet(WalletFragmentPtr fragment);

    TokenAccountApprovalFragment& operator=(const TokenAccountApprovalFragment& rhs);

    TokenAccountApprovalFragment& operator=(TokenAccountApprovalFragment&& rhs) noexcept;

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
    TokenAccountApprovalFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    TokenAccountApprovalFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    TokenAccountApprovalFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    TokenAccountApprovalFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_TOKENACCOUNTAPPROVALFRAGMENT_HPP
