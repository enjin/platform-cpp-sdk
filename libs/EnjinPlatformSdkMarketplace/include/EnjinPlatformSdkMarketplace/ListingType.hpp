#ifndef ENJINPLATFORMSDKMARKETPLACE_LISTINGTYPE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_LISTINGTYPE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk::marketplace
{
/// \brief Represents the type of a listing.
enum class ListingType
{
    /// \brief Indicates the listing is of type FIXED_PRICE.
    FixedPrice,

    /// \brief Indicates the listing is of type AUCTION.
    Auction,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::string ToString(ListingType value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<ListingType>& outField);
}

#endif //ENJINPLATFORMSDKMARKETPLACE_LISTINGTYPE_HPP
