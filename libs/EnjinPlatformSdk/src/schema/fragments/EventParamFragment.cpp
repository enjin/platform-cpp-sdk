#include "EnjinPlatformSdk/EventParamFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class EventParamFragment::Impl : public GraphQlFragment<Impl>
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

// region EventParamFragment

[[maybe_unused]]
EventParamFragment::EventParamFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
EventParamFragment::EventParamFragment(const EventParamFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
EventParamFragment::EventParamFragment(EventParamFragment&& other) noexcept = default;

EventParamFragment::~EventParamFragment() = default;

[[maybe_unused]]
EventParamFragment& EventParamFragment::WithType(const bool isIncluded)
{
    return WithField("type", isIncluded);
}

[[maybe_unused]]
EventParamFragment& EventParamFragment::WithValue(const bool isIncluded)
{
    return WithField("value", isIncluded);
}

EventParamFragment& EventParamFragment::operator=(const EventParamFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

EventParamFragment& EventParamFragment::operator=(EventParamFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string EventParamFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool EventParamFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool EventParamFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
EventParamFragment& EventParamFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
EventParamFragment& EventParamFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string EventParamFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& EventParamFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool EventParamFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool EventParamFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
EventParamFragment& EventParamFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
EventParamFragment& EventParamFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion EventParamFragment
