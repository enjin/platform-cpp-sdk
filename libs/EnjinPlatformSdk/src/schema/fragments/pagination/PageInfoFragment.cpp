#include "EnjinPlatformSdk/PageInfoFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class PageInfoFragment::Impl : public GraphQlFragment<Impl>
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

// region PageInfoFragment

[[maybe_unused]]
PageInfoFragment::PageInfoFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
PageInfoFragment::PageInfoFragment(const PageInfoFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
PageInfoFragment::PageInfoFragment(PageInfoFragment&& other) noexcept = default;

PageInfoFragment::~PageInfoFragment() = default;

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithHasNextPage(const bool isIncluded)
{
    return WithField("hasNextPage", isIncluded);
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithHasPreviousPage(const bool isIncluded)
{
    return WithField("hasPreviousPage", isIncluded);
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithHasStartCursor(const bool isIncluded)
{
    return WithField("startCursor", isIncluded);
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithHasEndCursor(const bool isIncluded)
{
    return WithField("endCursor", isIncluded);
}

PageInfoFragment& PageInfoFragment::operator=(const PageInfoFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

PageInfoFragment& PageInfoFragment::operator=(PageInfoFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string PageInfoFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool PageInfoFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool PageInfoFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string PageInfoFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& PageInfoFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool PageInfoFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool PageInfoFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion PageInfoFragment
