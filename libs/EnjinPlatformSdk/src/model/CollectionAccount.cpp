#include "EnjinPlatformSdk/CollectionAccount.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class CollectionAccount::Impl : public JsonDeserializableBase
{
    std::optional<int32_t> accountCount;
    std::optional<bool> isFrozen;
    std::optional<Collection> collection;
    std::optional<Wallet> wallet;
    std::optional<std::vector<CollectionAccountApproval>> approvals;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<int32_t>& GetAccountCount() const
    {
        return accountCount;
    }

    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const
    {
        return isFrozen;
    }

    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const
    {
        return collection;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const
    {
        return wallet;
    }

    [[nodiscard]]
    const std::optional<std::vector<CollectionAccountApproval>>& GetApprovals() const
    {
        return approvals;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "accountCount", accountCount);
        JsonUtil::TryGetField(json, "isFrozen", isFrozen);
        JsonUtil::TryGetField(json, "collection", collection);
        JsonUtil::TryGetField(json, "wallet", wallet);
        JsonUtil::TryGetField(json, "approvals", approvals);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region CollectionAccount

[[maybe_unused]]
CollectionAccount::CollectionAccount()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
CollectionAccount::CollectionAccount(const CollectionAccount& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
CollectionAccount::CollectionAccount(CollectionAccount&& other) noexcept = default;

CollectionAccount::~CollectionAccount() = default;

[[maybe_unused]]
const std::optional<int32_t>& CollectionAccount::GetAccountCount() const
{
    return _pimpl->GetAccountCount();
}

[[maybe_unused]]
const std::optional<bool>& CollectionAccount::GetIsFrozen() const
{
    return _pimpl->GetIsFrozen();
}

[[maybe_unused]]
const std::optional<Collection>& CollectionAccount::GetCollection() const
{
    return _pimpl->GetCollection();
}

[[maybe_unused]]
const std::optional<Wallet>& CollectionAccount::GetWallet() const
{
    return _pimpl->GetWallet();
}

[[maybe_unused]]
const std::optional<std::vector<CollectionAccountApproval>>& CollectionAccount::GetApprovals() const
{
    return _pimpl->GetApprovals();
}

CollectionAccount& CollectionAccount::operator=(const CollectionAccount& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

CollectionAccount& CollectionAccount::operator=(CollectionAccount&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void CollectionAccount::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion CollectionAccount
