#include "EnjinPlatformSdkFuelTanks/DispatchCall.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

constexpr char MultiTokens[] = "MULTI_TOKENS";
constexpr char FuelTanks[] = "FUEL_TANKS";

[[maybe_unused]]
std::string enjin::platform::sdk::fuelTanks::ToString(const DispatchCall value)
{
    switch (value)
    {
        case DispatchCall::None:
            return {};

        case DispatchCall::MultiTokens:
            return MultiTokens;

        case DispatchCall::FuelTanks:
            return FuelTanks;

        default:
            throw std::out_of_range("Value out of range for DispatchCall enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::fuelTanks::TryGetField(const JsonValue& json,
                                                  const std::string& key,
                                                  std::optional<DispatchCall>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == MultiTokens)
    {
        outField = DispatchCall::MultiTokens;
    }
    else if (value == FuelTanks)
    {
        outField = DispatchCall::FuelTanks;
    }

    return outField.has_value();
}
