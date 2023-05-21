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

#include "EnjinPlatformSdk/FreezeType.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char Collect[] = "COLLECTION";
constexpr char CollectionAccount[] = "COLLECTION_ACCOUNT";
constexpr char Token[] = "TOKEN";
constexpr char TokenAccount[] = "TOKEN_ACCOUNT";

std::string enjin::platform::sdk::ToString(const FreezeType value)
{
    switch (value)
    {
        case FreezeType::Collect:
            return Collect;

        case FreezeType::CollectionAccount:
            return CollectionAccount;

        case FreezeType::Token:
            return Token;

        case FreezeType::TokenAccount:
            return TokenAccount;

        default:
            throw std::out_of_range("Value out of range for FreezeType enum");
    }
}

bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<FreezeType>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == Collect)
    {
        outField = FreezeType::Collect;
    }
    else if (value == CollectionAccount)
    {
        outField = FreezeType::CollectionAccount;
    }
    else if (value == Token)
    {
        outField = FreezeType::Token;
    }
    else if (value == TokenAccount)
    {
        outField = FreezeType::TokenAccount;
    }

    return outField.has_value();
}
