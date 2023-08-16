#include "EnjinPlatformSdkMarketplace/MarketplaceStateFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class MarketplaceStateFragment::Impl : public GraphQlFragment<Impl>
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

// region MarketplaceStateFragment

[[maybe_unused]]
MarketplaceStateFragment::MarketplaceStateFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
MarketplaceStateFragment::MarketplaceStateFragment(const MarketplaceStateFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
MarketplaceStateFragment::MarketplaceStateFragment(MarketplaceStateFragment&& other) noexcept = default;

MarketplaceStateFragment::~MarketplaceStateFragment() = default;

[[maybe_unused]]
MarketplaceStateFragment& MarketplaceStateFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
MarketplaceStateFragment& MarketplaceStateFragment::WithState(const bool isIncluded)
{
    return WithField("state", isIncluded);
}

[[maybe_unused]]
MarketplaceStateFragment& MarketplaceStateFragment::WithHeight(const bool isIncluded)
{
    return WithField("height", isIncluded);
}

[[maybe_unused]]
MarketplaceStateFragment& MarketplaceStateFragment::WithListing(MarketplaceListingFragmentPtr fragment)
{
    return WithField("listing", std::move(fragment));
}

MarketplaceStateFragment& MarketplaceStateFragment::operator=(const MarketplaceStateFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

MarketplaceStateFragment& MarketplaceStateFragment::operator=(MarketplaceStateFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string MarketplaceStateFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool MarketplaceStateFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool MarketplaceStateFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
MarketplaceStateFragment& MarketplaceStateFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
MarketplaceStateFragment& MarketplaceStateFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string MarketplaceStateFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& MarketplaceStateFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool MarketplaceStateFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool MarketplaceStateFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
MarketplaceStateFragment& MarketplaceStateFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
MarketplaceStateFragment& MarketplaceStateFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion MarketplaceStateFragment
