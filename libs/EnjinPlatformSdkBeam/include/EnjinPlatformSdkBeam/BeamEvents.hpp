#ifndef ENJINPLATFORMSDKBEAM_BEAMEVENTS_HPP
#define ENJINPLATFORMSDKBEAM_BEAMEVENTS_HPP

#include "enjinplatformsdkbeam_export.h"
#include <string>

namespace enjin::platform::sdk::beam
{
/// \brief Static class which contains members representing the name of each beam based event on the platform.
class ENJINPLATFORMSDKBEAM_EXPORT BeamEvents final
{
public:
    /// \brief The name of the event for when a claim for a beam is in progress.
    static inline const std::string BeamClaimInProgress = "platform:beam-claim-in-progress";

    /// \brief The name of the event for when a claim for a beam becomes pending.
    static inline const std::string BeamClaimPending = "platform:beam-claim-pending";

    /// \brief The name of the event for when a claim for a beam is completed.
    static inline const std::string BeamClaimsComplete = "platform:beam-claims-complete";

    /// \brief The name of the event for when a claim for a beam fails.
    static inline const std::string BeamClaimsFailed = "platform:beam-claims-failed";

    /// \brief The name of the event for when a beam is created.
    static inline const std::string BeamCreated = "platform:beam-created";

    /// \brief The name of the event for when a beam is deleted.
    static inline const std::string BeamDeleted = "platform:beam-deleted";

    /// \brief The name of the event for when a beam is updated.
    static inline const std::string BeamUpdated = "platform:beam-updated";

    BeamEvents() = delete;
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMEVENTS_HPP
