#include "EnjinPlatformSdkBeam/BeamFlag.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

constexpr char Paused[] = "PAUSED";
constexpr char SingleUse[] = "SINGLE_USE";
constexpr char Prunable[] = "PRUNABLE";

[[maybe_unused]]
std::string enjin::platform::sdk::beam::ToString(const BeamFlag value)
{
    switch (value)
    {
        case BeamFlag::None:
            return {};

        case BeamFlag::Paused:
            return Paused;

        case BeamFlag::SingleUse:
            return SingleUse;

        case BeamFlag::Prunable:
            return Prunable;

        default:
            throw std::out_of_range("Value out of range for BeamFlag enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::beam::TryGetField(const JsonValue& json,
                                             const std::string& key,
                                             std::optional<BeamFlag>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == Paused)
    {
        outField = BeamFlag::Paused;
    }
    else if (value == SingleUse)
    {
        outField = BeamFlag::SingleUse;
    }
    else if (value == Prunable)
    {
        outField = BeamFlag::Prunable;
    }

    return outField.has_value();
}

[[maybe_unused]]
bool enjin::platform::sdk::beam::TryGetField(const JsonValue& json,
                                             const std::string& key,
                                             std::optional<std::vector<BeamFlag>>& outField)
{
    outField.reset();

    std::vector<JsonValue> array;

    if (!json.TryGetArrayField(key, array))
    {
        return false;
    }

    std::vector<BeamFlag> value;

    for (const JsonValue& el : array)
    {
        if (!el.IsString())
        {
            continue;
        }

        const std::string s = el.GetString();
        if (s == Paused)
        {
            value.push_back(BeamFlag::Paused);
        }
        else if (s == SingleUse)
        {
            value.push_back(BeamFlag::SingleUse);
        }
        else if (s == Prunable)
        {
            value.push_back(BeamFlag::Prunable);
        }
    }

    outField = std::move(value);

    return true;
}
