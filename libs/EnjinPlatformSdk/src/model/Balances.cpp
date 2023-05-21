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

#include "EnjinPlatformSdk/Balances.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Balances::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> free;
    std::optional<std::string> reserved;
    std::optional<std::string> miscFrozen;
    std::optional<std::string> feeFrozen;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetFree() const
    {
        return free;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetReserved() const
    {
        return reserved;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetMiscFrozen() const
    {
        return miscFrozen;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetFeeFrozen() const
    {
        return feeFrozen;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "free", free);
        JsonUtil::TryGetField(json, "reserved", reserved);
        JsonUtil::TryGetField(json, "miscFrozen", miscFrozen);
        JsonUtil::TryGetField(json, "feeFrozen", feeFrozen);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Balances

[[maybe_unused]]
Balances::Balances()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Balances::Balances(const Balances& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Balances::Balances(Balances&& other) noexcept = default;

Balances::~Balances() = default;

[[maybe_unused]]
const std::optional<std::string>& Balances::GetFree() const
{
    return _pimpl->GetFree();
}

[[maybe_unused]]
const std::optional<std::string>& Balances::GetReserved() const
{
    return _pimpl->GetReserved();
}

[[maybe_unused]]
const std::optional<std::string>& Balances::GetMiscFrozen() const
{
    return _pimpl->GetMiscFrozen();
}

[[maybe_unused]]
const std::optional<std::string>& Balances::GetFeeFrozen() const
{
    return _pimpl->GetFeeFrozen();
}

Balances& Balances::operator=(const Balances& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Balances& Balances::operator=(Balances&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Balances::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Balances