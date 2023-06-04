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

#include "EnjinPlatformSdk/SetWalletAccount.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<SetWalletAccount>;

[[maybe_unused]]
SetWalletAccount::SetWalletAccount()
    : RequestType("SetWalletAccount", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
SetWalletAccount::SetWalletAccount(const SetWalletAccount& other) = default;

[[maybe_unused]]
SetWalletAccount::SetWalletAccount(SetWalletAccount&& other) noexcept = default;

SetWalletAccount::~SetWalletAccount() = default;

[[maybe_unused]]
SetWalletAccount& SetWalletAccount::SetId(SerializableIntPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::Int, std::move(id));
}

[[maybe_unused]]
SetWalletAccount& SetWalletAccount::SetExternalId(SerializableIntPtr externalId)
{
    return RequestType::SetVariable("externalId", CoreTypes::String, std::move(externalId));
}

[[maybe_unused]]
SetWalletAccount& SetWalletAccount::SetAccount(SerializableIntPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

SetWalletAccount& SetWalletAccount::operator=(const SetWalletAccount& rhs) = default;

SetWalletAccount& SetWalletAccount::operator=(SetWalletAccount&& rhs) noexcept = default;
