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

#include "EnjinPlatformSdk/RemoveTokenAttribute.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<RemoveTokenAttribute, TransactionFragment>;

[[maybe_unused]]
RemoveTokenAttribute::RemoveTokenAttribute()
    : RequestType("RemoveTokenAttribute", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
RemoveTokenAttribute::RemoveTokenAttribute(const RemoveTokenAttribute& other) = default;

[[maybe_unused]]
RemoveTokenAttribute::RemoveTokenAttribute(RemoveTokenAttribute&& other) noexcept = default;

RemoveTokenAttribute::~RemoveTokenAttribute() = default;

[[maybe_unused]]
RemoveTokenAttribute& RemoveTokenAttribute::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
RemoveTokenAttribute& RemoveTokenAttribute::SetKey(SerializableStringPtr key)
{
    return RequestType::SetVariable("key", CoreTypes::String, std::move(key));
}

RemoveTokenAttribute& RemoveTokenAttribute::operator=(const RemoveTokenAttribute& rhs) = default;

RemoveTokenAttribute& RemoveTokenAttribute::operator=(RemoveTokenAttribute&& rhs) noexcept = default;
