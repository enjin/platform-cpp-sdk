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

#include "EnjinPlatformSdk/TokenMintCapType.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char SingleMint[] = "SINGLE_MINT";
constexpr char Supply[] = "SUPPLY";

[[maybe_unused]]
std::string enjin::platform::sdk::ToString(const TokenMintCapType value)
{
    switch (value)
    {
        case TokenMintCapType::SingleMint:
            return SingleMint;

        case TokenMintCapType::Supply:
            return Supply;

        default:
            throw std::out_of_range("Value out of range for TokenMintCapType enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<TokenMintCapType>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == SingleMint)
    {
        outField = TokenMintCapType::SingleMint;
    }
    else if (value == Supply)
    {
        outField = TokenMintCapType::Supply;
    }

    return outField.has_value();
}
