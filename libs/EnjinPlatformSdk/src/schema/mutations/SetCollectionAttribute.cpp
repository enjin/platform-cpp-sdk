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

#include "EnjinPlatformSdk/SetCollectionAttribute.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<SetCollectionAttribute, TransactionFragment>;

[[maybe_unused]]
SetCollectionAttribute::SetCollectionAttribute()
    : RequestType("SetCollectionAttribute", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
SetCollectionAttribute::SetCollectionAttribute(const SetCollectionAttribute& other) = default;

[[maybe_unused]]
SetCollectionAttribute::SetCollectionAttribute(SetCollectionAttribute&& other) noexcept = default;

SetCollectionAttribute::~SetCollectionAttribute() = default;

[[maybe_unused]]
SetCollectionAttribute& SetCollectionAttribute::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
SetCollectionAttribute& SetCollectionAttribute::SetKey(SerializableStringPtr key)
{
    return RequestType::SetVariable("key", CoreTypes::String, std::move(key));
}

[[maybe_unused]]
SetCollectionAttribute& SetCollectionAttribute::SetValue(SerializableStringPtr value)
{
    return RequestType::SetVariable("value", CoreTypes::String, std::move(value));
}

SetCollectionAttribute& SetCollectionAttribute::operator=(const SetCollectionAttribute& rhs) = default;

SetCollectionAttribute& SetCollectionAttribute::operator=(SetCollectionAttribute&& rhs) noexcept = default;
