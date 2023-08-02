#include "EnjinPlatformSdkBeam/BeamFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

// region Impl

class BeamFragment::Impl : public GraphQlFragment<Impl>
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

// region BeamFragment

[[maybe_unused]]
BeamFragment::BeamFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
BeamFragment::BeamFragment(const BeamFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
BeamFragment::BeamFragment(BeamFragment&& other) noexcept = default;

BeamFragment::~BeamFragment() = default;

[[maybe_unused]]
BeamFragment& BeamFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithCode(const bool isIncluded)
{
    return WithField("code", isIncluded);
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithName(const bool isIncluded)
{
    return WithField("name", isIncluded);
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithDescription(const bool isIncluded)
{
    return WithField("description", isIncluded);
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithImage(const bool isIncluded)
{
    return WithField("image", isIncluded);
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithStart(const bool isIncluded)
{
    return WithField("start", isIncluded);
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithEnd(const bool isIncluded)
{
    return WithField("end", isIncluded);
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithCollection(CollectionFragmentPtr fragment)
{
    return WithField("collection", std::move(fragment));
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithMessage(BeamScanFragmentPtr fragment)
{
    return WithField("message", std::move(fragment));
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithFlags(const bool isIncluded)
{
    return WithField("flags", isIncluded);
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithQr(BeamQrFragmentPtr fragment)
{
    return WithField("qr", std::move(fragment));
}

BeamFragment& BeamFragment::operator=(const BeamFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

BeamFragment& BeamFragment::operator=(BeamFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string BeamFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool BeamFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool BeamFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
BeamFragment& BeamFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string BeamFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& BeamFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool BeamFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
BeamFragment& BeamFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
BeamFragment& BeamFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion BeamFragment
