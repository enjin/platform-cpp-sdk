//  Copyright 2023 Enjin Pte. Ltd.
//  
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//  
//      http://www.apache.org/licenses/LICENSE-2.0
//  
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "EnjinPlatformSdk/CoreSchema.hpp"

#include "EnjinPlatformSdk/PlatformRequest.hpp"

using namespace enjin::platform::sdk;

PlatformRequestPtr CreateRequest(const IGraphQlRequest<>& request)
{
    return PlatformRequest::Builder()
        .SetPath("/graphql")
        .AddOperation(request.Compile(), request.GetVariablesWithoutTypes())
        .Build();
}

// region Queries

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Block>>>>
enjin::platform::sdk::SendGetBlocks(
    PlatformClient& client, const GetBlocks& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Block>>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Collection>>>
enjin::platform::sdk::SendGetCollection(
    PlatformClient& client, const GetCollection& request)
{
    return client.SendRequest<GraphQlResponse<Collection>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Collection>>>>
enjin::platform::sdk::SendGetCollections(
    PlatformClient& client, const GetCollections& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Collection>>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Token>>>
enjin::platform::sdk::SendGetToken(
    PlatformClient& client, const GetToken& request)
{
    return client.SendRequest<GraphQlResponse<Token>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Token>>>>
enjin::platform::sdk::SendGetTokens(
    PlatformClient& client, const GetTokens& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Token>>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendGetTransaction(
    PlatformClient& client, const GetTransaction& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Transaction>>>>
enjin::platform::sdk::SendGetTransactions(
    PlatformClient& client, const GetTransactions& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Transaction>>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Wallet>>>
enjin::platform::sdk::SendGetWallet(
    PlatformClient& client, const GetWallet& request)
{
    return client.SendRequest<GraphQlResponse<Wallet>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendVerifyMessage(
    PlatformClient& client, const VerifyMessage& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<AccountVerified>>>
enjin::platform::sdk::SendGetAccountVerified(
    PlatformClient& client, const GetAccountVerified& request)
{
    return client.SendRequest<GraphQlResponse<AccountVerified>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<WalletLink>>>
enjin::platform::sdk::SendGetLinkingCode(
    PlatformClient& client, const GetLinkingCode& request)
{
    return client.SendRequest<GraphQlResponse<WalletLink>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<PendingEvents>>>
enjin::platform::sdk::SendGetPendingEvents(
    PlatformClient& client, const GetPendingEvents& request)
{
    return client.SendRequest<GraphQlResponse<PendingEvents>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Wallet>>>>
enjin::platform::sdk::SendGetPendingWallets(
    PlatformClient& client, const GetPendingWallets& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Wallet>>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<AccountRequest>>>
enjin::platform::sdk::SendRequestAccount(
    PlatformClient& client, const RequestAccount& request)
{
    return client.SendRequest<GraphQlResponse<AccountRequest>>(CreateRequest(request));
}

// endregion Queries

// region Mutations

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendApproveCollection(
    PlatformClient& client, const ApproveCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendApproveToken(
    PlatformClient& client, const ApproveToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendBatchMint(
    PlatformClient& client, const BatchMint& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendBatchSetAttribute(
    PlatformClient& client, const BatchSetAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendBatchTransfer(
    PlatformClient& client, const BatchTransfer& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendBurn(
    PlatformClient& client, const Burn& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendCreateCollection(
    PlatformClient& client, const CreateCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendCreateToken(
    PlatformClient& client, const CreateToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendDestroyCollection(
    PlatformClient& client, const DestroyCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendFreeze(
    PlatformClient& client, const Freeze& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendMintToken(
    PlatformClient& client, const MintToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendMutateCollection(
    PlatformClient& client, const MutateCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendMutateToken(
    PlatformClient& client, const MutateToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendOperatorTransferToken(
    PlatformClient& client, const OperatorTransferToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendRemoveAllAttributes(
    PlatformClient& client, const RemoveAllAttributes& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendRemoveCollectionAttribute(
    PlatformClient& client, const RemoveCollectionAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendRemoveTokenAttribute(
    PlatformClient& client, const RemoveTokenAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendSetCollectionAttribute(
    PlatformClient& client, const SetCollectionAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendSetTokenAttribute(
    PlatformClient& client, const SetTokenAttribute& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendSimpleTransferToken(
    PlatformClient& client, const SimpleTransferToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendThaw(
    PlatformClient& client, const Thaw& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendTransferAllBalance(
    PlatformClient& client, const TransferAllBalance& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendTransferBalance(
    PlatformClient& client, const TransferBalance& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendUnapproveCollection(
    PlatformClient& client, const UnapproveCollection& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
enjin::platform::sdk::SendUnapproveToken(
    PlatformClient& client, const UnapproveToken& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendAcknowledgeEvents(
    PlatformClient& client, const AcknowledgeEvents& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendCreateWallet(
    PlatformClient& client, const CreateWallet& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Transaction>>>>
enjin::platform::sdk::SendMarkAndListPendingTransactions(
    PlatformClient& client, const MarkAndListPendingTransactions& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Transaction>>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendSetWalletAccount(
    PlatformClient& client, const SetWalletAccount& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendUpdateTransaction(
    PlatformClient& client, const UpdateTransaction& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendUpdateWalletExternalId(
    PlatformClient& client, const UpdateWalletExternalId& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::SendVerifyAccount(
    PlatformClient& client, const VerifyAccount& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(CreateRequest(request));
}

// endregion Mutations
