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

#include "EnjinPlatformSdk/MutateToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<MutateToken, TransactionFragment>;

[[maybe_unused]]
MutateToken::MutateToken()
    : RequestType("MutateToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
MutateToken::MutateToken(const MutateToken& other) = default;

[[maybe_unused]]
MutateToken::MutateToken(MutateToken&& other) noexcept = default;

MutateToken::~MutateToken() = default;

[[maybe_unused]]
MutateToken& MutateToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
MutateToken& MutateToken::SetMutation(TokenMutationInputPtr mutation)
{
    return RequestType::SetVariable("mutation", CoreTypes::TokenMutationInput, std::move(mutation));
}

MutateToken& MutateToken::operator=(const MutateToken& rhs) = default;

MutateToken& MutateToken::operator=(MutateToken&& rhs) noexcept = default;
