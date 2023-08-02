#include "EnjinPlatformSdkBeam/BeamMutations.hpp"

#include "BeamUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::beam::SendClaimBeam(
    PlatformClient& client, const ClaimBeam& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(BeamUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<std::string>>>
enjin::platform::sdk::beam::SendCreateBeam(
    PlatformClient& client, const CreateBeam& request)
{
    return client.SendRequest<GraphQlResponse<std::string>>(BeamUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::beam::SendDeleteBeam(
    PlatformClient& client, const DeleteBeam& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(BeamUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::beam::SendExpiresSingleUseCodes(
    PlatformClient& client, const ExpiresSingleUseCodes& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(BeamUtil::CreateRequest(request));
}

[[maybe_unused]]
std::future<PlatformResponsePtr<GraphQlResponse<bool>>>
enjin::platform::sdk::beam::SendUpdateBeam(
    PlatformClient& client, const UpdateBeam& request)
{
    return client.SendRequest<GraphQlResponse<bool>>(BeamUtil::CreateRequest(request));
}
