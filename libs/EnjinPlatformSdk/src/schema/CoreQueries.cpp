#include "EnjinPlatformSdk/CoreQueries.hpp"

#include "CoreUtil.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Block>>>>
enjin::platform::sdk::SendGetBlocks(
    PlatformClient& client, const GetBlocks& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Block>>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Collection>>>
enjin::platform::sdk::SendGetCollection(
    PlatformClient& client, const GetCollection& request)
{
    return client.SendRequest<GraphQlResponse<Collection>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Collection>>>>
enjin::platform::sdk::SendGetCollections(
    PlatformClient& client, const GetCollections& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Collection>>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Token>>>
enjin::platform::sdk::SendGetToken(
    PlatformClient& client, const GetToken& request)
{
    return client.SendRequest<GraphQlResponse<Token>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Token>>>>
enjin::platform::sdk::SendGetTokens(
    PlatformClient& client, const GetTokens& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Token>>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendGetTransaction(
    PlatformClient& client, const GetTransaction& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Transaction>>>>
enjin::platform::sdk::SendGetTransactions(
    PlatformClient& client, const GetTransactions& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Transaction>>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Wallet>>>
enjin::platform::sdk::SendGetWallet(
    PlatformClient& client, const GetWallet& request)
{
    return client.SendRequest<GraphQlResponse<Wallet>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendVerifyMessage(
    PlatformClient& client, const VerifyMessage& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<AccountVerified>>>
enjin::platform::sdk::SendGetAccountVerified(
    PlatformClient& client, const GetAccountVerified& request)
{
    return client.SendRequest<GraphQlResponse<AccountVerified>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<WalletLink>>>
enjin::platform::sdk::SendGetLinkingCode(
    PlatformClient& client, const GetLinkingCode& request)
{
    return client.SendRequest<GraphQlResponse<WalletLink>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<PendingEvents>>>
enjin::platform::sdk::SendGetPendingEvents(
    PlatformClient& client, const GetPendingEvents& request)
{
    return client.SendRequest<GraphQlResponse<PendingEvents>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Wallet>>>>
enjin::platform::sdk::SendGetPendingWallets(
    PlatformClient& client, const GetPendingWallets& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Wallet>>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<AccountRequest>>>
enjin::platform::sdk::SendRequestAccount(
    PlatformClient& client, const RequestAccount& request)
{
    return client.SendRequest<GraphQlResponse<AccountRequest>>(CoreUtil::CreateRequest(request));
}
