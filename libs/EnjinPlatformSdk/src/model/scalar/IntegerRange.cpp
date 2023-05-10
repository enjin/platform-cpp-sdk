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

#include "EnjinPlatformSdk/IntegerRange.hpp"

#include <sstream>

using namespace enjin::platform::sdk;

[[maybe_unused]]
IntegerRange::IntegerRange(const std::string& value)
    : IntegerRange(value, value)
{
}

[[maybe_unused]]
IntegerRange::IntegerRange(const std::string& start, const std::string& end)
{
    if (start == end)
    {
        _value = start;
    }
    else
    {
        std::stringstream ss;

        ss << start << ".." << end;

        _value = ss.str();
    }
}

IntegerRange::~IntegerRange() = default;

[[maybe_unused]]
JsonValue IntegerRange::ToJson() const
{
    return JsonValue::FromString(_value);
}

[[maybe_unused]]
std::string IntegerRange::ToString() const
{
    return ToJson().ToString();
}
