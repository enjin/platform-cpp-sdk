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

#include "EnjinPlatformSdk/GetTransactions.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetTransactions, TransactionConnectionFragment>;

[[maybe_unused]]
GetTransactions::GetTransactions()
    : RequestType("GetTransactions", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetTransactions::GetTransactions(const GetTransactions& other) = default;

[[maybe_unused]]
GetTransactions::GetTransactions(GetTransactions&& other) noexcept = default;

GetTransactions::~GetTransactions() = default;

[[maybe_unused]]
GetTransactions& GetTransactions::SetIdempotencyKeys(SerializableStringArrayPtr idempotencyKeys)
{
    return RequestType::SetVariable("idempotencyKeys", CoreTypes::StringArray, std::move(idempotencyKeys));
}

[[maybe_unused]]
GetTransactions& GetTransactions::SetTransactionIds(SerializableStringArrayPtr transactionIds)
{
    return RequestType::SetVariable("transactionIds", CoreTypes::StringArray, std::move(transactionIds));
}

[[maybe_unused]]
GetTransactions& GetTransactions::SetTransactionHashes(SerializableStringArrayPtr transactionHashes)
{
    return RequestType::SetVariable("transactionHashes", CoreTypes::StringArray, std::move(transactionHashes));
}

[[maybe_unused]]
GetTransactions& GetTransactions::SetMethods(const std::vector<TransactionMethod>& methods)
{
    SerializableStringArrayPtr arrayPtr = std::make_shared<SerializableArray<SerializableString>>();

    for (const TransactionMethod method : methods)
    {
        std::string s = enjin::platform::sdk::ToString(method);

        arrayPtr->PushBack(SerializableString(std::move(s)));
    }

    return RequestType::SetVariable("methods", CoreTypes::TransactionMethodArray, std::move(arrayPtr));
}

[[maybe_unused]]
GetTransactions& GetTransactions::SetStates(const std::vector<TransactionState>& states)
{
    SerializableStringArrayPtr arrayPtr = std::make_shared<SerializableArray<SerializableString>>();

    for (const TransactionState state : states)
    {
        std::string s = enjin::platform::sdk::ToString(state);

        arrayPtr->PushBack(SerializableString(std::move(s)));
    }

    return RequestType::SetVariable("states", CoreTypes::TransactionStateArray, std::move(arrayPtr));
}

[[maybe_unused]]
GetTransactions& GetTransactions::SetResults(const std::vector<TransactionResult>& results)
{
    SerializableStringArrayPtr arrayPtr = std::make_shared<SerializableArray<SerializableString>>();

    for (const TransactionResult result : results)
    {
        std::string s = enjin::platform::sdk::ToString(result);

        arrayPtr->PushBack(SerializableString(std::move(s)));
    }

    return RequestType::SetVariable("results", CoreTypes::TransactionResultArray, std::move(arrayPtr));
}

[[maybe_unused]]
GetTransactions& GetTransactions::SetAccounts(SerializableStringArrayPtr accounts)
{
    return RequestType::SetVariable("accounts", CoreTypes::StringArray, std::move(accounts));
}

GetTransactions& GetTransactions::operator=(const GetTransactions& rhs) = default;

GetTransactions& GetTransactions::operator=(GetTransactions&& rhs) noexcept = default;
