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

#include "EnjinPlatformSdk/DestroyCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<DestroyCollection, TransactionFragment>;

[[maybe_unused]]
DestroyCollection::DestroyCollection()
    : RequestType("DestroyCollection", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
DestroyCollection::DestroyCollection(const DestroyCollection& other) = default;

[[maybe_unused]]
DestroyCollection::DestroyCollection(DestroyCollection&& other) noexcept = default;

DestroyCollection::~DestroyCollection() = default;

[[maybe_unused]]
DestroyCollection& DestroyCollection::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

DestroyCollection& DestroyCollection::operator=(const DestroyCollection& rhs) = default;

DestroyCollection& DestroyCollection::operator=(DestroyCollection&& rhs) noexcept = default;
