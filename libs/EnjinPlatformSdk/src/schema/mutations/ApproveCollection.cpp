#include "EnjinPlatformSdk/ApproveCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<ApproveCollection, TransactionFragment>;

[[maybe_unused]]
ApproveCollection::ApproveCollection()
    : RequestType("ApproveCollection", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
ApproveCollection::ApproveCollection(const ApproveCollection& other) = default;

[[maybe_unused]]
ApproveCollection::ApproveCollection(ApproveCollection&& other) noexcept = default;

ApproveCollection::~ApproveCollection() = default;

[[maybe_unused]]
ApproveCollection& ApproveCollection::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::String, std::move(collectionId));
}

[[maybe_unused]]
ApproveCollection& ApproveCollection::SetOperator(SerializableStringPtr op)
{
    return RequestType::SetVariable("operator", CoreTypes::String, std::move(op));
}

[[maybe_unused]]
ApproveCollection& ApproveCollection::SetExpiration(SerializableIntPtr expiration)
{
    return RequestType::SetVariable("expiration", CoreTypes::Int, std::move(expiration));
}

ApproveCollection& ApproveCollection::operator=(const ApproveCollection& rhs) = default;

ApproveCollection& ApproveCollection::operator=(ApproveCollection&& rhs) noexcept = default;
