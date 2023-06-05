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

#include "EnjinPlatformSdk/WalletLink.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class WalletLink::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> code;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetCode() const
    {
        return code;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "code", code);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region WalletLink

[[maybe_unused]]
WalletLink::WalletLink()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
WalletLink::WalletLink(const WalletLink& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
WalletLink::WalletLink(WalletLink&& other) noexcept = default;

WalletLink::~WalletLink() = default;

[[maybe_unused]]
const std::optional<std::string>& WalletLink::GetCode() const
{
    return _pimpl->GetCode();
}

WalletLink& WalletLink::operator=(const WalletLink& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

WalletLink& WalletLink::operator=(WalletLink&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void WalletLink::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion WalletLink
