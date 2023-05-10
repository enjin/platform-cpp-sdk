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

#include "EnjinPlatformSdk/SerializableString.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableString::SerializableString() = default;

[[maybe_unused]]
SerializableString::SerializableString(std::string value)
    : value(std::move(value))
{
}

[[maybe_unused]]
SerializableString::SerializableString(const SerializableString& other) = default;

[[maybe_unused]]
SerializableString::SerializableString(SerializableString&& other) noexcept = default;

SerializableString::~SerializableString() = default;

SerializableString& SerializableString::operator=(const SerializableString& rhs) = default;

SerializableString& SerializableString::operator=(SerializableString&& rhs) noexcept = default;

bool SerializableString::operator==(const SerializableString& rhs) const
{
    return value == rhs.value;
}

bool SerializableString::operator!=(const SerializableString& rhs) const
{
    return !(rhs == *this);
}

bool SerializableString::operator<(const SerializableString& rhs) const
{
    return value < rhs.value;
}

bool SerializableString::operator>(const SerializableString& rhs) const
{
    return rhs < *this;
}

bool SerializableString::operator<=(const SerializableString& rhs) const
{
    return !(rhs < *this);
}

bool SerializableString::operator>=(const SerializableString& rhs) const
{
    return !(*this < rhs);
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableString::ToJson() const
{
    return JsonValue::FromString(value);
}

[[maybe_unused]]
std::string SerializableString::ToString() const
{
    return ToJson().ToString();
};

// endregion ISerializable
