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

#ifndef ENJINPLATFORMSDK_SETWALLETACCOUNT_HPP
#define ENJINPLATFORMSDK_SETWALLETACCOUNT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for setting the account on a wallet model.
class ENJINPLATFORMSDK_EXPORT SetWalletAccount : public GraphQlRequest<SetWalletAccount>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    SetWalletAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SetWalletAccount(const SetWalletAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SetWalletAccount(SetWalletAccount&& other) noexcept;

    /// \brief Class destructor.
    ~SetWalletAccount() override;

    /// \brief Sets the internal ID of the wallet.
    /// \param id The internal ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetWalletAccount& SetId(SerializableIntPtr id);

    /// \brief Sets the external ID for this wallet.
    /// \param externalId The external ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetWalletAccount& SetExternalId(SerializableIntPtr externalId);

    /// \brief Sets the wallet account on the blockchain.
    /// \param account The wallet account.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetWalletAccount& SetAccount(SerializableIntPtr account);

    SetWalletAccount& operator=(const SetWalletAccount& rhs);

    SetWalletAccount& operator=(SetWalletAccount&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_SETWALLETACCOUNT_HPP
