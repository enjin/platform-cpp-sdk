#include "EnjinPlatformSdkFuelTanks/RemoveAccount.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<RemoveAccount, TransactionFragment>;

[[maybe_unused]]
RemoveAccount::RemoveAccount()
    : RequestType("RemoveAccount", GraphQlRequestType::Mutation),
      HasIdempotencyKey<RemoveAccount>()
{
}

[[maybe_unused]]
RemoveAccount::RemoveAccount(const RemoveAccount& other) = default;

[[maybe_unused]]
RemoveAccount::RemoveAccount(RemoveAccount&& other) noexcept = default;

RemoveAccount::~RemoveAccount() = default;

[[maybe_unused]]
RemoveAccount& RemoveAccount::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
RemoveAccount& RemoveAccount::SetUserId(SerializableStringPtr userId)
{
    return RequestType::SetVariable("userId", CoreTypes::String, std::move(userId));
}

RemoveAccount& RemoveAccount::operator=(const RemoveAccount& rhs) = default;

RemoveAccount& RemoveAccount::operator=(RemoveAccount&& rhs) noexcept = default;
