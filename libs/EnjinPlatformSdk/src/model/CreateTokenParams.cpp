#include "EnjinPlatformSdk/CreateTokenParams.hpp"

#include <utility>

using namespace enjin::platform::sdk;

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
    return GraphQlParameter<CreateTokenParams>::SetParameter("initialSupply", std::move(initialSupply));
}

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetUnitPrice(SerializableStringPtr unitPrice)
{
    return GraphQlParameter<CreateTokenParams>::SetParameter("unitPrice", std::move(unitPrice));
}

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetCap(TokenMintCapPtr cap)
{
    return GraphQlParameter<CreateTokenParams>::SetParameter("cap", std::move(cap));
}

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetBehavior(TokenMarketBehaviorInputPtr behavior)
{
    return GraphQlParameter<CreateTokenParams>::SetParameter("behavior", std::move(behavior));
}

[[maybe_unused]]
CreateTokenParams& CreateTokenParams::SetListingForbidden(SerializableBoolPtr listingForbidden)
{
    return GraphQlParameter<CreateTokenParams>::SetParameter("listingForbidden", std::move(listingForbidden));
}

CreateTokenParams& CreateTokenParams::operator=(const CreateTokenParams& rhs) = default;

CreateTokenParams& CreateTokenParams::operator=(CreateTokenParams&& rhs) noexcept = default;
