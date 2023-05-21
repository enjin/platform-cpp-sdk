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

#include "EnjinPlatformSdk/EncodableTokenIdInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
EncodableTokenIdInput::EncodableTokenIdInput() = default;

[[maybe_unused]]
EncodableTokenIdInput::EncodableTokenIdInput(const EncodableTokenIdInput& other) = default;

[[maybe_unused]]
EncodableTokenIdInput::EncodableTokenIdInput(EncodableTokenIdInput&& other) noexcept = default;

EncodableTokenIdInput::~EncodableTokenIdInput() = default;

[[maybe_unused]]
EncodableTokenIdInput& EncodableTokenIdInput::SetErc1155(Erc1155EncoderInputPtr erc1155)
{
    return GraphQlParameter<EncodableTokenIdInput>::SetParameter("erc1155", std::move(erc1155));
}

[[maybe_unused]]
EncodableTokenIdInput& EncodableTokenIdInput::SetHash(SerializableJsonValuePtr hash)
{
    return GraphQlParameter<EncodableTokenIdInput>::SetParameter("hash", std::move(hash));
}

[[maybe_unused]]
EncodableTokenIdInput& EncodableTokenIdInput::SetInteger(SerializableStringPtr integer)
{
    return GraphQlParameter<EncodableTokenIdInput>::SetParameter("integer", std::move(integer));
}

[[maybe_unused]]
EncodableTokenIdInput& EncodableTokenIdInput::SetStringId(SerializableStringPtr stringId)
{
    return GraphQlParameter<EncodableTokenIdInput>::SetParameter("stringId", std::move(stringId));
}

EncodableTokenIdInput& EncodableTokenIdInput::operator=(const EncodableTokenIdInput& rhs) = default;

EncodableTokenIdInput& EncodableTokenIdInput::operator=(EncodableTokenIdInput&& rhs) noexcept = default;
