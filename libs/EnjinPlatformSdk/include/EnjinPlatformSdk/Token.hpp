//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef ENJINPLATFORMSDK_TOKEN_HPP
#define ENJINPLATFORMSDK_TOKEN_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Attribute.hpp"
#include "EnjinPlatformSdk/Collection.hpp"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Royalty.hpp"
#include "EnjinPlatformSdk/TokenAccount.hpp"
#include "EnjinPlatformSdk/TokenMintCapType.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
// region Forward declarations

class Attribute;

class Collection;

class Royalty;

class TokenAccount;

// endregion Forward declarations

/// \brief Models a token on the blockchain.
class ENJINPLATFORMSDK_EXPORT Token : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Token();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Token(const Token& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Token(Token&& other) noexcept;

    /// \brief Class destructor.
    ~Token() override;

    /// \brief Returns the token chain ID which is a 128-bit unsigned integer.
    /// \return The token chain ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetTokenId() const;

    /// \brief Returns the current supply of this token.
    /// \return The supply.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetSupply() const;

    /// \brief Returns the quantity setting for this token.
    /// \return The setting.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<TokenMintCapType>& GetCap() const;

    /// \brief Returns the maximum quantity available for this token.
    /// \return The maximum quantity.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetCapSupply() const;

    /// \brief Returns whether this token is frozen, disallowing transfers.
    /// \return Whether this token is frozen.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const;

    /// \brief Returns whether this token is a currency (fungible).
    /// \return Whether this token is a currency.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetIsCurrency() const;

    /// \brief Returns the token royalty if set.
    /// \return The royalty.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Royalty>& GetRoyalty() const;

    /// \brief Returns the minimum required balance of this token for all accounts.
    /// \return The minimum required balance.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetMinimumBalance() const;

    /// \brief Returns the price of each token in EFI.
    /// \return The price of each token.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetUnitPrice() const;

    /// \brief Returns the amount of currency reserved from the issuer for minting.
    /// \return The amount reserved for minting.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetMintDeposit() const;

    /// \brief Returns the number of attributes set on this token.
    /// \return The number of attributes.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetAttributeCount() const;

    /// \brief Returns the collection this token belongs to.
    /// \return The collection.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const;

    /// \brief Returns the attributes for this token.
    /// \return The attributes.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<Attribute>>& GetAttributes() const;

    /// \brief Returns the token accounts that hold this token.
    /// \return The token accounts.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<TokenAccount>>& GetAccounts() const;

    /// \brief Returns the metadata for this token.
    /// \return The metadata.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<JsonValue>& GetMetadata() const;

    /// \brief Returns whether this token is considered non-fungible (i.e. there is only one available and therefore
    /// truly unique).
    /// \return Whether this token is non-fungible.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetNonFungible() const;

    Token& operator=(const Token& rhs);

    Token& operator=(Token&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_TOKEN_HPP
