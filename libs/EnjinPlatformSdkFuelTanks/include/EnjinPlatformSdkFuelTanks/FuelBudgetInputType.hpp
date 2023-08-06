#ifndef ENJINPLATFORMSDKFUELTANKS_FUELBUDGETINPUTTYPE_HPP
#define ENJINPLATFORMSDKFUELTANKS_FUELBUDGETINPUTTYPE_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlParameterORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
class FuelBudgetInputType;

/// \brief Definition for a pointer containing a FuelBudgetInputType.
using FuelBudgetInputTypePtr [[maybe_unused]] = std::shared_ptr<FuelBudgetInputType>;

/// \brief Models a parameter for the rule for a fuel budget.
class ENJINPLATFORMSDKFUELTANKS_EXPORT FuelBudgetInputType : public GraphQlParameter<FuelBudgetInputType>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FuelBudgetInputType();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FuelBudgetInputType(const FuelBudgetInputType& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FuelBudgetInputType(FuelBudgetInputType&& other) noexcept;

    /// \brief Class destructor.
    ~FuelBudgetInputType() override;

    /// \brief Sets the amount of fuel.
    /// \param amount The amount.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    FuelBudgetInputType& SetAmount(SerializableStringPtr amount);

    /// \brief Sets the period when the amount will reset.
    /// \param resetPeriod The reset period.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    FuelBudgetInputType& SetResetPeriod(SerializableIntPtr resetPeriod);

    FuelBudgetInputType& operator=(const FuelBudgetInputType& rhs);

    FuelBudgetInputType& operator=(FuelBudgetInputType&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_FUELBUDGETINPUTTYPE_HPP
