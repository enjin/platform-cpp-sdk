#ifndef ENJINPLATFORMSDK_ISUBSCRIPTIONLISTENER_HPP
#define ENJINPLATFORMSDK_ISUBSCRIPTIONLISTENER_HPP

#include "PusherEvent.hpp"
#include <memory>

namespace pusher
{
class ISubscriptionListener;

/// \brief Definition for a pointer wrapping a ISubscriptionListener.
using SubscriptionListenerPtr [[maybe_unused]] = std::shared_ptr<ISubscriptionListener>;

/// \brief Interface for event listener for receiving Pusher events.
class ISubscriptionListener
{
public:
    /// \brief Class destructor.
    virtual ~ISubscriptionListener() = default;

    /// \brief Handler for Pusher events.
    /// \param evt The Pusher event.
    virtual void OnEvent(const PusherEvent& evt) = 0;
};
}

#endif //ENJINPLATFORMSDK_ISUBSCRIPTIONLISTENER_HPP
