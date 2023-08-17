#include "EnjinPlatformSdk/SerializableFloat.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableFloat::SerializableFloat()
    : value(0.0)
{
}

[[maybe_unused]]
SerializableFloat::SerializableFloat(const float value)
    : value(value)
{
}

[[maybe_unused]]
SerializableFloat::SerializableFloat(const SerializableFloat& other) = default;

[[maybe_unused]]
SerializableFloat::SerializableFloat(SerializableFloat&& other) noexcept = default;

SerializableFloat::~SerializableFloat() = default;

SerializableFloat& SerializableFloat::operator=(const SerializableFloat& rhs) = default;

SerializableFloat& SerializableFloat::operator=(SerializableFloat&& rhs) noexcept = default;

bool SerializableFloat::operator==(const SerializableFloat& rhs) const
{
    return value == rhs.value;
}

bool SerializableFloat::operator!=(const SerializableFloat& rhs) const
{
    return value != rhs.value;
}

bool SerializableFloat::operator<(const SerializableFloat& rhs) const
{
    return value < rhs.value;
}

bool SerializableFloat::operator>(const SerializableFloat& rhs) const
{
    return value > rhs.value;
}

bool SerializableFloat::operator<=(const SerializableFloat& rhs) const
{
    return value <= rhs.value;
}

bool SerializableFloat::operator>=(const SerializableFloat& rhs) const
{
    return value >= rhs.value;
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableFloat::ToJson() const
{
    return JsonValue::FromFloat(value);
}

[[maybe_unused]]
std::string SerializableFloat::ToString() const
{
    return ToJson().ToString();
}

// endregion ISerializable
