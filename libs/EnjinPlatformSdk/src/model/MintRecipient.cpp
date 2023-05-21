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

#include "EnjinPlatformSdk/MintRecipient.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
MintRecipient::MintRecipient() = default;

[[maybe_unused]]
MintRecipient::MintRecipient(const MintRecipient& other) = default;

[[maybe_unused]]
MintRecipient::MintRecipient(MintRecipient&& other) noexcept = default;

MintRecipient::~MintRecipient() = default;

[[maybe_unused]]
MintRecipient& MintRecipient::SetAccount(SerializableStringPtr account)
{
    return GraphQlParameter<MintRecipient>::SetParameter("account", std::move(account));
}

[[maybe_unused]]
MintRecipient& MintRecipient::SetCreateParams(CreateTokenParamsPtr createParams)
{
    return GraphQlParameter<MintRecipient>::SetParameter("createParams", std::move(createParams));
}

[[maybe_unused]]
MintRecipient& MintRecipient::SetMintParams(MintTokenParamsPtr mintParams)
{
    return GraphQlParameter<MintRecipient>::SetParameter("mintParams", std::move(mintParams));
}

MintRecipient& MintRecipient::operator=(const MintRecipient& rhs) = default;

MintRecipient& MintRecipient::operator=(MintRecipient&& rhs) noexcept = default;
