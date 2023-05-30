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

#ifndef ENJINPLATFORMSDK_GETWALLET_HPP
#define ENJINPLATFORMSDK_GETWALLET_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying a wallet using either its database ID, external ID, verification ID or account
/// address.
class ENJINPLATFORMSDK_EXPORT GetWallet : public GraphQlRequest<GetWallet, WalletFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetWallet();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetWallet(const GetWallet& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetWallet(GetWallet&& other) noexcept;

    /// \brief Class destructor.
    ~GetWallet() override;

    /// \brief Sets the internal ID for the wallet.
    /// \param id The internal ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetWallet& SetId(SerializableIntPtr id);

    /// \brief Sets the external ID for the wallet.
    /// \param externalId The external ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetWallet& SetExternalId(SerializableStringPtr externalId);

    /// \brief Sets the verification ID for the wallet.
    /// \param verificationId The verification ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetWallet& SetVerificationId(SerializableStringPtr verificationId);

    /// \brief Sets the wallet account on the blockchain.
    /// \param account The wallet account.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetWallet& SetAccount(SerializableStringPtr account);

    GetWallet& operator=(const GetWallet& rhs);

    GetWallet& operator=(GetWallet&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETWALLET_HPP
