#ifndef ENJINPLATFORMSDKFUELTANKS_DISPATCHRULEINPUTTYPE_HPP
#define ENJINPLATFORMSDKFUELTANKS_DISPATCHRULEINPUTTYPE_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/MultiTokenIdInput.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelBudgetInputType.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlParameterORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
class DispatchRuleInputType;

/// \brief Definition for a pointer containing a DispatchRuleInputType.
using DispatchRuleInputTypePtr [[maybe_unused]] = std::shared_ptr<DispatchRuleInputType>;

/// \brief Models a parameter for dispatch rules of a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT DispatchRuleInputType : public GraphQlParameter<DispatchRuleInputType>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    DispatchRuleInputType();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    DispatchRuleInputType(const DispatchRuleInputType& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    DispatchRuleInputType(DispatchRuleInputType&& other) noexcept;

    /// \brief Class destructor.
    ~DispatchRuleInputType() override;

    /// \brief Sets the wallet accounts that are allowed to use the fuel tank.
    /// \param whitelistedCallers The allowed accounts.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    DispatchRuleInputType& SetWhitelistedCallers(SerializableStringArrayPtr whitelistedCallers);

    /// \brief Sets the specific token the wallet account(s) must have to use the fuel tank.
    /// \param requireToken The required token.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    DispatchRuleInputType& SetRequireToken(MultiTokenIdInputPtr requireToken);

    /// \brief Sets the collections that are allowed to use the fuel tank.
    /// \param whitelistedCollections The allowed collections.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    DispatchRuleInputType& SetWhitelistedCollections(SerializableStringArrayPtr whitelistedCollections);

    /// \brief Sets the maximum amount of fuel that can be used per transaction.
    /// \param maxFuelBurnPerTransaction The maximum amount.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    DispatchRuleInputType& SetMaxFuelBurnPerTransactions(SerializableStringPtr maxFuelBurnPerTransaction);

    /// \brief Sets the rule for user fuel budget.
    /// \param userFuelBudget The budget rule.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    DispatchRuleInputType& SetUserFuelBudget(FuelBudgetInputTypePtr userFuelBudget);

    /// \brief Sets the rule for tank fuel budget.
    /// \param tankFuelBudget The budget rule.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    DispatchRuleInputType& SetTankFuelBudget(FuelBudgetInputTypePtr tankFuelBudget);

    DispatchRuleInputType& operator=(const DispatchRuleInputType& rhs);

    DispatchRuleInputType& operator=(DispatchRuleInputType&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_DISPATCHRULEINPUTTYPE_HPP
