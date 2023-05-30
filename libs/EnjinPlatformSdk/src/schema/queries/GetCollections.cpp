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

#include "EnjinPlatformSdk/GetCollections.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetCollections, CollectionConnectionFragment>;

[[maybe_unused]]
GetCollections::GetCollections()
    : RequestType("GetCollections", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetCollections::GetCollections(const GetCollections& other) = default;

[[maybe_unused]]
GetCollections::GetCollections(GetCollections&& other) noexcept = default;

GetCollections::~GetCollections() = default;

[[maybe_unused]]
GetCollections& GetCollections::SetCollectionIds(SerializableStringArrayPtr collectionIds)
{
    return RequestType::SetVariable("collectionIds", CoreTypes::BigIntArray, std::move(collectionIds));
}

GetCollections& GetCollections::operator=(const GetCollections& rhs) = default;

GetCollections& GetCollections::operator=(GetCollections&& rhs) noexcept = default;
