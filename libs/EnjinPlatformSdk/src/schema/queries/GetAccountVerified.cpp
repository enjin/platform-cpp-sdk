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

#include "EnjinPlatformSdk/GraphQlRequestType.hpp"

using namespace enjin::platform::sdk;

GetAccountVerified::GetAccountVerified()
    : GraphQlRequest<GetAccountVerified>("GetAccountVerified", GraphQlRequestType::Query)
{
}

GetAccountVerified::GetAccountVerified(const GetAccountVerified& other) = default;

GetAccountVerified::GetAccountVerified(GetAccountVerified&& other) noexcept = default;

GetAccountVerified::~GetAccountVerified() = default;

GetAccountVerified& GetAccountVerified::operator=(const GetAccountVerified& rhs) = default;

GetAccountVerified& GetAccountVerified::operator=(GetAccountVerified&& rhs) noexcept = default;
