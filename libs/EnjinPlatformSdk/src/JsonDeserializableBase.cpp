#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

[[maybe_unused]]
JsonDeserializableBase::JsonDeserializableBase() = default;

[[maybe_unused]]
JsonDeserializableBase::JsonDeserializableBase(const JsonDeserializableBase& other) = default;

[[maybe_unused]]
JsonDeserializableBase::JsonDeserializableBase(JsonDeserializableBase&& other) noexcept = default;

JsonDeserializableBase::~JsonDeserializableBase() = default;

JsonDeserializableBase& JsonDeserializableBase::operator=(const JsonDeserializableBase& rhs) = default;

JsonDeserializableBase& JsonDeserializableBase::operator=(JsonDeserializableBase&& rhs) noexcept = default;

bool JsonDeserializableBase::operator==(const JsonDeserializableBase&) const
{
    return true;
}

bool JsonDeserializableBase::operator!=(const JsonDeserializableBase&) const
{
    return false;
}

// region IJsonDeserializable

[[maybe_unused]]
void JsonDeserializableBase::Deserialize(const JsonValue&)
{
    if (_hasBeenDeserialized)
    {
        throw std::runtime_error("Cannot call Deserialize on instance that has already been deserialized");
    }

    _hasBeenDeserialized = true;
}

// endregion IJsonDeserializable
