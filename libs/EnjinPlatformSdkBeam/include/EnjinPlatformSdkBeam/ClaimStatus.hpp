#ifndef ENJINPLATFORMSDKBEAM_CLAIMSTATUS_HPP
#define ENJINPLATFORMSDKBEAM_CLAIMSTATUS_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk::beam
{
/// \brief Represents the claim status of a beam.
enum class ClaimStatus
{
    /// \brief Indicates the claim status is PENDING.
    Pending,

    /// \brief Indicates the claim status is IN_PROGRESS.
    InProgress,

    /// \brief Indicates the claim status is COMPLETED.
    Completed,

    /// \brief Indicates the claim status is FAILED.
    Failed,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDKBEAM_EXPORT
std::string ToString(ClaimStatus value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDKBEAM_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<ClaimStatus>& outField);
}

#endif //ENJINPLATFORMSDKBEAM_CLAIMSTATUS_HPP
