#include "EnjinPlatformSdkMarketplace/MarketplaceSaleFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class MarketplaceSaleFragment::Impl : public GraphQlFragment<Impl>
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

// region MarketplaceSaleFragment

[[maybe_unused]]
MarketplaceSaleFragment::MarketplaceSaleFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
MarketplaceSaleFragment::MarketplaceSaleFragment(const MarketplaceSaleFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
MarketplaceSaleFragment::MarketplaceSaleFragment(MarketplaceSaleFragment&& other) noexcept = default;

MarketplaceSaleFragment::~MarketplaceSaleFragment() = default;

[[maybe_unused]]
MarketplaceSaleFragment& MarketplaceSaleFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
MarketplaceSaleFragment& MarketplaceSaleFragment::WithPrice(const bool isIncluded)
{
    return WithField("price", isIncluded);
}

[[maybe_unused]]
MarketplaceSaleFragment& MarketplaceSaleFragment::WithAmount(const bool isIncluded)
{
    return WithField("amount", isIncluded);
}

[[maybe_unused]]
MarketplaceSaleFragment& MarketplaceSaleFragment::WithBidder(WalletFragmentPtr fragment)
{
    return WithField("bidder", std::move(fragment));
}

[[maybe_unused]]
MarketplaceSaleFragment& MarketplaceSaleFragment::WithListing(MarketplaceListingFragmentPtr fragment)
{
    return WithField("listing", std::move(fragment));
}

MarketplaceSaleFragment& MarketplaceSaleFragment::operator=(const MarketplaceSaleFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

MarketplaceSaleFragment& MarketplaceSaleFragment::operator=(MarketplaceSaleFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string MarketplaceSaleFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool MarketplaceSaleFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool MarketplaceSaleFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
MarketplaceSaleFragment& MarketplaceSaleFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
MarketplaceSaleFragment& MarketplaceSaleFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string MarketplaceSaleFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& MarketplaceSaleFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool MarketplaceSaleFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool MarketplaceSaleFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
MarketplaceSaleFragment& MarketplaceSaleFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
MarketplaceSaleFragment& MarketplaceSaleFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion MarketplaceSaleFragment
