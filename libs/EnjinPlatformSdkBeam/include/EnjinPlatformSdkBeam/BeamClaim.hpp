#ifndef ENJINPLATFORMSDKBEAM_BEAMCLAIM_HPP
#define ENJINPLATFORMSDKBEAM_BEAMCLAIM_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/Collection.hpp"
#include "EnjinPlatformSdk/DateTime.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdkBeam/Beam.hpp"
#include "EnjinPlatformSdkBeam/BeamQr.hpp"
#include "EnjinPlatformSdkBeam/BeamType.hpp"
#include "EnjinPlatformSdkBeam/ClaimStatus.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk::beam
{
// region Forward declarations

class Beam;

class BeamQr;

// endregion Forward declarations

/// \brief Models a beam claim.
class ENJINPLATFORMSDKBEAM_EXPORT BeamClaim : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BeamClaim();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BeamClaim(const BeamClaim& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BeamClaim(BeamClaim&& other) noexcept;

    /// \brief Class destructor.
    ~BeamClaim() override;

    /// \brief Returns the internal ID of this claim.
    /// \return The internal ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int>& GetId() const;

    /// \brief Returns the collection details.
    /// \return The collection details.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const;

    /// \brief Returns the token chain ID.
    /// \return The token chain ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetTokenId() const;

    /// \brief Returns the beam details.
    /// \return The beam details.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Beam>& GetBeam() const;

    /// \brief Returns the wallet account.
    /// \return The wallet account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const;

    /// \brief Returns the timestamp of this claim.
    /// \return The timestamp.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<DateTime>& GetClaimAt() const;

    /// \brief Returns status of this claim.
    /// \return The status.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<ClaimStatus>& GetClaimStatus() const;

    /// \brief Returns the beam type of this claim.
    /// \return The type.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<BeamType>& GetType() const;

    /// \brief Returns the single use code for this claim.
    /// \return The code.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetCode() const;

    /// \brief Returns the QR URL for the claimable code.
    /// \return The QR URL.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<BeamQr>& GetQr() const;

    BeamClaim& operator=(const BeamClaim& rhs);

    BeamClaim& operator=(BeamClaim&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMCLAIM_HPP
