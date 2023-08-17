#ifndef ENJINPLATFORMSDK_PENDINGEVENTS_HPP
#define ENJINPLATFORMSDK_PENDINGEVENTS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models events that have been broadcasted, but not yet acknowledge.
class ENJINPLATFORMSDK_EXPORT PendingEvents : public Connection<JsonValue>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    PendingEvents();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PendingEvents(const PendingEvents& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PendingEvents(PendingEvents&& other) noexcept;

    /// \brief Class destructor.
    ~PendingEvents() override;

    PendingEvents& operator=(const PendingEvents& rhs);

    PendingEvents& operator=(PendingEvents&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_PENDINGEVENTS_HPP
