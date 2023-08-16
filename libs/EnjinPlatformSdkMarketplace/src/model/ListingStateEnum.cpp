#include "EnjinPlatformSdkMarketplace/ListingStateEnum.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

constexpr char Active[] = "ACTIVE";
constexpr char Cancelled[] = "CANCELLED";
constexpr char Finalized[] = "FINALIZED";

[[maybe_unused]]
std::string enjin::platform::sdk::marketplace::ToString(const ListingStateEnum value)
{
    switch (value)
    {
        case ListingStateEnum::Active:
            return Active;

        case ListingStateEnum::Cancelled:
            return Cancelled;

        case ListingStateEnum::Finalized:
            return Finalized;

        default:
            throw std::out_of_range("Value out of range for ListingStateEnum enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::marketplace::TryGetField(const JsonValue& json,
                                                    const std::string& key,
                                                    std::optional<ListingStateEnum>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == Active)
    {
        outField = ListingStateEnum::Active;
    }
    else if (value == Cancelled)
    {
        outField = ListingStateEnum::Cancelled;
    }
    else if (value == Finalized)
    {
        outField = ListingStateEnum::Finalized;
    }

    return outField.has_value();
}
