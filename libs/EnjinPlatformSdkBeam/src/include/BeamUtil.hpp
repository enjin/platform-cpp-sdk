#ifndef ENJINPLATFORMSDKBEAM_BEAMUTIL_HPP
#define ENJINPLATFORMSDKBEAM_BEAMUTIL_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/IGraphQlRequest.hpp"
#include "EnjinPlatformSdk/IPlatformRequest.hpp"

namespace enjin::platform::sdk::beam
{
/// \brief Utility class for beam schema handling.
class ENJINPLATFORMSDKBEAM_EXPORT BeamUtil final
{
public:
    BeamUtil() = delete;

    /// \brief Creates a platform request from the given GraphQL request.
    /// \param request The GraphQL request.
    /// \return The pointer holding the platform request.
    [[maybe_unused]]
    [[nodiscard]]
    static PlatformRequestPtr CreateRequest(const IGraphQlRequest<>& request);
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMUTIL_HPP
