#include "EnjinPlatformSdkBeam/BeamQr.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk::beam;

// region Impl

class BeamQr::Impl : public JsonDeserializableBase
{
    std::optional<std::string> url;
    std::optional<std::string> payload;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetUrl() const
    {
        return url;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetPayload() const
    {
        return payload;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "url", url);
        JsonUtil::TryGetField(json, "payload", payload);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region BeamQr

[[maybe_unused]]
BeamQr::BeamQr()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
BeamQr::BeamQr(const BeamQr& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
BeamQr::BeamQr(BeamQr&& other) noexcept = default;

BeamQr::~BeamQr() = default;

[[maybe_unused]]
const std::optional<std::string>& BeamQr::GetUrl() const
{
    return _pimpl->GetUrl();
}

[[maybe_unused]]
const std::optional<std::string>& BeamQr::GetPayload() const
{
    return _pimpl->GetPayload();
}

BeamQr& BeamQr::operator=(const BeamQr& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

BeamQr& BeamQr::operator=(BeamQr&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void BeamQr::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion BeamQr
