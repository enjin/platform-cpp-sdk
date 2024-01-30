#include "EnjinPlatformSdkBeam/BeamClaimFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

// region Impl

class BeamClaimFragment::Impl : public GraphQlFragment<Impl>
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

// region BeamClaimFragment

[[maybe_unused]]
BeamClaimFragment::BeamClaimFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
BeamClaimFragment::BeamClaimFragment(const BeamClaimFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
BeamClaimFragment::BeamClaimFragment(BeamClaimFragment&& other) noexcept = default;

BeamClaimFragment::~BeamClaimFragment() = default;

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithId(const bool isIncluded)
{
    return WithField("id", isIncluded);
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithCollection(CollectionFragmentPtr fragment)
{
    return WithField("collection", std::move(fragment));
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithTokenId(const bool isIncluded)
{
    return WithField("tokenId", isIncluded);
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithBeam(BeamFragmentPtr fragment)
{
    return WithField("beam", std::move(fragment));
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithWallet(WalletFragmentPtr fragment)
{
    return WithField("wallet", std::move(fragment));
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithClaimedAt(const bool isIncluded)
{
    return WithField("claimedAt", isIncluded);
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithClaimStatus(const bool isIncluded)
{
    return WithField("claimedAt", isIncluded);
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithCode(const bool isIncluded)
{
    return WithField("code", isIncluded);
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithQr(BeamQrFragmentPtr fragment)
{
    return WithField("qr", std::move(fragment));
}

BeamClaimFragment& BeamClaimFragment::operator=(const BeamClaimFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

BeamClaimFragment& BeamClaimFragment::operator=(BeamClaimFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string BeamClaimFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool BeamClaimFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool BeamClaimFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string BeamClaimFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& BeamClaimFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool BeamClaimFragment::HasParameter(const std::string& key) const
{
    return _pimpl->HasParameter(key);
}

[[maybe_unused]]
bool BeamClaimFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
BeamClaimFragment& BeamClaimFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion BeamClaimFragment
