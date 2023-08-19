#include "EnjinPlatformSdk/Account.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Account::Impl : public JsonDeserializableBase
{
    std::optional<std::string> publicKey;
    std::optional<std::string> address;

public:
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
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Account::Account(const Account& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
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
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Account& Account::operator=(Account&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Account::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Account
