#include "EnjinPlatformSdk/CollectionAccountApproval.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class CollectionAccountApproval::Impl : public JsonDeserializableBase
{
public:
    std::optional<int32_t> expiration;
    std::optional<CollectionAccount> account;
    std::optional<Wallet> wallet;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<int32_t>& GetExpiration() const
    {
        return expiration;
    }

    [[nodiscard]]
    const std::optional<CollectionAccount>& GetAccount() const
    {
        return account;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const
    {
        return wallet;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "expiration", expiration);
        JsonUtil::TryGetField(json, "account", account);
        JsonUtil::TryGetField(json, "wallet", wallet);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region CollectionAccountApproval

[[maybe_unused]]
CollectionAccountApproval::CollectionAccountApproval()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
CollectionAccountApproval::CollectionAccountApproval(const CollectionAccountApproval& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
CollectionAccountApproval::CollectionAccountApproval(CollectionAccountApproval&& other) noexcept = default;

CollectionAccountApproval::~CollectionAccountApproval() = default;

[[maybe_unused]]
const std::optional<int32_t>& CollectionAccountApproval::GetExpiration() const
{
    return _pimpl->GetExpiration();
}

[[maybe_unused]]
const std::optional<CollectionAccount>& CollectionAccountApproval::GetAccount() const
{
    return _pimpl->GetAccount();
}

[[maybe_unused]]
const std::optional<Wallet>& CollectionAccountApproval::GetWallet() const
{
    return _pimpl->GetWallet();
}

CollectionAccountApproval& CollectionAccountApproval::operator=(const CollectionAccountApproval& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

CollectionAccountApproval& CollectionAccountApproval::operator=(CollectionAccountApproval&& rhs) noexcept = default;

// region IJsonDeserializable

void CollectionAccountApproval::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion CollectionAccountApproval
