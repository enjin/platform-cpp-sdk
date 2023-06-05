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

#include "EnjinPlatformSdk/TokenAccountNamedReserve.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class TokenAccountNamedReserve::Impl : public JsonDeserializableBase
{
public:
    std::optional<PalletIdentifier> pallet;
    std::optional<std::string> amount;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<PalletIdentifier>& GetPallet() const
    {
        return pallet;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetAmount() const
    {
        return amount;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        TryGetField(json, "pallet", pallet);
        JsonUtil::TryGetField(json, "amount", amount);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region TokenAccountNamedReserve

[[maybe_unused]]
TokenAccountNamedReserve::TokenAccountNamedReserve()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
TokenAccountNamedReserve::TokenAccountNamedReserve(const TokenAccountNamedReserve& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
TokenAccountNamedReserve::TokenAccountNamedReserve(TokenAccountNamedReserve&& other) noexcept = default;

TokenAccountNamedReserve::~TokenAccountNamedReserve() = default;

[[maybe_unused]]
const std::optional<PalletIdentifier>& TokenAccountNamedReserve::GetPallet() const
{
    return _pimpl->GetPallet();
}

[[maybe_unused]]
const std::optional<std::string>& TokenAccountNamedReserve::GetAmount() const
{
    return _pimpl->GetAmount();
}

TokenAccountNamedReserve& TokenAccountNamedReserve::operator=(const TokenAccountNamedReserve& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

TokenAccountNamedReserve& TokenAccountNamedReserve::operator=(TokenAccountNamedReserve&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void TokenAccountNamedReserve::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion TokenAccountNamedReserve
