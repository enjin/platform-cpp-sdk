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

#include "EnjinPlatformSdk/BurnParamsInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
BurnParamsInput::BurnParamsInput() = default;

[[maybe_unused]]
BurnParamsInput::BurnParamsInput(const BurnParamsInput& other) = default;

[[maybe_unused]]
BurnParamsInput::BurnParamsInput(BurnParamsInput&& other) noexcept = default;

BurnParamsInput::~BurnParamsInput() = default;

[[maybe_unused]]
BurnParamsInput& BurnParamsInput::SetAmount(SerializableStringPtr amount)
{
    return GraphQlParameter<BurnParamsInput>::SetParameter("amount", std::move(amount));
}

[[maybe_unused]]
BurnParamsInput& BurnParamsInput::SetKeepAlive(SerializableBoolPtr keepAlive)
{
    return GraphQlParameter<BurnParamsInput>::SetParameter("keepAlive", std::move(keepAlive));
}

[[maybe_unused]]
BurnParamsInput& BurnParamsInput::SetRemoveTokenStorage(SerializableBoolPtr removeTokenStorage)
{
    return GraphQlParameter<BurnParamsInput>::SetParameter("removeTokenStorage", std::move(removeTokenStorage));
}

BurnParamsInput& BurnParamsInput::operator=(const BurnParamsInput& rhs) = default;

BurnParamsInput& BurnParamsInput::operator=(BurnParamsInput&& rhs) noexcept = default;
