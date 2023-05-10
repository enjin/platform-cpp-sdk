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

#include "EnjinPlatformSdk/GraphQlErrorLocation.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
GraphQlErrorLocation::GraphQlErrorLocation() = default;

[[maybe_unused]]
GraphQlErrorLocation::GraphQlErrorLocation(const GraphQlErrorLocation& other) = default;

[[maybe_unused]]
GraphQlErrorLocation::GraphQlErrorLocation(GraphQlErrorLocation&& other) noexcept = default;

GraphQlErrorLocation::~GraphQlErrorLocation() = default;

[[maybe_unused]]
const std::optional<int32_t>& GraphQlErrorLocation::GetColumn() const
{
    return column;
}

[[maybe_unused]]
const std::optional<int32_t>& GraphQlErrorLocation::GetLine() const
{
    return line;
}

GraphQlErrorLocation& GraphQlErrorLocation::operator=(const GraphQlErrorLocation& rhs) = default;

GraphQlErrorLocation& GraphQlErrorLocation::operator=(GraphQlErrorLocation&& rhs) noexcept = default;

bool GraphQlErrorLocation::operator==(const GraphQlErrorLocation& rhs) const = default;

bool GraphQlErrorLocation::operator!=(const GraphQlErrorLocation& rhs) const = default;

// region IJsonDeserializable

[[maybe_unused]]
void GraphQlErrorLocation::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    JsonUtil::TryGetField(json, "line", line);
    JsonUtil::TryGetField(json, "column", column);
}

// endregion IJsonDeserializable
