#include "EnjinPlatformSdkBeam/GetSingleUseCodes.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<GetSingleUseCodes, BeamClaimConnectionFragment>;

[[maybe_unused]]
GetSingleUseCodes::GetSingleUseCodes()
    : RequestType("GetSingleUseCodes", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetSingleUseCodes::GetSingleUseCodes(const GetSingleUseCodes& other) = default;

[[maybe_unused]]
GetSingleUseCodes::GetSingleUseCodes(GetSingleUseCodes&& other) noexcept = default;

GetSingleUseCodes::~GetSingleUseCodes() = default;

[[maybe_unused]]
GetSingleUseCodes& GetSingleUseCodes::SetCode(SerializableStringPtr code)
{
    return RequestType::SetVariable("code", CoreTypes::String, std::move(code));
}

GetSingleUseCodes& GetSingleUseCodes::operator=(const GetSingleUseCodes& rhs) = default;

GetSingleUseCodes& GetSingleUseCodes::operator=(GetSingleUseCodes&& rhs) noexcept = default;
