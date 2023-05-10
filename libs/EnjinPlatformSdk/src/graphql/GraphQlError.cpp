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

#include "EnjinPlatformSdk/GraphQlError.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
GraphQlError::GraphQlError() = default;

[[maybe_unused]]
GraphQlError::GraphQlError(const GraphQlError& other) = default;

[[maybe_unused]]
GraphQlError::GraphQlError(GraphQlError&& other) noexcept = default;

GraphQlError::~GraphQlError() = default;

[[maybe_unused]]
const std::optional<JsonValue>& GraphQlError::GetExtensions() const
{
    return _extensions;
}

[[maybe_unused]]
const std::optional<std::vector<GraphQlErrorLocation>>& GraphQlError::GetLocations() const
{
    return _locations;
}

[[maybe_unused]]
const std::optional<std::string>& GraphQlError::GetMessage() const
{
    return _message;
}

[[maybe_unused]]
const std::optional<std::vector<std::string>>& GraphQlError::GetPath() const
{
    return _path;
}

GraphQlError& GraphQlError::operator=(const GraphQlError& rhs) = default;

GraphQlError& GraphQlError::operator=(GraphQlError&& rhs) noexcept = default;

bool GraphQlError::operator==(const GraphQlError& rhs) const = default;

bool GraphQlError::operator!=(const GraphQlError& rhs) const = default;

// region IJsonDeserializable

[[maybe_unused]]
void GraphQlError::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    JsonUtil::TryGetField(json, "message", _message);
    JsonUtil::TryGetField(json, "extensions", _extensions);
    JsonUtil::TryGetField(json, "locations", _locations);
    JsonUtil::TryGetField(json, "path", _path);
}

// endregion IJsonDeserializable
