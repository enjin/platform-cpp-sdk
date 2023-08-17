#include "EnjinPlatformSdk/MarkAndListPendingTransactions.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<MarkAndListPendingTransactions, TransactionFragment>;

[[maybe_unused]]
MarkAndListPendingTransactions::MarkAndListPendingTransactions()
    : RequestType("MarkAndListPendingTransactions", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
MarkAndListPendingTransactions::MarkAndListPendingTransactions(const MarkAndListPendingTransactions& other) = default;

[[maybe_unused]]
MarkAndListPendingTransactions::MarkAndListPendingTransactions(
    MarkAndListPendingTransactions&& other) noexcept = default;

MarkAndListPendingTransactions::~MarkAndListPendingTransactions() = default;

[[maybe_unused]]
MarkAndListPendingTransactions& MarkAndListPendingTransactions::SetAccounts(SerializableStringArrayPtr accounts)
{
    return RequestType::SetVariable("accounts", CoreTypes::StringArray, std::move(accounts));
}

[[maybe_unused]]
MarkAndListPendingTransactions&
MarkAndListPendingTransactions::SetMarkAsProcessing(SerializableBoolPtr markAsProcessing)
{
    return RequestType::SetVariable("markAsProcessing", CoreTypes::Boolean, std::move(markAsProcessing));
}

MarkAndListPendingTransactions&
MarkAndListPendingTransactions::operator=(const MarkAndListPendingTransactions& rhs) = default;

MarkAndListPendingTransactions&
MarkAndListPendingTransactions::operator=(MarkAndListPendingTransactions&& rhs) noexcept = default;
