#include "EnjinPlatformSdk/TransactionFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class TransactionFragment::Impl : public GraphQlFragment<Impl>
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

// region TransactionFragment

[[maybe_unused]]
TransactionFragment::TransactionFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
TransactionFragment::TransactionFragment(const TransactionFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
TransactionFragment::TransactionFragment(TransactionFragment&& other) noexcept = default;

TransactionFragment::~TransactionFragment() = default;

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithTransactionId(const bool isIncluded)
{
    return WithField("transactionId", isIncluded);
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithMethod(const bool isIncluded)
{
    return WithField("method", isIncluded);
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithState(const bool isIncluded)
{
    return WithField("state", isIncluded);
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithResult(const bool isIncluded)
{
    return WithField("result", isIncluded);
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithEncodedData(const bool isIncluded)
{
    return WithField("encodedData", isIncluded);
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithWallet(WalletFragmentPtr fragment)
{
    return WithField("wallet", std::move(fragment));
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithIdempotencyKey(const bool isIncluded)
{
    return WithField("idempotencyKey", isIncluded);
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithEvents(EventConnectionFragmentPtr fragment)
{
    return WithField("events", std::move(fragment));
}

TransactionFragment& TransactionFragment::operator=(const TransactionFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

TransactionFragment& TransactionFragment::operator=(TransactionFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string TransactionFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool TransactionFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool TransactionFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string TransactionFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& TransactionFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool TransactionFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool TransactionFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
TransactionFragment& TransactionFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion TransactionFragment
