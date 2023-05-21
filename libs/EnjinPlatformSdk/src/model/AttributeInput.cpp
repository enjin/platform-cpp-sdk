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

#include "EnjinPlatformSdk/AttributeInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
AttributeInput::AttributeInput() = default;

[[maybe_unused]]
AttributeInput::AttributeInput(const AttributeInput& other) = default;

[[maybe_unused]]
AttributeInput::AttributeInput(AttributeInput&& other) noexcept = default;

AttributeInput::~AttributeInput() = default;

[[maybe_unused]]
AttributeInput& AttributeInput::SetKey(SerializableStringPtr key)
{
    return GraphQlParameter<AttributeInput>::SetParameter("key", std::move(key));
}

[[maybe_unused]]
AttributeInput& AttributeInput::SetValue(SerializableStringPtr value)
{
    return GraphQlParameter<AttributeInput>::SetParameter("value", std::move(value));
}

AttributeInput& AttributeInput::operator=(const AttributeInput& rhs) = default;

AttributeInput& AttributeInput::operator=(AttributeInput&& rhs) noexcept = default;
