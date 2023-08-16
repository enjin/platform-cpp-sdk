#include "EnjinPlatformSdkMarketplace/MarketplaceListingFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class MarketplaceListingFragment::Impl : public GraphQlFragment<Impl>
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

// region MarketplaceListingFragment

[[maybe_unused]]
MarketplaceListingFragment::MarketplaceListingFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
MarketplaceListingFragment::MarketplaceListingFragment(const MarketplaceListingFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
MarketplaceListingFragment::MarketplaceListingFragment(MarketplaceListingFragment&& other) noexcept = default;

MarketplaceListingFragment::~MarketplaceListingFragment() = default;

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithListingId(const bool isIncluded)
{
    return WithField("listingId", isIncluded);
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithMakeAssetId(AssetFragmentPtr fragment)
{
    return WithField("makeAssetId", std::move(fragment));
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithTakeAssetId(AssetFragmentPtr fragment)
{
    return WithField("takeAssetId", std::move(fragment));
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithAmount(const bool isIncluded)
{
    return WithField("amount", isIncluded);
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithPrice(const bool isIncluded)
{
    return WithField("price", isIncluded);
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithMinTakeValue(const bool isIncluded)
{
    return WithField("minTakeValue", isIncluded);
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithFeeSide(const bool isIncluded)
{
    return WithField("feeSide", isIncluded);
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithCreationBlock(const bool isIncluded)
{
    return WithField("creationBlock", isIncluded);
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithDeposit(const bool isIncluded)
{
    return WithField("deposit", isIncluded);
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithSalt(const bool isIncluded)
{
    return WithField("salt", isIncluded);
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithSeller(WalletFragmentPtr fragment)
{
    return WithField("seller", std::move(fragment));
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithSales(MarketplaceSaleConnectionFragmentPtr fragment)
{
    return WithField("sales", std::move(fragment));
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithBids(MarketplaceBidConnectionFragmentPtr fragment)
{
    return WithField("bids", std::move(fragment));
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithStates(MarketplaceStateFragmentPtr fragment)
{
    return WithField("states", std::move(fragment));
}

MarketplaceListingFragment& MarketplaceListingFragment::operator=(const MarketplaceListingFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

MarketplaceListingFragment& MarketplaceListingFragment::operator=(MarketplaceListingFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string MarketplaceListingFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool MarketplaceListingFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool MarketplaceListingFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string MarketplaceListingFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& MarketplaceListingFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool MarketplaceListingFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool MarketplaceListingFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
MarketplaceListingFragment& MarketplaceListingFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion MarketplaceListingFragment
