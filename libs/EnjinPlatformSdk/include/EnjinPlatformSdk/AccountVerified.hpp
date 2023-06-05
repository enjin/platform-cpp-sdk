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

#ifndef ENJINPLATFORMSDK_ACCOUNTVERIFIED_HPP
#define ENJINPLATFORMSDK_ACCOUNTVERIFIED_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Account.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models the verification status of an account.
class ENJINPLATFORMSDK_EXPORT AccountVerified : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AccountVerified();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AccountVerified(const AccountVerified& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AccountVerified(AccountVerified&& other) noexcept;

    /// \brief Class destructor.
    ~AccountVerified() override;

    /// \brief Returns whether the user account has already been verified.
    /// \return Whether the user account has already been verified.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetVerified() const;

    /// \brief Returns the account that was verified.
    /// \return The account that was verified.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Account>& GetAccount() const;

    AccountVerified& operator=(const AccountVerified& rhs);

    AccountVerified& operator=(AccountVerified&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_ACCOUNTVERIFIED_HPP
