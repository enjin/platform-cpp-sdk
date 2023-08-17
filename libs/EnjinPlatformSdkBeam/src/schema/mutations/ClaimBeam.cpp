#include "EnjinPlatformSdkBeam/ClaimBeam.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <memory>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<ClaimBeam>;

[[maybe_unused]]
ClaimBeam::ClaimBeam()
    : RequestType("ClaimBeam", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
ClaimBeam::ClaimBeam(const ClaimBeam& other) = default;

[[maybe_unused]]
ClaimBeam::ClaimBeam(ClaimBeam&& other) noexcept = default;

ClaimBeam::~ClaimBeam() = default;

[[maybe_unused]]
ClaimBeam& ClaimBeam::SetCode(SerializableStringPtr code)
{
    return RequestType::SetVariable("code", CoreTypes::String, std::move(code));
}

[[maybe_unused]]
ClaimBeam& ClaimBeam::SetAccount(SerializableStringPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

[[maybe_unused]]
ClaimBeam& ClaimBeam::SetSignature(SerializableStringPtr signature)
{
    return RequestType::SetVariable("signature", CoreTypes::String, std::move(signature));
}

[[maybe_unused]]
ClaimBeam& ClaimBeam::SetCryptoSignatureType(const CryptoSignatureType cryptoSignatureType)
{
    std::string s = enjin::platform::sdk::ToString(cryptoSignatureType);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return RequestType::SetVariable("cryptoSignatureType", CoreTypes::CryptoSignatureType, std::move(sPtr));
}

ClaimBeam& ClaimBeam::operator=(const ClaimBeam& rhs) = default;

ClaimBeam& ClaimBeam::operator=(ClaimBeam&& rhs) noexcept = default;
