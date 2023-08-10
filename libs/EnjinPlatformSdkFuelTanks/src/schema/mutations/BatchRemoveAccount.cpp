#include "EnjinPlatformSdkFuelTanks/BatchRemoveAccount.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<BatchRemoveAccount, TransactionFragment>;

[[maybe_unused]]
BatchRemoveAccount::BatchRemoveAccount()
    : RequestType("BatchRemoveAccount", GraphQlRequestType::Mutation),
      HasIdempotencyKey<BatchRemoveAccount>()
{
}

[[maybe_unused]]
BatchRemoveAccount::BatchRemoveAccount(const BatchRemoveAccount& other) = default;

[[maybe_unused]]
BatchRemoveAccount::BatchRemoveAccount(BatchRemoveAccount&& other) noexcept = default;

BatchRemoveAccount::~BatchRemoveAccount() = default;

[[maybe_unused]]
BatchRemoveAccount& BatchRemoveAccount::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
BatchRemoveAccount& BatchRemoveAccount::SetUserIds(SerializableStringArrayPtr userIds)
{
    return RequestType::SetVariable("userIds", CoreTypes::StringArray, std::move(userIds));
}

BatchRemoveAccount& BatchRemoveAccount::operator=(const BatchRemoveAccount& rhs) = default;

BatchRemoveAccount& BatchRemoveAccount::operator=(BatchRemoveAccount&& rhs) noexcept = default;
