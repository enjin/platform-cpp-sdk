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

#include "EnjinPlatformSdk/BatchTransfer.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<BatchTransfer, TransactionFragment>;

[[maybe_unused]]
BatchTransfer::BatchTransfer()
    : RequestType("BatchTransfer", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
BatchTransfer::BatchTransfer(const BatchTransfer& other) = default;

[[maybe_unused]]
BatchTransfer::BatchTransfer(BatchTransfer&& other) noexcept = default;

BatchTransfer::~BatchTransfer() = default;

[[maybe_unused]]
BatchTransfer& BatchTransfer::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
BatchTransfer& BatchTransfer::SetRecipients(std::shared_ptr<SerializableArray<TransferRecipient>> recipients)
{
    return RequestType::SetVariable("recipients", CoreTypes::TransferRecipientArray, std::move(recipients));
}

[[maybe_unused]]
BatchTransfer& BatchTransfer::SetSigningAccount(SerializableStringPtr signingAccount)
{
    return RequestType::SetVariable("signingAccount", CoreTypes::String, std::move(signingAccount));
}

BatchTransfer& BatchTransfer::operator=(const BatchTransfer& rhs) = default;

BatchTransfer& BatchTransfer::operator=(BatchTransfer&& rhs) noexcept = default;
