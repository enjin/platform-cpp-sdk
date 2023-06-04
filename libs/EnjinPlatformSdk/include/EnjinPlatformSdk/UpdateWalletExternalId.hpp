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

#ifndef ENJINPLATFORMSDK_UPDATEWALLETEXTERNALID_HPP
#define ENJINPLATFORMSDK_UPDATEWALLETEXTERNALID_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for changing the external ID on a wallet model.
class ENJINPLATFORMSDK_EXPORT UpdateWalletExternalId : public GraphQlRequest<UpdateWalletExternalId>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    UpdateWalletExternalId();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    UpdateWalletExternalId(const UpdateWalletExternalId& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    UpdateWalletExternalId(UpdateWalletExternalId&& other) noexcept;

    /// \brief Class destructor.
    ~UpdateWalletExternalId() override;

    /// \brief Sets the internal ID of the wallet.
    /// \param id The internal ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateWalletExternalId& SetId(SerializableIntPtr id);

    /// \brief Sets the external ID for the wallet.
    /// \param externalId The external ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateWalletExternalId& SetExternalId(SerializableStringPtr externalId);

    /// \brief Sets the new external ID to set for the wallet.
    /// \param newExternalId The new external ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateWalletExternalId& SetNewExternalId(SerializableIntPtr newExternalId);

    /// \brief Sets the wallet account on the blockchain.
    /// \param account The wallet account.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateWalletExternalId& SetAccount(SerializableIntPtr account);

    UpdateWalletExternalId& operator=(const UpdateWalletExternalId& rhs);

    UpdateWalletExternalId& operator=(UpdateWalletExternalId&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_UPDATEWALLETEXTERNALID_HPP
