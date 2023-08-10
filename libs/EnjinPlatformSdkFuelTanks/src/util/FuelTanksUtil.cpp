#include "FuelTanksUtil.hpp"

#include "EnjinPlatformSdk/PlatformRequest.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

[[maybe_unused]]
PlatformRequestPtr FuelTanksUtil::CreateRequest(const IGraphQlRequest<>& request)
{
    return PlatformRequest::Builder()
        .SetPath("/graphql/fuel-tanks")
        .AddOperation(request.Compile(), request.GetVariablesWithoutTypes())
        .Build();
}
