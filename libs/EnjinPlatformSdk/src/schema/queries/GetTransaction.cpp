#include "EnjinPlatformSdk/GetTransaction.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetTransaction, TransactionFragment>;

[[maybe_unused]]
GetTransaction::GetTransaction()
    : RequestType("GetTransaction", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetTransaction::GetTransaction(const GetTransaction& other) = default;

[[maybe_unused]]
GetTransaction::GetTransaction(GetTransaction&& other) noexcept = default;

GetTransaction::~GetTransaction() = default;

[[maybe_unused]]
GetTransaction& GetTransaction::SetId(SerializableStringPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::BigInt, std::move(id));
}

[[maybe_unused]]
GetTransaction& GetTransaction::SetIdempotencyKey(SerializableStringPtr idempotencyKey)
{
    return RequestType::SetVariable("idempotencyKey", CoreTypes::String, std::move(idempotencyKey));
}

[[maybe_unused]]
GetTransaction& GetTransaction::SetTransactionId(SerializableStringPtr transactionId)
{
    return RequestType::SetVariable("transactionId", CoreTypes::String, std::move(transactionId));
}

[[maybe_unused]]
GetTransaction& GetTransaction::SetTransactionHash(SerializableStringPtr transactionHash)
{
    return RequestType::SetVariable("transactionHash", CoreTypes::String, std::move(transactionHash));
}

GetTransaction& GetTransaction::operator=(const GetTransaction& rhs) = default;

GetTransaction& GetTransaction::operator=(GetTransaction&& rhs) noexcept = default;
