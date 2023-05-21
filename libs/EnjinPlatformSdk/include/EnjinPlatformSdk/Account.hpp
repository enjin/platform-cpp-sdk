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

#ifndef ENJINPLATFORMSDK_ACCOUNT_HPP
#define ENJINPLATFORMSDK_ACCOUNT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models a substrate account.
class ENJINPLATFORMSDK_EXPORT Account : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Account();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Account(const Account& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Account(Account&& other) noexcept;

    /// \brief Class destructor.
    ~Account() override;

    /// \brief Returns the account public key.
    /// \return The account public key.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetPublicKey() const;

    /// \brief Returns the account address.
    /// \return The account address.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetAddress() const;

    Account& operator=(const Account& rhs);

    Account& operator=(Account&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_ACCOUNT_HPP
