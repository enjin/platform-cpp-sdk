#include "EnjinPlatformSdk/GetWallet.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetWallet, WalletFragment>;

[[maybe_unused]]
GetWallet::GetWallet()
    : RequestType("GetWallet", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetWallet::GetWallet(const GetWallet& other) = default;

[[maybe_unused]]
GetWallet::GetWallet(GetWallet&& other) noexcept = default;

GetWallet::~GetWallet() = default;

[[maybe_unused]]
GetWallet& GetWallet::SetId(SerializableIntPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::Int, std::move(id));
}

[[maybe_unused]]
GetWallet& GetWallet::SetExternalId(SerializableStringPtr externalId)
{
    return RequestType::SetVariable("externalId", CoreTypes::String, std::move(externalId));
}

[[maybe_unused]]
GetWallet& GetWallet::SetVerificationId(SerializableStringPtr verificationId)
{
    return RequestType::SetVariable("verificationId", CoreTypes::String, std::move(verificationId));
}

[[maybe_unused]]
GetWallet& GetWallet::SetAccount(SerializableStringPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

GetWallet& GetWallet::operator=(const GetWallet& rhs) = default;

GetWallet& GetWallet::operator=(GetWallet&& rhs) noexcept = default;
