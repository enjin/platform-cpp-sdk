#ifndef ENJINPLATFORMSDKBEAM_BEAMQUERIES_HPP
#define ENJINPLATFORMSDKBEAM_BEAMQUERIES_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include "EnjinPlatformSdkBeam/Beam.hpp"
#include "EnjinPlatformSdkBeam/BeamClaim.hpp"
#include "EnjinPlatformSdkBeam/GetBeam.hpp"
#include "EnjinPlatformSdkBeam/GetBeams.hpp"
#include "EnjinPlatformSdkBeam/GetClaims.hpp"
#include "EnjinPlatformSdkBeam/GetSingleUseCodes.hpp"
#include <future>

namespace enjin::platform::sdk::beam
{
/// \brief Sends a GetBeam request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKBEAM_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Beam>>> SendGetBeam(
    PlatformClient& client, const GetBeam& request);

/// \brief Sends a GetBeams request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKBEAM_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<Beam>>>> SendGetBeams(
    PlatformClient& client, const GetBeams& request);

/// \brief Sends a GetClaims request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKBEAM_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<BeamClaim>>>> SendGetClaims(
    PlatformClient& client, const GetClaims& request);

/// \brief Sends a GetSingleUseCodes request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKBEAM_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<Connection<BeamClaim>>>> SendGetSingleUseCodes(
    PlatformClient& client, const GetSingleUseCodes& request);
}

#endif //ENJINPLATFORMSDKBEAM_BEAMQUERIES_HPP
