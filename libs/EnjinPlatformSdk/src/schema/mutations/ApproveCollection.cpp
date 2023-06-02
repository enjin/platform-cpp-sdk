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

#include "EnjinPlatformSdk/ApproveCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<ApproveCollection, TransactionFragment>;

[[maybe_unused]]
ApproveCollection::ApproveCollection()
    : RequestType("ApproveCollection", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
ApproveCollection::ApproveCollection(const ApproveCollection& other) = default;

[[maybe_unused]]
ApproveCollection::ApproveCollection(ApproveCollection&& other) noexcept = default;

ApproveCollection::~ApproveCollection() = default;

[[maybe_unused]]
ApproveCollection& ApproveCollection::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::String, std::move(collectionId));
}

[[maybe_unused]]
ApproveCollection& ApproveCollection::SetOperator(SerializableStringPtr op)
{
    return RequestType::SetVariable("operator", CoreTypes::String, std::move(op));
}

[[maybe_unused]]
ApproveCollection& ApproveCollection::SetExpiration(SerializableIntPtr expiration)
{
    return RequestType::SetVariable("expiration", CoreTypes::Int, std::move(expiration));
}

ApproveCollection& ApproveCollection::operator=(const ApproveCollection& rhs) = default;

ApproveCollection& ApproveCollection::operator=(ApproveCollection&& rhs) noexcept = default;
