#include "EnjinPlatformSdk/TransferRecipient.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
TransferRecipient::TransferRecipient() = default;

[[maybe_unused]]
TransferRecipient::TransferRecipient(const TransferRecipient& other) = default;

[[maybe_unused]]
TransferRecipient::TransferRecipient(TransferRecipient&& other) noexcept = default;

TransferRecipient::~TransferRecipient() = default;

[[maybe_unused]]
TransferRecipient& TransferRecipient::SetAccount(SerializableStringPtr account)
{
    return GraphQlParameter<TransferRecipient>::SetParameter("account", std::move(account));
}

[[maybe_unused]]
TransferRecipient& TransferRecipient::SetSimpleParams(SimpleTransferParamsPtr simpleParams)
{
    return GraphQlParameter<TransferRecipient>::SetParameter("simpleParams", std::move(simpleParams));
}

[[maybe_unused]]
TransferRecipient& TransferRecipient::SetOperatorParams(OperatorTransferParamsPtr operatorParams)
{
    return GraphQlParameter<TransferRecipient>::SetParameter("operatorParams", std::move(operatorParams));
}

TransferRecipient& TransferRecipient::operator=(const TransferRecipient& rhs) = default;

TransferRecipient& TransferRecipient::operator=(TransferRecipient&& rhs) noexcept = default;
