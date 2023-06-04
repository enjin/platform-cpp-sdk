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

#include "EnjinPlatformSdk/SimpleTransferToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<SimpleTransferToken, TransactionFragment>;

[[maybe_unused]]
SimpleTransferToken::SimpleTransferToken()
    : RequestType("SimpleTransferToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
SimpleTransferToken::SimpleTransferToken(const SimpleTransferToken& other) = default;

[[maybe_unused]]
SimpleTransferToken::SimpleTransferToken(SimpleTransferToken&& other) noexcept = default;

SimpleTransferToken::~SimpleTransferToken() = default;

[[maybe_unused]]
SimpleTransferToken& SimpleTransferToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
SimpleTransferToken& SimpleTransferToken::SetRecipient(SerializableStringPtr recipient)
{
    return RequestType::SetVariable("recipient", CoreTypes::String, std::move(recipient));
}

[[maybe_unused]]
SimpleTransferToken& SimpleTransferToken::SetParams(SimpleTransferParamsPtr params)
{
    return RequestType::SetVariable("params", CoreTypes::SimpleTransferParams, std::move(params));
}

[[maybe_unused]]
SimpleTransferToken& SimpleTransferToken::SetSigningAccount(SerializableStringPtr signingAccount)
{
    return RequestType::SetVariable("signingAccount", CoreTypes::String, std::move(signingAccount));
}

SimpleTransferToken& SimpleTransferToken::operator=(const SimpleTransferToken& rhs) = default;

SimpleTransferToken& SimpleTransferToken::operator=(SimpleTransferToken&& rhs) noexcept = default;
