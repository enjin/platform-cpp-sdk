#include "EnjinPlatformSdk/TokenAccountNamedReserveFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class TokenAccountNamedReserveFragment::Impl : public GraphQlFragment<Impl>
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

// region TokenAccountNamedReserveFragment

[[maybe_unused]]
TokenAccountNamedReserveFragment::TokenAccountNamedReserveFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
TokenAccountNamedReserveFragment::TokenAccountNamedReserveFragment(const TokenAccountNamedReserveFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
TokenAccountNamedReserveFragment::TokenAccountNamedReserveFragment(
    TokenAccountNamedReserveFragment&& other) noexcept = default;

TokenAccountNamedReserveFragment::~TokenAccountNamedReserveFragment() = default;

[[maybe_unused]]
TokenAccountNamedReserveFragment& TokenAccountNamedReserveFragment::WalletPallet(const bool isIncluded)
{
    return WithField("pallet", isIncluded);
}

[[maybe_unused]]
TokenAccountNamedReserveFragment& TokenAccountNamedReserveFragment::WalletAmount(const bool isIncluded)
{
    return WithField("amount", isIncluded);
}

TokenAccountNamedReserveFragment&
TokenAccountNamedReserveFragment::operator=(const TokenAccountNamedReserveFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

TokenAccountNamedReserveFragment&
TokenAccountNamedReserveFragment::operator=(TokenAccountNamedReserveFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string TokenAccountNamedReserveFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool TokenAccountNamedReserveFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool TokenAccountNamedReserveFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
TokenAccountNamedReserveFragment& TokenAccountNamedReserveFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
TokenAccountNamedReserveFragment&
TokenAccountNamedReserveFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string TokenAccountNamedReserveFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& TokenAccountNamedReserveFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool TokenAccountNamedReserveFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
TokenAccountNamedReserveFragment& TokenAccountNamedReserveFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
TokenAccountNamedReserveFragment& TokenAccountNamedReserveFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion TokenAccountNamedReserveFragment
