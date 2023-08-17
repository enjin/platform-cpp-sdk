#include "EnjinPlatformSdk/SerializableInt.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableInt::SerializableInt()
    : value(0)
{
}

[[maybe_unused]]
SerializableInt::SerializableInt(int32_t value)
    : value(value)
{
}

[[maybe_unused]]
SerializableInt::SerializableInt(const SerializableInt& other) = default;

[[maybe_unused]]
SerializableInt::SerializableInt(SerializableInt&& other) noexcept = default;

SerializableInt::~SerializableInt() = default;

SerializableInt& SerializableInt::operator=(const SerializableInt& rhs) = default;

SerializableInt& SerializableInt::operator=(SerializableInt&& rhs) noexcept = default;

bool SerializableInt::operator==(const SerializableInt& rhs) const
{
    return value == rhs.value;
}

bool SerializableInt::operator!=(const SerializableInt& rhs) const
{
    return value != rhs.value;
}

bool SerializableInt::operator<(const SerializableInt& rhs) const
{
    return value < rhs.value;
}

bool SerializableInt::operator>(const SerializableInt& rhs) const
{
    return value > rhs.value;
}

bool SerializableInt::operator<=(const SerializableInt& rhs) const
{
    return value <= rhs.value;
}

bool SerializableInt::operator>=(const SerializableInt& rhs) const
{
    return value >= rhs.value;
}

// region ISerializable

JsonValue SerializableInt::ToJson() const
{
    return JsonValue::FromJson(ToString());
}

std::string SerializableInt::ToString() const
{
    return std::to_string(value);
}

// endregion ISerializable
