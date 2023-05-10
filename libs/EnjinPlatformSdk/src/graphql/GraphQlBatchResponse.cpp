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

#include "EnjinPlatformSdk/GraphQlBatchResponse.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
GraphQlBatchResponse::GraphQlBatchResponse() = default;

[[maybe_unused]]
GraphQlBatchResponse::GraphQlBatchResponse(const GraphQlBatchResponse& other) = default;

[[maybe_unused]]
GraphQlBatchResponse::GraphQlBatchResponse(GraphQlBatchResponse&& other) noexcept = default;

GraphQlBatchResponse::~GraphQlBatchResponse() = default;

[[maybe_unused]]
size_t GraphQlBatchResponse::Size() const
{
    return _responses.size();
}

GraphQlResponse<JsonValue>& GraphQlBatchResponse::operator[](size_t index)
{
    return _responses[index];
}

const GraphQlResponse<JsonValue>& GraphQlBatchResponse::operator[](size_t index) const
{
    return _responses[index];
}

GraphQlBatchResponse& GraphQlBatchResponse::operator=(const GraphQlBatchResponse& rhs) = default;

GraphQlBatchResponse& GraphQlBatchResponse::operator=(GraphQlBatchResponse&& rhs) noexcept = default;

bool GraphQlBatchResponse::operator==(const GraphQlBatchResponse& rhs) const = default;

bool GraphQlBatchResponse::operator!=(const GraphQlBatchResponse& rhs) const = default;

// region IJsonDeserializable

[[maybe_unused]]
void GraphQlBatchResponse::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    JsonUtil::TryGetArray(json, _responses);
}

// endregion IJsonDeserializable
