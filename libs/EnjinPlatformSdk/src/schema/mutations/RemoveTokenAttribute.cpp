#include "EnjinPlatformSdk/RemoveTokenAttribute.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<RemoveTokenAttribute, TransactionFragment>;

[[maybe_unused]]
RemoveTokenAttribute::RemoveTokenAttribute()
    : RequestType("RemoveTokenAttribute", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
RemoveTokenAttribute::RemoveTokenAttribute(const RemoveTokenAttribute& other) = default;

[[maybe_unused]]
RemoveTokenAttribute::RemoveTokenAttribute(RemoveTokenAttribute&& other) noexcept = default;

RemoveTokenAttribute::~RemoveTokenAttribute() = default;

[[maybe_unused]]
RemoveTokenAttribute& RemoveTokenAttribute::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
RemoveTokenAttribute& RemoveTokenAttribute::SetKey(SerializableStringPtr key)
{
    return RequestType::SetVariable("key", CoreTypes::String, std::move(key));
}

RemoveTokenAttribute& RemoveTokenAttribute::operator=(const RemoveTokenAttribute& rhs) = default;

RemoveTokenAttribute& RemoveTokenAttribute::operator=(RemoveTokenAttribute&& rhs) noexcept = default;
