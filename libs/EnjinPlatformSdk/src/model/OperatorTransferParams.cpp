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

#include "EnjinPlatformSdk/OperatorTransferParams.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
OperatorTransferParams::OperatorTransferParams() = default;

[[maybe_unused]]
OperatorTransferParams::OperatorTransferParams(const OperatorTransferParams& other) = default;

[[maybe_unused]]
OperatorTransferParams::OperatorTransferParams(OperatorTransferParams&& other) noexcept = default;

OperatorTransferParams::~OperatorTransferParams() = default;

[[maybe_unused]]
OperatorTransferParams& OperatorTransferParams::SetSource(SerializableStringPtr source)
{
    return GraphQlParameter<OperatorTransferParams>::SetParameter("source", std::move(source));
}

[[maybe_unused]]
OperatorTransferParams& OperatorTransferParams::SetAmount(SerializableStringPtr amount)
{
    return GraphQlParameter<OperatorTransferParams>::SetParameter("amount", std::move(amount));
}

[[maybe_unused]]
OperatorTransferParams& OperatorTransferParams::SetKeepAlive(SerializableBoolPtr keepAlive)
{
    return GraphQlParameter<OperatorTransferParams>::SetParameter("keepAlive", std::move(keepAlive));
}

OperatorTransferParams& OperatorTransferParams::operator=(const OperatorTransferParams& rhs) = default;

OperatorTransferParams& OperatorTransferParams::operator=(OperatorTransferParams&& rhs) noexcept = default;
