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

#ifndef ENJINPLATFORMSDK_BALANCES_HPP
#define ENJINPLATFORMSDK_BALANCES_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief  Models the EFI balances of a wallet.
class ENJINPLATFORMSDK_EXPORT Balances : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Balances();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Balances(const Balances& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Balances(Balances&& other) noexcept;

    /// \brief Class destructor.
    ~Balances() override;

    /// \brief Returns the amount of free EFI.
    /// \return The free amount.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetFree() const;

    /// \brief Returns the amount of reserved EFI.
    /// \return The reserved amount.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetReserved() const;

    /// \brief Returns the amount of EFI frozen for miscellaneous reasons.
    /// \return The amount frozen for miscellaneous reasons.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetMiscFrozen() const;

    /// \brief Returns the amount of EFI frozen for pending fees.
    /// \return The amount frozen for pending fees.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetFeeFrozen() const;

    Balances& operator=(const Balances& rhs);

    Balances& operator=(Balances&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_BALANCES_HPP