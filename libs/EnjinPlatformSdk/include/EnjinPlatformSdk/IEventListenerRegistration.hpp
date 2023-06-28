#ifndef ENJINPLATFORMSDK_IEVENTLISTENERREGISTRATION_HPP
#define ENJINPLATFORMSDK_IEVENTLISTENERREGISTRATION_HPP

#include "EnjinPlatformSdk/IEventListener.hpp"
#include <functional>
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
class IEventListenerRegistration;

/// \brief Definition for a pointer containing an event listener registration.
[[maybe_unused]]
typedef std::shared_ptr<IEventListenerRegistration> EventListenerRegistrationPtr;

/// \brief Definition for a function wrapper that takes a string and returns a boolean.
typedef std::function<bool(std::string)> EventMatcher;

/// \brief Interface to be implemented by event listener registrations.
class IEventListenerRegistration
{
public:
    /// \brief Class destructor.
    virtual ~IEventListenerRegistration() = default;

    /// \brief Returns the event listener for this registration.
    /// \return The event listener.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const EventListenerPtr& GetListener() const = 0;

    /// \brief Returns the event matcher for this registration.
    /// \return The event matcher.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const EventMatcher& GetMatcher() const = 0;

    /// \brief Determines whether this registration is still an active registration in its event service.
    /// \return Whether this registration is still a active.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool IsRegistered() const = 0;
};
}

#endif //ENJINPLATFORMSDK_IEVENTLISTENERREGISTRATION_HPP
