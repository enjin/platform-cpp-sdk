#include "EnjinPlatformSdk/SerializableDouble.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableDouble::SerializableDouble()
    : value(0.0)
{
}

[[maybe_unused]]
SerializableDouble::SerializableDouble(const double value)
    : value(value)
{
}

[[maybe_unused]]
SerializableDouble::SerializableDouble(const SerializableDouble& other) = default;

[[maybe_unused]]
SerializableDouble::SerializableDouble(SerializableDouble&& other) noexcept = default;

SerializableDouble::~SerializableDouble() = default;

SerializableDouble& SerializableDouble::operator=(const SerializableDouble& rhs) = default;

SerializableDouble& SerializableDouble::operator=(SerializableDouble&& rhs) noexcept = default;

bool SerializableDouble::operator==(const SerializableDouble& rhs) const
{
    return value == rhs.value;
}

bool SerializableDouble::operator!=(const SerializableDouble& rhs) const
{
    return value != rhs.value;
}

bool SerializableDouble::operator<(const SerializableDouble& rhs) const
{
    return value < rhs.value;
}

bool SerializableDouble::operator>(const SerializableDouble& rhs) const
{
    return value > rhs.value;
}

bool SerializableDouble::operator<=(const SerializableDouble& rhs) const
{
    return value <= rhs.value;
}

bool SerializableDouble::operator>=(const SerializableDouble& rhs) const
{
    return value >= rhs.value;
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableDouble::ToJson() const
{
    return JsonValue::FromDouble(value);
}

[[maybe_unused]]
std::string SerializableDouble::ToString() const
{
    return ToJson().ToString();
}

// endregion ISerializable
