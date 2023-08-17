#include "EnjinPlatformSdk/MutateToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<MutateToken, TransactionFragment>;

[[maybe_unused]]
MutateToken::MutateToken()
    : RequestType("MutateToken", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
MutateToken::MutateToken(const MutateToken& other) = default;

[[maybe_unused]]
MutateToken::MutateToken(MutateToken&& other) noexcept = default;

MutateToken::~MutateToken() = default;

[[maybe_unused]]
MutateToken& MutateToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
MutateToken& MutateToken::SetMutation(TokenMutationInputPtr mutation)
{
    return RequestType::SetVariable("mutation", CoreTypes::TokenMutationInput, std::move(mutation));
}

MutateToken& MutateToken::operator=(const MutateToken& rhs) = default;

MutateToken& MutateToken::operator=(MutateToken&& rhs) noexcept = default;
