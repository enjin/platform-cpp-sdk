#include "EnjinPlatformSdk/UnapproveCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<UnapproveCollection, TransactionFragment>;

[[maybe_unused]]
UnapproveCollection::UnapproveCollection()
    : RequestType("UnapproveCollection", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
UnapproveCollection::UnapproveCollection(const UnapproveCollection& other) = default;

[[maybe_unused]]
UnapproveCollection::UnapproveCollection(UnapproveCollection&& other) noexcept = default;

UnapproveCollection::~UnapproveCollection() = default;

[[maybe_unused]]
UnapproveCollection& UnapproveCollection::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
UnapproveCollection& UnapproveCollection::SetOperator(SerializableStringPtr op)
{
    return RequestType::SetVariable("operator", CoreTypes::String, std::move(op));
}

UnapproveCollection& UnapproveCollection::operator=(const UnapproveCollection& rhs) = default;

UnapproveCollection& UnapproveCollection::operator=(UnapproveCollection&& rhs) noexcept = default;
