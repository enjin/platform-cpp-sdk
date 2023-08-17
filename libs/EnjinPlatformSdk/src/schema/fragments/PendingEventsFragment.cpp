#include "EnjinPlatformSdk/PendingEventsFragment.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
PendingEventsFragment::PendingEventsFragment() = default;

[[maybe_unused]]
PendingEventsFragment::PendingEventsFragment(const PendingEventsFragment& other) = default;

[[maybe_unused]]
PendingEventsFragment::PendingEventsFragment(PendingEventsFragment&& other) noexcept = default;

PendingEventsFragment::~PendingEventsFragment() = default;

PendingEventsFragment& PendingEventsFragment::operator=(const PendingEventsFragment& rhs) = default;

PendingEventsFragment& PendingEventsFragment::operator=(PendingEventsFragment&& rhs) noexcept = default;
