#ifndef ENJINPLATFORMSDKFUELTANKS_INSERTRULESET_HPP
#define ENJINPLATFORMSDKFUELTANKS_INSERTRULESET_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include "EnjinPlatformSdkFuelTanks/DispatchRuleInputType.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation for inserting a new rule set for a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT InsertRuleSet : public GraphQlRequest<InsertRuleSet, TransactionFragment>,
                                                       public HasIdempotencyKey<InsertRuleSet>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    InsertRuleSet();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    InsertRuleSet(const InsertRuleSet& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    InsertRuleSet(InsertRuleSet&& other) noexcept;

    /// \brief Class destructor.
    ~InsertRuleSet() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    InsertRuleSet& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the rule set ID.
    /// \param ruleSetId The ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    InsertRuleSet& SetRuleSetId(SerializableStringPtr ruleSetId);

    /// \brief Sets the fuel tank dispatch rules.
    /// \param dispatchRules The dispatch rules.
    /// \return This request for chaining.
    [[maybe_unused]]
    InsertRuleSet& SetDispatchRules(std::shared_ptr<SerializableArray<DispatchRuleInputType>> dispatchRules);

    InsertRuleSet& operator=(const InsertRuleSet& rhs);

    InsertRuleSet& operator=(InsertRuleSet&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_INSERTRULESET_HPP
