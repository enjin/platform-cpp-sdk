#include "EnjinPlatformSdk/Attribute.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Attribute::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> key;
    std::optional<std::string> value;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetKey() const
    {
        return key;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetValue() const
    {
        return value;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "key", key);
        JsonUtil::TryGetField(json, "value", value);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Attribute

[[maybe_unused]]
Attribute::Attribute()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Attribute::Attribute(const Attribute& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Attribute::Attribute(Attribute&& other) noexcept = default;

Attribute::~Attribute() = default;

[[maybe_unused]]
const std::optional<std::string>& Attribute::GetKey() const
{
    return _pimpl->GetKey();
}

[[maybe_unused]]
const std::optional<std::string>& Attribute::GetValue() const
{
    return _pimpl->GetValue();
}

Attribute& Attribute::operator=(const Attribute& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Attribute& Attribute::operator=(Attribute&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Attribute::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Attribute
