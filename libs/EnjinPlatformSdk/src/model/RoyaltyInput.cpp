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

#include "EnjinPlatformSdk/RoyaltyInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
RoyaltyInput::RoyaltyInput() = default;

[[maybe_unused]]
RoyaltyInput::RoyaltyInput(const RoyaltyInput& other) = default;

[[maybe_unused]]
RoyaltyInput::RoyaltyInput(RoyaltyInput&& other) noexcept = default;

RoyaltyInput::~RoyaltyInput() = default;

[[maybe_unused]]
RoyaltyInput& RoyaltyInput::SetBeneficiary(SerializableStringPtr beneficiary)
{
    return GraphQlParameter<RoyaltyInput>::SetParameter("beneficiary", std::move(beneficiary));
}

[[maybe_unused]]
RoyaltyInput& RoyaltyInput::SetPercentage(SerializableDoublePtr percentage)
{
    return GraphQlParameter<RoyaltyInput>::SetParameter("percentage", std::move(percentage));
}

RoyaltyInput& RoyaltyInput::operator=(const RoyaltyInput& rhs) = default;

RoyaltyInput& RoyaltyInput::operator=(RoyaltyInput&& rhs) noexcept = default;
