#include "EnjinPlatformSdkBeam/BeamQueries.hpp"

#include "BeamUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Beam>>>
enjin::platform::sdk::beam::SendGetBeam(
    PlatformClient& client, const GetBeam& request)
{
    return client.SendRequest<GraphQlResponse<Beam>>(BeamUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Beam>>>>
enjin::platform::sdk::beam::SendGetBeams(
    PlatformClient& client, const GetBeams& request)
{
    return client.SendRequest<GraphQlResponse<Connection<Beam>>>(BeamUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<BeamClaim>>>>
enjin::platform::sdk::beam::SendGetClaims(
    PlatformClient& client, const GetClaims& request)
{
    return client.SendRequest<GraphQlResponse<Connection<BeamClaim>>>(BeamUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<Connection<BeamClaim>>>>
enjin::platform::sdk::beam::SendGetSingleUseCodes(
    PlatformClient& client, const GetSingleUseCodes& request)
{
    return client.SendRequest<GraphQlResponse<Connection<BeamClaim>>>(BeamUtil::CreateRequest(request));
}
