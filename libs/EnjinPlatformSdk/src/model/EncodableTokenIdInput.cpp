#include "EnjinPlatformSdk/EncodableTokenIdInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
EncodableTokenIdInput::EncodableTokenIdInput() = default;

[[maybe_unused]]
EncodableTokenIdInput::EncodableTokenIdInput(const EncodableTokenIdInput& other) = default;

[[maybe_unused]]
EncodableTokenIdInput::EncodableTokenIdInput(EncodableTokenIdInput&& other) noexcept = default;

EncodableTokenIdInput::~EncodableTokenIdInput() = default;

[[maybe_unused]]
EncodableTokenIdInput& EncodableTokenIdInput::SetErc1155(Erc1155EncoderInputPtr erc1155)
{
    return GraphQlParameter<EncodableTokenIdInput>::SetParameter("erc1155", std::move(erc1155));
}

[[maybe_unused]]
EncodableTokenIdInput& EncodableTokenIdInput::SetHash(SerializableJsonValuePtr hash)
{
    return GraphQlParameter<EncodableTokenIdInput>::SetParameter("hash", std::move(hash));
}

[[maybe_unused]]
EncodableTokenIdInput& EncodableTokenIdInput::SetInteger(SerializableStringPtr integer)
{
    return GraphQlParameter<EncodableTokenIdInput>::SetParameter("integer", std::move(integer));
}

[[maybe_unused]]
EncodableTokenIdInput& EncodableTokenIdInput::SetStringId(SerializableStringPtr stringId)
{
    return GraphQlParameter<EncodableTokenIdInput>::SetParameter("stringId", std::move(stringId));
}

EncodableTokenIdInput& EncodableTokenIdInput::operator=(const EncodableTokenIdInput& rhs) = default;

EncodableTokenIdInput& EncodableTokenIdInput::operator=(EncodableTokenIdInput&& rhs) noexcept = default;
