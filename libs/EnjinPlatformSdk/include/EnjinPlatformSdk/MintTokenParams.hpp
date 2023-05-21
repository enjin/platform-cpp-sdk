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

#ifndef ENJINPLATFORMSDK_MINTTOKENPARAMS_HPP
#define ENJINPLATFORMSDK_MINTTOKENPARAMS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class MintTokenParams;

/// \brief Definition for a pointer containing a mint token parameters.
using MintTokenParamsPtr [[maybe_unused]] = std::shared_ptr<MintTokenParams>;

/// \brief Models a parameter for parameters to mint a token.
class ENJINPLATFORMSDK_EXPORT MintTokenParams : public GraphQlParameter<MintTokenParams>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MintTokenParams();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MintTokenParams(const MintTokenParams& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MintTokenParams(MintTokenParams&& other) noexcept;

    /// \brief Class destructor.
    ~MintTokenParams() override;

    /// \brief The initial supply of tokens to mint to the specified recipient. Must not exceed the token cap if set.
    /// \param amount The amount to mint.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MintTokenParams& SetAmount(SerializableStringPtr amount);

    /// \brief Sets the price of each token.
    /// \param unitPrice The price per token.
    /// \return This parameter for chaining.
    /// \remarks Leave as null if you want to keep the same unitPrice. You can also put a value if you want to change
    /// the unit price. Please note you can only increase it and a deposit to the difference of every token previously
    /// minted will also be needed.
    [[maybe_unused]]
    MintTokenParams& SetUnitPrice(SerializableStringPtr unitPrice);

    MintTokenParams& operator=(const MintTokenParams& rhs);

    MintTokenParams& operator=(MintTokenParams&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MINTTOKENPARAMS_HPP
