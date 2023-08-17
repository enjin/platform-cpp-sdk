#include "EnjinPlatformSdk/CreateWallet.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<CreateWallet>;

[[maybe_unused]]
CreateWallet::CreateWallet()
    : RequestType("CreateWallet", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
CreateWallet::CreateWallet(const CreateWallet& other) = default;

[[maybe_unused]]
CreateWallet::CreateWallet(CreateWallet&& other) noexcept = default;

CreateWallet::~CreateWallet() = default;

[[maybe_unused]]
CreateWallet& CreateWallet::SetExternalId(SerializableStringPtr externalId)
{
    return RequestType::SetVariable("externalId", CoreTypes::String, std::move(externalId));
}

CreateWallet& CreateWallet::operator=(const CreateWallet& rhs) = default;

CreateWallet& CreateWallet::operator=(CreateWallet&& rhs) noexcept = default;
