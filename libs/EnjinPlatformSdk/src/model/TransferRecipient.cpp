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

#include "EnjinPlatformSdk/TransferRecipient.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
TransferRecipient::TransferRecipient() = default;

[[maybe_unused]]
TransferRecipient::TransferRecipient(const TransferRecipient& other) = default;

[[maybe_unused]]
TransferRecipient::TransferRecipient(TransferRecipient&& other) noexcept = default;

TransferRecipient::~TransferRecipient() = default;

[[maybe_unused]]
TransferRecipient& TransferRecipient::SetAccount(SerializableStringPtr account)
{
    return GraphQlParameter<TransferRecipient>::SetParameter("account", std::move(account));
}

[[maybe_unused]]
TransferRecipient& TransferRecipient::SetSimpleParams(SimpleTransferParamsPtr simpleParams)
{
    return GraphQlParameter<TransferRecipient>::SetParameter("simpleParams", std::move(simpleParams));
}

[[maybe_unused]]
TransferRecipient& TransferRecipient::SetOperatorParams(OperatorTransferParamsPtr operatorParams)
{
    return GraphQlParameter<TransferRecipient>::SetParameter("operatorParams", std::move(operatorParams));
}

TransferRecipient& TransferRecipient::operator=(const TransferRecipient& rhs) = default;

TransferRecipient& TransferRecipient::operator=(TransferRecipient&& rhs) noexcept = default;
