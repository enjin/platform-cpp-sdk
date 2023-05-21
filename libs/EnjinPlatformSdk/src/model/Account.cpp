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

#include "EnjinPlatformSdk/Account.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Account::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> publicKey;
    std::optional<std::string> address;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetPublicKey() const
    {
        return publicKey;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetAddress() const
    {
        return address;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "publicKey", publicKey);
        JsonUtil::TryGetField(json, "address", address);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Account

[[maybe_unused]]
Account::Account()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Account::Account(const Account& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Account::Account(Account&& other) noexcept = default;

Account::~Account() = default;

[[maybe_unused]]
const std::optional<std::string>& Account::GetPublicKey() const
{
    return _pimpl->GetPublicKey();
}

[[maybe_unused]]
const std::optional<std::string>& Account::GetAddress() const
{
    return _pimpl->GetAddress();
}

Account& Account::operator=(const Account& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Account& Account::operator=(Account&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Account::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Account
