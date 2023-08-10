#ifndef ENJINPLATFORMSDKFUELTANKS_DESTROYFUELTANK_HPP
#define ENJINPLATFORMSDKFUELTANKS_DESTROYFUELTANK_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation for destroying a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT DestroyFuelTank : public GraphQlRequest<DestroyFuelTank, TransactionFragment>,
                                                         public HasIdempotencyKey<DestroyFuelTank>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    DestroyFuelTank();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    DestroyFuelTank(const DestroyFuelTank& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    DestroyFuelTank(DestroyFuelTank&& other) noexcept;

    /// \brief Class destructor.
    ~DestroyFuelTank() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    DestroyFuelTank& SetTankId(SerializableStringPtr tankId);

    DestroyFuelTank& operator=(const DestroyFuelTank& rhs);

    DestroyFuelTank& operator=(DestroyFuelTank&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_DESTROYFUELTANK_HPP
