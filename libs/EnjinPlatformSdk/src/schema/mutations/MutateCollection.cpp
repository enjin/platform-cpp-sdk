#include "EnjinPlatformSdk/MutateCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<MutateCollection, TransactionFragment>;

[[maybe_unused]]
MutateCollection::MutateCollection()
    : RequestType("MutateCollection", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
MutateCollection::MutateCollection(const MutateCollection& other) = default;

[[maybe_unused]]
MutateCollection::MutateCollection(MutateCollection&& other) noexcept = default;

MutateCollection::~MutateCollection() = default;

[[maybe_unused]]
MutateCollection& MutateCollection::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
MutateCollection& MutateCollection::SetMutation(CollectionMutationInputPtr mutation)
{
    return RequestType::SetVariable("mutation", CoreTypes::CollectionMutationInput, std::move(mutation));
}

MutateCollection& MutateCollection::operator=(const MutateCollection& rhs) = default;

MutateCollection& MutateCollection::operator=(MutateCollection&& rhs) noexcept = default;
