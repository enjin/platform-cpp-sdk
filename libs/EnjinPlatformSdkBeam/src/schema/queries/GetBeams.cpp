#include "EnjinPlatformSdkBeam/GetBeams.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<GetBeams, BeamConnectionFragment>;

[[maybe_unused]]
GetBeams::GetBeams()
    : RequestType("GetBeams", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetBeams::GetBeams(const GetBeams& other) = default;

[[maybe_unused]]
GetBeams::GetBeams(GetBeams&& other) noexcept = default;

GetBeams::~GetBeams() = default;

[[maybe_unused]]
GetBeams& GetBeams::SetCodes(SerializableStringArrayPtr codes)
{
    return RequestType::SetVariable("codes", CoreTypes::StringArray, std::move(codes));
}

[[maybe_unused]]
GetBeams& GetBeams::SetNames(SerializableStringArrayPtr names)
{
    return RequestType::SetVariable("names", CoreTypes::StringArray, std::move(names));
}

GetBeams& GetBeams::operator=(const GetBeams& rhs) = default;

GetBeams& GetBeams::operator=(GetBeams&& rhs) noexcept = default;
