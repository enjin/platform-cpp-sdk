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

#include "EnjinPlatformSdk/AccountRequest.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class AccountRequest::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> qrCode;
    std::optional<std::string> verificationId;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetQrCode() const
    {
        return qrCode;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetVerificationId() const
    {
        return verificationId;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "qrCode", qrCode);
        JsonUtil::TryGetField(json, "verificationId", verificationId);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region AccountRequest

[[maybe_unused]]
AccountRequest::AccountRequest()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AccountRequest::AccountRequest(const AccountRequest& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AccountRequest::AccountRequest(AccountRequest&& other) noexcept = default;

AccountRequest::~AccountRequest() = default;

[[maybe_unused]]
const std::optional<std::string>& AccountRequest::GetQrCode() const
{
    return _pimpl->GetQrCode();
}

[[maybe_unused]]
const std::optional<std::string>& AccountRequest::GetVerificationId() const
{
    return _pimpl->GetVerificationId();
}

AccountRequest& AccountRequest::operator=(const AccountRequest& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AccountRequest& AccountRequest::operator=(AccountRequest&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void AccountRequest::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion AccountRequest
