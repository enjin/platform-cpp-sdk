#include "EnjinPlatformSdkMarketplace/FixedPriceState.hpp"

#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class FixedPriceState::Impl : public JsonDeserializableBase
{
    std::optional<ListingType> type;
    std::optional<std::string> amountFilled;

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
    const std::optional<std::string>& GetAmountFilled() const
    {
        return amountFilled;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        TryGetField(json, "type", type);
        JsonUtil::TryGetField(json, "amountFilled", amountFilled);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region FixedPriceState

[[maybe_unused]]
FixedPriceState::FixedPriceState()
    : ListingState(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
FixedPriceState::FixedPriceState(const FixedPriceState& other)
    : ListingState(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
FixedPriceState::FixedPriceState(FixedPriceState&& other) noexcept = default;

FixedPriceState::~FixedPriceState() = default;

[[maybe_unused]]
const std::optional<ListingType>& FixedPriceState::GetType() const
{
    return _pimpl->GetType();
}

[[maybe_unused]]
const std::optional<std::string>& FixedPriceState::GetAmountFilled() const
{
    return _pimpl->GetAmountFilled();
}

FixedPriceState& FixedPriceState::operator=(const FixedPriceState& rhs)
{
    ListingState::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

FixedPriceState& FixedPriceState::operator=(FixedPriceState&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void FixedPriceState::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion FixedPriceState
