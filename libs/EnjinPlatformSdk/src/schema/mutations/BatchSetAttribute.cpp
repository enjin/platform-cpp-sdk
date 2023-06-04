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

#include "EnjinPlatformSdk/BatchSetAttribute.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<BatchSetAttribute, TransactionFragment>;

[[maybe_unused]]
BatchSetAttribute::BatchSetAttribute()
    : RequestType("BatchSetAttribute", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
BatchSetAttribute::BatchSetAttribute(const BatchSetAttribute& other) = default;

[[maybe_unused]]
BatchSetAttribute::BatchSetAttribute(BatchSetAttribute&& other) noexcept = default;

BatchSetAttribute::~BatchSetAttribute() = default;

[[maybe_unused]]
BatchSetAttribute& BatchSetAttribute::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
BatchSetAttribute& BatchSetAttribute::SetAttributes(std::shared_ptr<SerializableArray<AttributeInput>> attributes)
{
    return RequestType::SetVariable("attributes", CoreTypes::AttributeInputArray, std::move(attributes));
}

BatchSetAttribute& BatchSetAttribute::operator=(const BatchSetAttribute& rhs) = default;

BatchSetAttribute& BatchSetAttribute::operator=(BatchSetAttribute&& rhs) noexcept = default;
