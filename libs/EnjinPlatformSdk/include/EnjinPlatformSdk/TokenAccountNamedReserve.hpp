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

#ifndef ENJINPLATFORMSDK_TOKENACCOUNTNAMEDRESERVE_HPP
#define ENJINPLATFORMSDK_TOKENACCOUNTNAMEDRESERVE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/PalletIdentifier.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models a pallet that has reserved some tokens and the amount.
class ENJINPLATFORMSDK_EXPORT TokenAccountNamedReserve : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenAccountNamedReserve();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenAccountNamedReserve(const TokenAccountNamedReserve& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenAccountNamedReserve(TokenAccountNamedReserve&& other) noexcept;

    /// \brief Class destructor.
    ~TokenAccountNamedReserve() override;

    /// \brief Returns the pallet that has created this reserve.
    /// \return The pallet.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<PalletIdentifier>& GetPallet() const;

    /// \brief Returns the amount in the wallet that has been reserved.
    /// \return The amount.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetAmount() const;

    TokenAccountNamedReserve& operator=(const TokenAccountNamedReserve& rhs);

    TokenAccountNamedReserve& operator=(TokenAccountNamedReserve&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_TOKENACCOUNTNAMEDRESERVE_HPP