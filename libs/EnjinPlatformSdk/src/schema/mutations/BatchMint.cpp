#include "EnjinPlatformSdk/BatchMint.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<BatchMint, TransactionFragment>;

[[maybe_unused]]
BatchMint::BatchMint()
    : RequestType("BatchMint", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
BatchMint::BatchMint(const BatchMint& other) = default;

[[maybe_unused]]
BatchMint::BatchMint(BatchMint&& other) noexcept = default;

BatchMint::~BatchMint() = default;

[[maybe_unused]]
BatchMint& BatchMint::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
BatchMint& BatchMint::SetRecipients(std::shared_ptr<SerializableArray<MintRecipient>> recipients)
{
    return RequestType::SetVariable("recipients", CoreTypes::MintRecipientArray, std::move(recipients));
}

BatchMint& BatchMint::operator=(const BatchMint& rhs) = default;

BatchMint& BatchMint::operator=(BatchMint&& rhs) noexcept = default;
