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

#include "EnjinPlatformSdk/SetTokenAttribute.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<SetTokenAttribute, TransactionFragment>;

SetTokenAttribute::SetTokenAttribute()
: RequestType("SetTokenAttribute", GraphQlRequestType::Mutation)
{
}

SetTokenAttribute::SetTokenAttribute(const SetTokenAttribute& other) = default;

SetTokenAttribute::SetTokenAttribute(SetTokenAttribute&& other) noexcept = default;

SetTokenAttribute::~SetTokenAttribute() = default;

SetTokenAttribute& SetTokenAttribute::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

SetTokenAttribute& SetTokenAttribute::SetKey(SerializableStringPtr key)
{
    return RequestType::SetVariable("key", CoreTypes::String, std::move(key));
}

SetTokenAttribute& SetTokenAttribute::SetValue(SerializableStringPtr value)
{
    return RequestType::SetVariable("value", CoreTypes::String, std::move(value));
}

SetTokenAttribute& SetTokenAttribute::operator=(const SetTokenAttribute& rhs) = default;

SetTokenAttribute& SetTokenAttribute::operator=(SetTokenAttribute&& rhs) noexcept = default;
