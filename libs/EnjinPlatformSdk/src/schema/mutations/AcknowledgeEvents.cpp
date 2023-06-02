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

#include "EnjinPlatformSdk/AcknowledgeEvents.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<AcknowledgeEvents>;

[[maybe_unused]]
AcknowledgeEvents::AcknowledgeEvents()
    : RequestType("AcknowledgeEvents", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
AcknowledgeEvents::AcknowledgeEvents(const AcknowledgeEvents& other) = default;

[[maybe_unused]]
AcknowledgeEvents::AcknowledgeEvents(AcknowledgeEvents&& other) noexcept = default;

AcknowledgeEvents::~AcknowledgeEvents() = default;

[[maybe_unused]]
AcknowledgeEvents& AcknowledgeEvents::SetUuids(SerializableStringArrayPtr uuids)
{
    return RequestType::SetVariable("uuids", CoreTypes::StringArray, std::move(uuids));
}

AcknowledgeEvents& AcknowledgeEvents::operator=(const AcknowledgeEvents& rhs) = default;

AcknowledgeEvents& AcknowledgeEvents::operator=(AcknowledgeEvents&& rhs) noexcept = default;
