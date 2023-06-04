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

#include "EnjinPlatformSdk/MintToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<MintToken, TransactionFragment>;

[[maybe_unused]]
MintToken::MintToken()
    : RequestType("MintToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
MintToken::MintToken(const MintToken& other) = default;

[[maybe_unused]]
MintToken::MintToken(MintToken&& other) noexcept = default;

MintToken::~MintToken() = default;

[[maybe_unused]]
MintToken& MintToken::SetRecipient(SerializableStringPtr recipient)
{
    return RequestType::SetVariable("recipient", CoreTypes::String, std::move(recipient));
}

[[maybe_unused]]
MintToken& MintToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
MintToken& MintToken::SetParams(MintTokenParamsPtr params)
{
    return RequestType::SetVariable("params", CoreTypes::MintTokenParams, std::move(params));
}

MintToken& MintToken::operator=(const MintToken& rhs) = default;

MintToken& MintToken::operator=(MintToken&& rhs) noexcept = default;
