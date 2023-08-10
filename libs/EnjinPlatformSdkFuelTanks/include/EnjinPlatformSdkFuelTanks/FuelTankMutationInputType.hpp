#ifndef ENJINPLATFORMSDKFUELTANKS_FUELTANKMUTATIONINPUTTYPE_HPP
#define ENJINPLATFORMSDKFUELTANKS_FUELTANKMUTATIONINPUTTYPE_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdkFuelTanks/AccountRuleInputType.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlParameterORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
class FuelTankMutationInputType;

/// \brief Definition for a pointer containing a BeamFlagInputType.
using FuelTankMutationInputTypePtr [[maybe_unused]] = std::shared_ptr<FuelTankMutationInputType>;

/// \brief Models a parameter for fuel tank input fields.
class ENJINPLATFORMSDKFUELTANKS_EXPORT FuelTankMutationInputType : public GraphQlParameter<FuelTankMutationInputType>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FuelTankMutationInputType();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FuelTankMutationInputType(const FuelTankMutationInputType& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FuelTankMutationInputType(FuelTankMutationInputType&& other) noexcept;

    /// \brief Class destructor.
    ~FuelTankMutationInputType() override;

    /// \brief Sets the flag for existential deposit.
    /// \param reservesExistentialDeposit The flag.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    FuelTankMutationInputType& SetReservesExistentialDeposit(SerializableBoolPtr reservesExistentialDeposit);

    /// \brief Sets the flag for account creation deposit.
    /// \param reservesAccountCreationDeposit The flag.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    FuelTankMutationInputType& SetReservesAccountCreationDeposit(SerializableBoolPtr reservesAccountCreationDeposit);

    /// \brief Sets the flag for deposit.
    /// \param providesDeposit The flag.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    FuelTankMutationInputType& SetProvidesDeposit(SerializableBoolPtr providesDeposit);

    /// \brief Sets the fuel tank account rules.
    /// \param accountRules The rules.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    FuelTankMutationInputType& SetAccountRules(AccountRuleInputTypePtr accountRules);

    FuelTankMutationInputType& operator=(const FuelTankMutationInputType& rhs);

    FuelTankMutationInputType& operator=(FuelTankMutationInputType&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_FUELTANKMUTATIONINPUTTYPE_HPP
