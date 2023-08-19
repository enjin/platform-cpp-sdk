#include "EnjinPlatformSdkFuelTanks/DispatchInputType.hpp"

#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using ParameterType = GraphQlParameter<DispatchInputType>;

[[maybe_unused]]
DispatchInputType::DispatchInputType() = default;

[[maybe_unused]]
DispatchInputType::DispatchInputType(const DispatchInputType& other) = default;

[[maybe_unused]]
DispatchInputType::DispatchInputType(DispatchInputType&& other) noexcept = default;

DispatchInputType::~DispatchInputType() = default;

[[maybe_unused]]
DispatchInputType& DispatchInputType::SetCall(const DispatchCall call)
{
    std::string s = enjin::platform::sdk::fuelTanks::ToString(call);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return ParameterType::SetParameter("call", std::move(sPtr));
}

[[maybe_unused]]
DispatchInputType& DispatchInputType::SetQuery(SerializableStringPtr query)
{
    return ParameterType::SetParameter("query", std::move(query));
}

[[maybe_unused]]
DispatchInputType& DispatchInputType::SetVariables(SerializableJsonValuePtr variables)
{
    return ParameterType::SetParameter("variables", std::move(variables));
}

DispatchInputType& DispatchInputType::operator=(const DispatchInputType& rhs) = default;

DispatchInputType& DispatchInputType::operator=(DispatchInputType&& rhs) noexcept = default;
