#ifndef ENJINPLATFORMSDKMARKETPLACE_LISTINGSTATEENUM_HPP
#define ENJINPLATFORMSDKMARKETPLACE_LISTINGSTATEENUM_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk::marketplace
{
/// \brief Represents the marketplace listing state.
enum class ListingStateEnum
{
    /// \brief Value used by the SDK for parameter setting to indicate the enum parameter should be unset.
    None,

    /// \brief Indicates the listing state is ACTIVE.
    Active,

    /// \brief Indicates the listing state is CANCELLED.
    Cancelled,

    /// \brief Indicates the listing state is FINALIZED.
    Finalized,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::string ToString(ListingStateEnum value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<ListingStateEnum>& outField);
}

#endif //ENJINPLATFORMSDKMARKETPLACE_LISTINGSTATEENUM_HPP
