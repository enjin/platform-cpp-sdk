#include "EnjinPlatformSdk/CollectionFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class CollectionFragment::Impl : public GraphQlFragment<Impl>
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

// region CollectionFragment

[[maybe_unused]]
CollectionFragment::CollectionFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
CollectionFragment::CollectionFragment(const CollectionFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
CollectionFragment::CollectionFragment(CollectionFragment&& other) noexcept = default;

CollectionFragment::~CollectionFragment() = default;

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithCollectionId(const bool isIncluded)
{
    return WithField("collectionId", isIncluded);
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithMaxTokenCount(const bool isIncluded)
{
    return WithField("maxTokenCount", isIncluded);
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithMaxTokenSupply(const bool isIncluded)
{
    return WithField("maxTokenSupply", isIncluded);
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithForceSingleMint(const bool isIncluded)
{
    return WithField("forceSingleMint", isIncluded);
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithFrozen(const bool isIncluded)
{
    return WithField("frozen", isIncluded);
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithRoyalty(RoyaltyFragmentPtr fragment)
{
    return WithField("royalty", std::move(fragment));
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithNetwork(const bool isIncluded)
{
    return WithField("network", isIncluded);
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithOwner(WalletFragmentPtr fragment)
{
    return WithField("owner", std::move(fragment));
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithAttributes(AttributeFragmentPtr fragment)
{
    return WithField("attributes", std::move(fragment));
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithAccounts(CollectionAccountConnectionFragmentPtr fragment)
{
    return WithField("accounts", std::move(fragment));
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithTokens(TokenConnectionFragmentPtr fragment)
{
    return WithField("tokens", std::move(fragment));
}

CollectionFragment& CollectionFragment::operator=(const CollectionFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

CollectionFragment& CollectionFragment::operator=(CollectionFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string CollectionFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool CollectionFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool CollectionFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string CollectionFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& CollectionFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool CollectionFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
CollectionFragment& CollectionFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion CollectionFragment
