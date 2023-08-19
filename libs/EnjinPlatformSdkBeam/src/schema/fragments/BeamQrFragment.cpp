#include "EnjinPlatformSdkBeam/BeamQrFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

// region Impl

class BeamQrFragment::Impl : public GraphQlFragment<Impl>
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

// region BeamQrFragment

[[maybe_unused]]
BeamQrFragment::BeamQrFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
BeamQrFragment::BeamQrFragment(const BeamQrFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
BeamQrFragment::BeamQrFragment(BeamQrFragment&& other) noexcept = default;

BeamQrFragment::~BeamQrFragment() = default;

[[maybe_unused]]
BeamQrFragment& BeamQrFragment::WithUrl(const bool isIncluded)
{
    return WithField("url", isIncluded);
}

[[maybe_unused]]
BeamQrFragment& BeamQrFragment::WithPayload(const bool isIncluded)
{
    return WithField("payload", isIncluded);
}

BeamQrFragment& BeamQrFragment::operator=(const BeamQrFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

BeamQrFragment& BeamQrFragment::operator=(BeamQrFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string BeamQrFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool BeamQrFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool BeamQrFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
BeamQrFragment& BeamQrFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
BeamQrFragment& BeamQrFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string BeamQrFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& BeamQrFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool BeamQrFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool BeamQrFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
BeamQrFragment& BeamQrFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
BeamQrFragment& BeamQrFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion BeamQrFragment
