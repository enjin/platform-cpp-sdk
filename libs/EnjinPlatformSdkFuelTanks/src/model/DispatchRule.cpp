#include "EnjinPlatformSdkFuelTanks/DispatchRule.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

// region Impl

class DispatchRule::Impl : public JsonDeserializableBase
{
    std::optional<std::string> rule;
    std::optional<int> ruleSetId;
    std::optional<JsonValue> value;
    std::optional<bool> isFrozen;

public:
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
    const std::optional<int>& GetRuleSetId() const
    {
        return ruleSetId;
    }

    [[nodiscard]]
    const std::optional<JsonValue>& GetValue() const
    {
        return value;
    }

    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const
    {
        return isFrozen;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "rule", rule);
        JsonUtil::TryGetField(json, "ruleSetId", ruleSetId);
        JsonUtil::TryGetField(json, "value", value);
        JsonUtil::TryGetField(json, "isFrozen", isFrozen);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region DispatchRule

[[maybe_unused]]
DispatchRule::DispatchRule()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
DispatchRule::DispatchRule(const DispatchRule& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
DispatchRule::DispatchRule(DispatchRule&& other) noexcept = default;

DispatchRule::~DispatchRule() = default;

[[maybe_unused]]
const std::optional<std::string>& DispatchRule::GetRule() const
{
    return _pimpl->GetRule();
}

[[maybe_unused]]
const std::optional<int>& DispatchRule::GetRuleSetId() const
{
    return _pimpl->GetRuleSetId();
}

[[maybe_unused]]
const std::optional<JsonValue>& DispatchRule::GetValue() const
{
    return _pimpl->GetValue();
}

[[maybe_unused]]
const std::optional<bool>& DispatchRule::GetIsFrozen() const
{
    return _pimpl->GetIsFrozen();
}

DispatchRule& DispatchRule::operator=(const DispatchRule& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

DispatchRule& DispatchRule::operator=(DispatchRule&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void DispatchRule::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion DispatchRule
