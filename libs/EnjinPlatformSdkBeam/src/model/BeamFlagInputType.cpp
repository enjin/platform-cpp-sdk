#include "EnjinPlatformSdkBeam/BeamFlagInputType.hpp"

#include "EnjinPlatformSdk/SerializableString.hpp"
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

[[maybe_unused]]
BeamFlagInputType::BeamFlagInputType() = default;

[[maybe_unused]]
BeamFlagInputType::BeamFlagInputType(const BeamFlagInputType& other) = default;

[[maybe_unused]]
BeamFlagInputType::BeamFlagInputType(BeamFlagInputType&& other) noexcept = default;

BeamFlagInputType::~BeamFlagInputType() = default;

[[maybe_unused]]
BeamFlagInputType& BeamFlagInputType::SetFlag(const BeamFlag flag)
{
    constexpr char key[] = "flag";

    if (flag == BeamFlag::None)
    {
        return RemoveParameter(key);
    }

    std::string s = enjin::platform::sdk::beam::ToString(flag);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return SetParameter(key, std::move(sPtr));
}

[[maybe_unused]]
BeamFlagInputType& BeamFlagInputType::SetEnabled(SerializableBoolPtr enabled)
{
    return SetParameter("enabled", std::move(enabled));
}

BeamFlagInputType& BeamFlagInputType::operator=(const BeamFlagInputType& rhs) = default;

BeamFlagInputType& BeamFlagInputType::operator=(BeamFlagInputType&& rhs) noexcept = default;
