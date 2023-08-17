#include "EnjinPlatformSdk/GetCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetCollection, CollectionFragment>;

[[maybe_unused]]
GetCollection::GetCollection()
    : RequestType("GetCollection", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetCollection::GetCollection(const GetCollection& other) = default;

[[maybe_unused]]
GetCollection::GetCollection(GetCollection&& other) noexcept = default;

GetCollection::~GetCollection() = default;

[[maybe_unused]]
GetCollection& GetCollection::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

GetCollection& GetCollection::operator=(const GetCollection& rhs) = default;

GetCollection& GetCollection::operator=(GetCollection&& rhs) noexcept = default;
