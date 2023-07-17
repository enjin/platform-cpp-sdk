#ifndef ENJINPLATFORMSDK_IEVENTLISTENER_HPP
#define ENJINPLATFORMSDK_IEVENTLISTENER_HPP

#include "EnjinPlatformSdk/PlatformEvent.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class IEventListener;

/// \brief Definition for a pointer containing an event listener.
[[maybe_unused]]
typedef std::shared_ptr<IEventListener> EventListenerPtr;

/// \brief Interface to be implemented by event listeners for receiving a platform event from an event service.
class IEventListener
{
public:
    /// \brief Class destructor.
    virtual ~IEventListener() = default;

    /// \brief Method to be called by an event service when an event has been received from the platform.
    /// \param evt The platform event.
    [[maybe_unused]]
    virtual void OnEvent(const PlatformEvent& evt) = 0;
};
}

#endif //ENJINPLATFORMSDK_IEVENTLISTENER_HPP
