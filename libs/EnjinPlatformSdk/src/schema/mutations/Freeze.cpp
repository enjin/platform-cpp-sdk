#include "EnjinPlatformSdk/Freeze.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <memory>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<Freeze, TransactionFragment>;

[[maybe_unused]]
Freeze::Freeze()
    : RequestType("Freeze", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
Freeze::Freeze(const Freeze& other) = default;

[[maybe_unused]]
Freeze::Freeze(Freeze&& other) noexcept = default;

Freeze::~Freeze() = default;

[[maybe_unused]]
Freeze& Freeze::SetFreezeType(const FreezeType freezeType)
{
    std::string s = enjin::platform::sdk::ToString(freezeType);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return RequestType::SetVariable("freezeType", CoreTypes::FreezeType, std::move(sPtr));
}

[[maybe_unused]]
Freeze& Freeze::SetFreezeState(const FreezeState freezeState)
{
    std::string s = enjin::platform::sdk::ToString(freezeState);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return RequestType::SetVariable("freezeState", CoreTypes::FreezeState, std::move(sPtr));
}

[[maybe_unused]]
Freeze& Freeze::SetCollection(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
Freeze& Freeze::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
Freeze& Freeze::SetCollectionAccount(SerializableStringPtr collectionAccount)
{
    return RequestType::SetVariable("collectionAccount", CoreTypes::String, std::move(collectionAccount));
}

[[maybe_unused]]
Freeze& Freeze::SetTokeAccount(SerializableStringPtr tokenAccount)
{
    return RequestType::SetVariable("tokenAccount", CoreTypes::String, std::move(tokenAccount));
}

Freeze& Freeze::operator=(const Freeze& rhs) = default;

Freeze& Freeze::operator=(Freeze&& rhs) noexcept = default;
