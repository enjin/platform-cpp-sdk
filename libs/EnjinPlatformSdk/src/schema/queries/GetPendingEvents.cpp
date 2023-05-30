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

#include "EnjinPlatformSdk/GetPendingEvents.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetPendingEvents, PendingEventsFragment>;

[[maybe_unused]]
GetPendingEvents::GetPendingEvents()
    : RequestType("GetPendingEvents", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetPendingEvents::GetPendingEvents(const GetPendingEvents& other) = default;

[[maybe_unused]]
GetPendingEvents::GetPendingEvents(GetPendingEvents&& other) noexcept = default;

GetPendingEvents::~GetPendingEvents() = default;

[[maybe_unused]]
GetPendingEvents& GetPendingEvents::SetAcknowledgeEvents(SerializableBoolPtr acknowledgeEvents)
{
    return RequestType::SetVariable("acknowledgeEvents", CoreTypes::Boolean, std::move(acknowledgeEvents));
}

GetPendingEvents& GetPendingEvents::operator=(const GetPendingEvents& rhs) = default;

GetPendingEvents& GetPendingEvents::operator=(GetPendingEvents&& rhs) noexcept = default;
