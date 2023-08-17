#include "EnjinPlatformSdk/IntegerRange.hpp"

#include <sstream>

using namespace enjin::platform::sdk;

[[maybe_unused]]
IntegerRange::IntegerRange(const std::string& value)
    : IntegerRange(value, value)
{
}

[[maybe_unused]]
IntegerRange::IntegerRange(const std::string& start, const std::string& end)
{
    if (start == end)
    {
        _value = start;
    }
    else
    {
        std::stringstream ss;

        ss << start << ".." << end;

        _value = ss.str();
    }
}

[[maybe_unused]]
IntegerRange::IntegerRange(const IntegerRange& other) = default;

[[maybe_unused]]
IntegerRange::IntegerRange(IntegerRange&& other) noexcept = default;

IntegerRange::~IntegerRange() = default;

IntegerRange& IntegerRange::operator=(const IntegerRange& rhs) = default;

IntegerRange& IntegerRange::operator=(IntegerRange&& rhs) noexcept = default;

// region ISerializable

[[maybe_unused]]
JsonValue IntegerRange::ToJson() const
{
    return JsonValue::FromString(_value);
}

[[maybe_unused]]
std::string IntegerRange::ToString() const
{
    return ToJson().ToString();
}

// endregion ISerializable
