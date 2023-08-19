#include "EnjinPlatformSdk/MintTokenParams.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<MintTokenParams>;

[[maybe_unused]]
MintTokenParams::MintTokenParams() = default;

[[maybe_unused]]
MintTokenParams::MintTokenParams(const MintTokenParams& other) = default;

[[maybe_unused]]
MintTokenParams::MintTokenParams(MintTokenParams&& other) noexcept = default;

MintTokenParams::~MintTokenParams() = default;

[[maybe_unused]]
MintTokenParams& MintTokenParams::SetAmount(SerializableStringPtr amount)
{
    return ParameterType::SetParameter("amount", std::move(amount));
}

[[maybe_unused]]
MintTokenParams& MintTokenParams::SetUnitPrice(SerializableStringPtr unitPrice)
{
    return ParameterType::SetParameter("unitPrice", std::move(unitPrice));
}

MintTokenParams& MintTokenParams::operator=(const MintTokenParams& rhs) = default;

MintTokenParams& MintTokenParams::operator=(MintTokenParams&& rhs) noexcept = default;
