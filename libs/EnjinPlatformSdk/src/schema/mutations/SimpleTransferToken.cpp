#include "EnjinPlatformSdk/SimpleTransferToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<SimpleTransferToken, TransactionFragment>;

[[maybe_unused]]
SimpleTransferToken::SimpleTransferToken()
    : RequestType("SimpleTransferToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
SimpleTransferToken::SimpleTransferToken(const SimpleTransferToken& other) = default;

[[maybe_unused]]
SimpleTransferToken::SimpleTransferToken(SimpleTransferToken&& other) noexcept = default;

SimpleTransferToken::~SimpleTransferToken() = default;

[[maybe_unused]]
SimpleTransferToken& SimpleTransferToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
SimpleTransferToken& SimpleTransferToken::SetRecipient(SerializableStringPtr recipient)
{
    return RequestType::SetVariable("recipient", CoreTypes::String, std::move(recipient));
}

[[maybe_unused]]
SimpleTransferToken& SimpleTransferToken::SetParams(SimpleTransferParamsPtr params)
{
    return RequestType::SetVariable("params", CoreTypes::SimpleTransferParams, std::move(params));
}

[[maybe_unused]]
SimpleTransferToken& SimpleTransferToken::SetSigningAccount(SerializableStringPtr signingAccount)
{
    return RequestType::SetVariable("signingAccount", CoreTypes::String, std::move(signingAccount));
}

SimpleTransferToken& SimpleTransferToken::operator=(const SimpleTransferToken& rhs) = default;

SimpleTransferToken& SimpleTransferToken::operator=(SimpleTransferToken&& rhs) noexcept = default;
