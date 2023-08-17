#include "EnjinPlatformSdk/BatchTransfer.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<BatchTransfer, TransactionFragment>;

[[maybe_unused]]
BatchTransfer::BatchTransfer()
    : RequestType("BatchTransfer", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
BatchTransfer::BatchTransfer(const BatchTransfer& other) = default;

[[maybe_unused]]
BatchTransfer::BatchTransfer(BatchTransfer&& other) noexcept = default;

BatchTransfer::~BatchTransfer() = default;

[[maybe_unused]]
BatchTransfer& BatchTransfer::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
BatchTransfer& BatchTransfer::SetRecipients(std::shared_ptr<SerializableArray<TransferRecipient>> recipients)
{
    return RequestType::SetVariable("recipients", CoreTypes::TransferRecipientArray, std::move(recipients));
}

[[maybe_unused]]
BatchTransfer& BatchTransfer::SetSigningAccount(SerializableStringPtr signingAccount)
{
    return RequestType::SetVariable("signingAccount", CoreTypes::String, std::move(signingAccount));
}

BatchTransfer& BatchTransfer::operator=(const BatchTransfer& rhs) = default;

BatchTransfer& BatchTransfer::operator=(BatchTransfer&& rhs) noexcept = default;
