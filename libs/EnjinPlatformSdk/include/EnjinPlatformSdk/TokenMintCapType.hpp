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

#ifndef ENJINPLATFORMSDK_TOKENMINTCAPTYPE_HPP
#define ENJINPLATFORMSDK_TOKENMINTCAPTYPE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Enum values representing the quantity setting for a token.
enum class TokenMintCapType
{
    /// \brief Indicates that a token can only be minted once, and cannot be re-minted once burned.
    SingleMint,

    /// \brief Indicates that a limit may be set on the total number of circulating tokens. This type allows for burned
    /// tokens to be re-minted even if the supply amount is 1.
    Supply,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::string ToString(TokenMintCapType value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<TokenMintCapType>& outField);
}

#endif //ENJINPLATFORMSDK_TOKENMINTCAPTYPE_HPP
