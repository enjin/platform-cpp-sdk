#include "EnjinPlatformSdkFuelTanks/AddAccount.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<AddAccount, TransactionFragment>;

[[maybe_unused]]
AddAccount::AddAccount()
    : RequestType("AddAccount", GraphQlRequestType::Mutation),
      HasIdempotencyKey<AddAccount>()
{
}

[[maybe_unused]]
AddAccount::AddAccount(const AddAccount& other) = default;

[[maybe_unused]]
AddAccount::AddAccount(AddAccount&& other) noexcept = default;

AddAccount::~AddAccount() = default;

[[maybe_unused]]
AddAccount& AddAccount::SetTankId(SerializableStringPtr tankId)
{
    return RequestType::SetVariable("tankId", CoreTypes::String, std::move(tankId));
}

[[maybe_unused]]
AddAccount& AddAccount::SetUserId(SerializableStringPtr userId)
{
    return RequestType::SetVariable("userId", CoreTypes::String, std::move(userId));
}

AddAccount& AddAccount::operator=(const AddAccount& rhs) = default;

AddAccount& AddAccount::operator=(AddAccount&& rhs) noexcept = default;
