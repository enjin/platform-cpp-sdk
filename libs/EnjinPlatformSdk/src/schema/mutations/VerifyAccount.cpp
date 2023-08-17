#include "EnjinPlatformSdk/VerifyAccount.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <memory>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<VerifyAccount>;

[[maybe_unused]]
VerifyAccount::VerifyAccount()
    : RequestType("VerifyAccount", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
VerifyAccount::VerifyAccount(const VerifyAccount& other) = default;

[[maybe_unused]]
VerifyAccount::VerifyAccount(VerifyAccount&& other) noexcept = default;

VerifyAccount::~VerifyAccount() = default;

[[maybe_unused]]
VerifyAccount& VerifyAccount::SetVerificationId(SerializableStringPtr verificationId)
{
    return RequestType::SetVariable("verificationId", CoreTypes::String, std::move(verificationId));
}

[[maybe_unused]]
VerifyAccount& VerifyAccount::SetSignature(SerializableStringPtr signature)
{
    return RequestType::SetVariable("signature", CoreTypes::String, std::move(signature));
}

[[maybe_unused]]
VerifyAccount& VerifyAccount::SetAccount(SerializableStringPtr account)
{
    return RequestType::SetVariable("account", CoreTypes::String, std::move(account));
}

[[maybe_unused]]
VerifyAccount& VerifyAccount::SetCryptoSignatureType(const CryptoSignatureType cryptoSignatureType)
{
    std::string s = enjin::platform::sdk::ToString(cryptoSignatureType);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return RequestType::SetVariable("cryptoSignatureType", CoreTypes::CryptoSignatureType, std::move(sPtr));
}

VerifyAccount& VerifyAccount::operator=(const VerifyAccount& rhs) = default;

VerifyAccount& VerifyAccount::operator=(VerifyAccount&& rhs) noexcept = default;
