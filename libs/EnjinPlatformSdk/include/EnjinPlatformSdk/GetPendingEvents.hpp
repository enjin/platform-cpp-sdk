#ifndef ENJINPLATFORMSDK_GETPENDINGEVENTS_HPP
#define ENJINPLATFORMSDK_GETPENDINGEVENTS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/PendingEventsFragment.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying a list of events that were broadcasted but not yet acknowledged.
class ENJINPLATFORMSDK_EXPORT GetPendingEvents : public GraphQlRequest<GetPendingEvents, PendingEventsFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetPendingEvents();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetPendingEvents(const GetPendingEvents& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetPendingEvents(GetPendingEvents&& other) noexcept;

    /// \brief Class destructor.
    ~GetPendingEvents() override;

    /// \brief Sets whether to automatically acknowledge all returned events.
    /// \param acknowledgeEvents Whether to acknowledge all returned events.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetPendingEvents& SetAcknowledgeEvents(SerializableBoolPtr acknowledgeEvents);

    GetPendingEvents& operator=(const GetPendingEvents& rhs);

    GetPendingEvents& operator=(GetPendingEvents&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETPENDINGEVENTS_HPP
