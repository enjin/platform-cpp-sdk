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
