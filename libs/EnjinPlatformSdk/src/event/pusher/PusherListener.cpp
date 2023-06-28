#include "PusherListener.hpp"

#include "IPusherEventServiceImpl.hpp"
#include "PusherEvent.hpp"
#include "EnjinPlatformSdk/PlatformEvent.hpp"
#include <string>
#include <vector>

using namespace enjin::platform::sdk;
using namespace pusher;

[[maybe_unused]]
PusherListener::PusherListener(IPusherEventServiceImpl& service)
    : _service(service)
{
}

PusherListener::~PusherListener() = default;

// region ISubscriptionListener

[[maybe_unused]]
void PusherListener::OnEvent(const PusherEvent& evt)
{
    const std::vector<EventListenerRegistrationPtr> registrations = _service.GetRegistrations();

    if (registrations.empty())
    {
        return;
    }

    const std::string& eventName = evt.GetEventName().value();
    const PlatformEvent platformEvent(eventName, evt.GetChannelName().value(), evt.GetData().value());

    for (const EventListenerRegistrationPtr& reg : registrations)
    {
        if (reg->GetMatcher()(eventName))
        {
            reg->GetListener()->OnEvent(platformEvent);
        }
    }
}

// region ISubscriptionListener
