#include "EnjinPlatformSdkMarketplace/MarketplaceBid.hpp"

#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class MarketplaceBid::Impl : public JsonDeserializableBase
{
    std::optional<std::string> id;
    std::optional<std::string> price;
    std::optional<int> height;
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
    const std::optional<int>& GetHeight() const
    {
        return height;
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
        JsonUtil::TryGetField(json, "height", height);
        JsonUtil::TryGetField(json, "bidder", bidder);
        JsonUtil::TryGetField(json, "listing", listing);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region MarketplaceBid

[[maybe_unused]]
MarketplaceBid::MarketplaceBid()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
MarketplaceBid::MarketplaceBid(const MarketplaceBid& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
MarketplaceBid::MarketplaceBid(MarketplaceBid&& other) noexcept = default;

MarketplaceBid::~MarketplaceBid() = default;

[[maybe_unused]]
const std::optional<std::string>& MarketplaceBid::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<std::string>& MarketplaceBid::GetPrice() const
{
    return _pimpl->GetPrice();
}

[[maybe_unused]]
const std::optional<int>& MarketplaceBid::GetHeight() const
{
    return _pimpl->GetHeight();
}

[[maybe_unused]]
const std::optional<Wallet>& MarketplaceBid::GetBidder() const
{
    return _pimpl->GetBidder();
}

[[maybe_unused]]
const std::optional<MarketplaceListing>& MarketplaceBid::GetListing() const
{
    return _pimpl->GetListing();
}

MarketplaceBid& MarketplaceBid::operator=(const MarketplaceBid& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

MarketplaceBid& MarketplaceBid::operator=(MarketplaceBid&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void MarketplaceBid::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion MarketplaceBid
