#include "EnjinPlatformSdk/Thaw.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <memory>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<Thaw, TransactionFragment>;

[[maybe_unused]]
Thaw::Thaw()
    : RequestType("Thaw", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
Thaw::Thaw(const Thaw& other) = default;

[[maybe_unused]]
Thaw::Thaw(Thaw&& other) noexcept = default;

Thaw::~Thaw() = default;

[[maybe_unused]]
Thaw& Thaw::SetFreezeType(const FreezeType freezeType)
{
    std::string s = enjin::platform::sdk::ToString(freezeType);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return RequestType::SetVariable("freezeType", CoreTypes::FreezeType, std::move(sPtr));
}

[[maybe_unused]]
Thaw& Thaw::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
Thaw& Thaw::SetCollectionAccount(SerializableStringPtr collectionAccount)
{
    return RequestType::SetVariable("collectionAccount", CoreTypes::String, std::move(collectionAccount));
}

[[maybe_unused]]
Thaw& Thaw::SetTokenAccount(SerializableStringPtr tokenAccount)
{
    return RequestType::SetVariable("tokenAccount", CoreTypes::String, std::move(tokenAccount));
}

Thaw& Thaw::operator=(const Thaw& rhs) = default;

Thaw& Thaw::operator=(Thaw&& rhs) noexcept = default;
