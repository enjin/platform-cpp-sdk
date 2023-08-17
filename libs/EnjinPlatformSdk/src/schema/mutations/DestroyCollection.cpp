#include "EnjinPlatformSdk/DestroyCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<DestroyCollection, TransactionFragment>;

[[maybe_unused]]
DestroyCollection::DestroyCollection()
    : RequestType("DestroyCollection", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
DestroyCollection::DestroyCollection(const DestroyCollection& other) = default;

[[maybe_unused]]
DestroyCollection::DestroyCollection(DestroyCollection&& other) noexcept = default;

DestroyCollection::~DestroyCollection() = default;

[[maybe_unused]]
DestroyCollection& DestroyCollection::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

DestroyCollection& DestroyCollection::operator=(const DestroyCollection& rhs) = default;

DestroyCollection& DestroyCollection::operator=(DestroyCollection&& rhs) noexcept = default;
