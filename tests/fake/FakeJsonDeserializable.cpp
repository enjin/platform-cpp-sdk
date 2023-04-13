#include "FakeJsonDeserializable.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable() = default;

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable(const bool field)
    : _field(field)
{
}

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable(const FakeJsonDeserializable& other) = default;

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable(FakeJsonDeserializable&& other) noexcept = default;

FakeJsonDeserializable::~FakeJsonDeserializable() = default;

FakeJsonDeserializable& FakeJsonDeserializable::operator=(const FakeJsonDeserializable& rhs) = default;

FakeJsonDeserializable& FakeJsonDeserializable::operator=(FakeJsonDeserializable&& rhs) noexcept = default;

bool FakeJsonDeserializable::operator==(const FakeJsonDeserializable& rhs) const = default;

bool FakeJsonDeserializable::operator!=(const FakeJsonDeserializable& rhs) const = default;

// region IJsonDeserializable

[[maybe_unused]]
void FakeJsonDeserializable::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    JsonUtil::TryGetField(json, "field", _field);
}

// endregion IJsonDeserializable
