#include "EnjinPlatformSdkMarketplace/MarketplaceBidFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class MarketplaceBidFragment::Impl : public GraphQlFragment<Impl>
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

// region MarketplaceBidFragment

[[maybe_unused]]
MarketplaceBidFragment::MarketplaceBidFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
MarketplaceBidFragment::MarketplaceBidFragment(const MarketplaceBidFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
MarketplaceBidFragment::MarketplaceBidFragment(MarketplaceBidFragment&& other) noexcept = default;

MarketplaceBidFragment::~MarketplaceBidFragment() = default;

[[maybe_unused]]
MarketplaceBidFragment& MarketplaceBidFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
MarketplaceBidFragment& MarketplaceBidFragment::WithPrice(const bool isIncluded)
{
    return WithField("price", isIncluded);
}

[[maybe_unused]]
MarketplaceBidFragment& MarketplaceBidFragment::WithHeight(const bool isIncluded)
{
    return WithField("height", isIncluded);
}

[[maybe_unused]]
MarketplaceBidFragment& MarketplaceBidFragment::WithBidder(WalletFragmentPtr fragment)
{
    return WithField("bidder", std::move(fragment));
}

[[maybe_unused]]
MarketplaceBidFragment& MarketplaceBidFragment::WithListing(MarketplaceListingFragmentPtr fragment)
{
    return WithField("listing", std::move(fragment));
}

MarketplaceBidFragment& MarketplaceBidFragment::operator=(const MarketplaceBidFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

MarketplaceBidFragment& MarketplaceBidFragment::operator=(MarketplaceBidFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string MarketplaceBidFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool MarketplaceBidFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool MarketplaceBidFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
MarketplaceBidFragment& MarketplaceBidFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
MarketplaceBidFragment& MarketplaceBidFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string MarketplaceBidFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& MarketplaceBidFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool MarketplaceBidFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool MarketplaceBidFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
MarketplaceBidFragment& MarketplaceBidFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
MarketplaceBidFragment& MarketplaceBidFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion MarketplaceBidFragment
