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

#include "EnjinPlatformSdk/CreateToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<CreateToken, TransactionFragment>;

[[maybe_unused]]
CreateToken::CreateToken()
    : RequestType("CreateToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
CreateToken::CreateToken(const CreateToken& other) = default;

[[maybe_unused]]
CreateToken::CreateToken(CreateToken&& other) noexcept = default;

CreateToken::~CreateToken() = default;

[[maybe_unused]]
CreateToken& CreateToken::SetRecipient(SerializableStringPtr recipient)
{
    return RequestType::SetVariable("recipient", CoreTypes::String, std::move(recipient));
}

[[maybe_unused]]
CreateToken& CreateToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
CreateToken& CreateToken::SetParams(CreateTokenParamsPtr params)
{
    return RequestType::SetVariable("params", CoreTypes::CreateTokenParams, std::move(params));
}

CreateToken& CreateToken::operator=(const CreateToken& rhs) = default;

CreateToken& CreateToken::operator=(CreateToken&& rhs) noexcept = default;
