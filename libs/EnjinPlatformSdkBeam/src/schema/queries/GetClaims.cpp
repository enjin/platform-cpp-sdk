#include "EnjinPlatformSdkBeam/GetClaims.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkBeam/BeamTypes.hpp"
#include <memory>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<GetClaims, BeamClaimConnectionFragment>;

[[maybe_unused]]
GetClaims::GetClaims()
    : RequestType("GetClaims", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetClaims::GetClaims(const GetClaims& other) = default;

[[maybe_unused]]
GetClaims::GetClaims(GetClaims&& other) noexcept = default;

GetClaims::~GetClaims() = default;

[[maybe_unused]]
GetClaims& GetClaims::SetIds(SerializableStringArrayPtr ids)
{
    return RequestType::SetVariable("ids", CoreTypes::StringArray, std::move(ids));
}

[[maybe_unused]]
GetClaims& GetClaims::SetCodes(SerializableStringArrayPtr codes)
{
    return RequestType::SetVariable("codes", CoreTypes::StringArray, std::move(codes));
}

[[maybe_unused]]
GetClaims& GetClaims::SetAccounts(SerializableStringArrayPtr accounts)
{
    return RequestType::SetVariable("accounts", CoreTypes::StringArray, std::move(accounts));
}

[[maybe_unused]]
GetClaims& GetClaims::SetStates(const std::vector<ClaimStatus>& states)
{
    SerializableStringArrayPtr arr = std::make_shared<SerializableStringArray>();

    for (const ClaimStatus state : states)
    {
        std::string s = enjin::platform::sdk::beam::ToString(state);
        arr->PushBack(SerializableString(std::move(s)));
    }

    return RequestType::SetVariable("states", BeamTypes::ClaimStatusArray, std::move(arr));
}

GetClaims& GetClaims::operator=(const GetClaims& rhs) = default;

GetClaims& GetClaims::operator=(GetClaims&& rhs) noexcept = default;
