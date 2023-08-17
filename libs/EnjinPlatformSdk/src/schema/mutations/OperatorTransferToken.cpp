#include "EnjinPlatformSdk/OperatorTransferToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<OperatorTransferToken, TransactionFragment>;

[[maybe_unused]]
OperatorTransferToken::OperatorTransferToken()
    : RequestType("OperatorTransferToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
OperatorTransferToken::OperatorTransferToken(const OperatorTransferToken& other) = default;

[[maybe_unused]]
OperatorTransferToken::OperatorTransferToken(OperatorTransferToken&& other) noexcept = default;

OperatorTransferToken::~OperatorTransferToken() = default;

[[maybe_unused]]
OperatorTransferToken& OperatorTransferToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
OperatorTransferToken& OperatorTransferToken::SetRecipient(SerializableStringPtr recipient)
{
    return RequestType::SetVariable("recipient", CoreTypes::String, std::move(recipient));
}

[[maybe_unused]]
OperatorTransferToken& OperatorTransferToken::SetParams(OperatorTransferParamsPtr params)
{
    return RequestType::SetVariable("params", CoreTypes::OperatorTransferParams, std::move(params));
}

[[maybe_unused]]
OperatorTransferToken& OperatorTransferToken::SetSigningAccount(SerializableStringPtr signingAccount)
{
    return RequestType::SetVariable("signingAccount", CoreTypes::String, std::move(signingAccount));
}

OperatorTransferToken& OperatorTransferToken::operator=(const OperatorTransferToken& rhs) = default;

OperatorTransferToken& OperatorTransferToken::operator=(OperatorTransferToken&& rhs) noexcept = default;
