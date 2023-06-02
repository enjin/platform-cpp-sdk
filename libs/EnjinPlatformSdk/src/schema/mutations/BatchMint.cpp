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

#include "EnjinPlatformSdk/BatchMint.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<BatchMint, TransactionFragment>;

BatchMint::BatchMint()
    : RequestType("BatchMint", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
BatchMint::BatchMint(const BatchMint& other) = default;

[[maybe_unused]]
BatchMint::BatchMint(BatchMint&& other) noexcept = default;

BatchMint::~BatchMint() = default;

[[maybe_unused]]
BatchMint& BatchMint::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
BatchMint& BatchMint::SetRecipients(std::shared_ptr<SerializableArray<MintRecipient>> recipients)
{
    return RequestType::SetVariable("recipients", CoreTypes::MintRecipientArray, std::move(recipients));
}

BatchMint& BatchMint::operator=(const BatchMint& rhs) = default;

BatchMint& BatchMint::operator=(BatchMint&& rhs) noexcept = default;
