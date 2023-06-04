//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

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
