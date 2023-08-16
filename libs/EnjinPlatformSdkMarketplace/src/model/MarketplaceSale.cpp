#include "EnjinPlatformSdkMarketplace/MarketplaceSale.hpp"

#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class MarketplaceSale::Impl : public JsonDeserializableBase
{
    std::optional<std::string> id;
    std::optional<std::string> price;
    std::optional<std::string> amount;
    std::optional<Wallet> bidder;
    std::optional<MarketplaceListing> listing;

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
    const std::optional<std::string>& GetPrice() const
    {
        return price;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetAmount() const
    {
        return amount;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetBidder() const
    {
        return bidder;
    }

    [[nodiscard]]
    const std::optional<MarketplaceListing>& GetListing() const
    {
        return listing;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "id", id);
        JsonUtil::TryGetField(json, "price", price);
        JsonUtil::TryGetField(json, "amount", amount);
        JsonUtil::TryGetField(json, "bidder", bidder);
        JsonUtil::TryGetField(json, "listing", listing);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region MarketplaceSale

[[maybe_unused]]
MarketplaceSale::MarketplaceSale()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
MarketplaceSale::MarketplaceSale(const MarketplaceSale& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
MarketplaceSale::MarketplaceSale(MarketplaceSale&& other) noexcept = default;

MarketplaceSale::~MarketplaceSale() = default;

[[maybe_unused]]
const std::optional<std::string>& MarketplaceSale::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<std::string>& MarketplaceSale::GetPrice() const
{
    return _pimpl->GetPrice();
}

[[maybe_unused]]
const std::optional<std::string>& MarketplaceSale::GetAmount() const
{
    return _pimpl->GetAmount();
}

[[maybe_unused]]
const std::optional<Wallet>& MarketplaceSale::GetBidder() const
{
    return _pimpl->GetBidder();
}

[[maybe_unused]]
const std::optional<MarketplaceListing>& MarketplaceSale::GetListing() const
{
    return _pimpl->GetListing();
}

MarketplaceSale& MarketplaceSale::operator=(const MarketplaceSale& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

MarketplaceSale& MarketplaceSale::operator=(MarketplaceSale&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void MarketplaceSale::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion MarketplaceSale
