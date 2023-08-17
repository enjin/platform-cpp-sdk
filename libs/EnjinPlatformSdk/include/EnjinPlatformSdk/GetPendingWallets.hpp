#ifndef ENJINPLATFORMSDK_GETPENDINGWALLETS_HPP
#define ENJINPLATFORMSDK_GETPENDINGWALLETS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying an array of wallet accounts which have yet to be verified.
class ENJINPLATFORMSDK_EXPORT GetPendingWallets : public GraphQlRequest<GetPendingWallets, WalletConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetPendingWallets();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetPendingWallets(const GetPendingWallets& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetPendingWallets(GetPendingWallets&& other) noexcept;

    /// \brief Class destructor.
    ~GetPendingWallets() override;

    GetPendingWallets& operator=(const GetPendingWallets& rhs);

    GetPendingWallets& operator=(GetPendingWallets&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETPENDINGWALLETS_HPP
