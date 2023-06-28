#include "EnjinPlatformSdk/EventListenerRegistration.hpp"

#include <stdexcept>
#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
EventListenerRegistration::EventListenerRegistration(EventListenerPtr listener, EventMatcher matcher)
    : _matcher(std::move(matcher))
{
    if (listener == nullptr)
    {
        throw std::invalid_argument("Listener cannot be null");
    }

    _listener = std::move(listener);
}

EventListenerRegistration::~EventListenerRegistration() = default;

[[maybe_unused]]
void EventListenerRegistration::SetIsRegistered(const bool isRegistered)
{
    _isRegistered = isRegistered;
}

// region IEventListenerRegistration

[[maybe_unused]]
const EventListenerPtr& EventListenerRegistration::GetListener() const
{
    return _listener;
}

[[maybe_unused]]
const EventMatcher& EventListenerRegistration::GetMatcher() const
{
    return _matcher;
}

[[maybe_unused]]
bool EventListenerRegistration::IsRegistered() const
{
    return _isRegistered;
}

// endregion IEventListenerRegistration
