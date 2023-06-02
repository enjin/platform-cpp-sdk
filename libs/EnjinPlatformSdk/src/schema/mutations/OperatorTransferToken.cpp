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

#include "EnjinPlatformSdk/OperatorTransferToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<OperatorTransferToken, TransactionFragment>;

[[maybe_unused]]
OperatorTransferToken::OperatorTransferToken()
    : RequestType("OperatorTransferToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
OperatorTransferToken::OperatorTransferToken(const OperatorTransferToken& other) = default;

[[maybe_unused]]
OperatorTransferToken::OperatorTransferToken(OperatorTransferToken&& other) noexcept = default;

OperatorTransferToken::~OperatorTransferToken() = default;

[[maybe_unused]]
OperatorTransferToken& OperatorTransferToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
OperatorTransferToken& OperatorTransferToken::SetRecipient(SerializableStringPtr recipient)
{
    return RequestType::SetVariable("recipient", CoreTypes::String, std::move(recipient));
}

[[maybe_unused]]
OperatorTransferToken& OperatorTransferToken::SetParams(OperatorTransferParamsPtr params)
{
    return RequestType::SetVariable("params", CoreTypes::OperatorTransferParams, std::move(params));
}

[[maybe_unused]]
OperatorTransferToken& OperatorTransferToken::SetSigningAccount(SerializableStringPtr signingAccount)
{
    return RequestType::SetVariable("signingAccount", CoreTypes::String, std::move(signingAccount));
}

OperatorTransferToken& OperatorTransferToken::operator=(const OperatorTransferToken& rhs) = default;

OperatorTransferToken& OperatorTransferToken::operator=(OperatorTransferToken&& rhs) noexcept = default;
