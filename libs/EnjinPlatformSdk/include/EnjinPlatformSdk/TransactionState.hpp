#ifndef ENJINPLATFORMSDK_TRANSACTIONSTATE_HPP
#define ENJINPLATFORMSDK_TRANSACTIONSTATE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Enum values representing the state of a transaction's lifecycle.
enum class TransactionState
{
    /// \brief Value used by the SDK for parameter setting to indicate the enum parameter should be unset.
    None,

    /// \brief Indicates the transaction state is ABANDONED.
    Abandoned,

    /// \brief Indicates the transaction state is PENDING.
    Pending,

    /// \brief Indicates the transaction state is PROCESSING.
    Processing,

    /// \brief Indicates the transaction state is BROADCAST.
    Broadcast,

    /// \brief Indicates the transaction state is EXECUTED.
    Executed,

    /// \brief Indicates the transaction state is FINALIZED.
    Finalized,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
std::string ToString(TransactionState value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<TransactionState>& outField);
}

#endif //ENJINPLATFORMSDK_TRANSACTIONSTATE_HPP
