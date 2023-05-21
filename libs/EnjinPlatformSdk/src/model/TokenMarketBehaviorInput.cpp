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

#include "EnjinPlatformSdk/TokenMarketBehaviorInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
TokenMarketBehaviorInput::TokenMarketBehaviorInput() = default;

[[maybe_unused]]
TokenMarketBehaviorInput::TokenMarketBehaviorInput(const TokenMarketBehaviorInput& other) = default;

[[maybe_unused]]
TokenMarketBehaviorInput::TokenMarketBehaviorInput(TokenMarketBehaviorInput&& other) noexcept = default;

TokenMarketBehaviorInput::~TokenMarketBehaviorInput() = default;

[[maybe_unused]]
TokenMarketBehaviorInput& TokenMarketBehaviorInput::SetHasRoyalty(RoyaltyInputPtr input)
{
    return GraphQlParameter<TokenMarketBehaviorInput>::SetParameter("input", std::move(input));
}

[[maybe_unused]]
TokenMarketBehaviorInput& TokenMarketBehaviorInput::SetIsCurrency(SerializableBoolPtr isCurrency)
{
    return GraphQlParameter<TokenMarketBehaviorInput>::SetParameter("isCurrency", std::move(isCurrency));
}

TokenMarketBehaviorInput& TokenMarketBehaviorInput::operator=(const TokenMarketBehaviorInput& rhs) = default;

TokenMarketBehaviorInput& TokenMarketBehaviorInput::operator=(TokenMarketBehaviorInput&& rhs) noexcept = default;
