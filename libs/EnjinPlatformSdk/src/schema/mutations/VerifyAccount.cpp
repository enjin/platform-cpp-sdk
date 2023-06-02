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
