#include "EnjinPlatformSdk/AccountRequestFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class AccountRequestFragment::Impl : public GraphQlFragment<Impl>
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

// region AccountRequestFragment

[[maybe_unused]]
AccountRequestFragment::AccountRequestFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AccountRequestFragment::AccountRequestFragment(const AccountRequestFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AccountRequestFragment::AccountRequestFragment(AccountRequestFragment&& other) noexcept = default;

AccountRequestFragment::~AccountRequestFragment() = default;

[[maybe_unused]]
AccountRequestFragment& AccountRequestFragment::WithQrCode(const bool isIncluded)
{
    return WithField("qrCode", isIncluded);
}

[[maybe_unused]]
AccountRequestFragment& AccountRequestFragment::WithVerificationId(const bool isIncluded)
{
    return WithField("verificationId", isIncluded);
}

AccountRequestFragment& AccountRequestFragment::operator=(const AccountRequestFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AccountRequestFragment& AccountRequestFragment::operator=(AccountRequestFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string AccountRequestFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool AccountRequestFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool AccountRequestFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
AccountRequestFragment& AccountRequestFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
AccountRequestFragment& AccountRequestFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string AccountRequestFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& AccountRequestFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool AccountRequestFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool AccountRequestFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
AccountRequestFragment& AccountRequestFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
AccountRequestFragment& AccountRequestFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion AccountRequestFragment
