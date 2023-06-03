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

#ifndef ENJINPLATFORMSDK_COREQUERIES_HPP
#define ENJINPLATFORMSDK_COREQUERIES_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AccountRequest.hpp"
#include "EnjinPlatformSdk/AccountVerified.hpp"
#include "EnjinPlatformSdk/Block.hpp"
#include "EnjinPlatformSdk/Collection.hpp"
#include "EnjinPlatformSdk/Connection.hpp"
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
#include "EnjinPlatformSdk/PendingEvents.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include "EnjinPlatformSdk/RequestAccount.hpp"
#include "EnjinPlatformSdk/Thaw.hpp"
#include "EnjinPlatformSdk/Token.hpp"
#include "EnjinPlatformSdk/Transaction.hpp"
#include "EnjinPlatformSdk/VerifyMessage.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdk/WalletLink.hpp"
#include <future>

namespace enjin::platform::sdk
{
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
}

#endif //ENJINPLATFORMSDK_COREQUERIES_HPP
