#include "EnjinPlatformSdk/GetLinkingCode.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetLinkingCode, WalletLinkFragment>;

[[maybe_unused]]
GetLinkingCode::GetLinkingCode()
    : RequestType("GetLinkingCode", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetLinkingCode::GetLinkingCode(const GetLinkingCode& other) = default;

[[maybe_unused]]
GetLinkingCode::GetLinkingCode(GetLinkingCode&& other) noexcept = default;

GetLinkingCode::~GetLinkingCode() = default;

[[maybe_unused]]
GetLinkingCode& GetLinkingCode::SetExternalId(SerializableStringPtr externalId)
{
    return RequestType::SetVariable("externalId", CoreTypes::String, std::move(externalId));
}

GetLinkingCode& GetLinkingCode::operator=(const GetLinkingCode& rhs) = default;

GetLinkingCode& GetLinkingCode::operator=(GetLinkingCode&& rhs) noexcept = default;
