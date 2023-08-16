#include "EnjinPlatformSdkMarketplace/FixedPriceData.hpp"

#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class FixedPriceData::Impl : public JsonDeserializableBase
{
    std::optional<ListingType> type;

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

// region FixedPriceData

[[maybe_unused]]
FixedPriceData::FixedPriceData()
    : ListingData(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
FixedPriceData::FixedPriceData(const FixedPriceData& other)
    : ListingData(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
FixedPriceData::FixedPriceData(FixedPriceData&& other) noexcept = default;

FixedPriceData::~FixedPriceData() = default;

[[maybe_unused]]
const std::optional<ListingType>& FixedPriceData::GetType() const
{
    return _pimpl->GetType();
}

FixedPriceData& FixedPriceData::operator=(const FixedPriceData& rhs)
{
    ListingData::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

FixedPriceData& FixedPriceData::operator=(FixedPriceData&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void FixedPriceData::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion FixedPriceData
