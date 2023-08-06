#ifndef ENJINPLATFORMSDKFUELTANKS_DISPATCHRULEENUM_HPP
#define ENJINPLATFORMSDKFUELTANKS_DISPATCHRULEENUM_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk::fuelTanks
{
/// \brief Represents the dispatch rule options.
enum class DispatchRuleEnum
{
    /// \brief Value used by the SDK for parameter setting to indicate the enum parameter should be unset.
    None,

    /// \brief Indicates a dispatch rule as WHITELISTED_CALLERS.
    WhitelistedCallers,

    /// \brief Indicates a dispatch rule as WHITELISTED_COLLECTIONS.
    WhitelistedCollection,

    /// \brief Indicates a dispatch rule as MAX_FUEL_BURN_PER_TRANSACTION.
    MaxFuelBurnPerTransaction,

    /// \brief Indicates a dispatch rule as USER_FUEL_BUDGET.
    UserFuelBudget,

    /// \brief Indicates a dispatch rule as TANK_FUEL_BUDGET.
    TankFuelBudget,

    /// \brief Indicates a dispatch rule as <c>REQUIRE_TOKEN.
    RequireToken,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::string ToString(DispatchRuleEnum value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<DispatchRuleEnum>& outField);
}

#endif //ENJINPLATFORMSDKFUELTANKS_DISPATCHRULEENUM_HPP
