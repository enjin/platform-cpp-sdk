#include "EnjinPlatformSdkMarketplace/FeeSide.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

constexpr char NoFee[] = "NO_FEE";
constexpr char MakeFee[] = "MAKE_FEE";
constexpr char TakeFee[] = "TAKE_FEE";

[[maybe_unused]]
std::string enjin::platform::sdk::marketplace::ToString(const FeeSide value)
{
    switch (value)
    {
        case FeeSide::NoFee:
            return NoFee;

        case FeeSide::MakeFee:
            return MakeFee;

        case FeeSide::TakeFee:
            return TakeFee;

        default:
            throw std::out_of_range("Value out of range for FeeSide enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::marketplace::TryGetField(const JsonValue& json,
                                                    const std::string& key,
                                                    std::optional<FeeSide>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == NoFee)
    {
        outField = FeeSide::NoFee;
    }
    else if (value == MakeFee)
    {
        outField = FeeSide::MakeFee;
    }
    else if (value == TakeFee)
    {
        outField = FeeSide::TakeFee;
    }

    return outField.has_value();
}
