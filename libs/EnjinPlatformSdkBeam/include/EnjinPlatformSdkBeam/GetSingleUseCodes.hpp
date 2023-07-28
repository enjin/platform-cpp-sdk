#ifndef ENJINPLATFORMSDKBEAM_GETSINGLEUSECODES_HPP
#define ENJINPLATFORMSDKBEAM_GETSINGLEUSECODES_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkBeam/BeamClaimFragment.hpp"

namespace enjin::platform::sdk::beam
{
/// \brief A request for querying single use codes.
class ENJINPLATFORMSDKBEAM_EXPORT GetSingleUseCodes
    : public GraphQlRequest<GetSingleUseCodes, BeamClaimConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetSingleUseCodes();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetSingleUseCodes(const GetSingleUseCodes& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetSingleUseCodes(GetSingleUseCodes&& other) noexcept;

    /// \brief Class destructor.
    ~GetSingleUseCodes() override;

    /// \brief Sets the beam code.
    /// \param code The beam code.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetSingleUseCodes& SetCode(SerializableStringPtr code);

    GetSingleUseCodes& operator=(const GetSingleUseCodes& rhs);

    GetSingleUseCodes& operator=(GetSingleUseCodes&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_GETSINGLEUSECODES_HPP
