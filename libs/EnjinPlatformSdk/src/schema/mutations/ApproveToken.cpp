#include "EnjinPlatformSdk/ApproveToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<ApproveToken, TransactionFragment>;

[[maybe_unused]]
ApproveToken::ApproveToken()
    : RequestType("ApproveToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
ApproveToken::ApproveToken(const ApproveToken& other) = default;

[[maybe_unused]]
ApproveToken::ApproveToken(ApproveToken&& other) noexcept = default;

ApproveToken::~ApproveToken() = default;

[[maybe_unused]]
ApproveToken& ApproveToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
ApproveToken& ApproveToken::SetOperator(SerializableStringPtr op)
{
    return RequestType::SetVariable("operator", CoreTypes::String, std::move(op));
}

[[maybe_unused]]
ApproveToken& ApproveToken::SetAmount(SerializableStringPtr amount)
{
    return RequestType::SetVariable("amount", CoreTypes::BigInt, std::move(amount));
}

[[maybe_unused]]
ApproveToken& ApproveToken::SetCurrentAmount(SerializableStringPtr currentAmount)
{
    return RequestType::SetVariable("currentAmount", CoreTypes::BigInt, std::move(currentAmount));
}

[[maybe_unused]]
ApproveToken& ApproveToken::SetExpiration(SerializableIntPtr expiration)
{
    return RequestType::SetVariable("expiration", CoreTypes::Int, std::move(expiration));
}

ApproveToken& ApproveToken::operator=(const ApproveToken& rhs) = default;

ApproveToken& ApproveToken::operator=(ApproveToken&& rhs) noexcept = default;
