#include "EnjinPlatformSdk/AccountRequest.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class AccountRequest::Impl : public JsonDeserializableBase
{
    std::optional<std::string> qrCode;
    std::optional<std::string> verificationId;

public:
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
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AccountRequest::AccountRequest(const AccountRequest& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
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
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AccountRequest& AccountRequest::operator=(AccountRequest&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void AccountRequest::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion AccountRequest
