#ifndef ENJINPLATFORMSDKFUELTANKS_FUELTANKSUTIL_HPP
#define ENJINPLATFORMSDKFUELTANKS_FUELTANKSUTIL_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/IGraphQlRequest.hpp"
#include "EnjinPlatformSdk/IPlatformRequest.hpp"

namespace enjin::platform::sdk::fuelTanks
{
/// \brief Utility class for fuel tanks schema handling.
class ENJINPLATFORMSDKFUELTANKS_EXPORT FuelTanksUtil final
{
public:
    FuelTanksUtil() = delete;

    /// \brief Creates a platform request from the given GraphQL request.
    /// \param request The GraphQL request.
    /// \return The pointer holding the platform request.
    [[maybe_unused]]
    [[nodiscard]]
    static PlatformRequestPtr CreateRequest(const IGraphQlRequest<>& request);
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_FUELTANKSUTIL_HPP
