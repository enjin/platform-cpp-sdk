#include "EnjinPlatformSdk/TokenAccountApprovalFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class TokenAccountApprovalFragment::Impl : public GraphQlFragment<Impl>
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

// region TokenAccountApprovalFragment

[[maybe_unused]]
TokenAccountApprovalFragment::TokenAccountApprovalFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
TokenAccountApprovalFragment::TokenAccountApprovalFragment(const TokenAccountApprovalFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
TokenAccountApprovalFragment::TokenAccountApprovalFragment(TokenAccountApprovalFragment&& other) noexcept = default;

TokenAccountApprovalFragment::~TokenAccountApprovalFragment() = default;

[[maybe_unused]]
TokenAccountApprovalFragment& TokenAccountApprovalFragment::WithAmount(const bool isIncluded)
{
    return WithField("amount", isIncluded);
}

[[maybe_unused]]
TokenAccountApprovalFragment& TokenAccountApprovalFragment::WithExpiration(const bool isIncluded)
{
    return WithField("expiration", isIncluded);
}

[[maybe_unused]]
TokenAccountApprovalFragment& TokenAccountApprovalFragment::WithAccount(TokenAccountFragmentPtr fragment)
{
    return WithField("account", std::move(fragment));
}

[[maybe_unused]]
TokenAccountApprovalFragment& TokenAccountApprovalFragment::WithWallet(WalletFragmentPtr fragment)
{
    return WithField("wallet", std::move(fragment));
}

TokenAccountApprovalFragment& TokenAccountApprovalFragment::operator=(const TokenAccountApprovalFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

TokenAccountApprovalFragment&
TokenAccountApprovalFragment::operator=(TokenAccountApprovalFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string TokenAccountApprovalFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool TokenAccountApprovalFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool TokenAccountApprovalFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
TokenAccountApprovalFragment& TokenAccountApprovalFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
TokenAccountApprovalFragment& TokenAccountApprovalFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string TokenAccountApprovalFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& TokenAccountApprovalFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool TokenAccountApprovalFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
TokenAccountApprovalFragment& TokenAccountApprovalFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
TokenAccountApprovalFragment& TokenAccountApprovalFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion TokenAccountApprovalFragment
