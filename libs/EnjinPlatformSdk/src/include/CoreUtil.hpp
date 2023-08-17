#ifndef ENJINPLATFORMSDK_COREUTIL_HPP
#define ENJINPLATFORMSDK_COREUTIL_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IGraphQlRequest.hpp"
#include "EnjinPlatformSdk/IPlatformRequest.hpp"

namespace enjin::platform::sdk
{
/// \brief Utility class for core schema handling.
class ENJINPLATFORMSDK_EXPORT CoreUtil final
{
public:
    CoreUtil() = delete;

    /// \brief Creates a platform request from the given GraphQL request.
    /// \param request The GraphQL request.
    /// \return The pointer holding the platform request.
    [[maybe_unused]]
    [[nodiscard]]
    static PlatformRequestPtr CreateRequest(const IGraphQlRequest<>& request);
};
}

#endif //ENJINPLATFORMSDK_COREUTIL_HPP
