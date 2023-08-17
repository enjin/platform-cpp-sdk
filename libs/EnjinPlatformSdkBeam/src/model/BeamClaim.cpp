#include "EnjinPlatformSdkBeam/BeamClaim.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

// region Impl

class BeamClaim::Impl : public JsonDeserializableBase
{
    std::optional<int> id;
    std::optional<Collection> collection;
    std::optional<std::string> tokenId;
    std::optional<Beam> beam;
    std::optional<Wallet> wallet;
    std::optional<DateTime> claimAt;
    std::optional<ClaimStatus> claimStatus;
    std::optional<BeamType> type;
    std::optional<std::string> code;
    std::optional<BeamQr> qr;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<int>& GetId() const
    {
        return id;
    }

    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const
    {
        return collection;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetTokenId() const
    {
        return tokenId;
    }

    [[nodiscard]]
    const std::optional<Beam>& GetBeam() const
    {
        return beam;
    }

    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const
    {
        return wallet;
    }

    [[nodiscard]]
    const std::optional<DateTime>& GetClaimAt() const
    {
        return claimAt;
    }

    [[nodiscard]]
    const std::optional<ClaimStatus>& GetClaimStatus() const
    {
        return claimStatus;
    }

    [[nodiscard]]
    const std::optional<BeamType>& GetType() const
    {
        return type;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetCode() const
    {
        return code;
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
        JsonUtil::TryGetField(json, "collection", collection);
        JsonUtil::TryGetField(json, "tokenId", tokenId);
        JsonUtil::TryGetField(json, "beam", beam);
        JsonUtil::TryGetField(json, "wallet", wallet);
        JsonUtil::TryGetField(json, "claimAt", claimAt);
        TryGetField(json, "claimStatus", claimStatus);
        TryGetField(json, "type", type);
        JsonUtil::TryGetField(json, "code", code);
        JsonUtil::TryGetField(json, "qr", qr);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region BeamClaim

[[maybe_unused]]
BeamClaim::BeamClaim()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
BeamClaim::BeamClaim(const BeamClaim& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
BeamClaim::BeamClaim(BeamClaim&& other) noexcept = default;

BeamClaim::~BeamClaim() = default;

[[maybe_unused]]
const std::optional<int>& BeamClaim::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<Collection>& BeamClaim::GetCollection() const
{
    return _pimpl->GetCollection();
}

[[maybe_unused]]
const std::optional<std::string>& BeamClaim::GetTokenId() const
{
    return _pimpl->GetTokenId();
}

[[maybe_unused]]
const std::optional<Beam>& BeamClaim::GetBeam() const
{
    return _pimpl->GetBeam();
}

[[maybe_unused]]
const std::optional<Wallet>& BeamClaim::GetWallet() const
{
    return _pimpl->GetWallet();
}

[[maybe_unused]]
const std::optional<DateTime>& BeamClaim::GetClaimAt() const
{
    return _pimpl->GetClaimAt();
}

[[maybe_unused]]
const std::optional<ClaimStatus>& BeamClaim::GetClaimStatus() const
{
    return _pimpl->GetClaimStatus();
}

[[maybe_unused]]
const std::optional<BeamType>& BeamClaim::GetType() const
{
    return _pimpl->GetType();
}

[[maybe_unused]]
const std::optional<std::string>& BeamClaim::GetCode() const
{
    return _pimpl->GetCode();
}

[[maybe_unused]]
const std::optional<BeamQr>& BeamClaim::GetQr() const
{
    return _pimpl->GetQr();
}

BeamClaim& BeamClaim::operator=(const BeamClaim& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

BeamClaim& BeamClaim::operator=(BeamClaim&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void BeamClaim::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion BeamClaim
