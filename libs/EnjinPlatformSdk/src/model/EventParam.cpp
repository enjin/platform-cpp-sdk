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

#include "EnjinPlatformSdk/EventParam.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class EventParam::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> type;
    std::optional<JsonValue> value;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetType() const
    {
        return type;
    }

    [[nodiscard]]
    const std::optional<JsonValue>& GetValue() const
    {
        return value;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "type", type);
        JsonUtil::TryGetField(json, "value", value);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region EventParam

[[maybe_unused]]
EventParam::EventParam()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
EventParam::EventParam(const EventParam& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
EventParam::EventParam(EventParam&& other) noexcept = default;

EventParam::~EventParam() = default;

[[maybe_unused]]
const std::optional<std::string>& EventParam::GetType() const
{
    return _pimpl->GetType();
}

[[maybe_unused]]
const std::optional<JsonValue>& EventParam::GetValue() const
{
    return _pimpl->GetValue();
}

EventParam& EventParam::operator=(const EventParam& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

EventParam& EventParam::operator=(EventParam&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void EventParam::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion EventParam
