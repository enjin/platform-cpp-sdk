#ifndef ENJINPLATFORMSDKFUELTANKS_MUTATEFUELTANK_HPP
#define ENJINPLATFORMSDKFUELTANKS_MUTATEFUELTANK_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTankMutationInputType.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation for applying a mutation to a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT MutateFuelTank : public GraphQlRequest<MutateFuelTank, TransactionFragment>,
                                                        public HasIdempotencyKey<MutateFuelTank>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MutateFuelTank();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MutateFuelTank(const MutateFuelTank& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MutateFuelTank(MutateFuelTank&& other) noexcept;

    /// \brief Class destructor.
    ~MutateFuelTank() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    MutateFuelTank& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the fuel tank input fields.
    /// \param mutation The mutation.
    /// \return This request for chaining.
    [[maybe_unused]]
    MutateFuelTank& SetMutation(FuelTankMutationInputTypePtr mutation);

    MutateFuelTank& operator=(const MutateFuelTank& rhs);

    MutateFuelTank& operator=(MutateFuelTank&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_MUTATEFUELTANK_HPP
