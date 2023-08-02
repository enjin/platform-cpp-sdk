#ifndef ENJINPLATFORMSDKBEAM_BEAMCLAIMFRAGMENT_HPP
#define ENJINPLATFORMSDKBEAM_BEAMCLAIMFRAGMENT_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/CollectionFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include "EnjinPlatformSdkBeam/BeamFragment.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlFragmentORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
// region Forward declarations

class BeamFragment;

using BeamFragmentPtr = std::shared_ptr<BeamFragment>;

// endregion Forward declarations

class BeamClaimFragment;

/// \brief Definition for a pointer containing a beam claim fragment.
using BeamClaimFragmentPtr [[maybe_unused]] = std::shared_ptr<BeamClaimFragment>;

/// \brief Definition for a beam claim connection fragment.
using BeamClaimConnectionFragment [[maybe_unused]] = ConnectionFragment<BeamClaimFragment>;

/// \brief Definition for a pointer containing a beam claim connection fragment.
using BeamClaimConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<BeamClaimConnectionFragment>;

/// \brief A fragment for requesting properties of a BeamClaim returned by the platform.
class ENJINPLATFORMSDKBEAM_EXPORT BeamClaimFragment : public IGraphQlFragment<BeamClaimFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BeamClaimFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BeamClaimFragment(const BeamClaimFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BeamClaimFragment(BeamClaimFragment&& other) noexcept;

    /// \brief Class destructor.
    ~BeamClaimFragment() override;

    /// \brief Sets whether the BeamClaim is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamClaimFragment& WithId(bool isIncluded = true);

    /// \brief Sets the Collection fragment to be used for getting the collection property of the BeamClaim.
    /// \param fragment The Collection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamClaimFragment& WithCollection(CollectionFragmentPtr fragment);

    /// \brief Sets whether the BeamClaim is to be returned with its tokenId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamClaimFragment& WithTokenId(bool isIncluded = true);

    /// \brief Sets the Beam fragment to be used for getting the beam property of the BeamClaim.
    /// \param fragment The Beam fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamClaimFragment& WithBeam(BeamFragmentPtr fragment);

    /// \brief Sets the Wallet fragment to be used for getting the wallet property of the BeamClaim.
    /// \param fragment The Wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamClaimFragment& WithWallet(WalletFragmentPtr fragment);

    /// \brief Sets whether the BeamClaim is to be returned with its claimedAt property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamClaimFragment& WithClaimedAt(bool isIncluded = true);

    /// \brief Sets whether the BeamClaim is to be returned with its claimStatus property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamClaimFragment& WithClaimStatus(bool isIncluded = true);

    /// \brief Sets whether the BeamClaim is to be returned with its code property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamClaimFragment& WithCode(bool isIncluded = true);

    /// \brief Sets whether the BeamClaim is to be returned with its qr property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamClaimFragment& WithQr(bool isIncluded = true);

    BeamClaimFragment& operator=(const BeamClaimFragment& rhs);

    BeamClaimFragment& operator=(BeamClaimFragment&& rhs) noexcept;

    // region IGraphQlFragment

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileFields() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasField(const std::string& name) const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasFields() const override;

    [[maybe_unused]]
    BeamClaimFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    BeamClaimFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

    // endregion IGraphQlFragment

    // region IGraphQlParameterHolder

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, SerializablePtr>& GetParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override;

    [[maybe_unused]]
    BeamClaimFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    BeamClaimFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMCLAIMFRAGMENT_HPP
