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
