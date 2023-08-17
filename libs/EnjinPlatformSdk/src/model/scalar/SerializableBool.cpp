#include "EnjinPlatformSdk/SerializableBool.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableBool::SerializableBool()
    : value(false)
{
}

[[maybe_unused]]
SerializableBool::SerializableBool(const bool value)
    : value(value)
{
}

[[maybe_unused]]
SerializableBool::SerializableBool(const SerializableBool& other) = default;

[[maybe_unused]]
SerializableBool::SerializableBool(SerializableBool&& other) noexcept = default;

SerializableBool::~SerializableBool() = default;

SerializableBool& SerializableBool::operator=(const SerializableBool& rhs) = default;

SerializableBool& SerializableBool::operator=(SerializableBool&& rhs) noexcept = default;

bool SerializableBool::operator==(const SerializableBool& rhs) const
{
    return value == rhs.value;
}

bool SerializableBool::operator!=(const SerializableBool& rhs) const
{
    return value != rhs.value;
}

bool SerializableBool::operator<(const SerializableBool& rhs) const
{
    return value < rhs.value;
}

bool SerializableBool::operator>(const SerializableBool& rhs) const
{
    return value > rhs.value;
}

bool SerializableBool::operator<=(const SerializableBool& rhs) const
{
    return value <= rhs.value;
}

bool SerializableBool::operator>=(const SerializableBool& rhs) const
{
    return value >= rhs.value;
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableBool::ToJson() const
{
    return JsonValue::FromBool(value);
}

[[maybe_unused]]
std::string SerializableBool::ToString() const
{
    return ToJson().ToString();
}

// endregion ISerializable
