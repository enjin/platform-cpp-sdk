#include "EnjinPlatformSdk/MultiTokenIdInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
MultiTokenIdInput::MultiTokenIdInput() = default;

[[maybe_unused]]
MultiTokenIdInput::MultiTokenIdInput(const MultiTokenIdInput& other) = default;

[[maybe_unused]]
MultiTokenIdInput::MultiTokenIdInput(MultiTokenIdInput&& other) noexcept = default;

MultiTokenIdInput::~MultiTokenIdInput() = default;

[[maybe_unused]]
MultiTokenIdInput& MultiTokenIdInput::SetCollectionId(SerializableStringPtr collectionId)
{
    return GraphQlParameter<MultiTokenIdInput>::SetParameter("collectionId", std::move(collectionId));
}

MultiTokenIdInput& MultiTokenIdInput::operator=(const MultiTokenIdInput& rhs) = default;

MultiTokenIdInput& MultiTokenIdInput::operator=(MultiTokenIdInput&& rhs) noexcept = default;
