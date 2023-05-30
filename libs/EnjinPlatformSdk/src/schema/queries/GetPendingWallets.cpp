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

#include "EnjinPlatformSdk/GetPendingWallets.hpp"

#include "EnjinPlatformSdk/GraphQlRequestType.hpp"

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetPendingWallets, WalletConnectionFragment>;

[[maybe_unused]]
GetPendingWallets::GetPendingWallets()
    : RequestType("GetPendingWallets", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetPendingWallets::GetPendingWallets(const GetPendingWallets& other) = default;

[[maybe_unused]]
GetPendingWallets::GetPendingWallets(GetPendingWallets&& other) noexcept = default;

GetPendingWallets::~GetPendingWallets() = default;

GetPendingWallets& GetPendingWallets::operator=(const GetPendingWallets& rhs) = default;

GetPendingWallets& GetPendingWallets::operator=(GetPendingWallets&& rhs) noexcept = default;
