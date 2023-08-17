#ifndef ENJINPLATFORMSDK_PALLETIDENTIFIER_HPP
#define ENJINPLATFORMSDK_PALLETIDENTIFIER_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Enum values the on-chain pallet identifiers.
enum class PalletIdentifier
{
    /// \brief Value used by the SDK for parameter setting to indicate the enum parameter should be unset.
    None,

    /// \brief Pallet identifier for marketplace.
    Marketplace,

    /// \brief Pallet identifier for multi-tokens.
    MultiTokens,

    /// \brief Pallet identifier for fuel tanks.
    FuelTanks,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
std::string ToString(PalletIdentifier value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<PalletIdentifier>& outField);
}

#endif //ENJINPLATFORMSDK_PALLETIDENTIFIER_HPP
