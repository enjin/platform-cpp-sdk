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

#ifndef ENJINPLATFORMSDK_CREATEWALLET_HPP
#define ENJINPLATFORMSDK_CREATEWALLET_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for storing a new unverified wallet record using an external ID.
class ENJINPLATFORMSDK_EXPORT CreateWallet : public GraphQlRequest<CreateWallet>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CreateWallet();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CreateWallet(const CreateWallet& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CreateWallet(CreateWallet&& other) noexcept;

    /// \brief Class destructor.
    ~CreateWallet() override;

    /// \brief Sets the external ID set for the wallet.
    /// \param externalId The external ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateWallet& SetExternalId(SerializableStringPtr externalId);

    CreateWallet& operator=(const CreateWallet& rhs);

    CreateWallet& operator=(CreateWallet&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_CREATEWALLET_HPP
