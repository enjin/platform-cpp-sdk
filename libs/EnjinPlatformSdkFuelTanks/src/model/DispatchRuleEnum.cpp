#include "EnjinPlatformSdkFuelTanks/DispatchRuleEnum.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

constexpr char WhitelistedCallers[] = "WHITELISTED_CALLERS";
constexpr char WhitelistedCollection[] = "WHITELISTED_COLLECTIONS";
constexpr char MaxFuelBurnPerTransaction[] = "MAX_FUEL_BURN_PER_TRANSACTION";
constexpr char UserFuelBudget[] = "USER_FUEL_BUDGET";
constexpr char TankFuelBudget[] = "TANK_FUEL_BUDGET";
constexpr char RequireToken[] = "REQUIRE_TOKEN";

[[maybe_unused]]
std::string enjin::platform::sdk::fuelTanks::ToString(const DispatchRuleEnum value)
{
    switch (value)
    {
        case DispatchRuleEnum::None:
            return {};

        case DispatchRuleEnum::WhitelistedCallers:
            return WhitelistedCallers;

        case DispatchRuleEnum::WhitelistedCollection:
            return WhitelistedCollection;

        case DispatchRuleEnum::MaxFuelBurnPerTransaction:
            return MaxFuelBurnPerTransaction;

        case DispatchRuleEnum::UserFuelBudget:
            return UserFuelBudget;

        case DispatchRuleEnum::TankFuelBudget:
            return TankFuelBudget;

        case DispatchRuleEnum::RequireToken:
            return RequireToken;

        default:
            throw std::out_of_range("Value out of range for DispatchRuleEnum enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::fuelTanks::TryGetField(const JsonValue& json,
                                                  const std::string& key,
                                                  std::optional<DispatchRuleEnum>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == WhitelistedCallers)
    {
        outField = DispatchRuleEnum::WhitelistedCallers;
    }
    else if (value == WhitelistedCollection)
    {
        outField = DispatchRuleEnum::WhitelistedCollection;
    }
    else if (value == MaxFuelBurnPerTransaction)
    {
        outField = DispatchRuleEnum::MaxFuelBurnPerTransaction;
    }
    else if (value == UserFuelBudget)
    {
        outField = DispatchRuleEnum::UserFuelBudget;
    }
    else if (value == TankFuelBudget)
    {
        outField = DispatchRuleEnum::TankFuelBudget;
    }
    else if (value == RequireToken)
    {
        outField = DispatchRuleEnum::RequireToken;
    }

    return outField.has_value();
}
