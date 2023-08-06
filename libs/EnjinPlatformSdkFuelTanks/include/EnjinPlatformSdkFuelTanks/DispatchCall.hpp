#ifndef ENJINPLATFORMSDKFUELTANKS_DISPATCHCALL_HPP
#define ENJINPLATFORMSDKFUELTANKS_DISPATCHCALL_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk::fuelTanks
{
/// \brief Represents the dispatch rule options.
enum class DispatchCall
{
    /// \brief Value used by the SDK for parameter setting to indicate the enum parameter should be unset.
    None,

    /// \brief Indicates a dispatch call as MULTI_TOKENS.
    MultiTokens,

    /// \brief Indicates a dispatch call as FUEL_TANKS.
    FuelTanks,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::string ToString(DispatchCall value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<DispatchCall>& outField);
}

#endif //ENJINPLATFORMSDKFUELTANKS_DISPATCHCALL_HPP
