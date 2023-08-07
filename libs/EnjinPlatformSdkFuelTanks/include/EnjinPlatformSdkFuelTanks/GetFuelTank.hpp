#ifndef ENJINPLATFORMSDKFUELTANKS_GETFUELTANK_HPP
#define ENJINPLATFORMSDKFUELTANKS_GETFUELTANK_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTankFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request for querying a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT GetFuelTank : public GraphQlRequest<GetFuelTank, FuelTankFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetFuelTank();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetFuelTank(const GetFuelTank& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetFuelTank(GetFuelTank&& other) noexcept;

    /// \brief Class destructor.
    ~GetFuelTank() override;

    /// \brief Sets the fuel tank name.
    /// \param name The name.
    /// \return This request for chaining.
    [[maybe_unused]]
    [[nodiscard]]
    GetFuelTank& SetName(SerializableStringPtr name);

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    [[nodiscard]]
    GetFuelTank& SetTankId(SerializableStringPtr tankId);

    GetFuelTank& operator=(const GetFuelTank& rhs);

    GetFuelTank& operator=(GetFuelTank&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_GETFUELTANK_HPP
