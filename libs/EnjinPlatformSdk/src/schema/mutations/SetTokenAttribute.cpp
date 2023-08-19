#include "EnjinPlatformSdk/SetTokenAttribute.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<SetTokenAttribute, TransactionFragment>;

[[maybe_unused]]
SetTokenAttribute::SetTokenAttribute()
    : RequestType("SetTokenAttribute", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
SetTokenAttribute::SetTokenAttribute(const SetTokenAttribute& other) = default;

[[maybe_unused]]
SetTokenAttribute::SetTokenAttribute(SetTokenAttribute&& other) noexcept = default;

SetTokenAttribute::~SetTokenAttribute() = default;

[[maybe_unused]]
SetTokenAttribute& SetTokenAttribute::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
SetTokenAttribute& SetTokenAttribute::SetKey(SerializableStringPtr key)
{
    return RequestType::SetVariable("key", CoreTypes::String, std::move(key));
}

[[maybe_unused]]
SetTokenAttribute& SetTokenAttribute::SetValue(SerializableStringPtr value)
{
    return RequestType::SetVariable("value", CoreTypes::String, std::move(value));
}

SetTokenAttribute& SetTokenAttribute::operator=(const SetTokenAttribute& rhs) = default;

SetTokenAttribute& SetTokenAttribute::operator=(SetTokenAttribute&& rhs) noexcept = default;
