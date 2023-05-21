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

#include "EnjinPlatformSdk/MintPolicy.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
MintPolicy::MintPolicy() = default;

[[maybe_unused]]
MintPolicy::MintPolicy(const MintPolicy& other) = default;

[[maybe_unused]]
MintPolicy::MintPolicy(MintPolicy&& other) noexcept = default;

MintPolicy::~MintPolicy() = default;

[[maybe_unused]]
MintPolicy& MintPolicy::SetMaxTokenCount(SerializableStringPtr maxTokenCount)
{
    return GraphQlParameter<MintPolicy>::SetParameter("maxTokenCount", std::move(maxTokenCount));
}

[[maybe_unused]]
MintPolicy& MintPolicy::SetMaxTokenSupply(SerializableStringPtr maxTokenSupply)
{
    return GraphQlParameter<MintPolicy>::SetParameter("maxTokenSupply", std::move(maxTokenSupply));
}

[[maybe_unused]]
MintPolicy& MintPolicy::SetForceSingleMint(SerializableBoolPtr forceSingleMint)
{
    return GraphQlParameter<MintPolicy>::SetParameter("forceSingleMint", std::move(forceSingleMint));
}

MintPolicy& MintPolicy::operator=(const MintPolicy& rhs) = default;

MintPolicy& MintPolicy::operator=(MintPolicy&& rhs) noexcept = default;
