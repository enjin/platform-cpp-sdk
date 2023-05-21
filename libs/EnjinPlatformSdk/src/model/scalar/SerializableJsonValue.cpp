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

#include "EnjinPlatformSdk/SerializableJsonValue.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableJsonValue::SerializableJsonValue() = default;

[[maybe_unused]]
SerializableJsonValue::SerializableJsonValue(JsonValue value)
    : value(std::move(value))
{
}

[[maybe_unused]]
SerializableJsonValue::SerializableJsonValue(const SerializableJsonValue& other) = default;

[[maybe_unused]]
SerializableJsonValue::SerializableJsonValue(SerializableJsonValue&& other) noexcept = default;

SerializableJsonValue::~SerializableJsonValue() = default;

SerializableJsonValue& SerializableJsonValue::operator=(const SerializableJsonValue& rhs) = default;

SerializableJsonValue& SerializableJsonValue::operator=(SerializableJsonValue&& rhs) noexcept = default;

bool SerializableJsonValue::operator==(const SerializableJsonValue& rhs) const
{
    return value == rhs.value;
}

bool SerializableJsonValue::operator!=(const SerializableJsonValue& rhs) const
{
    return value != rhs.value;
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableJsonValue::ToJson() const
{
    return value;
}

[[maybe_unused]]
std::string SerializableJsonValue::ToString() const
{
    return value.ToString();
}

// endregion ISerializable
