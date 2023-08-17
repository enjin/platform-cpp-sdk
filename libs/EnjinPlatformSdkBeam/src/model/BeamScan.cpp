#include "EnjinPlatformSdkBeam/BeamScan.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk::beam;

// region Impl

class BeamScan::Impl : public JsonDeserializableBase
{
    std::optional<std::string> id;
    std::optional<std::string> walletPublicKey;
    std::optional<std::string> message;

public:
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
    const std::optional<std::string>& GetWalletPublicKey() const
    {
        return walletPublicKey;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetMessage() const
    {
        return message;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "id", id);
        JsonUtil::TryGetField(json, "walletPublicKey", walletPublicKey);
        JsonUtil::TryGetField(json, "message", message);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region BeamScan

[[maybe_unused]]
BeamScan::BeamScan()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
BeamScan::BeamScan(const BeamScan& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
BeamScan::BeamScan(BeamScan&& other) noexcept = default;

BeamScan::~BeamScan() = default;

[[maybe_unused]]
const std::optional<std::string>& BeamScan::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<std::string>& BeamScan::GetWalletPublicKey() const
{
    return _pimpl->GetWalletPublicKey();
}

[[maybe_unused]]
const std::optional<std::string>& BeamScan::GetMessage() const
{
    return _pimpl->GetMessage();
}

BeamScan& BeamScan::operator=(const BeamScan& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

BeamScan& BeamScan::operator=(BeamScan&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void BeamScan::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion BeamScan
