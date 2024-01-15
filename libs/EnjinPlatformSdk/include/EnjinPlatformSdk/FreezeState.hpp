#ifndef ENJINPLATFORMSDK_FREEZESTATE_HPP
#define ENJINPLATFORMSDK_FREEZESTATE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief The freeze states supported on-chain.
enum class FreezeState
{
    /// \brief Indicates the token will be permanently frozen.
    Permanent,

    /// \brief Indicates the token will be frozen temporarily.
    Temporary,

    /// \brief RIndicates the the token cannot be frozen.
    Never,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
std::string ToString(FreezeState value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<FreezeState>& outField);
}

#endif //ENJINPLATFORMSDK_FREEZESTATE_HPP
