#ifndef ENJINPLATFORMSDKBEAM_GETCLAIMS_HPP
#define ENJINPLATFORMSDKBEAM_GETCLAIMS_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkBeam/BeamClaimFragment.hpp"
#include "EnjinPlatformSdkBeam/ClaimStatus.hpp"
#include <vector>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
/// \brief A request for querying claim details.
class ENJINPLATFORMSDKBEAM_EXPORT GetClaims : public GraphQlRequest<GetClaims, BeamClaimConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetClaims();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetClaims(const GetClaims& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetClaims(GetClaims&& other) noexcept;

    /// \brief Class destructor.
    ~GetClaims() override;

    /// \brief Sets the internal IDs.
    /// \param ids The internal IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetClaims& SetIds(SerializableStringArrayPtr ids);

    /// \brief Sets the beam codes.
    /// \param codes The beam codes.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetClaims& SetCodes(SerializableStringArrayPtr codes);

    /// \brief Sets the wallet accounts.
    /// \param accounts The wallet accounts.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetClaims& SetAccounts(SerializableStringArrayPtr accounts);

    /// \brief Sets the claim statuses.
    /// \param states The claim statuses.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetClaims& SetStates(const std::vector<ClaimStatus>& states);

    GetClaims& operator=(const GetClaims& rhs);

    GetClaims& operator=(GetClaims&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_GETCLAIMS_HPP
