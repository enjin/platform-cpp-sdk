#ifndef ENJINPLATFORMSDKBEAM_GETBEAM_HPP
#define ENJINPLATFORMSDKBEAM_GETBEAM_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkBeam/BeamFragment.hpp"

namespace enjin::platform::sdk::beam
{
/// \brief A request for querying a beam.
class ENJINPLATFORMSDKBEAM_EXPORT GetBeam : public GraphQlRequest<GetBeam, BeamFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetBeam();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetBeam(const GetBeam& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetBeam(GetBeam&& other) noexcept;

    /// \brief Class destructor.
    ~GetBeam() override;

    /// \brief Sets the beam code.
    /// \param code The code.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBeam& SetCode(SerializableStringPtr code);

    /// \brief Sets the wallet account.
    /// \param account The wallet account.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBeam& SetAccount(SerializableStringPtr account);

    GetBeam& operator=(const GetBeam& rhs);

    GetBeam& operator=(GetBeam&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_GETBEAM_HPP
