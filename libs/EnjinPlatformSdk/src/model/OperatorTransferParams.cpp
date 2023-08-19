#include "EnjinPlatformSdk/OperatorTransferParams.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<OperatorTransferParams>;

[[maybe_unused]]
OperatorTransferParams::OperatorTransferParams() = default;

[[maybe_unused]]
OperatorTransferParams::OperatorTransferParams(const OperatorTransferParams& other) = default;

[[maybe_unused]]
OperatorTransferParams::OperatorTransferParams(OperatorTransferParams&& other) noexcept = default;

OperatorTransferParams::~OperatorTransferParams() = default;

[[maybe_unused]]
OperatorTransferParams& OperatorTransferParams::SetSource(SerializableStringPtr source)
{
    return ParameterType::SetParameter("source", std::move(source));
}

[[maybe_unused]]
OperatorTransferParams& OperatorTransferParams::SetAmount(SerializableStringPtr amount)
{
    return ParameterType::SetParameter("amount", std::move(amount));
}

[[maybe_unused]]
OperatorTransferParams& OperatorTransferParams::SetKeepAlive(SerializableBoolPtr keepAlive)
{
    return ParameterType::SetParameter("keepAlive", std::move(keepAlive));
}

OperatorTransferParams& OperatorTransferParams::operator=(const OperatorTransferParams& rhs) = default;

OperatorTransferParams& OperatorTransferParams::operator=(OperatorTransferParams&& rhs) noexcept = default;
