#include "EnjinPlatformSdkMarketplace/AuctionState.hpp"

#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class AuctionState::Impl : public JsonDeserializableBase
{
    std::optional<ListingType> type;
    std::optional<MarketplaceBid> highestBid;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<ListingType>& GetType() const
    {
        return type;
    }

    [[nodiscard]]
    const std::optional<MarketplaceBid>& GetHighestBid() const
    {
        return highestBid;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region AuctionState

[[maybe_unused]]
AuctionState::AuctionState()
    : ListingState(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AuctionState::AuctionState(const AuctionState& other)
    : ListingState(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AuctionState::AuctionState(AuctionState&& other) noexcept = default;

AuctionState::~AuctionState() = default;

[[maybe_unused]]
const std::optional<ListingType>& AuctionState::GetType() const
{
    return _pimpl->GetType();
}

[[maybe_unused]]
const std::optional<MarketplaceBid>& AuctionState::GetHighestBid() const
{
    return _pimpl->GetHighestBid();
}

AuctionState& AuctionState::operator=(const AuctionState& rhs)
{
    ListingState::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AuctionState& AuctionState::operator=(AuctionState&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void AuctionState::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion AuctionState
