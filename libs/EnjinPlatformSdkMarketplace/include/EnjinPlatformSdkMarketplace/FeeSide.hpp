#ifndef ENJINPLATFORMSDKMARKETPLACE_FEESIDE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_FEESIDE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk::marketplace
{
/// \brief Represents the side of the listing that is considered money and is used to pay fees.
enum class FeeSide
{
    /// \brief Indicates the fee side as NO_FEE.
    NoFee,

    /// \brief Indicates the fee side as MAKE_FEE.
    MakeFee,

    /// \brief Indicates the fee side as TAKE_FEE.
    TakeFee,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
std::string ToString(FeeSide value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDKMARKETPLACE_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<FeeSide>& outField);
}

#endif //ENJINPLATFORMSDKMARKETPLACE_FEESIDE_HPP
