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

#ifndef ENJINPLATFORMSDK_ROYALTY_HPP
#define ENJINPLATFORMSDK_ROYALTY_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>

namespace enjin::platform::sdk
{
// region Forward declarations

class Wallet;

// endregion Forward declarations

/// \brief Models a royalty policy.
class ENJINPLATFORMSDK_EXPORT Royalty : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Royalty();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Royalty(const Royalty& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Royalty(Royalty&& other) noexcept;

    /// \brief Class destructor.
    ~Royalty() override;

    /// \brief Returns the benefactor of this royalty.
    /// \return The beneficiary.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetBeneficiary() const;

    /// \brief Returns the percentage of this royalty.
    /// \return The percentage.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<double>& GetPercentage() const;

    Royalty& operator=(const Royalty& rhs);

    Royalty& operator=(Royalty&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_ROYALTY_HPP
