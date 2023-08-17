#include "EnjinPlatformSdk/PalletIdentifier.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char Marketplace[] = "MARKETPLACE";
constexpr char MultiTokens[] = "MULTI_TOKENS";
constexpr char FuelTanks[] = "FUEL_TANKS";

[[maybe_unused]]
std::string enjin::platform::sdk::ToString(const PalletIdentifier value)
{
    switch (value)
    {
        case PalletIdentifier::None:
            return {};

        case PalletIdentifier::Marketplace:
            return Marketplace;

        case PalletIdentifier::MultiTokens:
            return MultiTokens;

        case PalletIdentifier::FuelTanks:
            return FuelTanks;

        default:
            throw std::out_of_range("Value out of range for PalletIdentifier enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<PalletIdentifier>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == "MARKETPLACE")
    {
        outField = PalletIdentifier::Marketplace;
    }
    else if (value == "MULTI_TOKENS")
    {
        outField = PalletIdentifier::MultiTokens;
    }
    else if (value == "FUEL_TANKS")
    {
        outField = PalletIdentifier::FuelTanks;
    }

    return outField.has_value();
}
