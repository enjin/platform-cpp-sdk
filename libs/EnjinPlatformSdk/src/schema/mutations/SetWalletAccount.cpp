#include "EnjinPlatformSdk/SetWalletAccount.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<SetWalletAccount>;

[[maybe_unused]]
SetWalletAccount::SetWalletAccount()
    : RequestType("SetWalletAccount", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
SetWalletAccount::SetWalletAccount(const SetWalletAccount& other) = default;

[[maybe_unused]]
SetWalletAccount::SetWalletAccount(SetWalletAccount&& other) noexcept = default;

SetWalletAccount::~SetWalletAccount() = default;

[[maybe_unused]]
SetWalletAccount& SetWalletAccount::SetId(SerializableIntPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::Int, std::move(id));
}

[[maybe_unused]]
SetWalletAccount& SetWalletAccount::SetExternalId(SerializableIntPtr externalId)
{
    return RequestType::SetVariable("externalId", CoreTypes::String, std::move(externalId));
}

[[maybe_unused]]
SetWalletAccount& SetWalletAccount::SetAccount(SerializableIntPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

SetWalletAccount& SetWalletAccount::operator=(const SetWalletAccount& rhs) = default;

SetWalletAccount& SetWalletAccount::operator=(SetWalletAccount&& rhs) noexcept = default;
