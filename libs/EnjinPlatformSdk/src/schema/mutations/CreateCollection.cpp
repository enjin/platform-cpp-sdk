#include "EnjinPlatformSdk/CreateCollection.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<CreateCollection, TransactionFragment>;

[[maybe_unused]]
CreateCollection::CreateCollection()
    : RequestType("CreateCollection", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
CreateCollection::CreateCollection(const CreateCollection& other) = default;

[[maybe_unused]]
CreateCollection::CreateCollection(CreateCollection&& other) noexcept = default;

CreateCollection::~CreateCollection() = default;

[[maybe_unused]]
CreateCollection& CreateCollection::SetMintPolicy(MintPolicyPtr mintPolicy)
{
    return RequestType::SetVariable("mintPolicy", CoreTypes::MintPolicy, std::move(mintPolicy));
}

[[maybe_unused]]
CreateCollection& CreateCollection::SetMarketPolicy(MarketPolicyPtr marketPolicy)
{
    return RequestType::SetVariable("marketPolicy", CoreTypes::MarketPolicy, std::move(marketPolicy));
}

[[maybe_unused]]
CreateCollection& CreateCollection::SetExplicitRoyaltyCurrencies(
    std::shared_ptr<SerializableArray<MultiTokenIdInput>> explicitRoyaltyCurrencies)
{
    return RequestType::SetVariable("explicitRoyaltyCurrencies",
                                    CoreTypes::MultiTokenIdInputArray,
                                    std::move(explicitRoyaltyCurrencies));
}

[[maybe_unused]]
CreateCollection& CreateCollection::SetAttributes(std::shared_ptr<SerializableArray<AttributeInput>> attributes)
{
    return RequestType::SetVariable("attributes", CoreTypes::AttributeInputArray, std::move(attributes));
}

CreateCollection& CreateCollection::operator=(const CreateCollection& rhs) = default;

CreateCollection& CreateCollection::operator=(CreateCollection&& rhs) noexcept = default;
