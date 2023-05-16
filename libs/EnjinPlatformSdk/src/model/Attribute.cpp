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

#include "EnjinPlatformSdk/Attribute.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Attribute::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> key;
    std::optional<std::string> value;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetKey() const
    {
        return key;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetValue() const
    {
        return value;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "key", key);
        JsonUtil::TryGetField(json, "value", value);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Attribute

[[maybe_unused]]
Attribute::Attribute()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Attribute::Attribute(const Attribute& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Attribute::Attribute(Attribute&& other) noexcept = default;

Attribute::~Attribute() = default;

[[maybe_unused]]
const std::optional<std::string>& Attribute::GetKey() const
{
    return _pimpl->GetKey();
}

[[maybe_unused]]
const std::optional<std::string>& Attribute::GetValue() const
{
    return _pimpl->GetValue();
}

Attribute& Attribute::operator=(const Attribute& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Attribute& Attribute::operator=(Attribute&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Attribute::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Attribute
