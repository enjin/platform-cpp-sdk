#include "EnjinPlatformSdk/Token.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Token::Impl : public JsonDeserializableBase
{
    std::optional<std::string> tokenId;
    std::optional<std::string> supply;
    std::optional<TokenMintCapType> cap;
    std::optional<std::string> capSupply;
    std::optional<bool> isFrozen;
    std::optional<bool> isCurrency;
    std::optional<Royalty> royalty;
    std::optional<std::string> minimumBalance;
    std::optional<std::string> unitPrice;
    std::optional<std::string> mintDeposit;
    std::optional<int32_t> attributeCount;
    std::optional<Collection> collection;
    std::optional<std::vector<Attribute>> attributes;
    std::optional<Connection<TokenAccount>> accounts;
    std::optional<JsonValue> metadata;
    std::optional<bool> nonFungible;

public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<std::string>& GetTokenId() const
    {
        return tokenId;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetSupply() const
    {
        return supply;
    }

    [[nodiscard]]
    const std::optional<TokenMintCapType>& GetCap() const
    {
        return cap;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetCapSupply() const
    {
        return capSupply;
    }

    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const
    {
        return isFrozen;
    }

    [[nodiscard]]
    const std::optional<bool>& GetIsCurrency() const
    {
        return isCurrency;
    }

    [[nodiscard]]
    const std::optional<Royalty>& GetRoyalty() const
    {
        return royalty;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetMinimumBalance() const
    {
        return minimumBalance;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetUnitPrice() const
    {
        return unitPrice;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetMintDeposit() const
    {
        return mintDeposit;
    }

    [[nodiscard]]
    const std::optional<int32_t>& GetAttributeCount() const
    {
        return attributeCount;
    }

    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const
    {
        return collection;
    }

    [[nodiscard]]
    const std::optional<std::vector<Attribute>>& GetAttributes() const
    {
        return attributes;
    }

    [[nodiscard]]
    const std::optional<Connection<TokenAccount>>& GetAccounts() const
    {
        return accounts;
    }

    [[nodiscard]]
    const std::optional<JsonValue>& GetMetadata() const
    {
        return metadata;
    }

    [[nodiscard]]
    const std::optional<bool>& GetNonFungible() const
    {
        return nonFungible;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "tokenId", tokenId);
        JsonUtil::TryGetField(json, "supply", supply);
        TryGetField(json, "cap", cap);
        JsonUtil::TryGetField(json, "capSupply", capSupply);
        JsonUtil::TryGetField(json, "isFrozen", isFrozen);
        JsonUtil::TryGetField(json, "isCurrency", isCurrency);
        JsonUtil::TryGetField(json, "royalty", royalty);
        JsonUtil::TryGetField(json, "minimumBalance", minimumBalance);
        JsonUtil::TryGetField(json, "unitPrice", unitPrice);
        JsonUtil::TryGetField(json, "mintDeposit", mintDeposit);
        JsonUtil::TryGetField(json, "attributeCount", attributeCount);
        JsonUtil::TryGetField(json, "collection", collection);
        JsonUtil::TryGetField(json, "attributes", attributes);
        JsonUtil::TryGetField(json, "accounts", accounts);
        JsonUtil::TryGetField(json, "metadata", metadata);
        JsonUtil::TryGetField(json, "nonFungible", nonFungible);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Token

[[maybe_unused]]
Token::Token()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Token::Token(const Token& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Token::Token(Token&& other) noexcept = default;

Token::~Token() = default;

[[maybe_unused]]
const std::optional<std::string>& Token::GetTokenId() const
{
    return _pimpl->GetTokenId();
}

[[maybe_unused]]
const std::optional<std::string>& Token::GetSupply() const
{
    return _pimpl->GetSupply();
}

[[maybe_unused]]
const std::optional<TokenMintCapType>& Token::GetCap() const
{
    return _pimpl->GetCap();
}

[[maybe_unused]]
const std::optional<std::string>& Token::GetCapSupply() const
{
    return _pimpl->GetCapSupply();
}

[[maybe_unused]]
const std::optional<bool>& Token::GetIsFrozen() const
{
    return _pimpl->GetIsFrozen();
}

[[maybe_unused]]
const std::optional<bool>& Token::GetIsCurrency() const
{
    return _pimpl->GetIsCurrency();
}

[[maybe_unused]]
const std::optional<Royalty>& Token::GetRoyalty() const
{
    return _pimpl->GetRoyalty();
}

[[maybe_unused]]
const std::optional<std::string>& Token::GetMinimumBalance() const
{
    return _pimpl->GetMinimumBalance();
}

[[maybe_unused]]
const std::optional<std::string>& Token::GetUnitPrice() const
{
    return _pimpl->GetUnitPrice();
}

[[maybe_unused]]
const std::optional<std::string>& Token::GetMintDeposit() const
{
    return _pimpl->GetMintDeposit();
}

[[maybe_unused]]
const std::optional<int32_t>& Token::GetAttributeCount() const
{
    return _pimpl->GetAttributeCount();
}

[[maybe_unused]]
const std::optional<Collection>& Token::GetCollection() const
{
    return _pimpl->GetCollection();
}

[[maybe_unused]]
const std::optional<std::vector<Attribute>>& Token::GetAttributes() const
{
    return _pimpl->GetAttributes();
}

[[maybe_unused]]
const std::optional<Connection<TokenAccount>>& Token::GetAccounts() const
{
    return _pimpl->GetAccounts();
}

[[maybe_unused]]
const std::optional<JsonValue>& Token::GetMetadata() const
{
    return _pimpl->GetMetadata();
}

[[maybe_unused]]
const std::optional<bool>& Token::GetNonFungible() const
{
    return _pimpl->GetNonFungible();
}

Token& Token::operator=(const Token& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Token& Token::operator=(Token&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Token::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Token
