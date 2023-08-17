#include "EnjinPlatformSdk/RemoveAllAttributes.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<RemoveAllAttributes, TransactionFragment>;

[[maybe_unused]]
RemoveAllAttributes::RemoveAllAttributes()
    : RequestType("RemoveAllAttributes", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
RemoveAllAttributes::RemoveAllAttributes(const RemoveAllAttributes& other) = default;

[[maybe_unused]]
RemoveAllAttributes::RemoveAllAttributes(RemoveAllAttributes&& other) noexcept = default;

RemoveAllAttributes::~RemoveAllAttributes() = default;

[[maybe_unused]]
RemoveAllAttributes& RemoveAllAttributes::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
RemoveAllAttributes& RemoveAllAttributes::SetAttributeCount(SerializableIntPtr attributeCount)
{
    return RequestType::SetVariable("attributeCount", CoreTypes::BigInt, std::move(attributeCount));
}

RemoveAllAttributes& RemoveAllAttributes::operator=(const RemoveAllAttributes& rhs) = default;

RemoveAllAttributes& RemoveAllAttributes::operator=(RemoveAllAttributes&& rhs) noexcept = default;
