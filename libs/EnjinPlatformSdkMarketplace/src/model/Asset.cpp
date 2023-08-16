#include "EnjinPlatformSdkMarketplace/Asset.hpp"

#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class Asset::Impl : public JsonDeserializableBase
{
    std::optional<std::string> collectionId;
    std::optional<std::string> tokenId;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetCollectionId() const
    {
        return collectionId;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetTokenId() const
    {
        return tokenId;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "collectionId", collectionId);
        JsonUtil::TryGetField(json, "tokenId", tokenId);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Asset

[[maybe_unused]]
Asset::Asset()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Asset::Asset(const Asset& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Asset::Asset(Asset&& other) noexcept = default;

Asset::~Asset() = default;

[[maybe_unused]]
const std::optional<std::string>& Asset::GetCollectionId() const
{
    return _pimpl->GetCollectionId();
}

[[maybe_unused]]
const std::optional<std::string>& Asset::GetTokenId() const
{
    return _pimpl->GetTokenId();
}

Asset& Asset::operator=(const Asset& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Asset& Asset::operator=(Asset&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Asset::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Asset
