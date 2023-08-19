#include "EnjinPlatformSdk/CollectionMutationInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<CollectionMutationInput>;

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
    return ParameterType::SetParameter("owner", std::move(owner));
}

[[maybe_unused]]
CollectionMutationInput& CollectionMutationInput::SetRoyalty(MutateRoyaltyInputPtr royalty)
{
    return ParameterType::SetParameter("royalty", std::move(royalty));
}

[[maybe_unused]]
CollectionMutationInput&
CollectionMutationInput::SetExplicitRoyaltyCurrencies(MultiTokenIdInputPtr explicitRoyaltyCurrencies)
{
    return ParameterType::SetParameter("explicitRoyaltyCurrencies",
                                       std::move(explicitRoyaltyCurrencies));
}

CollectionMutationInput& CollectionMutationInput::operator=(const CollectionMutationInput& rhs) = default;

CollectionMutationInput& CollectionMutationInput::operator=(CollectionMutationInput&& rhs) noexcept = default;
