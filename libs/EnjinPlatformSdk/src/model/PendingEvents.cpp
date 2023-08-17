#include "EnjinPlatformSdk/PendingEvents.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
PendingEvents::PendingEvents() = default;

[[maybe_unused]]
PendingEvents::PendingEvents(const PendingEvents& other) = default;

[[maybe_unused]]
PendingEvents::PendingEvents(PendingEvents&& other) noexcept = default;

PendingEvents::~PendingEvents() = default;

PendingEvents& PendingEvents::operator=(const PendingEvents& rhs) = default;

PendingEvents& PendingEvents::operator=(PendingEvents&& rhs) noexcept = default;
