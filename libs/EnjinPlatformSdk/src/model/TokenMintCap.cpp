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

#include "EnjinPlatformSdk/TokenMintCap.hpp"

#include <utility>

using namespace enjin::platform::sdk;

constexpr char TypeKey[] = "type";

[[maybe_unused]]
TokenMintCap::TokenMintCap() = default;

[[maybe_unused]]
TokenMintCap::TokenMintCap(const TokenMintCap& other) = default;

[[maybe_unused]]
TokenMintCap::TokenMintCap(TokenMintCap&& other) noexcept = default;

TokenMintCap::~TokenMintCap() = default;

[[maybe_unused]]
TokenMintCap& TokenMintCap::SetType(const TokenMintCapType type)
{
    if (type == TokenMintCapType::None)
    {
        return GraphQlParameter<TokenMintCap>::RemoveParameter(TypeKey);
    }

    SerializableStringPtr s = std::make_shared<SerializableString>(enjin::platform::sdk::ToString(type));
    return GraphQlParameter<TokenMintCap>::SetParameter(TypeKey, std::move(s));
}

[[maybe_unused]]
TokenMintCap& TokenMintCap::SetAmount(SerializableStringPtr amount)
{
    return GraphQlParameter<TokenMintCap>::SetParameter("amount", std::move(amount));
}

TokenMintCap& TokenMintCap::operator=(const TokenMintCap& rhs) = default;

TokenMintCap& TokenMintCap::operator=(TokenMintCap&& rhs) noexcept = default;
