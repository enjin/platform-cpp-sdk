#ifndef ENJINPLATFORMSDK_PENDINGEVENTSFRAGMENT_HPP
#define ENJINPLATFORMSDK_PENDINGEVENTSFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class PendingEventsFragment;

/// \brief Definition for a pointer containing a PendingEventsFragment.
using PendingEventsFragmentPtr [[maybe_unused]] = std::shared_ptr<PendingEventsFragment>;

/// \brief A fragment for requesting properties of a pending events returned by the platform.
class ENJINPLATFORMSDK_EXPORT PendingEventsFragment : public ConnectionFragment<>
{
public:
    /// \brief Constructs an instance of this class.
    PendingEventsFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    PendingEventsFragment(const PendingEventsFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    PendingEventsFragment(PendingEventsFragment&& other) noexcept;

    /// \brief Class destructor.
    ~PendingEventsFragment() override;

    PendingEventsFragment& operator=(const PendingEventsFragment& rhs);

    PendingEventsFragment& operator=(PendingEventsFragment&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_PENDINGEVENTSFRAGMENT_HPP
