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

#ifndef ENJINPLATFORMSDK_COLLECTIONACCOUNTAPPROVAL_HPP
#define ENJINPLATFORMSDK_COLLECTIONACCOUNTAPPROVAL_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CollectionAccount.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>

namespace enjin::platform::sdk
{
// region Forward declarations

class CollectionAccount;

class Wallet;

// endregion Forward declarations

/// \brief Models the wallet that has been approved to use the collection account.
class ENJINPLATFORMSDK_EXPORT CollectionAccountApproval : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CollectionAccountApproval();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CollectionAccountApproval(const CollectionAccountApproval& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CollectionAccountApproval(CollectionAccountApproval&& other) noexcept;

    /// \brief Class destructor.
    ~CollectionAccountApproval() override;

    /// \brief Returns the expiration block the wallet will lose the approval.
    /// \return The expiration block.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetExpiration() const;

    /// \brief Returns the collection account this approval belongs to.
    /// \return The collection account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<CollectionAccount>& GetAccount() const;

    /// \brief Returns the wallet that has been approved.
    /// \return The wallet.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const;

    CollectionAccountApproval& operator=(const CollectionAccountApproval& rhs);

    CollectionAccountApproval& operator=(CollectionAccountApproval&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_COLLECTIONACCOUNTAPPROVAL_HPP