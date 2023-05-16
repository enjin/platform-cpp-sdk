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

#include "EnjinPlatformSdk/AccountVerified.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class AccountVerified::Impl : public JsonDeserializableBase
{
public:
    std::optional<bool> verified;
    std::optional<Account> account;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<bool>& GetVerified() const
    {
        return verified;
    }

    [[nodiscard]]
    const std::optional<Account>& GetAccount() const
    {
        return account;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "verified", verified);
        JsonUtil::TryGetField(json, "account", account);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region AccountVerified

[[maybe_unused]]
AccountVerified::AccountVerified()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AccountVerified::AccountVerified(const AccountVerified& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AccountVerified::AccountVerified(AccountVerified&& other) noexcept = default;

AccountVerified::~AccountVerified() = default;

[[maybe_unused]]
const std::optional<bool>& AccountVerified::GetVerified() const
{
    return _pimpl->GetVerified();
}

[[maybe_unused]]
const std::optional<Account>& AccountVerified::GetAccount() const
{
    return _pimpl->GetAccount();
}

AccountVerified& AccountVerified::operator=(const AccountVerified& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AccountVerified& AccountVerified::operator=(AccountVerified&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void AccountVerified::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion AccountVerified
