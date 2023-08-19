#include "EnjinPlatformSdk/BlockFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class BlockFragment::Impl : public GraphQlFragment<Impl>
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

// region BlockFragment

[[maybe_unused]]
BlockFragment::BlockFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
BlockFragment::BlockFragment(const BlockFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
BlockFragment::BlockFragment(BlockFragment&& other) noexcept = default;

BlockFragment::~BlockFragment() = default;

[[maybe_unused]]
BlockFragment& BlockFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
BlockFragment& BlockFragment::WithNumber(const bool isIncluded)
{
    return WithField("number", isIncluded);
}

[[maybe_unused]]
BlockFragment& BlockFragment::WithHash(const bool isIncluded)
{
    return WithField("hash", isIncluded);
}

[[maybe_unused]]
BlockFragment& BlockFragment::WithSynced(const bool isIncluded)
{
    return WithField("synced", isIncluded);
}

[[maybe_unused]]
BlockFragment& BlockFragment::WithFailed(const bool isIncluded)
{
    return WithField("failed", isIncluded);
}

[[maybe_unused]]
BlockFragment& BlockFragment::WithException(const bool isIncluded)
{
    return WithField("exception", isIncluded);
}

BlockFragment& BlockFragment::operator=(const BlockFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

BlockFragment& BlockFragment::operator=(BlockFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string BlockFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool BlockFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool BlockFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
BlockFragment& BlockFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
BlockFragment& BlockFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string BlockFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& BlockFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool BlockFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool BlockFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
BlockFragment& BlockFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
BlockFragment& BlockFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion BlockFragment
