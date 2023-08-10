#include "EnjinPlatformSdkFuelTanks/BatchAddAccount.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<BatchAddAccount, TransactionFragment>;

[[maybe_unused]]
BatchAddAccount::BatchAddAccount()
    : RequestType("BatchAddAccount", GraphQlRequestType::Mutation),
      HasIdempotencyKey<BatchAddAccount>()
{
}

[[maybe_unused]]
BatchAddAccount::BatchAddAccount(const BatchAddAccount& other) = default;

[[maybe_unused]]
BatchAddAccount::BatchAddAccount(BatchAddAccount&& other) noexcept = default;

BatchAddAccount::~BatchAddAccount() = default;

[[maybe_unused]]
BatchAddAccount& BatchAddAccount::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
BatchAddAccount& BatchAddAccount::SetUserIds(SerializableStringArrayPtr userIds)
{
    return RequestType::SetVariable("userIds", CoreTypes::StringArray, std::move(userIds));
}

BatchAddAccount& BatchAddAccount::operator=(const BatchAddAccount& rhs) = default;

BatchAddAccount& BatchAddAccount::operator=(BatchAddAccount&& rhs) noexcept = default;
