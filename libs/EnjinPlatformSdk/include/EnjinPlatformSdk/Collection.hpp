#ifndef ENJINPLATFORMSDK_COLLECTION_HPP
#define ENJINPLATFORMSDK_COLLECTION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Attribute.hpp"
#include "EnjinPlatformSdk/CollectionAccount.hpp"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Royalty.hpp"
#include "EnjinPlatformSdk/Token.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
// region Forward declarations

class Attribute;

class CollectionAccount;

class Royalty;

class Token;

class Wallet;

// endregion Forward declarations

/// \brief Models a collection on the platform.
class ENJINPLATFORMSDK_EXPORT Collection : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Collection();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Collection(const Collection& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Collection(Collection&& other) noexcept;

    /// \brief Class destructor.
    ~Collection() override;

    /// \brief Returns the ID assigned to this collection.
    /// \return The ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetCollectionId() const;

    /// \brief Returns the maximum number of tokens that can be issued for this collection.
    /// \return The maximum number of tokens.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetMaxTokenCount() const;

    /// \brief Returns the maximum amount of each token in this collection that may be minted.
    /// \return The maximum amount of each token.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetMaxTokenSupply() const;

    /// \brief Returns whether the tokens in this collection will be minted as single mint types.
    /// \return Whether the tokens will be minted as single mint types.
    /// \remarks This would indicate the tokens in this collection are non-fungible.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetForceSingleMint() const;

    /// \brief Returns whether this collection is frozen.
    /// \return Whether this collection is frozen.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetFrozen() const;

    /// \brief Returns the royalty policy for this collection.
    /// \return The royalty.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Royalty>& GetRoyalty() const;

    /// \brief Returns the network this collection belongs to.
    /// \return The network.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetNetwork() const;

    /// \brief Returns the wallet which can mint tokens from this collection.
    /// \return The wallet.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetOwner() const;

    /// \brief Returns the attributes for this collection.
    /// \return The attributes.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<Attribute>>& GetAttributes() const;

    /// \brief Returns the accounts for this collection.
    /// \return The accounts.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<CollectionAccount>>& GetAccounts() const;

    /// \brief Returns the tokens minted from this collection.
    /// \return The tokens minted from this collection.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<Token>>& GetTokens() const;

    Collection& operator=(const Collection& rhs);

    Collection& operator=(Collection&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_COLLECTION_HPP
