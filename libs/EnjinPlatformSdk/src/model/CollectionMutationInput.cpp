#include "EnjinPlatformSdk/CollectionMutationInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
CollectionMutationInput::CollectionMutationInput() = default;

[[maybe_unused]]
CollectionMutationInput::CollectionMutationInput(const CollectionMutationInput& other) = default;

[[maybe_unused]]
CollectionMutationInput::CollectionMutationInput(CollectionMutationInput&& other) noexcept = default;

CollectionMutationInput::~CollectionMutationInput() = default;

[[maybe_unused]]
CollectionMutationInput& CollectionMutationInput::SetOwner(SerializableStringPtr owner)
{
    return GraphQlParameter<CollectionMutationInput>::SetParameter("owner", std::move(owner));
}

[[maybe_unused]]
CollectionMutationInput& CollectionMutationInput::SetRoyalty(MutateRoyaltyInputPtr royalty)
{
    return GraphQlParameter<CollectionMutationInput>::SetParameter("royalty", std::move(royalty));
}

[[maybe_unused]]
CollectionMutationInput&
CollectionMutationInput::SetExplicitRoyaltyCurrencies(MultiTokenIdInputPtr explicitRoyaltyCurrencies)
{
    return GraphQlParameter<CollectionMutationInput>::SetParameter("explicitRoyaltyCurrencies",
                                                                   std::move(explicitRoyaltyCurrencies));
}

CollectionMutationInput& CollectionMutationInput::operator=(const CollectionMutationInput& rhs) = default;

CollectionMutationInput& CollectionMutationInput::operator=(CollectionMutationInput&& rhs) noexcept = default;
