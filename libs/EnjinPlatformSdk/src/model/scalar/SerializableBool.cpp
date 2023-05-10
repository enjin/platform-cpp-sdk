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

#include "EnjinPlatformSdk/SerializableBool.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableBool::SerializableBool()
    : value(false)
{
}

[[maybe_unused]]
SerializableBool::SerializableBool(const bool value)
    : value(value)
{
}

[[maybe_unused]]
SerializableBool::SerializableBool(const SerializableBool& other) = default;

[[maybe_unused]]
SerializableBool::SerializableBool(SerializableBool&& other) noexcept = default;

SerializableBool::~SerializableBool() = default;

SerializableBool& SerializableBool::operator=(const SerializableBool& rhs) = default;

SerializableBool& SerializableBool::operator=(SerializableBool&& rhs) noexcept = default;

bool SerializableBool::operator==(const SerializableBool& rhs) const
{
    return value == rhs.value;
}

bool SerializableBool::operator!=(const SerializableBool& rhs) const
{
    return !(rhs == *this);
}

bool SerializableBool::operator<(const SerializableBool& rhs) const
{
    return value < rhs.value;
}

bool SerializableBool::operator>(const SerializableBool& rhs) const
{
    return rhs < *this;
}

bool SerializableBool::operator<=(const SerializableBool& rhs) const
{
    return !(rhs < *this);
}

bool SerializableBool::operator>=(const SerializableBool& rhs) const
{
    return !(*this < rhs);
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableBool::ToJson() const
{
    return JsonValue::FromBool(value);
}

[[maybe_unused]]
std::string SerializableBool::ToString() const
{
    return ToJson().ToString();
}

// endregion ISerializable
