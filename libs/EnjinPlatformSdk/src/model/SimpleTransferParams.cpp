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

#include "EnjinPlatformSdk/SimpleTransferParams.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
SimpleTransferParams::SimpleTransferParams() = default;

[[maybe_unused]]
SimpleTransferParams::SimpleTransferParams(const SimpleTransferParams& other) = default;

[[maybe_unused]]
SimpleTransferParams::SimpleTransferParams(SimpleTransferParams&& other) noexcept = default;

SimpleTransferParams::~SimpleTransferParams() = default;

[[maybe_unused]]
SimpleTransferParams& SimpleTransferParams::SetAmount(SerializableStringPtr amount)
{
    return GraphQlParameter<SimpleTransferParams>::SetParameter("amount", std::move(amount));
}

[[maybe_unused]]
SimpleTransferParams& SimpleTransferParams::SetKeepAlive(SerializableBoolPtr keepAlive)
{
    return GraphQlParameter<SimpleTransferParams>::SetParameter("keepAlive", std::move(keepAlive));
}

SimpleTransferParams& SimpleTransferParams::operator=(const SimpleTransferParams& rhs) = default;

SimpleTransferParams& SimpleTransferParams::operator=(SimpleTransferParams&& rhs) noexcept = default;
