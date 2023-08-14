#include "EnjinPlatformSdkMarketplace/AuctionData.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class AuctionData::Impl : public JsonDeserializableBase
{
    std::optional<ListingType> type;
    std::optional<int> startBlock;
    std::optional<int> endBlock;

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
    const std::optional<int>& GetStartBlock() const
    {
        return startBlock;
    }

    [[nodiscard]]
    const std::optional<int>& GetEndBlock() const
    {
        return endBlock;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        TryGetField(json, "type", type);
        JsonUtil::TryGetField(json, "startBlock", startBlock);
        JsonUtil::TryGetField(json, "endBlock", endBlock);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region AuctionData

[[maybe_unused]]
AuctionData::AuctionData()
    : ListingData(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AuctionData::AuctionData(const AuctionData& other)
    : ListingData(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AuctionData::AuctionData(AuctionData&& other) noexcept = default;

AuctionData::~AuctionData() = default;

[[maybe_unused]]
const std::optional<ListingType>& AuctionData::GetType() const
{
    return _pimpl->GetType();
}

[[maybe_unused]]
const std::optional<int>& AuctionData::GetStartBlock() const
{
    return _pimpl->GetStartBlock();
}

[[maybe_unused]]
const std::optional<int>& AuctionData::GetEndBlock() const
{
    return _pimpl->GetEndBlock();
}

AuctionData& AuctionData::operator=(const AuctionData& rhs)
{
    ListingData::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AuctionData& AuctionData::operator=(AuctionData&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void AuctionData::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion AuctionData
