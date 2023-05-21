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

#include "EnjinPlatformSdk/MarketPolicy.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
MarketPolicy::MarketPolicy() = default;

[[maybe_unused]]
MarketPolicy::MarketPolicy(const MarketPolicy& other) = default;

[[maybe_unused]]
MarketPolicy::MarketPolicy(MarketPolicy&& other) noexcept = default;

MarketPolicy::~MarketPolicy() = default;

[[maybe_unused]]
MarketPolicy& MarketPolicy::SetRoyalty(RoyaltyInputPtr royalty)
{
    return GraphQlParameter<MarketPolicy>::SetParameter("royalty", std::move(royalty));
}

MarketPolicy& MarketPolicy::operator=(const MarketPolicy& rhs) = default;

MarketPolicy& MarketPolicy::operator=(MarketPolicy&& rhs) noexcept = default;
