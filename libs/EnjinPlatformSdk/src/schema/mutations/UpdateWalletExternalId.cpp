#include "EnjinPlatformSdk/UpdateWalletExternalId.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<UpdateWalletExternalId>;

[[maybe_unused]]
UpdateWalletExternalId::UpdateWalletExternalId()
    : RequestType("UpdateWalletExternalId", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
UpdateWalletExternalId::UpdateWalletExternalId(const UpdateWalletExternalId& other) = default;

[[maybe_unused]]
UpdateWalletExternalId::UpdateWalletExternalId(UpdateWalletExternalId&& other) noexcept = default;

UpdateWalletExternalId::~UpdateWalletExternalId() = default;

[[maybe_unused]]
UpdateWalletExternalId& UpdateWalletExternalId::SetId(SerializableIntPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::Int, std::move(id));
}

[[maybe_unused]]
UpdateWalletExternalId& UpdateWalletExternalId::SetExternalId(SerializableStringPtr externalId)
{
    return RequestType::SetVariable("externalId", CoreTypes::String, std::move(externalId));
}

[[maybe_unused]]
UpdateWalletExternalId& UpdateWalletExternalId::SetNewExternalId(SerializableIntPtr newExternalId)
{
    return RequestType::SetVariable("newExternalId", CoreTypes::String, std::move(newExternalId));
}

[[maybe_unused]]
UpdateWalletExternalId& UpdateWalletExternalId::SetAccount(SerializableIntPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

UpdateWalletExternalId& UpdateWalletExternalId::operator=(const UpdateWalletExternalId& rhs) = default;

UpdateWalletExternalId& UpdateWalletExternalId::operator=(UpdateWalletExternalId&& rhs) noexcept = default;
