#include "EnjinPlatformSdk/RoyaltyFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class RoyaltyFragment::Impl : public GraphQlFragment<Impl>
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

// region RoyaltyFragment

[[maybe_unused]]
RoyaltyFragment::RoyaltyFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
RoyaltyFragment::RoyaltyFragment(const RoyaltyFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
RoyaltyFragment::RoyaltyFragment(RoyaltyFragment&& other) noexcept = default;

RoyaltyFragment::~RoyaltyFragment() = default;

[[maybe_unused]]
RoyaltyFragment& RoyaltyFragment::WithBeneficiary(WalletFragmentPtr fragment)
{
    return WithField("beneficiary", std::move(fragment));
}

[[maybe_unused]]
RoyaltyFragment& RoyaltyFragment::WithPercentage(const bool isIncluded)
{
    return WithField("percentage", isIncluded);
}

RoyaltyFragment& RoyaltyFragment::operator=(const RoyaltyFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

RoyaltyFragment& RoyaltyFragment::operator=(RoyaltyFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string RoyaltyFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool RoyaltyFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool RoyaltyFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
RoyaltyFragment& RoyaltyFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
RoyaltyFragment& RoyaltyFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string RoyaltyFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& RoyaltyFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool RoyaltyFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
RoyaltyFragment& RoyaltyFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
RoyaltyFragment& RoyaltyFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion RoyaltyFragment
