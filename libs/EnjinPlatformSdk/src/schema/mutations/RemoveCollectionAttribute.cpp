#include "EnjinPlatformSdk/RemoveCollectionAttribute.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<RemoveCollectionAttribute, TransactionFragment>;

[[maybe_unused]]
RemoveCollectionAttribute::RemoveCollectionAttribute()
    : RequestType("RemoveCollectionAttribute", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
RemoveCollectionAttribute::RemoveCollectionAttribute(const RemoveCollectionAttribute& other) = default;

[[maybe_unused]]
RemoveCollectionAttribute::RemoveCollectionAttribute(RemoveCollectionAttribute&& other) noexcept = default;

RemoveCollectionAttribute::~RemoveCollectionAttribute() = default;

[[maybe_unused]]
RemoveCollectionAttribute& RemoveCollectionAttribute::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
RemoveCollectionAttribute& RemoveCollectionAttribute::SetKey(SerializableStringPtr key)
{
    return RequestType::SetVariable("key", CoreTypes::String, std::move(key));
}

RemoveCollectionAttribute& RemoveCollectionAttribute::operator=(const RemoveCollectionAttribute& rhs) = default;

RemoveCollectionAttribute& RemoveCollectionAttribute::operator=(RemoveCollectionAttribute&& rhs) noexcept = default;
