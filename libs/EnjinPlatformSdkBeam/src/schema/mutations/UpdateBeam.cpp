#include "EnjinPlatformSdkBeam/UpdateBeam.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkBeam/BeamTypes.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<UpdateBeam>;

[[maybe_unused]]
UpdateBeam::UpdateBeam()
    : RequestType("UpdateBeam", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
UpdateBeam::UpdateBeam(const UpdateBeam& other) = default;

[[maybe_unused]]
UpdateBeam::UpdateBeam(UpdateBeam&& other) noexcept = default;

UpdateBeam::~UpdateBeam() = default;

[[maybe_unused]]
UpdateBeam& UpdateBeam::SetCode(SerializableStringPtr code)
{
    return RequestType::SetVariable("code", CoreTypes::String, std::move(code));
}

[[maybe_unused]]
UpdateBeam& UpdateBeam::SetFlags(std::shared_ptr<SerializableArray<BeamFlagInputType>> flags)
{
    return RequestType::SetVariable("flags", BeamTypes::BeamFlagInputTypeArray, std::move(flags));
}

UpdateBeam& UpdateBeam::operator=(const UpdateBeam& rhs) = default;

UpdateBeam& UpdateBeam::operator=(UpdateBeam&& rhs) noexcept = default;
