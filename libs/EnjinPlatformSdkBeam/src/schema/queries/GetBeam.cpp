#include "EnjinPlatformSdkBeam/GetBeam.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<GetBeam, BeamFragment>;

[[maybe_unused]]
GetBeam::GetBeam()
    : RequestType("GetBeam", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetBeam::GetBeam(const GetBeam& other) = default;

[[maybe_unused]]
GetBeam::GetBeam(GetBeam&& other) noexcept = default;

GetBeam::~GetBeam() = default;

[[maybe_unused]]
GetBeam& GetBeam::SetCode(SerializableStringPtr code)
{
    return RequestType::SetVariable("code", CoreTypes::String, std::move(code));
}

[[maybe_unused]]
GetBeam& GetBeam::SetAccount(SerializableStringPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

GetBeam& GetBeam::operator=(const GetBeam& rhs) = default;

GetBeam& GetBeam::operator=(GetBeam&& rhs) noexcept = default;
