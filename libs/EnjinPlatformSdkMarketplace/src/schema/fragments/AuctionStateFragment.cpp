#include "EnjinPlatformSdkMarketplace/AuctionStateFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class AuctionStateFragment::Impl : public GraphQlFragment<Impl>
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

// region AuctionStateFragment

[[maybe_unused]]
AuctionStateFragment::AuctionStateFragment()
    : ListingStateFragment<AuctionStateFragment>(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AuctionStateFragment::AuctionStateFragment(const AuctionStateFragment& other)
    : ListingStateFragment<AuctionStateFragment>(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AuctionStateFragment::AuctionStateFragment(AuctionStateFragment&& other) noexcept = default;

AuctionStateFragment::~AuctionStateFragment() = default;

[[maybe_unused]]
AuctionStateFragment& AuctionStateFragment::WithType(const bool isIncluded)
{
    return WithField("type", isIncluded);
}

[[maybe_unused]]
AuctionStateFragment& AuctionStateFragment::WithHighestBid(MarketplaceBidFragmentPtr fragment)
{
    return WithField("highestBid", std::move(fragment));
}

AuctionStateFragment& AuctionStateFragment::operator=(const AuctionStateFragment& rhs)
{
    ListingStateFragment<AuctionStateFragment>::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AuctionStateFragment& AuctionStateFragment::operator=(AuctionStateFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string AuctionStateFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool AuctionStateFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool AuctionStateFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
AuctionStateFragment& AuctionStateFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
AuctionStateFragment& AuctionStateFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string AuctionStateFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& AuctionStateFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool AuctionStateFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool AuctionStateFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
AuctionStateFragment& AuctionStateFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
AuctionStateFragment& AuctionStateFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion AuctionStateFragment
