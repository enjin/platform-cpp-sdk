#ifndef ENJINPLATFORMSDK_GLOBALEVENTS_HPP
#define ENJINPLATFORMSDK_GLOBALEVENTS_HPP

#include "enjinplatformsdk_export.h"
#include <string>

namespace enjin::platform::sdk
{
/// \brief Static class which contains members representing the name of each global event on the platform.
class ENJINPLATFORMSDK_EXPORT GlobalEvents final
{
public:
    /// \brief The name of the event for when a Transaction is created.
    static inline const std::string TransactionCreated = "platform:transaction-created";

    /// \brief The name of the event for when a Transaction is updated.
    static inline const std::string TransactionUpdated = "platform:transaction-updated";

    GlobalEvents() = delete;

    /// \brief Class destructor.
    ~GlobalEvents();
};
}

#endif //ENJINPLATFORMSDK_GLOBALEVENTS_HPP
