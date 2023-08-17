#include "EnjinPlatformSdk/SerializableString.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
SerializableString::SerializableString() = default;

[[maybe_unused]]
SerializableString::SerializableString(std::string value)
    : value(std::move(value))
{
}

[[maybe_unused]]
SerializableString::SerializableString(const SerializableString& other) = default;

[[maybe_unused]]
SerializableString::SerializableString(SerializableString&& other) noexcept = default;

SerializableString::~SerializableString() = default;

SerializableString& SerializableString::operator=(const SerializableString& rhs) = default;

SerializableString& SerializableString::operator=(SerializableString&& rhs) noexcept = default;

bool SerializableString::operator==(const SerializableString& rhs) const
{
    return value == rhs.value;
}

bool SerializableString::operator!=(const SerializableString& rhs) const
{
    return value != rhs.value;
}

bool SerializableString::operator<(const SerializableString& rhs) const
{
    return value < rhs.value;
}

bool SerializableString::operator>(const SerializableString& rhs) const
{
    return value > rhs.value;
}

bool SerializableString::operator<=(const SerializableString& rhs) const
{
    return value <= rhs.value;
}

bool SerializableString::operator>=(const SerializableString& rhs) const
{
    return value >= rhs.value;
}

// region ISerializable

[[maybe_unused]]
JsonValue SerializableString::ToJson() const
{
    return JsonValue::FromString(value);
}

[[maybe_unused]]
std::string SerializableString::ToString() const
{
    return ToJson().ToString();
};

// endregion ISerializable
