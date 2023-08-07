#ifndef ENJINPLATFORMSDKFUELTANKS_GETACCOUNTS_HPP
#define ENJINPLATFORMSDKFUELTANKS_GETACCOUNTS_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request for querying the wallet accounts of a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT GetAccounts : public GraphQlRequest<GetAccounts, WalletConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetAccounts();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetAccounts(const GetAccounts& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetAccounts(GetAccounts&& other) noexcept;

    /// \brief Class destructor.
    ~GetAccounts() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address of the fuel tank.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetAccounts& SetTankId(SerializableStringPtr tankId);

    GetAccounts& operator=(const GetAccounts& rhs);

    GetAccounts& operator=(GetAccounts&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETACCOUNTS_HPP
