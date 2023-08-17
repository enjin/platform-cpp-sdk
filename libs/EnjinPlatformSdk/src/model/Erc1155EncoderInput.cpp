#include "EnjinPlatformSdk/Erc1155EncoderInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
Erc1155EncoderInput::Erc1155EncoderInput() = default;

[[maybe_unused]]
Erc1155EncoderInput::Erc1155EncoderInput(const Erc1155EncoderInput& other) = default;

[[maybe_unused]]
Erc1155EncoderInput::Erc1155EncoderInput(Erc1155EncoderInput&& other) noexcept = default;

Erc1155EncoderInput::~Erc1155EncoderInput() = default;

[[maybe_unused]]
Erc1155EncoderInput& Erc1155EncoderInput::SetTokenId(SerializableStringPtr tokenId)
{
    return GraphQlParameter<Erc1155EncoderInput>::SetParameter("tokenId", std::move(tokenId));
}

[[maybe_unused]]
Erc1155EncoderInput& Erc1155EncoderInput::SetIndex(SerializableStringPtr index)
{
    return GraphQlParameter<Erc1155EncoderInput>::SetParameter("index", std::move(index));
}

Erc1155EncoderInput& Erc1155EncoderInput::operator=(const Erc1155EncoderInput& rhs) = default;

Erc1155EncoderInput& Erc1155EncoderInput::operator=(Erc1155EncoderInput&& rhs) noexcept = default;
