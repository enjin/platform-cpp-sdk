#include "EnjinPlatformSdk/GetPendingWallets.hpp"

#include "EnjinPlatformSdk/GraphQlRequestType.hpp"

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetPendingWallets, WalletConnectionFragment>;

[[maybe_unused]]
GetPendingWallets::GetPendingWallets()
    : RequestType("GetPendingWallets", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetPendingWallets::GetPendingWallets(const GetPendingWallets& other) = default;

[[maybe_unused]]
GetPendingWallets::GetPendingWallets(GetPendingWallets&& other) noexcept = default;

GetPendingWallets::~GetPendingWallets() = default;

GetPendingWallets& GetPendingWallets::operator=(const GetPendingWallets& rhs) = default;

GetPendingWallets& GetPendingWallets::operator=(GetPendingWallets&& rhs) noexcept = default;
