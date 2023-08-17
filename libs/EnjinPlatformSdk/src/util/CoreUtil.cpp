#include "CoreUtil.hpp"

#include "EnjinPlatformSdk/PlatformRequest.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
PlatformRequestPtr CoreUtil::CreateRequest(const IGraphQlRequest<>& request)
{
    return PlatformRequest::Builder()
        .SetPath("/graphql")
        .AddOperation(request.Compile(), request.GetVariablesWithoutTypes())
        .Build();
}
