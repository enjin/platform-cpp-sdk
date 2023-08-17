#include "EnjinPlatformSdk/CryptoSignatureType.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char Ed25519[] = "ED25519";
constexpr char Sr25519[] = "SR25519";

[[maybe_unused]]
std::string enjin::platform::sdk::ToString(const CryptoSignatureType value)
{
    switch (value)
    {
        case CryptoSignatureType::None:
            return {};

        case CryptoSignatureType::Ed25519:
            return Ed25519;

        case CryptoSignatureType::Sr25519:
            return Sr25519;

        default:
            throw std::out_of_range("Value out of range for CryptoSignatureType enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<CryptoSignatureType>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == Ed25519)
    {
        outField = CryptoSignatureType::Ed25519;
    }
    else if (value == Sr25519)
    {
        outField = CryptoSignatureType::Sr25519;
    }

    return outField.has_value();
}
