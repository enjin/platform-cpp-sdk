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

#ifndef ENJINPLATFORMSDK_ACCOUNTREQUEST_HPP
#define ENJINPLATFORMSDK_ACCOUNTREQUEST_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models a request to verify an account.
class ENJINPLATFORMSDK_EXPORT AccountRequest : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AccountRequest();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AccountRequest(const AccountRequest& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AccountRequest(AccountRequest&& other) noexcept;

    /// \brief Class destructor.
    ~AccountRequest() override;

    /// \brief Returns the QR code a user can scan in the wallet app to verify their account.
    /// \return The QR code.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetQrCode() const;

    /// \brief Returns the verification ID generated to get the account from.
    /// \return The verification ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetVerificationId() const;

    AccountRequest& operator=(const AccountRequest& rhs);

    AccountRequest& operator=(AccountRequest&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_ACCOUNTREQUEST_HPP
