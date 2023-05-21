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

#include "EnjinPlatformSdk/MintTokenParams.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
MintTokenParams::MintTokenParams() = default;

[[maybe_unused]]
MintTokenParams::MintTokenParams(const MintTokenParams& other) = default;

[[maybe_unused]]
MintTokenParams::MintTokenParams(MintTokenParams&& other) noexcept = default;

MintTokenParams::~MintTokenParams() = default;

[[maybe_unused]]
MintTokenParams& MintTokenParams::SetAmount(SerializableStringPtr amount)
{
    return GraphQlParameter<MintTokenParams>::SetParameter("amount", std::move(amount));
}

[[maybe_unused]]
MintTokenParams& MintTokenParams::SetUnitPrice(SerializableStringPtr unitPrice)
{
    return GraphQlParameter<MintTokenParams>::SetParameter("unitPrice", std::move(unitPrice));
}

MintTokenParams& MintTokenParams::operator=(const MintTokenParams& rhs) = default;

MintTokenParams& MintTokenParams::operator=(MintTokenParams&& rhs) noexcept = default;
