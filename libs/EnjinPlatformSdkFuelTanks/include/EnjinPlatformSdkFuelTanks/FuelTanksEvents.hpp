#ifndef ENJINPLATFORMSDKFUELTANKS_FUELTANKSEVENTS_HPP
#define ENJINPLATFORMSDKFUELTANKS_FUELTANKSEVENTS_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include <string>

namespace enjin::platform::sdk::fuelTanks
{
/// \brief Static class which contains members representing the name of each fuel tanks based event on the platform.
class ENJINPLATFORMSDKFUELTANKS_EXPORT FuelTanks final
{
public:
    /// \brief The name of the event for when an account is added.
    static inline const std::string AccountAdded = "platform:account-added";

    /// \brief The name of the event for when an account is removed.
    static inline const std::string AccountRemoved = "platform:account-removed";

    /// \brief The name of the event for when a call is dispatched.
    static inline const std::string CallDispatched = "platform:call-dispatched";

    /// \brief The name of the event for when a freeze state is mutated.
    static inline const std::string FreezeStateMutated = "platform:freeze-state-mutated";

    /// \brief The name of the event for when a fuel tank is created.
    static inline const std::string FuelTankCreated = "platform:fuel-tank-created";

    /// \brief The name of the event for when a fuel tank is destroyed.
    static inline const std::string FuelTankDestroyed = "platform:fuel-tank-destroyed";

    /// \brief The name of the event for when a fuel tank is mutated.
    static inline const std::string FuelTankMutated = "platform:fuel-tank-mutated";

    /// \brief The name of the event for when a mutation of a freeze state is scheduled.
    static inline const std::string MutateFreezeStateScheduled = "platform:mutate-freeze-state-scheduled";

    /// \brief The name of the event for when a rule set is inserted.
    static inline const std::string RuleSetInserted = "platform:rule-set-inserted";

    /// \brief The name of the event for when a rule set is removed.
    static inline const std::string RuleSetRemoved = "platform:rule-set-removed";

    FuelTanks() = delete;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_FUELTANKSEVENTS_HPP
