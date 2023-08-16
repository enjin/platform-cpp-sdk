#include "EnjinPlatformSdkMarketplace/MarketplaceListing.hpp"

#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class MarketplaceListing::Impl : public JsonDeserializableBase
{
    std::optional<std::string> id;
    std::optional<std::string> listingId;
    std::optional<Asset> makeAssetId;
    std::optional<Asset> takeAssetId;
    std::optional<std::string> amount;
    std::optional<std::string> price;
    std::optional<std::string> minTakeValue;
    std::optional<FeeSide> feeSide;
    std::optional<int> creationBlock;
    std::optional<std::string> deposit;
    std::optional<std::string> salt;
    std::optional<JsonValue> state;
    std::optional<JsonValue> data;
    std::optional<Wallet> seller;
    std::optional<Connection<MarketplaceSale>> sales;
    std::optional<Connection<MarketplaceBid>> bids;
    std::optional<std::vector<MarketplaceState>> states;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetId() const
    {
        return id;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetListingId() const
    {
        return listingId;
    }

    [[nodiscard]]
    const std::optional<Asset>& GetMakeAssetId() const
    {
        return makeAssetId;
    }

    [[nodiscard]]
    const std::optional<Asset>& GetTakeAssetId() const
    {
        return takeAssetId;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetAmount() const
    {
        return amount;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetPrice() const
    {
        return price;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetMinTakeValue() const
    {
        return minTakeValue;
    }

    [[nodiscard]]
    const std::optional<FeeSide>& GetFeeSide() const
    {
        return feeSide;
    }

    [[nodiscard]]
    const std::optional<int>& GetCreationBlock() const
    {
        return creationBlock;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetDeposit() const
    {
        return deposit;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetSalt() const
    {
        return salt;
    }

    [[nodiscard]]
    const std::optional<JsonValue>& GetState() const
    {
        return state;
    }

    [[nodiscard]]
    const std::optional<JsonValue>& GetData() const
    {
        return data;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetSeller() const
    {
        return seller;
    }

    [[nodiscard]]
    const std::optional<Connection<MarketplaceSale>>& GetSales() const
    {
        return sales;
    }

    [[nodiscard]]
    const std::optional<Connection<MarketplaceBid>>& GetBids() const
    {
        return bids;
    }

    [[nodiscard]]
    const std::optional<std::vector<MarketplaceState>>& GetStates() const
    {
        return states;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "id", id);
        JsonUtil::TryGetField(json, "listingId", listingId);
        JsonUtil::TryGetField(json, "makeAssetId", makeAssetId);
        JsonUtil::TryGetField(json, "takeAssetId", takeAssetId);
        JsonUtil::TryGetField(json, "amount", amount);
        JsonUtil::TryGetField(json, "price", price);
        JsonUtil::TryGetField(json, "minTakeValue", minTakeValue);
        TryGetField(json, "feeSide", feeSide);
        JsonUtil::TryGetField(json, "creationBlock", creationBlock);
        JsonUtil::TryGetField(json, "deposit", deposit);
        JsonUtil::TryGetField(json, "salt", salt);
        JsonUtil::TryGetField(json, "state", state);
        JsonUtil::TryGetField(json, "data", data);
        JsonUtil::TryGetField(json, "seller", seller);
        JsonUtil::TryGetField(json, "sales", sales);
        JsonUtil::TryGetField(json, "bids", bids);
        JsonUtil::TryGetField(json, "states", states);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region MarketplaceListing

[[maybe_unused]]
MarketplaceListing::MarketplaceListing()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
MarketplaceListing::MarketplaceListing(const MarketplaceListing& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
MarketplaceListing::MarketplaceListing(MarketplaceListing&& other) noexcept = default;

MarketplaceListing::~MarketplaceListing() = default;

[[maybe_unused]]
const std::optional<std::string>& MarketplaceListing::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<std::string>& MarketplaceListing::GetListingId() const
{
    return _pimpl->GetListingId();
}

[[maybe_unused]]
const std::optional<Asset>& MarketplaceListing::GetMakeAssetId() const
{
    return _pimpl->GetMakeAssetId();
}

[[maybe_unused]]
const std::optional<Asset>& MarketplaceListing::GetTakeAssetId() const
{
    return _pimpl->GetTakeAssetId();
}

[[maybe_unused]]
const std::optional<std::string>& MarketplaceListing::GetAmount() const
{
    return _pimpl->GetAmount();
}

[[maybe_unused]]
const std::optional<std::string>& MarketplaceListing::GetPrice() const
{
    return _pimpl->GetPrice();
}

[[maybe_unused]]
const std::optional<std::string>& MarketplaceListing::GetMinTakeValue() const
{
    return _pimpl->GetMinTakeValue();
}

[[maybe_unused]]
const std::optional<FeeSide>& MarketplaceListing::GetFeeSide() const
{
    return _pimpl->GetFeeSide();
}

[[maybe_unused]]
const std::optional<int>& MarketplaceListing::GetCreationBlock() const
{
    return _pimpl->GetCreationBlock();
}

[[maybe_unused]]
const std::optional<std::string>& MarketplaceListing::GetDeposit() const
{
    return _pimpl->GetDeposit();
}

[[maybe_unused]]
const std::optional<std::string>& MarketplaceListing::GetSalt() const
{
    return _pimpl->GetSalt();
}

[[maybe_unused]]
const std::optional<JsonValue>& MarketplaceListing::GetState() const
{
    return _pimpl->GetState();
}

[[maybe_unused]]
const std::optional<JsonValue>& MarketplaceListing::GetData() const
{
    return _pimpl->GetData();
}

[[maybe_unused]]
const std::optional<Wallet>& MarketplaceListing::GetSeller() const
{
    return _pimpl->GetSeller();
}

[[maybe_unused]]
const std::optional<Connection<MarketplaceSale>>& MarketplaceListing::GetSales() const
{
    return _pimpl->GetSales();
}

[[maybe_unused]]
const std::optional<Connection<MarketplaceBid>>& MarketplaceListing::GetBids() const
{
    return _pimpl->GetBids();
}

[[maybe_unused]]
const std::optional<std::vector<MarketplaceState>>& MarketplaceListing::GetStates() const
{
    return _pimpl->GetStates();
}

MarketplaceListing& MarketplaceListing::operator=(const MarketplaceListing& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

MarketplaceListing& MarketplaceListing::operator=(MarketplaceListing&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void MarketplaceListing::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion MarketplaceListing
