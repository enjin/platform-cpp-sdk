#include "EnjinPlatformSdkMarketplace/FixedPriceStateFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class FixedPriceStateFragment::Impl : public GraphQlFragment<Impl>
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

// region FixedPriceStateFragment

[[maybe_unused]]
FixedPriceStateFragment::FixedPriceStateFragment()
    : ListingStateFragment<FixedPriceStateFragment>(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
FixedPriceStateFragment::FixedPriceStateFragment(const FixedPriceStateFragment& other)
    : ListingStateFragment<FixedPriceStateFragment>(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
FixedPriceStateFragment::FixedPriceStateFragment(FixedPriceStateFragment&& other) noexcept = default;

FixedPriceStateFragment::~FixedPriceStateFragment() = default;

[[maybe_unused]]
FixedPriceStateFragment& FixedPriceStateFragment::WithType(const bool isIncluded)
{
    return WithField("type", isIncluded);
}

[[maybe_unused]]
FixedPriceStateFragment& FixedPriceStateFragment::WithAmountFilled(const bool isIncluded)
{
    return WithField("amountFilled", isIncluded);
}

FixedPriceStateFragment& FixedPriceStateFragment::operator=(const FixedPriceStateFragment& rhs)
{
    ListingStateFragment<FixedPriceStateFragment>::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

FixedPriceStateFragment& FixedPriceStateFragment::operator=(FixedPriceStateFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string FixedPriceStateFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool FixedPriceStateFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool FixedPriceStateFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
FixedPriceStateFragment& FixedPriceStateFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
FixedPriceStateFragment& FixedPriceStateFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string FixedPriceStateFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& FixedPriceStateFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool FixedPriceStateFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool FixedPriceStateFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
FixedPriceStateFragment& FixedPriceStateFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
FixedPriceStateFragment& FixedPriceStateFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion FixedPriceStateFragment
