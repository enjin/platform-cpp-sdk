#include "EnjinPlatformSdk/UnapproveToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<UnapproveToken, TransactionFragment>;

[[maybe_unused]]
UnapproveToken::UnapproveToken()
    : RequestType("UnapproveToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
UnapproveToken::UnapproveToken(const UnapproveToken& other) = default;

[[maybe_unused]]
UnapproveToken::UnapproveToken(UnapproveToken&& other) noexcept = default;

UnapproveToken::~UnapproveToken() = default;

[[maybe_unused]]
UnapproveToken& UnapproveToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
UnapproveToken& UnapproveToken::SetOperator(SerializableStringPtr op)
{
    return RequestType::SetVariable("operator", CoreTypes::String, std::move(op));
}

UnapproveToken& UnapproveToken::operator=(const UnapproveToken& rhs) = default;

UnapproveToken& UnapproveToken::operator=(UnapproveToken&& rhs) noexcept = default;
