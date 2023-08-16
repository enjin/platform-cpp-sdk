#include "EnjinPlatformSdkMarketplace/AssetFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;

// region Impl

class AssetFragment::Impl : public GraphQlFragment<Impl>
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

// region AssetFragment

[[maybe_unused]]
AssetFragment::AssetFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
AssetFragment::AssetFragment(const AssetFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
AssetFragment::AssetFragment(AssetFragment&& other) noexcept = default;

AssetFragment::~AssetFragment() = default;

[[maybe_unused]]
AssetFragment& AssetFragment::WithCollectionId(const bool isIncluded)
{
    return WithField("collectionId", isIncluded);
}

[[maybe_unused]]
AssetFragment& AssetFragment::WithTokenId(const bool isIncluded)
{
    return WithField("tokenId", isIncluded);
}

AssetFragment& AssetFragment::operator=(const AssetFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

AssetFragment& AssetFragment::operator=(AssetFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string AssetFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool AssetFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool AssetFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
AssetFragment& AssetFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
AssetFragment& AssetFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string AssetFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& AssetFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool AssetFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool AssetFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
AssetFragment& AssetFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
AssetFragment& AssetFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion AssetFragment
