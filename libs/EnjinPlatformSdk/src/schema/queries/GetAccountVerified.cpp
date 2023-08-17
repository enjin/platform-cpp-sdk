#include "EnjinPlatformSdk/GetAccountVerified.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetAccountVerified, AccountVerifiedFragment>;

[[maybe_unused]]
GetAccountVerified::GetAccountVerified()
    : RequestType("GetAccountVerified", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetAccountVerified::GetAccountVerified(const GetAccountVerified& other) = default;

[[maybe_unused]]
GetAccountVerified::GetAccountVerified(GetAccountVerified&& other) noexcept = default;

GetAccountVerified::~GetAccountVerified() = default;

[[maybe_unused]]
GetAccountVerified& GetAccountVerified::SetVerificationId(SerializableStringPtr verificationId)
{
    return RequestType::SetVariable("verificationId", CoreTypes::String, std::move(verificationId));
}

[[maybe_unused]]
GetAccountVerified& GetAccountVerified::SetAccount(SerializableStringPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

GetAccountVerified& GetAccountVerified::operator=(const GetAccountVerified& rhs) = default;

GetAccountVerified& GetAccountVerified::operator=(GetAccountVerified&& rhs) noexcept = default;
