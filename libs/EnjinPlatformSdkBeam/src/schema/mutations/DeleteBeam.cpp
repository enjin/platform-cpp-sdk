#include "EnjinPlatformSdkBeam/DeleteBeam.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<DeleteBeam>;

[[maybe_unused]]
DeleteBeam::DeleteBeam()
    : RequestType("DeleteBeam", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
DeleteBeam::DeleteBeam(const DeleteBeam& other) = default;

[[maybe_unused]]
DeleteBeam::DeleteBeam(DeleteBeam&& other) noexcept = default;

DeleteBeam::~DeleteBeam() = default;

[[maybe_unused]]
DeleteBeam& DeleteBeam::SetCode(SerializableStringPtr code)
{
    return RequestType::SetVariable("code", CoreTypes::String, std::move(code));
}

DeleteBeam& DeleteBeam::operator=(const DeleteBeam& rhs) = default;

DeleteBeam& DeleteBeam::operator=(DeleteBeam&& rhs) noexcept = default;
