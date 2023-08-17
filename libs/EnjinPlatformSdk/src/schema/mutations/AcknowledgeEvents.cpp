#include "EnjinPlatformSdk/AcknowledgeEvents.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<AcknowledgeEvents>;

[[maybe_unused]]
AcknowledgeEvents::AcknowledgeEvents()
    : RequestType("AcknowledgeEvents", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
AcknowledgeEvents::AcknowledgeEvents(const AcknowledgeEvents& other) = default;

[[maybe_unused]]
AcknowledgeEvents::AcknowledgeEvents(AcknowledgeEvents&& other) noexcept = default;

AcknowledgeEvents::~AcknowledgeEvents() = default;

[[maybe_unused]]
AcknowledgeEvents& AcknowledgeEvents::SetUuids(SerializableStringArrayPtr uuids)
{
    return RequestType::SetVariable("uuids", CoreTypes::StringArray, std::move(uuids));
}

AcknowledgeEvents& AcknowledgeEvents::operator=(const AcknowledgeEvents& rhs) = default;

AcknowledgeEvents& AcknowledgeEvents::operator=(AcknowledgeEvents&& rhs) noexcept = default;
