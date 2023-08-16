#include "MarketplaceUtil.hpp"

#include "EnjinPlatformSdk/PlatformRequest.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

[[maybe_unused]]
PlatformRequestPtr MarketplaceUtil::CreateRequest(const IGraphQlRequest<>& request)
{
    return PlatformRequest::Builder()
        .SetPath("/graphql/marketplace")
        .AddOperation(request.Compile(), request.GetVariablesWithoutTypes())
        .Build();
}
