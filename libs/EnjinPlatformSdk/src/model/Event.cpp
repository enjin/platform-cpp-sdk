#include "EnjinPlatformSdk/Event.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Event::Impl : public JsonDeserializableBase
{
    std::optional<int32_t> phase;
    std::optional<std::string> lookup;
    std::optional<std::string> moduleId;
    std::optional<std::string> eventId;
    std::optional<std::vector<EventParam>> params;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<int32_t>& GetPhase() const
    {
        return phase;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetLookup() const
    {
        return lookup;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetModuleId() const
    {
        return moduleId;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetEventId() const
    {
        return eventId;
    }

    [[nodiscard]]
    const std::optional<std::vector<EventParam>>& GetParams() const
    {
        return params;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "phase", phase);
        JsonUtil::TryGetField(json, "lookup", lookup);
        JsonUtil::TryGetField(json, "moduleId", moduleId);
        JsonUtil::TryGetField(json, "eventId", eventId);
        JsonUtil::TryGetField(json, "params", params);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Event

[[maybe_unused]]
Event::Event()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Event::Event(const Event& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Event::Event(Event&& other) noexcept = default;

Event::~Event() = default;

[[maybe_unused]]
const std::optional<int32_t>& Event::GetPhase() const
{
    return _pimpl->GetPhase();
}

[[maybe_unused]]
const std::optional<std::string>& Event::GetLookup() const
{
    return _pimpl->GetLookup();
}

[[maybe_unused]]
const std::optional<std::string>& Event::GetModuleId() const
{
    return _pimpl->GetModuleId();
}

[[maybe_unused]]
const std::optional<std::string>& Event::GetEventId() const
{
    return _pimpl->GetEventId();
}

[[maybe_unused]]
const std::optional<std::vector<EventParam>>& Event::GetParams() const
{
    return _pimpl->GetParams();
}

[[maybe_unused]]
Event& Event::operator=(const Event& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Event& Event::operator=(Event&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Event::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Event
