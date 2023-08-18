#include "EnjinPlatformSdk/CreateTokenParams.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<CreateTokenParams>;

[[maybe_unused]]
CreateTokenParams::CreateTokenParams() = default;

[[maybe_unused]]
CreateTokenParams::CreateTokenParams(const CreateTokenParams& other) = default;

[[maybe_unused]]
CreateTokenParams::CreateTokenParams(CreateTokenParams&& other) noexcept = default;

CreateTokenParams::~CreateTokenParams() = default;

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetInitialSupply(SerializableStringPtr initialSupply)
{
    return ParameterType::SetParameter("initialSupply", std::move(initialSupply));
}

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetUnitPrice(SerializableStringPtr unitPrice)
{
    return ParameterType::SetParameter("unitPrice", std::move(unitPrice));
}

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetCap(TokenMintCapPtr cap)
{
    return ParameterType::SetParameter("cap", std::move(cap));
}

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetBehavior(TokenMarketBehaviorInputPtr behavior)
{
    return ParameterType::SetParameter("behavior", std::move(behavior));
}

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetListingForbidden(SerializableBoolPtr listingForbidden)
{
    return ParameterType::SetParameter("listingForbidden", std::move(listingForbidden));
}

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetAttributes(std::shared_ptr<SerializableArray<AttributeInput>> attributes)
{
    return ParameterType::SetParameter("attributes", std::move(attributes));
}

CreateTokenParams& CreateTokenParams::operator=(const CreateTokenParams& rhs) = default;

CreateTokenParams& CreateTokenParams::operator=(CreateTokenParams&& rhs) noexcept = default;
