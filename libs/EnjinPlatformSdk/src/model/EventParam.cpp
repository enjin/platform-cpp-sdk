#include "EnjinPlatformSdk/EventParam.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class EventParam::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> type;
    std::optional<JsonValue> value;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetType() const
    {
        return type;
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
        JsonUtil::TryGetField(json, "type", type);
        JsonUtil::TryGetField(json, "value", value);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region EventParam

[[maybe_unused]]
EventParam::EventParam()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
EventParam::EventParam(const EventParam& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
EventParam::EventParam(EventParam&& other) noexcept = default;

EventParam::~EventParam() = default;

[[maybe_unused]]
const std::optional<std::string>& EventParam::GetType() const
{
    return _pimpl->GetType();
}

[[maybe_unused]]
const std::optional<JsonValue>& EventParam::GetValue() const
{
    return _pimpl->GetValue();
}

EventParam& EventParam::operator=(const EventParam& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

EventParam& EventParam::operator=(EventParam&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void EventParam::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion EventParam
