#include "EnjinPlatformSdkFuelTanks/FuelTanksMutations.hpp"

#include "FuelTanksUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendAddAccount(PlatformClient& client, const AddAccount& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendBatchAddAccount(PlatformClient& client, const BatchAddAccount& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendBatchRemoveAccount(PlatformClient& client, const BatchRemoveAccount& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendCreateFuelTank(PlatformClient& client, const CreateFuelTank& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendDestroyFuelTank(PlatformClient& client, const DestroyFuelTank& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendDispatch(PlatformClient& client, const Dispatch& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendDispatchAndTouch(PlatformClient& client, const DispatchAndTouch& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendInsertRuleSet(PlatformClient& client, const InsertRuleSet& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendMutateFuelTank(PlatformClient& client, const MutateFuelTank& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendRemoveAccount(PlatformClient& client, const RemoveAccount& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendRemoveAccountRuleData(PlatformClient& client, const RemoveAccountRuleData& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendRemoveRuleSet(PlatformClient& client, const RemoveRuleSet& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendScheduleMutateFreeze(PlatformClient& client, const ScheduleMutateFreeze& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Transaction>>>
SendSetConsumption(PlatformClient& client, const SetConsumption& request)
{
    return client.SendRequest<GraphQlResponse<Transaction>>(FuelTanksUtil::CreateRequest(request));
}
