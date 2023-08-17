#include "EnjinPlatformSdk/AccountVerifiedFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class AccountVerifiedFragment::Impl : public GraphQlFragment<Impl>
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

// region AccountVerifiedFragment

[[maybe_unused]]
AccountVerifiedFragment::AccountVerifiedFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AccountVerifiedFragment::AccountVerifiedFragment(const AccountVerifiedFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AccountVerifiedFragment::AccountVerifiedFragment(AccountVerifiedFragment&& other) noexcept = default;

AccountVerifiedFragment::~AccountVerifiedFragment() = default;

[[maybe_unused]]
AccountVerifiedFragment& AccountVerifiedFragment::WithVerified(const bool isIncluded)
{
    return WithField("verified", isIncluded);
}

[[maybe_unused]]
AccountVerifiedFragment& AccountVerifiedFragment::WithAccount(AccountFragmentPtr fragment)
{
    return WithField("account", std::move(fragment));
}

AccountVerifiedFragment& AccountVerifiedFragment::operator=(const AccountVerifiedFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AccountVerifiedFragment& AccountVerifiedFragment::operator=(AccountVerifiedFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string AccountVerifiedFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool AccountVerifiedFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool AccountVerifiedFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
AccountVerifiedFragment& AccountVerifiedFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
AccountVerifiedFragment& AccountVerifiedFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string AccountVerifiedFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& AccountVerifiedFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool AccountVerifiedFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
AccountVerifiedFragment& AccountVerifiedFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
AccountVerifiedFragment& AccountVerifiedFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion AccountVerifiedFragment
