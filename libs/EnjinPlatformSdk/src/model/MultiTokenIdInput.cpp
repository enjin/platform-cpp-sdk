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

#include "EnjinPlatformSdk/MultiTokenIdInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
MultiTokenIdInput::MultiTokenIdInput() = default;

[[maybe_unused]]
MultiTokenIdInput::MultiTokenIdInput(const MultiTokenIdInput& other) = default;

[[maybe_unused]]
MultiTokenIdInput::MultiTokenIdInput(MultiTokenIdInput&& other) noexcept = default;

MultiTokenIdInput::~MultiTokenIdInput() = default;

[[maybe_unused]]
MultiTokenIdInput& MultiTokenIdInput::SetCollectionId(SerializableStringPtr collectionId)
{
    return GraphQlParameter<MultiTokenIdInput>::SetParameter("collectionId", std::move(collectionId));
}

MultiTokenIdInput& MultiTokenIdInput::operator=(const MultiTokenIdInput& rhs) = default;

MultiTokenIdInput& MultiTokenIdInput::operator=(MultiTokenIdInput&& rhs) noexcept = default;
