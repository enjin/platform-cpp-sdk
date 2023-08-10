#ifndef ENJINPLATFORMSDKFUELTANKS_SCHEDULEMUTATEFREEZE_HPP
#define ENJINPLATFORMSDKFUELTANKS_SCHEDULEMUTATEFREEZE_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation for scheduling a mutation of the is_frozen state that determines if a fuel
/// tank or rule set may be frozen.
class ENJINPLATFORMSDKFUELTANKS_EXPORT ScheduleMutateFreeze
    : public GraphQlRequest<ScheduleMutateFreeze, TransactionFragment>,
      public HasIdempotencyKey<ScheduleMutateFreeze>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ScheduleMutateFreeze();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ScheduleMutateFreeze(const ScheduleMutateFreeze& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ScheduleMutateFreeze(ScheduleMutateFreeze&& other) noexcept;

    /// \brief Class destructor.
    ~ScheduleMutateFreeze() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    ScheduleMutateFreeze& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the flag for the frozen state.
    /// \param isFrozen The flag.
    /// \return This request for chaining.
    [[maybe_unused]]
    ScheduleMutateFreeze& SetIsFrozen(SerializableBoolPtr isFrozen);

    /// \brief Sets the rule set ID.
    /// \param ruleSetId The ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    ScheduleMutateFreeze& SetRuleSetId(SerializableStringPtr ruleSetId);

    ScheduleMutateFreeze& operator=(const ScheduleMutateFreeze& rhs);

    ScheduleMutateFreeze& operator=(ScheduleMutateFreeze&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_SCHEDULEMUTATEFREEZE_HPP
