#include "EnjinPlatformSdk/SimpleTransferParams.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<SimpleTransferParams>;

[[maybe_unused]]
SimpleTransferParams::SimpleTransferParams() = default;

[[maybe_unused]]
SimpleTransferParams::SimpleTransferParams(const SimpleTransferParams& other) = default;

[[maybe_unused]]
SimpleTransferParams::SimpleTransferParams(SimpleTransferParams&& other) noexcept = default;

SimpleTransferParams::~SimpleTransferParams() = default;

[[maybe_unused]]
SimpleTransferParams& SimpleTransferParams::SetAmount(SerializableStringPtr amount)
{
    return ParameterType::SetParameter("amount", std::move(amount));
}

[[maybe_unused]]
SimpleTransferParams& SimpleTransferParams::SetKeepAlive(SerializableBoolPtr keepAlive)
{
    return ParameterType::SetParameter("keepAlive", std::move(keepAlive));
}

SimpleTransferParams& SimpleTransferParams::operator=(const SimpleTransferParams& rhs) = default;

SimpleTransferParams& SimpleTransferParams::operator=(SimpleTransferParams&& rhs) noexcept = default;
