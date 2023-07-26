#ifndef ENJINPLATFORMSDKBEAM_BEAMFLAGINPUTTYPE_HPP
#define ENJINPLATFORMSDKBEAM_BEAMFLAGINPUTTYPE_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdkBeam/BeamFlag.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlParameterORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
class BeamFlagInputType;

/// \brief Definition for a pointer containing a BeamFlagInputType.
[[maybe_unused]]
typedef std::shared_ptr<BeamFlagInputType> BeamFlagInputTypePtr;

/// \brief Models a parameter for inputting a beam flag.
class ENJINPLATFORMSDKBEAM_EXPORT BeamFlagInputType : public GraphQlParameter<BeamFlagInputType>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BeamFlagInputType();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BeamFlagInputType(const BeamFlagInputType& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BeamFlagInputType(BeamFlagInputType&& other) noexcept;

    /// \brief Class destructor.
    ~BeamFlagInputType() override;

    /// \brief Sets the beam flag.
    /// \param flag The beam flag.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    BeamFlagInputType& SetFlag(BeamFlag flag);

    /// \brief Sets whether the flag is enabled.
    /// \param enabled Whether the flag is enabled.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    BeamFlagInputType& SetEnabled(SerializableBoolPtr enabled);

    BeamFlagInputType& operator=(const BeamFlagInputType& rhs);

    BeamFlagInputType& operator=(BeamFlagInputType&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMFLAGINPUTTYPE_HPP
