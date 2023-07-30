#ifndef ENJINPLATFORMSDKBEAM_BEAMMUTATIONS_HPP
#define ENJINPLATFORMSDKBEAM_BEAMMUTATIONS_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include "EnjinPlatformSdkBeam/ClaimBeam.hpp"
#include "EnjinPlatformSdkBeam/CreateBeam.hpp"
#include "EnjinPlatformSdkBeam/DeleteBeam.hpp"
#include "EnjinPlatformSdkBeam/ExpiresSingleUseCodes.hpp"
#include "EnjinPlatformSdkBeam/UpdateBeam.hpp"
#include <future>
#include <string>

namespace enjin::platform::sdk::beam
{
/// \brief Sends a ClaimBeam request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKBEAM_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendClaimBeam(
    PlatformClient& client, const ClaimBeam& request);

/// \brief Sends a CreateBeam request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKBEAM_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<std::string>>> SendCreateBeam(
    PlatformClient& client, const CreateBeam& request);

/// \brief Sends a DeleteBeam request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKBEAM_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendDeleteBeam(
    PlatformClient& client, const DeleteBeam& request);

/// \brief Sends a ExpiresSingleUseCodes request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKBEAM_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendExpiresSingleUseCodes(
    PlatformClient& client, const ExpiresSingleUseCodes& request);

/// \brief Sends a UpdateBeam request to the platform.
/// \param client The platform client to send the request from.
/// \param request The request to send.
/// \return The future containing the response.
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDKBEAM_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<bool>>> SendUpdateBeam(
    PlatformClient& client, const UpdateBeam& request);
}

#endif //ENJINPLATFORMSDKBEAM_BEAMMUTATIONS_HPP
