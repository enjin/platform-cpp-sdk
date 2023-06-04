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

#ifndef ENJINPLATFORMSDK_GETACCOUNTVERIFIED_HPP
#define ENJINPLATFORMSDK_GETACCOUNTVERIFIED_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AccountVerifiedFragment.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying the verification status of an account.
class ENJINPLATFORMSDK_EXPORT GetAccountVerified : public GraphQlRequest<GetAccountVerified, AccountVerifiedFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetAccountVerified();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetAccountVerified(const GetAccountVerified& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetAccountVerified(GetAccountVerified&& other) noexcept;

    /// \brief Class destructor.
    ~GetAccountVerified() override;

    /// \brief Sets the verification ID to be checked.
    /// \param verificationId The verification ID.
    /// \return This requesting for chaining.
    [[maybe_unused]]
    [[nodiscard]]
    GetAccountVerified& SetVerificationId(SerializableStringPtr verificationId);

    /// \brief Sets the wallet account to be checked.
    /// \param account The wallet account.
    /// \return This requesting for chaining.
    [[maybe_unused]]
    [[nodiscard]]
    GetAccountVerified& SetAccount(SerializableStringPtr account);

    GetAccountVerified& operator=(const GetAccountVerified& rhs);

    GetAccountVerified& operator=(GetAccountVerified&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETACCOUNTVERIFIED_HPP
