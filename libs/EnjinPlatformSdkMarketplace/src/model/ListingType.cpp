#include "EnjinPlatformSdkMarketplace/ListingType.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

constexpr char FixedPrice[] = "FIXED_PRICE";
constexpr char Auction[] = "AUCTION";

[[maybe_unused]]
std::string enjin::platform::sdk::marketplace::ToString(const ListingType value)
{
    switch (value)
    {
        case ListingType::FixedPrice:
            return FixedPrice;

        case ListingType::Auction:
            return Auction;

        default:
            throw std::out_of_range("Value out of range for ListingType enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::marketplace::TryGetField(const JsonValue& json,
                                                    const std::string& key,
                                                    std::optional<ListingType>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == FixedPrice)
    {
        outField = ListingType::FixedPrice;
    }
    else if (value == Auction)
    {
        outField = ListingType::Auction;
    }

    return outField.has_value();
}
