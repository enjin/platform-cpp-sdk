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

#ifndef ENJINPLATFORMSDK_WALLETLINK_HPP
#define ENJINPLATFORMSDK_WALLETLINK_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models a linking code used to associate an external ID to a wallet account.
class ENJINPLATFORMSDK_EXPORT WalletLink : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    WalletLink();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    WalletLink(const WalletLink& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    WalletLink(WalletLink&& other) noexcept;

    /// \brief Class destructor.
    ~WalletLink() override;

    /// \brief Returns the code a user can input into the wallet app to link their account on the platform.
    /// \return The code to link.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetCode() const;

    WalletLink& operator=(const WalletLink& rhs);

    WalletLink& operator=(WalletLink&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_WALLETLINK_HPP
