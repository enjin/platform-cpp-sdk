#include "EnjinPlatformSdk/TransferAllBalance.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<TransferAllBalance, TransactionFragment>;

[[maybe_unused]]
TransferAllBalance::TransferAllBalance()
    : RequestType("TransferAllBalance", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
TransferAllBalance::TransferAllBalance(const TransferAllBalance& other) = default;

[[maybe_unused]]
TransferAllBalance::TransferAllBalance(TransferAllBalance&& other) noexcept = default;

TransferAllBalance::~TransferAllBalance() = default;

[[maybe_unused]]
TransferAllBalance& TransferAllBalance::SetRecipient(SerializableStringPtr recipient)
{
    return RequestType::SetVariable("recipient", CoreTypes::String, std::move(recipient));
}

[[maybe_unused]]
TransferAllBalance& TransferAllBalance::SetKeepAlive(SerializableBoolPtr keepAlive)
{
    return RequestType::SetVariable("keepAlive", CoreTypes::Boolean, std::move(keepAlive));
}

[[maybe_unused]]
TransferAllBalance& TransferAllBalance::SetSigningAccount(SerializableStringPtr signingAccount)
{
    return RequestType::SetVariable("signingAccount", CoreTypes::String, std::move(signingAccount));
}

TransferAllBalance& TransferAllBalance::operator=(const TransferAllBalance& rhs) = default;

TransferAllBalance& TransferAllBalance::operator=(TransferAllBalance&& rhs) noexcept = default;
