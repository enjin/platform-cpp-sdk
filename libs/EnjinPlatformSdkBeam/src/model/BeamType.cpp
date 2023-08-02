#include "EnjinPlatformSdkBeam/BeamType.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

constexpr char TransferToken[] = "TRANSFER_TOKEN";
constexpr char MintOnDemand[] = "MINT_ON_DEMAND";

[[maybe_unused]]
std::string enjin::platform::sdk::beam::ToString(const BeamType value)
{
    switch (value)
    {
        case BeamType::None:
            return {};

        case BeamType::TransferToken:
            return TransferToken;

        case BeamType::MintOnDemand:
            return MintOnDemand;

        default:
            throw std::out_of_range("Value out of range for BeamType enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::beam::TryGetField(const JsonValue& json,
                                             const std::string& key,
                                             std::optional<BeamType>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == TransferToken)
    {
        outField = BeamType::TransferToken;
    }
    else if (value == MintOnDemand)
    {
        outField = BeamType::MintOnDemand;
    }

    return outField.has_value();
}
