#include "EnjinPlatformSdkBeam/BeamScanFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

// region Impl

class BeamScanFragment::Impl : public GraphQlFragment<Impl>
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

// region BeamScanFragment

[[maybe_unused]]
BeamScanFragment::BeamScanFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
BeamScanFragment::BeamScanFragment(const BeamScanFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
BeamScanFragment::BeamScanFragment(BeamScanFragment&& other) noexcept = default;

BeamScanFragment::~BeamScanFragment() = default;

[[maybe_unused]]
BeamScanFragment& BeamScanFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
BeamScanFragment& BeamScanFragment::WithWalletPublicKey(const bool isIncluded)
{
    return WithField("walletPublicKey", isIncluded);
}

[[maybe_unused]]
BeamScanFragment& BeamScanFragment::WithMessage(const bool isIncluded)
{
    return WithField("message", isIncluded);
}

BeamScanFragment& BeamScanFragment::operator=(const BeamScanFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

BeamScanFragment& BeamScanFragment::operator=(BeamScanFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string BeamScanFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool BeamScanFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool BeamScanFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
BeamScanFragment& BeamScanFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
BeamScanFragment& BeamScanFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string BeamScanFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& BeamScanFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool BeamScanFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool BeamScanFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
BeamScanFragment& BeamScanFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
BeamScanFragment& BeamScanFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion BeamScanFragment
