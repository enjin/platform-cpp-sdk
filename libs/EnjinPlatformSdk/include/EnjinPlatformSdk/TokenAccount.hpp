#ifndef ENJINPLATFORMSDK_TOKENACCOUNT_HPP
#define ENJINPLATFORMSDK_TOKENACCOUNT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Collection.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Token.hpp"
#include "EnjinPlatformSdk/TokenAccountApproval.hpp"
#include "EnjinPlatformSdk/TokenAccountNamedReserve.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
// region Forward declarations

class Collection;

class Token;

class TokenAccountApproval;

class TokenAccountNamedReserve;

class Wallet;

// endregion Forward declarations

/// \brief Models a token account, which stores the balances of tokens.
class ENJINPLATFORMSDK_EXPORT TokenAccount : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenAccount(const TokenAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenAccount(TokenAccount&& other) noexcept;

    /// \brief Class destructor.
    ~TokenAccount() override;

    /// \brief Returns the balance of the token this account holds.
    /// \return The balance.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetBalance() const;

    /// \brief Returns the reserved value for this account.
    /// \return The reserved value.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetReservedBalance() const;

    /// \brief Returns whether this account is frozen, disallowing transfers.
    /// \return Whether this account is frozen.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const;

    /// \brief Returns the collection this account belongs to.
    /// \return The collection.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const;

    /// \brief Returns the wallet which owns this account.
    /// \return The wallet.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const;

    /// \brief Returns the token for this account.
    /// \return The token.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Token>& GetToken() const;

    /// \brief Returns the list of approvals for this account.
    /// \return The list of approvals.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<TokenAccountApproval>>& GetApprovals() const;

    /// \brief Returns the list of the named reserves for this account.
    /// \return The list of the named reserves.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<TokenAccountNamedReserve>>& GetNamedReserves() const;

    TokenAccount& operator=(const TokenAccount& rhs);

    TokenAccount& operator=(TokenAccount&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_TOKENACCOUNT_HPP
