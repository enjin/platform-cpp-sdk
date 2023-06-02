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

#include "EnjinPlatformSdk/Burn.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<Burn, TransactionFragment>;

[[maybe_unused]]
Burn::Burn()
    : RequestType("Burn", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
Burn::Burn(const Burn& other) = default;

[[maybe_unused]]
Burn::Burn(Burn&& other) noexcept = default;

Burn::~Burn() = default;

[[maybe_unused]]
Burn& Burn::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
Burn& Burn::SetParams(BurnParamsInputPtr params)
{
    return RequestType::SetVariable("params", CoreTypes::BurnParamsInput, std::move(params));
}

Burn& Burn::operator=(const Burn& rhs) = default;

Burn& Burn::operator=(Burn&& rhs) noexcept = default;
