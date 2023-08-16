#include "EnjinPlatformSdkMarketplace/FixedPriceDataFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class FixedPriceDataFragment::Impl : public GraphQlFragment<Impl>
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

// region FixedPriceDataFragment

[[maybe_unused]]
FixedPriceDataFragment::FixedPriceDataFragment()
    : ListingDataFragment<FixedPriceDataFragment>(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
FixedPriceDataFragment::FixedPriceDataFragment(const FixedPriceDataFragment& other)
    : ListingDataFragment<FixedPriceDataFragment>(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
FixedPriceDataFragment::FixedPriceDataFragment(FixedPriceDataFragment&& other) noexcept = default;

FixedPriceDataFragment::~FixedPriceDataFragment() = default;

[[maybe_unused]]
FixedPriceDataFragment& FixedPriceDataFragment::WithType(const bool isIncluded)
{
    return WithField("type", isIncluded);
}

FixedPriceDataFragment& FixedPriceDataFragment::operator=(const FixedPriceDataFragment& rhs)
{
    ListingDataFragment<FixedPriceDataFragment>::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

FixedPriceDataFragment& FixedPriceDataFragment::operator=(FixedPriceDataFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string FixedPriceDataFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool FixedPriceDataFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool FixedPriceDataFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
FixedPriceDataFragment& FixedPriceDataFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
FixedPriceDataFragment& FixedPriceDataFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string FixedPriceDataFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& FixedPriceDataFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool FixedPriceDataFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool FixedPriceDataFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
FixedPriceDataFragment& FixedPriceDataFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
FixedPriceDataFragment& FixedPriceDataFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion FixedPriceDataFragment
