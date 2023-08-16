#include "EnjinPlatformSdkMarketplace/AuctionDataFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class AuctionDataFragment::Impl : public GraphQlFragment<Impl>
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

// region AuctionDataFragment

[[maybe_unused]]
AuctionDataFragment::AuctionDataFragment()
    : ListingDataFragment<AuctionDataFragment>(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AuctionDataFragment::AuctionDataFragment(const AuctionDataFragment& other)
    : ListingDataFragment<AuctionDataFragment>(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AuctionDataFragment::AuctionDataFragment(AuctionDataFragment&& other) noexcept = default;

AuctionDataFragment::~AuctionDataFragment() = default;

[[maybe_unused]]
AuctionDataFragment& AuctionDataFragment::WithType(const bool isIncluded)
{
    return WithField("type", isIncluded);
}

[[maybe_unused]]
AuctionDataFragment& AuctionDataFragment::WithStartBlock(const bool isIncluded)
{
    return WithField("startBlock", isIncluded);
}

[[maybe_unused]]
AuctionDataFragment& AuctionDataFragment::WithEndBlock(const bool isIncluded)
{
    return WithField("endBlock", isIncluded);
}

AuctionDataFragment& AuctionDataFragment::operator=(const AuctionDataFragment& rhs)
{
    ListingDataFragment<AuctionDataFragment>::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AuctionDataFragment& AuctionDataFragment::operator=(AuctionDataFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string AuctionDataFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool AuctionDataFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool AuctionDataFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
AuctionDataFragment& AuctionDataFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
AuctionDataFragment& AuctionDataFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string AuctionDataFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& AuctionDataFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool AuctionDataFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool AuctionDataFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
AuctionDataFragment& AuctionDataFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
AuctionDataFragment& AuctionDataFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion AuctionDataFragment
