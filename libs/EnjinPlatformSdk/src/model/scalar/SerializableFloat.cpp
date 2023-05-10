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

#include "EnjinPlatformSdk/SerializableFloat.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableFloat::SerializableFloat()
    : value(0.0)
{
}

[[maybe_unused]]
SerializableFloat::SerializableFloat(const float value)
    : value(value)
{
}

[[maybe_unused]]
SerializableFloat::SerializableFloat(const SerializableFloat& other) = default;

[[maybe_unused]]
SerializableFloat::SerializableFloat(SerializableFloat&& other) noexcept = default;

SerializableFloat::~SerializableFloat() = default;

SerializableFloat& SerializableFloat::operator=(const SerializableFloat& rhs) = default;

SerializableFloat& SerializableFloat::operator=(SerializableFloat&& rhs) noexcept = default;

bool SerializableFloat::operator==(const SerializableFloat& rhs) const
{
    return value == rhs.value;
}

bool SerializableFloat::operator!=(const SerializableFloat& rhs) const
{
    return !(rhs == *this);
}

bool SerializableFloat::operator<(const SerializableFloat& rhs) const
{
    return value < rhs.value;
}

bool SerializableFloat::operator>(const SerializableFloat& rhs) const
{
    return rhs < *this;
}

bool SerializableFloat::operator<=(const SerializableFloat& rhs) const
{
    return !(rhs < *this);
}

bool SerializableFloat::operator>=(const SerializableFloat& rhs) const
{
    return !(*this < rhs);
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableFloat::ToJson() const
{
    return JsonValue::FromFloat(value);
}

[[maybe_unused]]
std::string SerializableFloat::ToString() const
{
    return ToJson().ToString();
}

// endregion ISerializable
