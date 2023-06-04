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

#ifndef ENJINPLATFORMSDK_REQUESTACCOUNT_HPP
#define ENJINPLATFORMSDK_REQUESTACCOUNT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AccountRequestFragment.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for generating a QR code that a user can scan to request an account for their wallet.
class ENJINPLATFORMSDK_EXPORT RequestAccount : public GraphQlRequest<RequestAccount, AccountRequestFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RequestAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RequestAccount(const RequestAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RequestAccount(RequestAccount&& other) noexcept;

    /// \brief Class destructor.
    ~RequestAccount() override;

    /// \brief Sets the callback URL that the wallet should send the verification to.
    /// \param callback The callback URL.
    /// \return This request for chaining.
    [[maybe_unused]]
    RequestAccount& SetCallback(SerializableStringPtr callback);

    RequestAccount& operator=(const RequestAccount& rhs);

    RequestAccount& operator=(RequestAccount&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_REQUESTACCOUNT_HPP
