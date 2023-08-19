#ifndef ENJINPLATFORMSDK_EVENTLISTENERREGISTRATION_HPP
#define ENJINPLATFORMSDK_EVENTLISTENERREGISTRATION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IEventListenerRegistration.hpp"
#include "EnjinPlatformSdk/PusherEventService.hpp"

namespace enjin::platform::sdk
{
/// \brief Implementation class for event listener registrations.
class ENJINPLATFORMSDK_EXPORT EventListenerRegistration : public virtual IEventListenerRegistration
{
    bool _isRegistered = false;
    EventListenerPtr _listener;
    EventMatcher _matcher;

public:
    /// \brief Event matcher that matches for any event provided to it.
    inline static EventMatcher AllowAllMatcher = [](const std::string&) {
        return true;
    };

    EventListenerRegistration() = delete;

    EventListenerRegistration(const EventListenerRegistration& other) = delete;

    EventListenerRegistration(EventListenerRegistration&& other) noexcept = delete;

    /// \brief Class destructor.
    ~EventListenerRegistration() override;

    EventListenerRegistration& operator=(const EventListenerRegistration& rhs) = delete;

    EventListenerRegistration& operator=(EventListenerRegistration&& rhs) noexcept = delete;

    // region IEventListenerRegistration

    [[maybe_unused]]
    [[nodiscard]]
    const EventListenerPtr& GetListener() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const EventMatcher& GetMatcher() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsRegistered() const override;

    // endregion IEventListenerRegistration

private:
    /// \brief Constructs an instance of this class with the given listener and event matcher.
    /// \param listener The listener.
    /// \param matcher The event matcher.
    /// \throws std::invalid_argument If listener is null.
    [[maybe_unused]]
    EventListenerRegistration(EventListenerPtr listener, EventMatcher matcher);

    /// \brief Sets whether this registration is active.
    /// \param isRegistered Whether this registration is active.
    [[maybe_unused]]
    void SetIsRegistered(bool isRegistered);

    friend class PusherEventService;
};
}

#endif //ENJINPLATFORMSDK_EVENTLISTENERREGISTRATION_HPP
