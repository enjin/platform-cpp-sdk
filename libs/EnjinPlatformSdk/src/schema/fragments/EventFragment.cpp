#include "EnjinPlatformSdk/EventFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class EventFragment::Impl : public GraphQlFragment<Impl>
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

// region EventFragment

[[maybe_unused]]
EventFragment::EventFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
EventFragment::EventFragment(const EventFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
EventFragment::EventFragment(EventFragment&& other) noexcept = default;

EventFragment::~EventFragment() = default;

[[maybe_unused]]
EventFragment& EventFragment::WithPhase(const bool isIncluded)
{
    return WithField("phase", isIncluded);
}

[[maybe_unused]]
EventFragment& EventFragment::WithLookup(const bool isIncluded)
{
    return WithField("lookUp", isIncluded);
}

[[maybe_unused]]
EventFragment& EventFragment::WithModuleId(const bool isIncluded)
{
    return WithField("moduleId", isIncluded);
}

[[maybe_unused]]
EventFragment& EventFragment::WithEventId(const bool isIncluded)
{
    return WithField("eventId", isIncluded);
}

[[maybe_unused]]
EventFragment& EventFragment::WithParams(EventParamFragmentPtr fragment)
{
    return WithField("params", std::move(fragment));
}

EventFragment& EventFragment::operator=(const EventFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

EventFragment& EventFragment::operator=(EventFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string EventFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool EventFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool EventFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
EventFragment& EventFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
EventFragment& EventFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string EventFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& EventFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool EventFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool EventFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
EventFragment& EventFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
EventFragment& EventFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion EventFragment
