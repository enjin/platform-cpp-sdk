#ifndef ENJINPLATFORMSDKBEAM_CLAIMBEAM_HPP
#define ENJINPLATFORMSDKBEAM_CLAIMBEAM_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/CryptoSignatureType.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
/// \brief A request to act as a mutation for claiming a beam.
class ENJINPLATFORMSDKBEAM_EXPORT ClaimBeam : public GraphQlRequest<ClaimBeam>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ClaimBeam();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ClaimBeam(const ClaimBeam& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ClaimBeam(ClaimBeam&& other) noexcept;

    /// \brief Class destructor.
    ~ClaimBeam() override;

    /// \brief Sets the code of the beam to claim.
    /// \param code The beam code.
    /// \return This request for chaining.
    [[maybe_unused]]
    ClaimBeam& SetCode(SerializableStringPtr code);

    /// \brief Sets the wallet account.
    /// \param account The beam code.
    /// \return This request for chaining.
    [[maybe_unused]]
    ClaimBeam& SetAccount(SerializableStringPtr account);

    /// \brief Sets the signed message.
    /// \param signature The beam code.
    /// \return This request for chaining.
    [[maybe_unused]]
    ClaimBeam& SetSignature(SerializableStringPtr signature);

    /// \brief Sets the crypto type of signature.
    /// \param cryptoSignatureType The beam code.
    /// \return This request for chaining.
    /// \remarks If not set or null, then the platform may default this argument to SR25519.
    [[maybe_unused]]
    ClaimBeam& SetCryptoSignatureType(CryptoSignatureType cryptoSignatureType);

    ClaimBeam& operator=(const ClaimBeam& rhs);

    ClaimBeam& operator=(ClaimBeam&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_CLAIMBEAM_HPP
