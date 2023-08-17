#include "EnjinPlatformSdk/CoreMutations.hpp"

#include "CoreUtil.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendApproveCollection(
    PlatformClient& client, const ApproveCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendApproveToken(
    PlatformClient& client, const ApproveToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendBatchMint(
    PlatformClient& client, const BatchMint& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendBatchSetAttribute(
    PlatformClient& client, const BatchSetAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendBatchTransfer(
    PlatformClient& client, const BatchTransfer& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendBurn(
    PlatformClient& client, const Burn& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendCreateCollection(
    PlatformClient& client, const CreateCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendCreateToken(
    PlatformClient& client, const CreateToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendDestroyCollection(
    PlatformClient& client, const DestroyCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendFreeze(
    PlatformClient& client, const Freeze& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendMintToken(
    PlatformClient& client, const MintToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendMutateCollection(
    PlatformClient& client, const MutateCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendMutateToken(
    PlatformClient& client, const MutateToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendOperatorTransferToken(
    PlatformClient& client, const OperatorTransferToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendRemoveAllAttributes(
    PlatformClient& client, const RemoveAllAttributes& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendRemoveCollectionAttribute(
    PlatformClient& client, const RemoveCollectionAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendRemoveTokenAttribute(
    PlatformClient& client, const RemoveTokenAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendSetCollectionAttribute(
    PlatformClient& client, const SetCollectionAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendSetTokenAttribute(
    PlatformClient& client, const SetTokenAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendSimpleTransferToken(
    PlatformClient& client, const SimpleTransferToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendThaw(
    PlatformClient& client, const Thaw& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendTransferAllBalance(
    PlatformClient& client, const TransferAllBalance& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendTransferBalance(
    PlatformClient& client, const TransferBalance& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendUnapproveCollection(
    PlatformClient& client, const UnapproveCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendUnapproveToken(
    PlatformClient& client, const UnapproveToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendAcknowledgeEvents(
    PlatformClient& client, const AcknowledgeEvents& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendCreateWallet(
    PlatformClient& client, const CreateWallet& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Transaction>>>>
enjin::platform::sdk::SendMarkAndListPendingTransactions(
    PlatformClient& client, const MarkAndListPendingTransactions& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Transaction>>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendSetWalletAccount(
    PlatformClient& client, const SetWalletAccount& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendUpdateTransaction(
    PlatformClient& client, const UpdateTransaction& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendUpdateWalletExternalId(
    PlatformClient& client, const UpdateWalletExternalId& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CoreUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendVerifyAccount(
    PlatformClient& client, const VerifyAccount& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CoreUtil::CreateRequest(request));
}
