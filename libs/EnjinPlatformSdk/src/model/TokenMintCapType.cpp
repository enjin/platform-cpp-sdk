#include "EnjinPlatformSdk/TokenMintCapType.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char SingleMint[] = "SINGLE_MINT";
constexpr char Supply[] = "SUPPLY";

[[maybe_unused]]
std::string enjin::platform::sdk::ToString(const TokenMintCapType value)
{
    switch (value)
    {
        case TokenMintCapType::None:
            return {};

        case TokenMintCapType::SingleMint:
            return SingleMint;

        case TokenMintCapType::Supply:
            return Supply;

        default:
            throw std::out_of_range("Value out of range for TokenMintCapType enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<TokenMintCapType>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == SingleMint)
    {
        outField = TokenMintCapType::SingleMint;
    }
    else if (value == Supply)
    {
        outField = TokenMintCapType::Supply;
    }

    return outField.has_value();
}
