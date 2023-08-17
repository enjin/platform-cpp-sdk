#include "EnjinPlatformSdk/SerializableJsonValue.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableJsonValue::SerializableJsonValue() = default;

[[maybe_unused]]
SerializableJsonValue::SerializableJsonValue(JsonValue value)
    : value(std::move(value))
{
}

[[maybe_unused]]
SerializableJsonValue::SerializableJsonValue(const SerializableJsonValue& other) = default;

[[maybe_unused]]
SerializableJsonValue::SerializableJsonValue(SerializableJsonValue&& other) noexcept = default;

SerializableJsonValue::~SerializableJsonValue() = default;

SerializableJsonValue& SerializableJsonValue::operator=(const SerializableJsonValue& rhs) = default;

SerializableJsonValue& SerializableJsonValue::operator=(SerializableJsonValue&& rhs) noexcept = default;

bool SerializableJsonValue::operator==(const SerializableJsonValue& rhs) const
{
    return value == rhs.value;
}

bool SerializableJsonValue::operator!=(const SerializableJsonValue& rhs) const
{
    return value != rhs.value;
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableJsonValue::ToJson() const
{
    return value;
}

[[maybe_unused]]
std::string SerializableJsonValue::ToString() const
{
    return value.ToString();
}

// endregion ISerializable
