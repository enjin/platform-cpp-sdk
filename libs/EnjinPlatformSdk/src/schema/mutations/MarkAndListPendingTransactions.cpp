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

#include "EnjinPlatformSdk/MarkAndListPendingTransactions.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<MarkAndListPendingTransactions, TransactionFragment>;

[[maybe_unused]]
MarkAndListPendingTransactions::MarkAndListPendingTransactions()
    : RequestType("MarkAndListPendingTransactions", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
MarkAndListPendingTransactions::MarkAndListPendingTransactions(const MarkAndListPendingTransactions& other) = default;

[[maybe_unused]]
MarkAndListPendingTransactions::MarkAndListPendingTransactions(
    MarkAndListPendingTransactions&& other) noexcept = default;

MarkAndListPendingTransactions::~MarkAndListPendingTransactions() = default;

[[maybe_unused]]
MarkAndListPendingTransactions& MarkAndListPendingTransactions::SetAccounts(SerializableStringArrayPtr accounts)
{
    return RequestType::SetVariable("accounts", CoreTypes::StringArray, std::move(accounts));
}

[[maybe_unused]]
MarkAndListPendingTransactions&
MarkAndListPendingTransactions::SetMarkAsProcessing(SerializableBoolPtr markAsProcessing)
{
    return RequestType::SetVariable("markAsProcessing", CoreTypes::Boolean, std::move(markAsProcessing));
}

MarkAndListPendingTransactions&
MarkAndListPendingTransactions::operator=(const MarkAndListPendingTransactions& rhs) = default;

MarkAndListPendingTransactions&
MarkAndListPendingTransactions::operator=(MarkAndListPendingTransactions&& rhs) noexcept = default;
