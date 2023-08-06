#include "EnjinPlatformSdkFuelTanks/AccountRule.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

// region Impl

class AccountRule::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> rule;
    std::optional<JsonValue> value;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetRule() const
    {
        return rule;
    }

    [[nodiscard]]
    const std::optional<JsonValue>& GetValue() const
    {
        return value;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "rule", rule);
        JsonUtil::TryGetField(json, "value", value);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region AccountRule

[[maybe_unused]]
AccountRule::AccountRule()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AccountRule::AccountRule(const AccountRule& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AccountRule::AccountRule(AccountRule&& other) noexcept = default;

AccountRule::~AccountRule() = default;

[[maybe_unused]]
const std::optional<std::string>& AccountRule::GetRule() const
{
    return _pimpl->GetRule();
}

[[maybe_unused]]
const std::optional<JsonValue>& AccountRule::GetValue() const
{
    return _pimpl->GetValue();
}

AccountRule& AccountRule::operator=(const AccountRule& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AccountRule& AccountRule::operator=(AccountRule&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void AccountRule::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion AccountRule
