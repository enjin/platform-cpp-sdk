#include "EnjinPlatformSdk/CreateToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<CreateToken, TransactionFragment>;

[[maybe_unused]]
CreateToken::CreateToken()
    : RequestType("CreateToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
CreateToken::CreateToken(const CreateToken& other) = default;

[[maybe_unused]]
CreateToken::CreateToken(CreateToken&& other) noexcept = default;

CreateToken::~CreateToken() = default;

[[maybe_unused]]
CreateToken& CreateToken::SetRecipient(SerializableStringPtr recipient)
{
    return RequestType::SetVariable("recipient", CoreTypes::String, std::move(recipient));
}

[[maybe_unused]]
CreateToken& CreateToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
CreateToken& CreateToken::SetParams(CreateTokenParamsPtr params)
{
    return RequestType::SetVariable("params", CoreTypes::CreateTokenParams, std::move(params));
}

CreateToken& CreateToken::operator=(const CreateToken& rhs) = default;

CreateToken& CreateToken::operator=(CreateToken&& rhs) noexcept = default;
