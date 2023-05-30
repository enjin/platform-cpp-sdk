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

#ifndef ENJINPLATFORMSDK_GETLINKINGCODE_HPP
#define ENJINPLATFORMSDK_GETLINKINGCODE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/WalletLinkFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for for creating a new linking code to associate an external ID to a wallet account.
class ENJINPLATFORMSDK_EXPORT GetLinkingCode : public GraphQlRequest<GetLinkingCode, WalletLinkFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetLinkingCode();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetLinkingCode(const GetLinkingCode& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetLinkingCode(GetLinkingCode&& other) noexcept;

    /// \brief Class destructor.
    ~GetLinkingCode() override;

    /// \brief Sets the external ID to link.
    /// \param externalId The external ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetLinkingCode& SetExternalId(SerializableStringPtr externalId);

    GetLinkingCode& operator=(const GetLinkingCode& rhs);

    GetLinkingCode& operator=(GetLinkingCode&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETLINKINGCODE_HPP
