#include "EnjinPlatformSdk/Burn.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<Burn, TransactionFragment>;

[[maybe_unused]]
Burn::Burn()
    : RequestType("Burn", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
Burn::Burn(const Burn& other) = default;

[[maybe_unused]]
Burn::Burn(Burn&& other) noexcept = default;

Burn::~Burn() = default;

[[maybe_unused]]
Burn& Burn::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
Burn& Burn::SetParams(BurnParamsInputPtr params)
{
    return RequestType::SetVariable("params", CoreTypes::BurnParamsInput, std::move(params));
}

Burn& Burn::operator=(const Burn& rhs) = default;

Burn& Burn::operator=(Burn&& rhs) noexcept = default;
