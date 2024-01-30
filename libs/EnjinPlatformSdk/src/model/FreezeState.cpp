#include "EnjinPlatformSdk/FreezeState.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char Permanent[] = "PERMANENT";
constexpr char Temporary[] = "TEMPORARY";
constexpr char Never[] = "NEVER";

std::string enjin::platform::sdk::ToString(const FreezeState value)
{
    switch (value)
    {
        case FreezeState::Permanent:
            return Permanent;

        case FreezeState::Temporary:
            return Temporary;

        case FreezeState::Never:
            return Never;

        default:
            throw std::out_of_range("Value out of range for FreezeState enum");
    }
}

bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<FreezeState>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == Permanent)
    {
        outField = FreezeState::Permanent;
    }
    else if (value == Temporary)
    {
        outField = FreezeState::Temporary;
    }
    else if (value == Never)
    {
        outField = FreezeState::Never;
    }

    return outField.has_value();
}
