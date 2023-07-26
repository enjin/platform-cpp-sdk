#include "EnjinPlatformSdkBeam/Beam.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

// region Impl

class Beam::Impl : public JsonDeserializableBase
{
public:
    std::optional<std::string> id;
    std::optional<std::string> code;
    std::optional<std::string> name;
    std::optional<std::string> description;
    std::optional<std::string> image;
    std::optional<DateTime> start;
    std::optional<DateTime> end;
    std::optional<Collection> collection;
    std::optional<BeamScan> message;
    std::optional<bool> isClaimable;
    std::optional<std::vector<BeamFlag>> flags;
    std::optional<BeamQr> qr;

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
    const std::optional<std::string>& GetCode() const
    {
        return code;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetName() const
    {
        return name;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetDescription() const
    {
        return description;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetImage() const
    {
        return image;
    }

    [[nodiscard]]
    const std::optional<DateTime>& GetStart() const
    {
        return start;
    }

    [[nodiscard]]
    const std::optional<DateTime>& GetEnd() const
    {
        return end;
    }

    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const
    {
        return collection;
    }

    [[nodiscard]]
    const std::optional<BeamScan>& GetMessage() const
    {
        return message;
    }

    [[nodiscard]]
    const std::optional<bool>& GetIsClaimable() const
    {
        return isClaimable;
    }

    [[nodiscard]]
    const std::optional<std::vector<BeamFlag>>& GetFlags() const
    {
        return flags;
    }

    [[nodiscard]]
    const std::optional<BeamQr>& GetQr() const
    {
        return qr;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "id", id);
        JsonUtil::TryGetField(json, "code", code);
        JsonUtil::TryGetField(json, "name", name);
        JsonUtil::TryGetField(json, "description", description);
        JsonUtil::TryGetField(json, "image", image);
        JsonUtil::TryGetField(json, "start", start);
        JsonUtil::TryGetField(json, "end", end);
        JsonUtil::TryGetField(json, "collection", collection);
        JsonUtil::TryGetField(json, "message", message);
        JsonUtil::TryGetField(json, "isClaimable", isClaimable);
        TryGetField(json, "flags", flags);
        JsonUtil::TryGetField(json, "qr", qr);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Beam

[[maybe_unused]]
Beam::Beam()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Beam::Beam(const Beam& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Beam::Beam(Beam&& other) noexcept = default;

Beam::~Beam() = default;

[[maybe_unused]]
const std::optional<std::string>& Beam::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<std::string>& Beam::GetCode() const
{
    return _pimpl->GetCode();
}

[[maybe_unused]]
const std::optional<std::string>& Beam::GetName() const
{
    return _pimpl->GetName();
}

[[maybe_unused]]
const std::optional<std::string>& Beam::GetDescription() const
{
    return _pimpl->GetDescription();
}

[[maybe_unused]]
const std::optional<std::string>& Beam::GetImage() const
{
    return _pimpl->GetImage();
}

[[maybe_unused]]
const std::optional<DateTime>& Beam::GetStart() const
{
    return _pimpl->GetStart();
}

[[maybe_unused]]
const std::optional<DateTime>& Beam::GetEnd() const
{
    return _pimpl->GetEnd();
}

[[maybe_unused]]
const std::optional<Collection>& Beam::GetCollection() const
{
    return _pimpl->GetCollection();
}

[[maybe_unused]]
const std::optional<BeamScan>& Beam::GetMessage() const
{
    return _pimpl->GetMessage();
}

[[maybe_unused]]
const std::optional<bool>& Beam::GetIsClaimable() const
{
    return _pimpl->GetIsClaimable();
}

[[maybe_unused]]
const std::optional<std::vector<BeamFlag>>& Beam::GetFlags() const
{
    return _pimpl->GetFlags();
}

[[maybe_unused]]
const std::optional<BeamQr>& Beam::GetQr() const
{
    return _pimpl->GetQr();
}

Beam& Beam::operator=(const Beam& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Beam& Beam::operator=(Beam&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Beam::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Beam
