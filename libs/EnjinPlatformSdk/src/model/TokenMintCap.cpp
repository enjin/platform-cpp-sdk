#include "EnjinPlatformSdk/TokenMintCap.hpp"

#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<TokenMintCap>;

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
    constexpr char key[] = "type";

    if (type == TokenMintCapType::None)
    {
        return GraphQlParameter<TokenMintCap>::RemoveParameter(key);
    }

    std::string s = enjin::platform::sdk::ToString(type);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return GraphQlParameter<TokenMintCap>::SetParameter(key, std::move(sPtr));
}

[[maybe_unused]]
TokenMintCap& TokenMintCap::SetAmount(SerializableStringPtr amount)
{
    return GraphQlParameter<TokenMintCap>::SetParameter("amount", std::move(amount));
}

TokenMintCap& TokenMintCap::operator=(const TokenMintCap& rhs) = default;

TokenMintCap& TokenMintCap::operator=(TokenMintCap&& rhs) noexcept = default;
