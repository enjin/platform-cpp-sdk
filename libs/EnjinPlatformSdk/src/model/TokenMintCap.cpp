#include "EnjinPlatformSdk/TokenMintCap.hpp"

#include <utility>

using namespace enjin::platform::sdk;

constexpr char TypeKey[] = "type";

[[maybe_unused]]
TokenMintCap::TokenMintCap() = default;

[[maybe_unused]]
TokenMintCap::TokenMintCap(const TokenMintCap& other) = default;

[[maybe_unused]]
TokenMintCap::TokenMintCap(TokenMintCap&& other) noexcept = default;

TokenMintCap::~TokenMintCap() = default;

[[maybe_unused]]
TokenMintCap& TokenMintCap::SetType(const TokenMintCapType type)
{
    if (type == TokenMintCapType::None)
    {
        return GraphQlParameter<TokenMintCap>::RemoveParameter(TypeKey);
    }

    SerializableStringPtr s = std::make_shared<SerializableString>(enjin::platform::sdk::ToString(type));
    return GraphQlParameter<TokenMintCap>::SetParameter(TypeKey, std::move(s));
}

[[maybe_unused]]
TokenMintCap& TokenMintCap::SetAmount(SerializableStringPtr amount)
{
    return GraphQlParameter<TokenMintCap>::SetParameter("amount", std::move(amount));
}

TokenMintCap& TokenMintCap::operator=(const TokenMintCap& rhs) = default;

TokenMintCap& TokenMintCap::operator=(TokenMintCap&& rhs) noexcept = default;
