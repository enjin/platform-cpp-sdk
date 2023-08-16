#ifndef ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEUTIL_HPP
#define ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEUTIL_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/IGraphQlRequest.hpp"
#include "EnjinPlatformSdk/IPlatformRequest.hpp"

namespace enjin::platform::sdk::marketplace
{
/// \brief Utility class for marketplace schema handling.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT MarketplaceUtil final
{
public:
    MarketplaceUtil() = delete;

    /// \brief Creates a platform request from the given GraphQL request.
    /// \param request The GraphQL request.
    /// \return The pointer holding the platform request.
    [[maybe_unused]]
    [[nodiscard]]
    static PlatformRequestPtr CreateRequest(const IGraphQlRequest<>& request);
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_MARKETPLACEUTIL_HPP
