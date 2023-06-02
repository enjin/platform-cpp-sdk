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

#include "EnjinPlatformSdk/MutateCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<MutateCollection, TransactionFragment>;

[[maybe_unused]]
MutateCollection::MutateCollection()
    : RequestType("MutateCollection", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
MutateCollection::MutateCollection(const MutateCollection& other) = default;

[[maybe_unused]]
MutateCollection::MutateCollection(MutateCollection&& other) noexcept = default;

MutateCollection::~MutateCollection() = default;

[[maybe_unused]]
MutateCollection& MutateCollection::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
MutateCollection& MutateCollection::SetMutation(CollectionMutationInputPtr mutation)
{
    return RequestType::SetVariable("mutation", CoreTypes::CollectionMutationInput, std::move(mutation));
}

MutateCollection& MutateCollection::operator=(const MutateCollection& rhs) = default;

MutateCollection& MutateCollection::operator=(MutateCollection&& rhs) noexcept = default;
