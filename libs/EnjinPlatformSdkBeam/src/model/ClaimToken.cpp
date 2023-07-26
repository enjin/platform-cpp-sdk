#include "EnjinPlatformSdkBeam/ClaimToken.hpp"

#include "EnjinPlatformSdk/SerializableString.hpp"
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using ParameterType = GraphQlParameter<ClaimToken>;

[[maybe_unused]]
ClaimToken::ClaimToken() = default;

[[maybe_unused]]
ClaimToken::ClaimToken(const ClaimToken& other) = default;

[[maybe_unused]]
ClaimToken::ClaimToken(ClaimToken&& other) noexcept = default;

ClaimToken::~ClaimToken() = default;

[[maybe_unused]]
ClaimToken& ClaimToken::SetTokenIds(std::shared_ptr<SerializableArray<IntegerRange>> tokenIds)
{
    return ParameterType::SetParameter("tokenIds", std::move(tokenIds));
}

[[maybe_unused]]
ClaimToken& ClaimToken::SetTokenIdDataUpload(UploadPtr tokenIdDataUpload)
{
    return ParameterType::SetParameter("tokenIdDataUpload", std::move(tokenIdDataUpload));
}

[[maybe_unused]]
ClaimToken& ClaimToken::SetAttributes(std::shared_ptr<SerializableArray<AttributeInput>> attributes)
{
    return ParameterType::SetParameter("attributes", std::move(attributes));
}

[[maybe_unused]]
ClaimToken& ClaimToken::SetTokenQuantityPerClaim(SerializableIntPtr tokenQuantityPerClaim)
{
    return ParameterType::SetParameter("tokenQuantityPerClaim", std::move(tokenQuantityPerClaim));
}

[[maybe_unused]]
ClaimToken& ClaimToken::SetClaimQuantity(SerializableIntPtr claimQuantity)
{
    return ParameterType::SetParameter("claimQuantity", std::move(claimQuantity));
}

[[maybe_unused]]
ClaimToken& ClaimToken::SetType(const BeamType type)
{
    constexpr char key[] = "type";

    if (type == BeamType::None)
    {
        return ParameterType::RemoveParameter(key);
    }

    std::string s = enjin::platform::sdk::beam::ToString(type);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return ParameterType::SetParameter(key, std::move(sPtr));
}

ClaimToken& ClaimToken::operator=(const ClaimToken& rhs) = default;

ClaimToken& ClaimToken::operator=(ClaimToken&& rhs) noexcept = default;
