#ifndef ENJINPLATFORMSDKFUELTANKS_FUELTANKSMUTATIONS_HPP
#define ENJINPLATFORMSDKFUELTANKS_FUELTANKSMUTATIONS_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include "EnjinPlatformSdk/Transaction.hpp"
#include "EnjinPlatformSdkFuelTanks/AddAccount.hpp"
#include "EnjinPlatformSdkFuelTanks/BatchAddAccount.hpp"
#include "EnjinPlatformSdkFuelTanks/BatchRemoveAccount.hpp"
#include "EnjinPlatformSdkFuelTanks/CreateFuelTank.hpp"
#include "EnjinPlatformSdkFuelTanks/DestroyFuelTank.hpp"
#include "EnjinPlatformSdkFuelTanks/Dispatch.hpp"
#include "EnjinPlatformSdkFuelTanks/DispatchAndTouch.hpp"
#include "EnjinPlatformSdkFuelTanks/InsertRuleSet.hpp"
#include "EnjinPlatformSdkFuelTanks/MutateFuelTank.hpp"
#include "EnjinPlatformSdkFuelTanks/RemoveAccount.hpp"
#include "EnjinPlatformSdkFuelTanks/RemoveAccountRuleData.hpp"
#include "EnjinPlatformSdkFuelTanks/RemoveRuleSet.hpp"
#include "EnjinPlatformSdkFuelTanks/ScheduleMutateFreeze.hpp"
#include "EnjinPlatformSdkFuelTanks/SetConsumption.hpp"
#include <future>

namespace enjin::platform::sdk::fuelTanks
{
/// \brief Sends a AddAccount request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendAddAccount(
    PlatformClient& client, const AddAccount& request);

/// \brief Sends a BatchAddAccount request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendBatchAddAccount(
    PlatformClient& client, const BatchAddAccount& request);

/// \brief Sends a BatchRemoveAccount request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendBatchRemoveAccount(
    PlatformClient& client, const BatchRemoveAccount& request);

/// \brief Sends a CreateFuelTank request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendCreateFuelTank(
    PlatformClient& client, const CreateFuelTank& request);

/// \brief Sends a DestroyFuelTank request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendDestroyFuelTank(
    PlatformClient& client, const DestroyFuelTank& request);

/// \brief Sends a Dispatch request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendDispatch(
    PlatformClient& client, const Dispatch& request);

/// \brief Sends a DispatchAndTouch request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendDispatchAndTouch(
    PlatformClient& client, const DispatchAndTouch& request);

/// \brief Sends a InsertRuleSet request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendInsertRuleSet(
    PlatformClient& client, const InsertRuleSet& request);

/// \brief Sends a MutateFuelTank request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendMutateFuelTank(
    PlatformClient& client, const MutateFuelTank& request);

/// \brief Sends a RemoveAccount request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendRemoveAccount(
    PlatformClient& client, const RemoveAccount& request);

/// \brief Sends a RemoveAccountRuleData request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendRemoveAccountRuleData(
    PlatformClient& client, const RemoveAccountRuleData& request);

/// \brief Sends a RemoveRuleSet request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendRemoveRuleSet(
    PlatformClient& client, const RemoveRuleSet& request);

/// \brief Sends a ScheduleMutateFreeze request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendScheduleMutateFreeze(
    PlatformClient& client, const ScheduleMutateFreeze& request);

/// \brief Sends a SetConsumption request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKFUELTANKS_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>> SendSetConsumption(
    PlatformClient& client, const SetConsumption& request);
}

#endif //ENJINPLATFORMSDKFUELTANKS_FUELTANKSMUTATIONS_HPP
