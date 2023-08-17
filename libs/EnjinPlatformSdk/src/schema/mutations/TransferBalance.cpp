#include "EnjinPlatformSdk/TransferBalance.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<TransferBalance, TransactionFragment>;

[[maybe_unused]]
TransferBalance::TransferBalance()
    : RequestType("TransferBalance", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
TransferBalance::TransferBalance(const TransferBalance& other) = default;

[[maybe_unused]]
TransferBalance::TransferBalance(TransferBalance&& other) noexcept = default;

TransferBalance::~TransferBalance() = default;

[[maybe_unused]]
TransferBalance& TransferBalance::SetRecipient(SerializableStringPtr recipient)
{
    return RequestType::SetVariable("recipient", CoreTypes::String, std::move(recipient));
}

[[maybe_unused]]
TransferBalance& TransferBalance::SetAmount(SerializableStringPtr amount)
{
    return RequestType::SetVariable("amount", CoreTypes::BigInt, std::move(amount));
}

[[maybe_unused]]
TransferBalance& TransferBalance::SetKeepAlive(SerializableBoolPtr keepAlive)
{
    return RequestType::SetVariable("keepAlive", CoreTypes::Boolean, std::move(keepAlive));
}

[[maybe_unused]]
TransferBalance& TransferBalance::SetSigningAccount(SerializableStringPtr signingAccount)
{
    return RequestType::SetVariable("signingAccount", CoreTypes::String, std::move(signingAccount));
}

TransferBalance& TransferBalance::operator=(const TransferBalance& rhs) = default;

TransferBalance& TransferBalance::operator=(TransferBalance&& rhs) noexcept = default;
