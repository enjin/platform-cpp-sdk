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

#ifndef ENJINPLATFORMSDK_TOKENMINTCAP_HPP
#define ENJINPLATFORMSDK_TOKENMINTCAP_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TokenMintCapType.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class TokenMintCap;

/// \brief Definition for a pointer containing a token mint cap.
using TokenMintCapPtr [[maybe_unused]] = std::shared_ptr<TokenMintCap>;

/// \brief Models a parameter for setting the attribute of a collection or token.
class ENJINPLATFORMSDK_EXPORT TokenMintCap : public GraphQlParameter<TokenMintCap>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenMintCap();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenMintCap(const TokenMintCap& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenMintCap(TokenMintCap&& other) noexcept;

    /// \brief Class destructor.
    ~TokenMintCap() override;

    /// \brief The type of mint cap for this token.
    /// \param type The cap type.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TokenMintCap& SetType(TokenMintCapType type);

    /// \brief The cap amount when using the SUPPLY type of TokenMintCapType.
    /// \param amount The cap amount.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TokenMintCap& SetAmount(SerializableStringPtr amount);

    TokenMintCap& operator=(const TokenMintCap& rhs);

    TokenMintCap& operator=(TokenMintCap&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_TOKENMINTCAP_HPP
