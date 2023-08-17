#include "EnjinPlatformSdk/SetTokenAttribute.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<SetTokenAttribute, TransactionFragment>;

SetTokenAttribute::SetTokenAttribute()
: RequestType("SetTokenAttribute", GraphQlRequestType::Mutation)
{
}

SetTokenAttribute::SetTokenAttribute(const SetTokenAttribute& other) = default;

SetTokenAttribute::SetTokenAttribute(SetTokenAttribute&& other) noexcept = default;

SetTokenAttribute::~SetTokenAttribute() = default;

SetTokenAttribute& SetTokenAttribute::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

SetTokenAttribute& SetTokenAttribute::SetKey(SerializableStringPtr key)
{
    return RequestType::SetVariable("key", CoreTypes::String, std::move(key));
}

SetTokenAttribute& SetTokenAttribute::SetValue(SerializableStringPtr value)
{
    return RequestType::SetVariable("value", CoreTypes::String, std::move(value));
}

SetTokenAttribute& SetTokenAttribute::operator=(const SetTokenAttribute& rhs) = default;

SetTokenAttribute& SetTokenAttribute::operator=(SetTokenAttribute&& rhs) noexcept = default;
