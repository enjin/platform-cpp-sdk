#include "EnjinPlatformSdkFuelTanks/FuelTankFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;

// region Impl

class FuelTankFragment::Impl : public GraphQlFragment<Impl>
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

// region FuelTankFragment

[[maybe_unused]]
FuelTankFragment::FuelTankFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
FuelTankFragment::FuelTankFragment(const FuelTankFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
FuelTankFragment::FuelTankFragment(FuelTankFragment&& other) noexcept = default;

FuelTankFragment::~FuelTankFragment() = default;

[[maybe_unused]]
FuelTankFragment& FuelTankFragment::WithName(const bool isIncluded)
{
    return WithField("name", isIncluded);
}

[[maybe_unused]]
FuelTankFragment& FuelTankFragment::WithTankId(const bool isIncluded)
{
    return WithField("tankId", isIncluded);
}

FuelTankFragment& FuelTankFragment::operator=(const FuelTankFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

FuelTankFragment& FuelTankFragment::operator=(FuelTankFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string FuelTankFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool FuelTankFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool FuelTankFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
FuelTankFragment& FuelTankFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
FuelTankFragment& FuelTankFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string FuelTankFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& FuelTankFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool FuelTankFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool FuelTankFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
FuelTankFragment& FuelTankFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
FuelTankFragment& FuelTankFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion FuelTankFragment
