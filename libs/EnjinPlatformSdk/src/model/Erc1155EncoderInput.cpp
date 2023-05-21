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

#include "EnjinPlatformSdk/Erc1155EncoderInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
Erc1155EncoderInput::Erc1155EncoderInput() = default;

[[maybe_unused]]
Erc1155EncoderInput::Erc1155EncoderInput(const Erc1155EncoderInput& other) = default;

[[maybe_unused]]
Erc1155EncoderInput::Erc1155EncoderInput(Erc1155EncoderInput&& other) noexcept = default;

Erc1155EncoderInput::~Erc1155EncoderInput() = default;

[[maybe_unused]]
Erc1155EncoderInput& Erc1155EncoderInput::SetTokenId(SerializableStringPtr tokenId)
{
    return GraphQlParameter<Erc1155EncoderInput>::SetParameter("tokenId", std::move(tokenId));
}

[[maybe_unused]]
Erc1155EncoderInput& Erc1155EncoderInput::SetIndex(SerializableStringPtr index)
{
    return GraphQlParameter<Erc1155EncoderInput>::SetParameter("index", std::move(index));
}

Erc1155EncoderInput& Erc1155EncoderInput::operator=(const Erc1155EncoderInput& rhs) = default;

Erc1155EncoderInput& Erc1155EncoderInput::operator=(Erc1155EncoderInput&& rhs) noexcept = default;
