#include "EnjinPlatformSdk/VerifyMessage.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <memory>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<VerifyMessage>;

[[maybe_unused]]
VerifyMessage::VerifyMessage()
    : RequestType("VerifyMessage", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
VerifyMessage::VerifyMessage(const VerifyMessage& other) = default;

[[maybe_unused]]
VerifyMessage::VerifyMessage(VerifyMessage&& other) noexcept = default;

VerifyMessage::~VerifyMessage() = default;

[[maybe_unused]]
VerifyMessage& VerifyMessage::SetMessage(SerializableStringPtr message)
{
    return RequestType::SetVariable("message", CoreTypes::String, std::move(message));
}

[[maybe_unused]]
VerifyMessage& VerifyMessage::SetSignature(SerializableStringPtr signature)
{
    return RequestType::SetVariable("signature", CoreTypes::String, std::move(signature));
}

[[maybe_unused]]
VerifyMessage& VerifyMessage::SetPublicKey(SerializableStringPtr publicKey)
{
    return RequestType::SetVariable("publicKey", CoreTypes::String, std::move(publicKey));
}

[[maybe_unused]]
VerifyMessage& VerifyMessage::SetCryptoSignatureType(const CryptoSignatureType cryptoSignatureType)
{
    std::string s = enjin::platform::sdk::ToString(cryptoSignatureType);
    SerializableStringPtr sPtr = std::make_shared<SerializableString>(std::move(s));

    return RequestType::SetVariable("cryptoSignatureType", CoreTypes::CryptoSignatureType, std::move(sPtr));
}

VerifyMessage& VerifyMessage::operator=(const VerifyMessage& rhs) = default;

VerifyMessage& VerifyMessage::operator=(VerifyMessage&& rhs) noexcept = default;
