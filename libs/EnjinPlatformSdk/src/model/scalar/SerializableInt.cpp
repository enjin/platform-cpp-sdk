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

#include "EnjinPlatformSdk/SerializableInt.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableInt::SerializableInt()
    : value(0)
{
}

[[maybe_unused]]
SerializableInt::SerializableInt(int32_t value)
    : value(value)
{
}

[[maybe_unused]]
SerializableInt::SerializableInt(const SerializableInt& other) = default;

[[maybe_unused]]
SerializableInt::SerializableInt(SerializableInt&& other) noexcept = default;

SerializableInt::~SerializableInt() = default;

SerializableInt& SerializableInt::operator=(const SerializableInt& rhs) = default;

SerializableInt& SerializableInt::operator=(SerializableInt&& rhs) noexcept = default;

bool SerializableInt::operator==(const SerializableInt& rhs) const
{
    return value == rhs.value;
}

bool SerializableInt::operator!=(const SerializableInt& rhs) const
{
    return value != rhs.value;
}

bool SerializableInt::operator<(const SerializableInt& rhs) const
{
    return value < rhs.value;
}

bool SerializableInt::operator>(const SerializableInt& rhs) const
{
    return value > rhs.value;
}

bool SerializableInt::operator<=(const SerializableInt& rhs) const
{
    return value <= rhs.value;
}

bool SerializableInt::operator>=(const SerializableInt& rhs) const
{
    return value >= rhs.value;
}

// region ISerializable

JsonValue SerializableInt::ToJson() const
{
    return JsonValue::FromJson(ToString());
}

std::string SerializableInt::ToString() const
{
    return std::to_string(value);
}

// endregion ISerializable
