#include "BeamUtil.hpp"

#include "EnjinPlatformSdk/PlatformRequest.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

[[maybe_unused]]
PlatformRequestPtr BeamUtil::CreateRequest(const IGraphQlRequest<>& request)
{
    return PlatformRequest::Builder()
        .SetPath("/graphql/beam")
        .AddOperation(request.Compile(), request.GetVariablesWithoutTypes())
        .Build();
}
