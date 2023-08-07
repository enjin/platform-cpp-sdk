#ifndef ENJINPLATFORMSDKFUELTANKS_GETFUELTANKS_HPP
#define ENJINPLATFORMSDKFUELTANKS_GETFUELTANKS_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTankFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request for querying a fuel tanks.
class ENJINPLATFORMSDKFUELTANKS_EXPORT GetFuelTanks : public GraphQlRequest<GetFuelTanks, FuelTankConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetFuelTanks();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetFuelTanks(const GetFuelTanks& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetFuelTanks(GetFuelTanks&& other) noexcept;

    /// \brief Class destructor.
    ~GetFuelTanks() override;

    /// \brief Sets the beam code.
    /// \param names The wallet account.
    /// \return This request for chaining.
    [[maybe_unused]]
    [[nodiscard]]
    GetFuelTanks& SetNames(SerializableStringArrayPtr names);

    /// \brief Sets the wallet account.
    /// \param tankIds The wallet account.
    /// \return This request for chaining.
    [[maybe_unused]]
    [[nodiscard]]
    GetFuelTanks& SetTankIds(SerializableStringArrayPtr tankIds);

    GetFuelTanks& operator=(const GetFuelTanks& rhs);

    GetFuelTanks& operator=(GetFuelTanks&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_GETFUELTANKS_HPP
