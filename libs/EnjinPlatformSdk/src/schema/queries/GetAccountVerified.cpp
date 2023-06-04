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

#include "EnjinPlatformSdk/GetAccountVerified.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetAccountVerified, AccountVerifiedFragment>;

[[maybe_unused]]
GetAccountVerified::GetAccountVerified()
    : RequestType("GetAccountVerified", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetAccountVerified::GetAccountVerified(const GetAccountVerified& other) = default;

[[maybe_unused]]
GetAccountVerified::GetAccountVerified(GetAccountVerified&& other) noexcept = default;

GetAccountVerified::~GetAccountVerified() = default;

[[maybe_unused]]
GetAccountVerified& GetAccountVerified::SetVerificationId(SerializableStringPtr verificationId)
{
    return RequestType::SetVariable("verificationId", CoreTypes::String, std::move(verificationId));
}

[[maybe_unused]]
GetAccountVerified& GetAccountVerified::SetAccount(SerializableStringPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

GetAccountVerified& GetAccountVerified::operator=(const GetAccountVerified& rhs) = default;

GetAccountVerified& GetAccountVerified::operator=(GetAccountVerified&& rhs) noexcept = default;
