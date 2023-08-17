#include "EnjinPlatformSdk/GetCollections.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetCollections, CollectionConnectionFragment>;

[[maybe_unused]]
GetCollections::GetCollections()
    : RequestType("GetCollections", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetCollections::GetCollections(const GetCollections& other) = default;

[[maybe_unused]]
GetCollections::GetCollections(GetCollections&& other) noexcept = default;

GetCollections::~GetCollections() = default;

[[maybe_unused]]
GetCollections& GetCollections::SetCollectionIds(SerializableStringArrayPtr collectionIds)
{
    return RequestType::SetVariable("collectionIds", CoreTypes::BigIntArray, std::move(collectionIds));
}

GetCollections& GetCollections::operator=(const GetCollections& rhs) = default;

GetCollections& GetCollections::operator=(GetCollections&& rhs) noexcept = default;
