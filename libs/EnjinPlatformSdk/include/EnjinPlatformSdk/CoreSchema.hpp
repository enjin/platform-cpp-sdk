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

#ifndef ENJINPLATFORMSDK_CORESCHEMA_HPP
#define ENJINPLATFORMSDK_CORESCHEMA_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AccountRequest.hpp"
#include "EnjinPlatformSdk/AccountVerified.hpp"
#include "EnjinPlatformSdk/AcknowledgeEvents.hpp"
#include "EnjinPlatformSdk/ApproveCollection.hpp"
#include "EnjinPlatformSdk/ApproveToken.hpp"
#include "EnjinPlatformSdk/BatchMint.hpp"
#include "EnjinPlatformSdk/BatchSetAttribute.hpp"
#include "EnjinPlatformSdk/BatchTransfer.hpp"
#include "EnjinPlatformSdk/Block.hpp"
#include "EnjinPlatformSdk/Burn.hpp"
#include "EnjinPlatformSdk/Collection.hpp"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/CreateCollection.hpp"
#include "EnjinPlatformSdk/CreateToken.hpp"
#include "EnjinPlatformSdk/CreateWallet.hpp"
#include "EnjinPlatformSdk/DestroyCollection.hpp"
#include "EnjinPlatformSdk/Freeze.hpp"
#include "EnjinPlatformSdk/GetAccountVerified.hpp"
#include "EnjinPlatformSdk/GetBlocks.hpp"
#include "EnjinPlatformSdk/GetCollection.hpp"
#include "EnjinPlatformSdk/GetCollections.hpp"
#include "EnjinPlatformSdk/GetLinkingCode.hpp"
#include "EnjinPlatformSdk/GetPendingEvents.hpp"
#include "EnjinPlatformSdk/GetPendingWallets.hpp"
#include "EnjinPlatformSdk/GetToken.hpp"
#include "EnjinPlatformSdk/GetTokens.hpp"
#include "EnjinPlatformSdk/GetTransaction.hpp"
#include "EnjinPlatformSdk/GetTransactions.hpp"
#include "EnjinPlatformSdk/GetWallet.hpp"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include "EnjinPlatformSdk/MarkAndListPendingTransactions.hpp"
#include "EnjinPlatformSdk/MintToken.hpp"
#include "EnjinPlatformSdk/MutateCollection.hpp"
#include "EnjinPlatformSdk/MutateToken.hpp"
#include "EnjinPlatformSdk/OperatorTransferToken.hpp"
#include "EnjinPlatformSdk/PendingEvents.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include "EnjinPlatformSdk/RemoveAllAttributes.hpp"
#include "EnjinPlatformSdk/RemoveCollectionAttribute.hpp"
#include "EnjinPlatformSdk/RemoveTokenAttribute.hpp"
#include "EnjinPlatformSdk/RequestAccount.hpp"
#include "EnjinPlatformSdk/SetCollectionAttribute.hpp"
#include "EnjinPlatformSdk/SetTokenAttribute.hpp"
#include "EnjinPlatformSdk/SetWalletAccount.hpp"
#include "EnjinPlatformSdk/SimpleTransferToken.hpp"
#include "EnjinPlatformSdk/Thaw.hpp"
#include "EnjinPlatformSdk/Token.hpp"
#include "EnjinPlatformSdk/Transaction.hpp"
#include "EnjinPlatformSdk/TransferAllBalance.hpp"
#include "EnjinPlatformSdk/TransferBalance.hpp"
#include "EnjinPlatformSdk/UnapproveCollection.hpp"
#include "EnjinPlatformSdk/UnapproveToken.hpp"
#include "EnjinPlatformSdk/UpdateTransaction.hpp"
#include "EnjinPlatformSdk/UpdateWalletExternalId.hpp"
#include "EnjinPlatformSdk/VerifyAccount.hpp"
#include "EnjinPlatformSdk/VerifyMessage.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdk/WalletLink.hpp"
#include <future>

namespace enjin::platform::sdk
{
// region Queries

/// \brief Sends a GetBlocks request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Block>>>> SendGetBlocks(
    PlatformClient& client, const GetBlocks& request);

/// \brief Sends a GetCollection request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Collection>>> SendGetCollection(
    PlatformClient& client, const GetCollection& request);

/// \brief Sends a GetCollections request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Collection>>>> SendGetCollections(
    PlatformClient& client, const GetCollections& request);

/// \brief Sends a GetToken request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Token>>> SendGetToken(
    PlatformClient& client, const GetToken& request);

/// \brief Sends a GetTokens request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Token>>>> SendGetTokens(
    PlatformClient& client, const GetTokens& request);

/// \brief Sends a GetTransaction request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendGetTransaction(
    PlatformClient& client, const GetTransaction& request);

/// \brief Sends a GetTransactions request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Transaction>>>> SendGetTransactions(
    PlatformClient& client, const GetTransactions& request);

/// \brief Sends a GetWallet request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Wallet>>> SendGetWallet(
    PlatformClient& client, const GetWallet& request);

/// \brief Sends a VerifyMessage request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendVerifyMessage(
    PlatformClient& client, const VerifyMessage& request);

/// \brief Sends a GetAccountVerified request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<AccountVerified>>> SendGetAccountVerified(
    PlatformClient& client, const GetAccountVerified& request);

/// \brief Sends a GetLinkingCode request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<WalletLink>>> SendGetLinkingCode(
    PlatformClient& client, const GetLinkingCode& request);

/// \brief Sends a GetPendingEvents request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<PendingEvents>>> SendGetPendingEvents(
    PlatformClient& client, const GetPendingEvents& request);

/// \brief Sends a GetPendingWallets request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Wallet>>>> SendGetPendingWallets(
    PlatformClient& client, const GetPendingWallets& request);

/// \brief Sends a RequestAccount request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<AccountRequest>>> SendRequestAccount(
    PlatformClient& client, const RequestAccount& request);

// endregion Queries

// region Mutations

/// \brief Sends a ApproveCollection request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendApproveCollection(
    PlatformClient& client, const ApproveCollection& request);

/// \brief Sends a ApproveToken request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendApproveToken(
    PlatformClient& client, const ApproveToken& request);

/// \brief Sends a BatchMint request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendBatchMint(
    PlatformClient& client, const BatchMint& request);

/// \brief Sends a BatchSetAttribute request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendBatchSetAttribute(
    PlatformClient& client, const BatchSetAttribute& request);

/// \brief Sends a BatchTransfer request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendBatchTransfer(
    PlatformClient& client, const BatchTransfer& request);

/// \brief Sends a Burn request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendBurn(
    PlatformClient& client, const Burn& request);

/// \brief Sends a CreateCollection request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendCreateCollection(
    PlatformClient& client, const CreateCollection& request);

/// \brief Sends a CreateToken request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendCreateToken(
    PlatformClient& client, const CreateToken& request);

/// \brief Sends a DestroyCollection request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendDestroyCollection(
    PlatformClient& client, const DestroyCollection& request);

/// \brief Sends a Freeze request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendFreeze(
    PlatformClient& client, const Freeze& request);

/// \brief Sends a MintToken request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendMintToken(
    PlatformClient& client, const MintToken& request);

/// \brief Sends a MutateCollection request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendMutateCollection(
    PlatformClient& client, const MutateCollection& request);

/// \brief Sends a MutateToken request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendMutateToken(
    PlatformClient& client, const MutateToken& request);

/// \brief Sends a OperatorTransferToken request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendOperatorTransferToken(
    PlatformClient& client, const OperatorTransferToken& request);

/// \brief Sends a RemoveAllAttributes request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendRemoveAllAttributes(
    PlatformClient& client, const RemoveAllAttributes& request);

/// \brief Sends a RemoveCollectionAttribute request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendRemoveCollectionAttribute(
    PlatformClient& client, const RemoveCollectionAttribute& request);

/// \brief Sends a RemoveTokenAttribute request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendRemoveTokenAttribute(
    PlatformClient& client, const RemoveTokenAttribute& request);

/// \brief Sends a SetCollectionAttribute request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendSetCollectionAttribute(
    PlatformClient& client, const SetCollectionAttribute& request);

/// \brief Sends a SetTokenAttribute request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendSetTokenAttribute(
    PlatformClient& client, const SetTokenAttribute& request);

/// \brief Sends a SimpleTransferToken request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendSimpleTransferToken(
    PlatformClient& client, const SimpleTransferToken& request);

/// \brief Sends a Thaw request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendThaw(
    PlatformClient& client, const Thaw& request);

/// \brief Sends a TransferAllBalance request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendTransferAllBalance(
    PlatformClient& client, const TransferAllBalance& request);

/// \brief Sends a TransferBalance request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendTransferBalance(
    PlatformClient& client, const TransferBalance& request);

/// \brief Sends a UnapproveCollection request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendUnapproveCollection(
    PlatformClient& client, const UnapproveCollection& request);

/// \brief Sends a UnapproveToken request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendUnapproveToken(
    PlatformClient& client, const UnapproveToken& request);

/// \brief Sends an AcknowledgeEvents request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendAcknowledgeEvents(
    PlatformClient& client, const AcknowledgeEvents& request);

/// \brief Sends a CreateWallet request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendCreateWallet(
    PlatformClient& client, const CreateWallet& request);

/// \brief Sends a MarkAndListPendingTransactions request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Transaction>>>> SendMarkAndListPendingTransactions(
    PlatformClient& client, const MarkAndListPendingTransactions& request);

/// \brief Sends a SetWalletAccount request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendSetWalletAccount(
    PlatformClient& client, const SetWalletAccount& request);

/// \brief Sends an UpdateTransaction request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendUpdateTransaction(
    PlatformClient& client, const UpdateTransaction& request);

/// \brief Sends an UpdateWalletExternalId request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendUpdateWalletExternalId(
    PlatformClient& client, const UpdateWalletExternalId& request);

/// \brief Sends a VerifyAccount request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendVerifyAccount(
    PlatformClient& client, const VerifyAccount& request);

// endregion Mutations
}

#endif //ENJINPLATFORMSDK_CORESCHEMA_HPP
