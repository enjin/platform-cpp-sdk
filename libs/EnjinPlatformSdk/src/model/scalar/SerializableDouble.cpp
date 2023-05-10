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

#include "EnjinPlatformSdk/SerializableDouble.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableDouble::SerializableDouble()
    : value(0.0)
{
}

[[maybe_unused]]
SerializableDouble::SerializableDouble(const double value)
    : value(value)
{
}

[[maybe_unused]]
SerializableDouble::SerializableDouble(const SerializableDouble& other) = default;

[[maybe_unused]]
SerializableDouble::SerializableDouble(SerializableDouble&& other) noexcept = default;

SerializableDouble::~SerializableDouble() = default;

SerializableDouble& SerializableDouble::operator=(const SerializableDouble& rhs) = default;

SerializableDouble& SerializableDouble::operator=(SerializableDouble&& rhs) noexcept = default;

bool SerializableDouble::operator==(const SerializableDouble& rhs) const
{
    return value == rhs.value;
}

bool SerializableDouble::operator!=(const SerializableDouble& rhs) const
{
    return !(rhs == *this);
}

bool SerializableDouble::operator<(const SerializableDouble& rhs) const
{
    return value < rhs.value;
}

bool SerializableDouble::operator>(const SerializableDouble& rhs) const
{
    return rhs < *this;
}

bool SerializableDouble::operator<=(const SerializableDouble& rhs) const
{
    return !(rhs < *this);
}

bool SerializableDouble::operator>=(const SerializableDouble& rhs) const
{
    return !(*this < rhs);
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableDouble::ToJson() const
{
    return JsonValue::FromDouble(value);
}

[[maybe_unused]]
std::string SerializableDouble::ToString() const
{
    return ToJson().ToString();
}

// endregion ISerializable
