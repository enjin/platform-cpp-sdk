#ifndef ENJINPLATFORMSDKFUELTANKS_REMOVERULESET_HPP
#define ENJINPLATFORMSDKFUELTANKS_REMOVERULESET_HPP

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
/// \brief A request to act as a mutation for removing account rule from a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT RemoveRuleSet : public GraphQlRequest<RemoveRuleSet, TransactionFragment>,
                                                       public HasIdempotencyKey<RemoveRuleSet>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RemoveRuleSet();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RemoveRuleSet(const RemoveRuleSet& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RemoveRuleSet(RemoveRuleSet&& other) noexcept;

    /// \brief Class destructor.
    ~RemoveRuleSet() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveRuleSet& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the rule set ID.
    /// \param ruleSetId The ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveRuleSet& SetRuleSetId(SerializableStringPtr ruleSetId);

    RemoveRuleSet& operator=(const RemoveRuleSet& rhs);

    RemoveRuleSet& operator=(RemoveRuleSet&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_REMOVERULESET_HPP
