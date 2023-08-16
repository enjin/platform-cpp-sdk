#include "EnjinPlatformSdkMarketplace/MarketplaceState.hpp"

#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class MarketplaceState::Impl : public JsonDeserializableBase
{
    std::optional<std::string> id;
    std::optional<ListingStateEnum> state;
    std::optional<int> height;
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
    const std::optional<ListingStateEnum>& GetState() const
    {
        return state;
    }

    [[nodiscard]]
    const std::optional<int>& GetHeight() const
    {
        return height;
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
        TryGetField(json, "state", state);
        JsonUtil::TryGetField(json, "height", height);
        JsonUtil::TryGetField(json, "listing", listing);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region MarketplaceStale

[[maybe_unused]]
MarketplaceState::MarketplaceState()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
MarketplaceState::MarketplaceState(const MarketplaceState& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
MarketplaceState::MarketplaceState(MarketplaceState&& other) noexcept = default;

MarketplaceState::~MarketplaceState() = default;

[[maybe_unused]]
const std::optional<std::string>& MarketplaceState::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<ListingStateEnum>& MarketplaceState::GetState() const
{
    return _pimpl->GetState();
}

[[maybe_unused]]
const std::optional<int>& MarketplaceState::GetHeight() const
{
    return _pimpl->GetHeight();
}

[[maybe_unused]]
const std::optional<MarketplaceListing>& MarketplaceState::GetListing() const
{
    return _pimpl->GetListing();
}

MarketplaceState& MarketplaceState::operator=(const MarketplaceState& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

MarketplaceState& MarketplaceState::operator=(MarketplaceState&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void MarketplaceState::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion MarketplaceStale
