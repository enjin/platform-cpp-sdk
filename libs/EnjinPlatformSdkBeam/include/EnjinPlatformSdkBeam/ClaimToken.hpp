#ifndef ENJINPLATFORMSDKBEAM_CLAIMTOKEN_HPP
#define ENJINPLATFORMSDKBEAM_CLAIMTOKEN_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/AttributeInput.hpp"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/IntegerRange.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/Upload.hpp"
#include "EnjinPlatformSdkBeam/BeamType.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlParameterORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
class ClaimToken;

/// \brief Definition for a pointer containing a ClaimToken.
using ClaimTokenPtr [[maybe_unused]] = std::shared_ptr<ClaimToken>;

/// \brief Models a parameter for setting the claimable tokens of a beam.
class ENJINPLATFORMSDKBEAM_EXPORT ClaimToken : public GraphQlParameter<ClaimToken>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ClaimToken();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ClaimToken(const ClaimToken& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ClaimToken(ClaimToken&& other) noexcept;

    /// \brief Class destructor.
    ~ClaimToken() override;

    /// \brief Sets the token chain IDs to claim.
    /// \param tokenIds The token chain IDs.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    ClaimToken& SetTokenIds(std::shared_ptr<SerializableArray<IntegerRange>> tokenIds);

    /// \brief Sets the text file to upload which contains one token ID range per line.
    /// \param tokenIdDataUpload The upload.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    ClaimToken& SetTokenIdDataUpload(UploadPtr tokenIdDataUpload);

    /// \brief Sets the initial attributes for the token.
    /// \param attributes The initial attributes.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    ClaimToken& SetAttributes(std::shared_ptr<SerializableArray<AttributeInput>> attributes);

    /// \brief Sets the quantity of tokens that can be received per claim.
    /// \param tokenQuantityPerClaim The amount received per claim.
    /// \return This parameter for chaining.
    /// \remarks If null or left unset, then the platform may default this argument to 1.
    [[maybe_unused]]
    ClaimToken& SetTokenQuantityPerClaim(SerializableIntPtr tokenQuantityPerClaim);

    /// \brief Sets the total amount of tokens than can be claimed.
    /// \param claimQuantity The amount that can be claimed.
    /// \return This parameter for chaining.
    /// \remarks If null or left unset, then the platform may default this argument to 1.
    [[maybe_unused]]
    ClaimToken& SetClaimQuantity(SerializableIntPtr claimQuantity);

    /// \brief Sets the type of the beam.
    /// \param type The type.
    /// \return This parameter for chaining.
    /// \remarks If not set or None, then the platform may default this argument to TransferToken.
    [[maybe_unused]]
    ClaimToken& SetType(BeamType type);

    ClaimToken& operator=(const ClaimToken& rhs);

    ClaimToken& operator=(ClaimToken&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_CLAIMTOKEN_HPP
