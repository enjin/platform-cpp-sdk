#include "EnjinPlatformSdk/GetPendingEvents.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetPendingEvents, PendingEventsFragment>;

[[maybe_unused]]
GetPendingEvents::GetPendingEvents()
    : RequestType("GetPendingEvents", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetPendingEvents::GetPendingEvents(const GetPendingEvents& other) = default;

[[maybe_unused]]
GetPendingEvents::GetPendingEvents(GetPendingEvents&& other) noexcept = default;

GetPendingEvents::~GetPendingEvents() = default;

[[maybe_unused]]
GetPendingEvents& GetPendingEvents::SetAcknowledgeEvents(SerializableBoolPtr acknowledgeEvents)
{
    return RequestType::SetVariable("acknowledgeEvents", CoreTypes::Boolean, std::move(acknowledgeEvents));
}

GetPendingEvents& GetPendingEvents::operator=(const GetPendingEvents& rhs) = default;

GetPendingEvents& GetPendingEvents::operator=(GetPendingEvents&& rhs) noexcept = default;
