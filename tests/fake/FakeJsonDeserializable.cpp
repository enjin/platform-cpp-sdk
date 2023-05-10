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

#include "FakeJsonDeserializable.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable() = default;

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable(const bool field)
    : _field(field)
{
}

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable(const FakeJsonDeserializable& other) = default;

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable(FakeJsonDeserializable&& other) noexcept = default;

FakeJsonDeserializable::~FakeJsonDeserializable() = default;

FakeJsonDeserializable& FakeJsonDeserializable::operator=(const FakeJsonDeserializable& rhs) = default;

FakeJsonDeserializable& FakeJsonDeserializable::operator=(FakeJsonDeserializable&& rhs) noexcept = default;

bool FakeJsonDeserializable::operator==(const FakeJsonDeserializable& rhs) const = default;

bool FakeJsonDeserializable::operator!=(const FakeJsonDeserializable& rhs) const = default;

// region IJsonDeserializable

[[maybe_unused]]
void FakeJsonDeserializable::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    JsonUtil::TryGetField(json, "field", _field);
}

// endregion IJsonDeserializable
