#ifndef ENJINPLATFORMSDK_TRANSACTIONRESULT_HPP
#define ENJINPLATFORMSDK_TRANSACTIONRESULT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Enum values representing the result status of a transaction.
enum class TransactionResult
{
    /// \brief Value used by the SDK for parameter setting to indicate the enum parameter should be unset.
    None,

    /// \brief Indicates the transaction result is EXTRINSIC_SUCCESS.
    ExtrinsicSuccess,

    /// \brief Indicates the transaction result is EXTRINSIC_FAILED.
    ExtrinsicFailed,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
std::string ToString(TransactionResult value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<TransactionResult>& outField);
}

#endif //ENJINPLATFORMSDK_TRANSACTIONRESULT_HPP
