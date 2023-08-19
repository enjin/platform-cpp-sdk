#include "EnjinPlatformSdk/WalletFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class WalletFragment::Impl : public GraphQlFragment<Impl>
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

// region WalletFragment

[[maybe_unused]]
WalletFragment::WalletFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
WalletFragment::WalletFragment(const WalletFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
WalletFragment::WalletFragment(WalletFragment&& other) noexcept = default;

WalletFragment::~WalletFragment() = default;

[[maybe_unused]]
WalletFragment& WalletFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithAccount(AccountFragmentPtr fragment)
{
    return WithField("account", std::move(fragment));
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithExternalId(const bool isIncluded)
{
    return WithField("externalId", isIncluded);
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithManaged(const bool isIncluded)
{
    return WithField("managed", isIncluded);
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithNetwork(const bool isIncluded)
{
    return WithField("network", isIncluded);
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithNonce(const bool isIncluded)
{
    return WithField("nonce", isIncluded);
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithBalances(BalancesFragmentPtr fragment)
{
    return WithField("balances", std::move(fragment));
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithCollectionAccounts(CollectionAccountConnectionFragmentPtr fragment)
{
    return WithField("collectionAccounts", std::move(fragment));
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithTokenAccounts(TokenAccountConnectionFragmentPtr fragment)
{
    return WithField("tokenAccounts", std::move(fragment));
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithCollectionAccountApprovals(CollectionAccountApprovalConnectionFragmentPtr fragment)
{
    return WithField("collectionAccountApprovals", std::move(fragment));
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithTokenAccountApprovals(TokenAccountApprovalConnectionFragmentPtr fragment)
{
    return WithField("tokenAccountApprovals", std::move(fragment));
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithTransactions(TransactionConnectionFragmentPtr fragment)
{
    return WithField("transactions", std::move(fragment));
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithOwnedCollections(CollectionConnectionFragmentPtr fragment)
{
    return WithField("ownedCollections", std::move(fragment));
}

WalletFragment& WalletFragment::operator=(const WalletFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

WalletFragment& WalletFragment::operator=(WalletFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string WalletFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool WalletFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool WalletFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
WalletFragment& WalletFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string WalletFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& WalletFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool WalletFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool WalletFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
WalletFragment& WalletFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
WalletFragment& WalletFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion WalletFragment
