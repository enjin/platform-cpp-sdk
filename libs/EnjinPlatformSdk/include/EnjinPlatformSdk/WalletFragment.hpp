#ifndef ENJINPLATFORMSDK_WALLETFRAGMENT_HPP
#define ENJINPLATFORMSDK_WALLETFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AccountFragment.hpp"
#include "EnjinPlatformSdk/BalancesFragment.hpp"
#include "EnjinPlatformSdk/CollectionAccountApprovalFragment.hpp"
#include "EnjinPlatformSdk/CollectionAccountFragment.hpp"
#include "EnjinPlatformSdk/CollectionFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/TokenAccountApprovalFragment.hpp"
#include "EnjinPlatformSdk/TokenAccountFragment.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class AccountFragment;

using AccountFragmentPtr = std::shared_ptr<AccountFragment>;

class BalancesFragment;

using BalancesFragmentPtr = std::shared_ptr<BalancesFragment>;

class CollectionAccountApprovalFragment;

using CollectionAccountApprovalConnectionFragment = ConnectionFragment<CollectionAccountApprovalFragment>;
using CollectionAccountApprovalConnectionFragmentPtr = std::shared_ptr<CollectionAccountApprovalConnectionFragment>;

class CollectionAccountFragment;

using CollectionAccountConnectionFragment = ConnectionFragment<CollectionAccountFragment>;
using CollectionAccountConnectionFragmentPtr = std::shared_ptr<CollectionAccountConnectionFragment>;

class CollectionFragment;

using CollectionConnectionFragment = ConnectionFragment<CollectionFragment>;
using CollectionConnectionFragmentPtr = std::shared_ptr<ConnectionFragment<CollectionFragment>>;

class TokenAccountApprovalFragment;

using TokenAccountApprovalConnectionFragment = ConnectionFragment<TokenAccountApprovalFragment>;
using TokenAccountApprovalConnectionFragmentPtr = std::shared_ptr<TokenAccountApprovalConnectionFragment>;

class TokenAccountFragment;

using TokenAccountConnectionFragment = ConnectionFragment<TokenAccountFragment>;
using TokenAccountConnectionFragmentPtr = std::shared_ptr<TokenAccountConnectionFragment>;

class TransactionFragment;

using TransactionConnectionFragment = ConnectionFragment<TransactionFragment>;
using TransactionConnectionFragmentPtr = std::shared_ptr<TransactionConnectionFragment>;

// endregion Forward declarations

class WalletFragment;

/// \brief Definition for a pointer containing a wallet fragment.
using WalletFragmentPtr [[maybe_unused]] = std::shared_ptr<WalletFragment>;

/// \brief Definition for a wallet connection fragment.
using WalletConnectionFragment [[maybe_unused]] = ConnectionFragment<WalletFragment>;

/// \brief Definition for a pointer containing a wallet connection fragment.
using WalletConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<WalletConnectionFragment>;

/// \brief A fragment for requesting properties of a wallet returned by the platform.
class ENJINPLATFORMSDK_EXPORT WalletFragment : public IGraphQlFragment<WalletFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    WalletFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    WalletFragment(const WalletFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    WalletFragment(WalletFragment&& other) noexcept;

    /// \brief Class destructor.
    ~WalletFragment() override;

    /// \brief Sets whether the wallet is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithId(bool isIncluded = true);

    /// \brief Sets the account fragment to be used for getting the account property of the wallet.
    /// \param fragment The account fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithAccount(AccountFragmentPtr fragment);

    /// \brief Sets whether the wallet is to be returned with its externalId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithExternalId(bool isIncluded = true);

    /// \brief Sets whether the wallet is to be returned with its managed property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithManaged(bool isIncluded = true);

    /// \brief Sets whether the wallet is to be returned with its network property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithNetwork(bool isIncluded = true);

    /// \brief Sets whether the wallet is to be returned with its nonce property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithNonce(bool isIncluded = true);

    /// \brief Sets the balances fragment to be used for getting the account property of the wallet.
    /// \param fragment The balances fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithBalances(BalancesFragmentPtr fragment);

    /// \brief Sets the connection fragment, to be used for getting the collectionAccounts property of the wallet.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithCollectionAccounts(CollectionAccountConnectionFragmentPtr fragment);

    /// \brief Sets the connection fragment, to be used for getting the tokenAccounts property of the wallet.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithTokenAccounts(TokenAccountConnectionFragmentPtr fragment);

    /// \brief Sets the connection fragment, to be used for getting the collectionAccountApprovals property of the
    /// wallet.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithCollectionAccountApprovals(CollectionAccountApprovalConnectionFragmentPtr fragment);

    /// \brief Sets the connection fragment, to be used for getting the tokenAccountApprovals property of the wallet.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithTokenAccountApprovals(TokenAccountApprovalConnectionFragmentPtr fragment);

    /// \brief Sets the connection fragment, to be used for getting the transactions property of the wallet.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithTransactions(TransactionConnectionFragmentPtr fragment);

    /// \brief Sets the connection fragment, to be used for getting the ownedCollections property of the wallet.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    WalletFragment& WithOwnedCollections(CollectionConnectionFragmentPtr fragment);

    WalletFragment& operator=(const WalletFragment& rhs);

    WalletFragment& operator=(WalletFragment&& rhs) noexcept;

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
    WalletFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    WalletFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    WalletFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    WalletFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_WALLETFRAGMENT_HPP
