#ifndef ENJINPLATFORMSDKBEAM_UPDATEBEAM_HPP
#define ENJINPLATFORMSDKBEAM_UPDATEBEAM_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkBeam/BeamFlagInputType.hpp"
#include "EnjinPlatformSdkBeam/HasBeamCommonFields.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
/// \brief A request to act as a mutation for updating a beam.
class ENJINPLATFORMSDKBEAM_EXPORT UpdateBeam : public GraphQlRequest<UpdateBeam>,
                                               public HasBeamCommonFields<UpdateBeam>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    UpdateBeam();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    UpdateBeam(const UpdateBeam& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    UpdateBeam(UpdateBeam&& other) noexcept;

    /// \brief Class destructor.
    ~UpdateBeam() override;

    /// \brief Sets the code of the beam to update.
    /// \param code The beam code.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateBeam& SetCode(SerializableStringPtr code);

    /// \brief Sets the beam flags that should be enabled or disabled.
    /// \param flags The flags.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateBeam& SetFlags(std::shared_ptr<SerializableArray<BeamFlagInputType>> flags);

    UpdateBeam& operator=(const UpdateBeam& rhs);

    UpdateBeam& operator=(UpdateBeam&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_UPDATEBEAM_HPP
