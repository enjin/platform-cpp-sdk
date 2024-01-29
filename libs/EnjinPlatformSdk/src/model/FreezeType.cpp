#include "EnjinPlatformSdk/FreezeType.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char Collect[] = "COLLECTION";
constexpr char CollectionAccount[] = "COLLECTION_ACCOUNT";
constexpr char Token[] = "TOKEN";
constexpr char TokenAccount[] = "TOKEN_ACCOUNT";

std::string enjin::platform::sdk::ToString(const FreezeType value)
{
    switch (value)
    {
        case FreezeType::None:
            return {};

        case FreezeType::Collection:
            return Collection;

        case FreezeType::CollectionAccount:
            return CollectionAccount;

        case FreezeType::Token:
            return Token;

        case FreezeType::TokenAccount:
            return TokenAccount;

        default:
            throw std::out_of_range("Value out of range for FreezeType enum");
    }
}

bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<FreezeType>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == Collection)
    {
        outField = FreezeType::Collection;
    }
    else if (value == CollectionAccount)
    {
        outField = FreezeType::CollectionAccount;
    }
    else if (value == Token)
    {
        outField = FreezeType::Token;
    }
    else if (value == TokenAccount)
    {
        outField = FreezeType::TokenAccount;
    }

    return outField.has_value();
}
