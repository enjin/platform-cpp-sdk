#ifndef ENJINPLATFORMSDKBEAM_BEAMFLAG_HPP
#define ENJINPLATFORMSDKBEAM_BEAMFLAG_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk::beam
{
/// \brief Represents the flags that may be applied to a beam.
enum class BeamFlag
{
    /// \brief Value used by the SDK for parameter setting to indicate the enum parameter should be unset.
    None,

    /// \brief Indicates a beam is flagged as PAUSED.
    Paused,

    /// \brief Indicates a beam is flagged as SINGLE_USE.
    SingleUse,

    /// \brief Indicates a beam is flagged as PRUNABLE.
    Prunable,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDKBEAM_EXPORT
std::string ToString(BeamFlag value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDKBEAM_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<BeamFlag>& outField);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDKBEAM_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<std::vector<BeamFlag>>& outField);
}

#endif //ENJINPLATFORMSDKBEAM_BEAMFLAG_HPP
