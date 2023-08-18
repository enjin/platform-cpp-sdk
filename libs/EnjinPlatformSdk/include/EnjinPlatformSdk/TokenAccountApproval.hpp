#ifndef ENJINPLATFORMSDK_TOKENACCOUNTAPPROVAL_HPP
#define ENJINPLATFORMSDK_TOKENACCOUNTAPPROVAL_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/TokenAccount.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
// region Forward declarations

class TokenAccount;

class Wallet;

// endregion Forward declarations

/// \brief Models a wallet that has been approved to use a token account.
class ENJINPLATFORMSDK_EXPORT TokenAccountApproval : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenAccountApproval();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenAccountApproval(const TokenAccountApproval& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenAccountApproval(TokenAccountApproval&& other) noexcept;

    /// \brief Class destructor.
    ~TokenAccountApproval() override;

    /// \brief Returns the amount the wallet has been approved.
    /// \return The amount.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetAmount() const;

    /// \brief Returns the expiration block the wallet will lose the approval.
    /// \return The expiration block.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetExpiration() const;

    /// \brief Returns the token account this approval belongs to.
    /// \return The token account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<TokenAccount>& GetAccount() const;

    /// \brief Returns the wallet that has been approved.
    /// \return The wallet.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const;

    TokenAccountApproval& operator=(const TokenAccountApproval& rhs);

    TokenAccountApproval& operator=(TokenAccountApproval&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_TOKENACCOUNTAPPROVAL_HPP
