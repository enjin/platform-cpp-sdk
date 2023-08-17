#include "EnjinPlatformSdk/BatchSetAttribute.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<BatchSetAttribute, TransactionFragment>;

[[maybe_unused]]
BatchSetAttribute::BatchSetAttribute()
    : RequestType("BatchSetAttribute", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
BatchSetAttribute::BatchSetAttribute(const BatchSetAttribute& other) = default;

[[maybe_unused]]
BatchSetAttribute::BatchSetAttribute(BatchSetAttribute&& other) noexcept = default;

BatchSetAttribute::~BatchSetAttribute() = default;

[[maybe_unused]]
BatchSetAttribute& BatchSetAttribute::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
BatchSetAttribute& BatchSetAttribute::SetAttributes(std::shared_ptr<SerializableArray<AttributeInput>> attributes)
{
    return RequestType::SetVariable("attributes", CoreTypes::AttributeInputArray, std::move(attributes));
}

BatchSetAttribute& BatchSetAttribute::operator=(const BatchSetAttribute& rhs) = default;

BatchSetAttribute& BatchSetAttribute::operator=(BatchSetAttribute&& rhs) noexcept = default;
