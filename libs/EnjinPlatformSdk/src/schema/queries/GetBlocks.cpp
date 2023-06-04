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

#include "EnjinPlatformSdk/GetBlocks.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetBlocks, BlockConnectionFragment>;

[[maybe_unused]]
GetBlocks::GetBlocks()
    : RequestType("GetBlocks", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetBlocks::GetBlocks(const GetBlocks& other) = default;

[[maybe_unused]]
GetBlocks::GetBlocks(GetBlocks&& other) noexcept = default;

GetBlocks::~GetBlocks() = default;

[[maybe_unused]]
GetBlocks& GetBlocks::SetNumber(SerializableStringArrayPtr numbers)
{
    return RequestType::SetVariable("numbers", CoreTypes::StringArray, std::move(numbers));
}

[[maybe_unused]]
GetBlocks& GetBlocks::SetHashes(SerializableStringArrayPtr hashes)
{
    return RequestType::SetVariable("hashes", CoreTypes::StringArray, std::move(hashes));
}

GetBlocks& GetBlocks::operator=(const GetBlocks& rhs) = default;

GetBlocks& GetBlocks::operator=(GetBlocks&& rhs) noexcept = default;
