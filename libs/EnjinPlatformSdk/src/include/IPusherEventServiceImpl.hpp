#ifndef ENJINPLATFORMSDK_IPUSHEREVENTSERVICEIMPL_HPP
#define ENJINPLATFORMSDK_IPUSHEREVENTSERVICEIMPL_HPP

#include "EnjinPlatformSdk/EventListenerRegistration.hpp"
#include "EnjinPlatformSdk/IEventService.hpp"
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Interface to be implemented by internal Pusher event services.
class IPusherEventServiceImpl : public virtual IEventService
{
public:
    /// \brief Class destructor.
    ~IPusherEventServiceImpl() override = default;

    /// \brief Returns the event listener registrations of this service.
    /// \return The registrations.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::vector<EventListenerRegistrationPtr> GetRegistrations() const = 0;
};
}

#endif //ENJINPLATFORMSDK_IPUSHEREVENTSERVICEIMPL_HPP
