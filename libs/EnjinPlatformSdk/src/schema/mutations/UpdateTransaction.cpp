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

#include "EnjinPlatformSdk/UpdateTransaction.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <memory>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<UpdateTransaction>;

[[maybe_unused]]
UpdateTransaction::UpdateTransaction()
    : RequestType("UpdateTransaction", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
UpdateTransaction::UpdateTransaction(const UpdateTransaction& other) = default;

[[maybe_unused]]
UpdateTransaction::UpdateTransaction(UpdateTransaction&& other) noexcept = default;

UpdateTransaction::~UpdateTransaction() = default;

[[maybe_unused]]
UpdateTransaction& UpdateTransaction::SetId(SerializableIntPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::Int, std::move(id));
}

[[maybe_unused]]
UpdateTransaction& UpdateTransaction::SetState(const TransactionState state)
{
    std::string s = enjin::platform::sdk::ToString(state);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return RequestType::SetVariable("state", CoreTypes::TransactionState, std::move(sPtr));
}

[[maybe_unused]]
UpdateTransaction& UpdateTransaction::SetTransactionId(SerializableStringPtr transactionId)
{
    return RequestType::SetVariable("transactionId", CoreTypes::String, std::move(transactionId));
}

[[maybe_unused]]
UpdateTransaction& UpdateTransaction::SetTransactionHash(SerializableStringPtr transactionHash)
{
    return RequestType::SetVariable("transactionHash", CoreTypes::String, std::move(transactionHash));
}

UpdateTransaction& UpdateTransaction::operator=(const UpdateTransaction& rhs) = default;

UpdateTransaction& UpdateTransaction::operator=(UpdateTransaction&& rhs) noexcept = default;
