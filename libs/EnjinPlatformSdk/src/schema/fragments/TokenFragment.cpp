#include "EnjinPlatformSdk/TokenFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class TokenFragment::Impl : public GraphQlFragment<Impl>
{
public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;
};

// endregion Impl

// region TokenFragment

[[maybe_unused]]
TokenFragment::TokenFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
TokenFragment::TokenFragment(const TokenFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
TokenFragment::TokenFragment(TokenFragment&& other) noexcept = default;

TokenFragment::~TokenFragment() = default;

[[maybe_unused]]
TokenFragment& TokenFragment::WithTokenId(const bool isIncluded)
{
    return WithField("tokenId", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithSupply(const bool isIncluded)
{
    return WithField("supply", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithCap(const bool isIncluded)
{
    return WithField("cap", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithCapSupply(const bool isIncluded)
{
    return WithField("capSupply", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithIsFrozen(const bool isIncluded)
{
    return WithField("isFrozen", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithIsCurrency(const bool isIncluded)
{
    return WithField("isCurrency", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithRoyalty(RoyaltyFragmentPtr fragment)
{
    return WithField("royalty", std::move(fragment));
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithMinimumBalance(const bool isIncluded)
{
    return WithField("minimumBalance", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithUnitPrice(const bool isIncluded)
{
    return WithField("unitPrice", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithMintDeposit(const bool isIncluded)
{
    return WithField("mintDeposit", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithAttributeCount(const bool isIncluded)
{
    return WithField("attributeCount", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithCollection(CollectionFragmentPtr fragment)
{
    return WithField("collection", std::move(fragment));
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithAttributes(AttributeFragmentPtr fragment)
{
    return WithField("attributes", std::move(fragment));
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithAccounts(TokenAccountConnectionFragmentPtr fragment)
{
    return WithField("accounts", std::move(fragment));
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithMetadata(const bool isIncluded)
{
    return WithField("metadata", isIncluded);
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithNonFungible(const bool isIncluded)
{
    return WithField("nonFungible", isIncluded);
}

TokenFragment& TokenFragment::operator=(const TokenFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

TokenFragment& TokenFragment::operator=(TokenFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string TokenFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool TokenFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool TokenFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
TokenFragment& TokenFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string TokenFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& TokenFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool TokenFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
TokenFragment& TokenFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
TokenFragment& TokenFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion TokenFragment
