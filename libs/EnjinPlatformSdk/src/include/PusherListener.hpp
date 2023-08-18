#ifndef ENJINPLATFORMSDK_PUSHERLISTENER_HPP
#define ENJINPLATFORMSDK_PUSHERLISTENER_HPP

#include "enjinplatformsdk_export.h"
#include "IPusherEventServiceImpl.hpp"
#include "ISubscriptionListener.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class PusherEventService;

// endregion Forward declarations

/// \brief A listener class used by a <see cref="IPusherEventServiceImpl"/> for processing events received broadcasted
/// through a Pusher client.
class ENJINPLATFORMSDK_EXPORT PusherListener : public virtual pusher::ISubscriptionListener
{
    IPusherEventServiceImpl& _service;

public:
    PusherListener() = delete;

    /// \brief Constructs an instance of this class for the given service.
    /// \param service The event service this listener is for.
    [[maybe_unused]]
    explicit PusherListener(IPusherEventServiceImpl& service);

    PusherListener(const PusherListener& other) = delete;

    PusherListener(PusherListener&& other) noexcept = delete;

    /// \brief Class destructor.
    ~PusherListener() override;

    PusherListener& operator=(const PusherListener& rhs) = delete;

    PusherListener& operator=(PusherListener&& rhs) noexcept = delete;

    // region ISubscriptionListener

    [[maybe_unused]]
    void OnEvent(const pusher::PusherEvent& evt) override;

    // endregion ISubscriptionListener
};
}

#endif //ENJINPLATFORMSDK_PUSHERLISTENER_HPP
