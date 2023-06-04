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

#include "EnjinPlatformSdk/UnapproveCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<UnapproveCollection, TransactionFragment>;

[[maybe_unused]]
UnapproveCollection::UnapproveCollection()
    : RequestType("UnapproveCollection", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
UnapproveCollection::UnapproveCollection(const UnapproveCollection& other) = default;

[[maybe_unused]]
UnapproveCollection::UnapproveCollection(UnapproveCollection&& other) noexcept = default;

UnapproveCollection::~UnapproveCollection() = default;

[[maybe_unused]]
UnapproveCollection& UnapproveCollection::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
UnapproveCollection& UnapproveCollection::SetOperator(SerializableStringPtr op)
{
    return RequestType::SetVariable("operator", CoreTypes::String, std::move(op));
}

UnapproveCollection& UnapproveCollection::operator=(const UnapproveCollection& rhs) = default;

UnapproveCollection& UnapproveCollection::operator=(UnapproveCollection&& rhs) noexcept = default;
