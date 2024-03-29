#include "EnjinPlatformSdk/Royalty.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Royalty::Impl : public JsonDeserializableBase
{
public:
    std::optional<Wallet> beneficiary;
    std::optional<double> percentage;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<Wallet>& GetBeneficiary() const
    {
        return beneficiary;
    }

    [[nodiscard]]
    const std::optional<double>& GetPercentage() const
    {
        return percentage;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "beneficiary", beneficiary);
        JsonUtil::TryGetField(json, "percentage", percentage);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Royalty

[[maybe_unused]]
Royalty::Royalty()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Royalty::Royalty(const Royalty& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Royalty::Royalty(Royalty&& other) noexcept = default;

Royalty::~Royalty() = default;

[[maybe_unused]]
const std::optional<Wallet>& Royalty::GetBeneficiary() const
{
    return _pimpl->GetBeneficiary();
}

[[maybe_unused]]
const std::optional<double>& Royalty::GetPercentage() const
{
    return _pimpl->GetPercentage();
}

Royalty& Royalty::operator=(const Royalty& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Royalty& Royalty::operator=(Royalty&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Royalty::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Royalty
