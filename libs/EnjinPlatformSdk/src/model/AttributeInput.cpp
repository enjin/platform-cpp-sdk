#include "EnjinPlatformSdk/AttributeInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
AttributeInput::AttributeInput() = default;

[[maybe_unused]]
AttributeInput::AttributeInput(const AttributeInput& other) = default;

[[maybe_unused]]
AttributeInput::AttributeInput(AttributeInput&& other) noexcept = default;

AttributeInput::~AttributeInput() = default;

[[maybe_unused]]
AttributeInput& AttributeInput::SetKey(SerializableStringPtr key)
{
    return GraphQlParameter<AttributeInput>::SetParameter("key", std::move(key));
}

[[maybe_unused]]
AttributeInput& AttributeInput::SetValue(SerializableStringPtr value)
{
    return GraphQlParameter<AttributeInput>::SetParameter("value", std::move(value));
}

AttributeInput& AttributeInput::operator=(const AttributeInput& rhs) = default;

AttributeInput& AttributeInput::operator=(AttributeInput&& rhs) noexcept = default;
