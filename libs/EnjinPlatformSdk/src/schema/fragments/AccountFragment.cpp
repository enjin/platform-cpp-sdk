#include "EnjinPlatformSdk/AccountFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class AccountFragment::Impl : public GraphQlFragment<Impl>
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

// region AccountFragment

[[maybe_unused]]
AccountFragment::AccountFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AccountFragment::AccountFragment(const AccountFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AccountFragment::AccountFragment(AccountFragment&& other) noexcept = default;

AccountFragment::~AccountFragment() = default;

[[maybe_unused]]
AccountFragment& AccountFragment::WithPublicKey(const bool isIncluded)
{
    return WithField("publicKey", isIncluded);
}

[[maybe_unused]]
AccountFragment& AccountFragment::WithAddress(const bool isIncluded)
{
    return WithField("address", isIncluded);
}

AccountFragment& AccountFragment::operator=(const AccountFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AccountFragment& AccountFragment::operator=(AccountFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string AccountFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool AccountFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool AccountFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
AccountFragment& AccountFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
AccountFragment& AccountFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string AccountFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& AccountFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool AccountFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool AccountFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
AccountFragment& AccountFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
AccountFragment& AccountFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion AccountFragment
