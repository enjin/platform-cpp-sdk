#include "EnjinPlatformSdk/UpdateTransaction.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <memory>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<UpdateTransaction>;

[[maybe_unused]]
UpdateTransaction::UpdateTransaction()
    : RequestType("UpdateTransaction", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
UpdateTransaction::UpdateTransaction(const UpdateTransaction& other) = default;

[[maybe_unused]]
UpdateTransaction::UpdateTransaction(UpdateTransaction&& other) noexcept = default;

UpdateTransaction::~UpdateTransaction() = default;

[[maybe_unused]]
UpdateTransaction& UpdateTransaction::SetId(SerializableIntPtr id)
{
    return RequestType::SetVariable("id", CoreTypes::Int, std::move(id));
}

[[maybe_unused]]
UpdateTransaction& UpdateTransaction::SetState(const TransactionState state)
{
    std::string s = enjin::platform::sdk::ToString(state);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return RequestType::SetVariable("state", CoreTypes::TransactionState, std::move(sPtr));
}

[[maybe_unused]]
UpdateTransaction& UpdateTransaction::SetTransactionId(SerializableStringPtr transactionId)
{
    return RequestType::SetVariable("transactionId", CoreTypes::String, std::move(transactionId));
}

[[maybe_unused]]
UpdateTransaction& UpdateTransaction::SetTransactionHash(SerializableStringPtr transactionHash)
{
    return RequestType::SetVariable("transactionHash", CoreTypes::String, std::move(transactionHash));
}

UpdateTransaction& UpdateTransaction::operator=(const UpdateTransaction& rhs) = default;

UpdateTransaction& UpdateTransaction::operator=(UpdateTransaction&& rhs) noexcept = default;
