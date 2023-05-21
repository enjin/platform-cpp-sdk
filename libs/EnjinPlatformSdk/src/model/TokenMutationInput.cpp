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

#include "EnjinPlatformSdk/TokenMutationInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
TokenMutationInput::TokenMutationInput() = default;

[[maybe_unused]]
TokenMutationInput::TokenMutationInput(const TokenMutationInput& other) = default;

[[maybe_unused]]
TokenMutationInput::TokenMutationInput(TokenMutationInput&& other) noexcept = default;

TokenMutationInput::~TokenMutationInput() = default;

[[maybe_unused]]
TokenMutationInput& TokenMutationInput::SetBehavior(TokenMarketBehaviorInputPtr behavior)
{
    return GraphQlParameter<TokenMutationInput>::SetParameter("behavior", std::move(behavior));
}

[[maybe_unused]]
TokenMutationInput& TokenMutationInput::SetListingForbidden(SerializableBoolPtr listingForbidden)
{
    return GraphQlParameter<TokenMutationInput>::SetParameter("listingForbidden", std::move(listingForbidden));
}

TokenMutationInput& TokenMutationInput::operator=(const TokenMutationInput& rhs) = default;

TokenMutationInput& TokenMutationInput::operator=(TokenMutationInput&& rhs) noexcept = default;
