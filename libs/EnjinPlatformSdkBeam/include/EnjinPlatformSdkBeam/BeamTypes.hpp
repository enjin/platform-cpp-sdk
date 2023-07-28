#ifndef ENJINPLATFORMSDKBEAM_BEAMTYPES_HPP
#define ENJINPLATFORMSDKBEAM_BEAMTYPES_HPP

#include "enjinplatformsdkbeam_export.h"

namespace enjin::platform::sdk::beam
{
/// \brief Contains fields describing variable types used in the platform's Beam API.
class ENJINPLATFORMSDKBEAM_EXPORT BeamTypes final
{
public:
    // BeamFlagInputType

    /// \brief String for BeamFlagInputType type.
    [[maybe_unused]]
    static constexpr char BeamFlagInputType[] = "BeamFlagInputType!";

    /// \brief String for an array of BeamFlagInputType type.
    [[maybe_unused]]
    static constexpr char BeamFlagInputTypeArray[] = "[BeamFlagInputType!]!";

    // ClaimStatus

    /// \brief String for ClaimStatus type.
    [[maybe_unused]]
    static constexpr char ClaimStatus[] = "ClaimStatus!";

    /// \brief String for an array of ClaimStatus type.
    [[maybe_unused]]
    static constexpr char ClaimStatusArray[] = "[ClaimStatus!]!";

    // ClaimToken

    /// \brief String for ClaimToken type.
    [[maybe_unused]]
    static constexpr char ClaimToken[] = "ClaimToken!";

    /// \brief String for an array of ClaimToken type.
    [[maybe_unused]]
    static constexpr char ClaimTokenArray[] = "[ClaimToken!]!";

    BeamTypes() = delete;
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMTYPES_HPP
