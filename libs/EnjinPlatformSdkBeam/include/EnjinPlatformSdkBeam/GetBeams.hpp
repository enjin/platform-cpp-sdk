#ifndef ENJINPLATFORMSDKBEAM_GETBEAMS_HPP
#define ENJINPLATFORMSDKBEAM_GETBEAMS_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkBeam/BeamFragment.hpp"

namespace enjin::platform::sdk::beam
{
/// \brief A request for querying an array of beams.
class ENJINPLATFORMSDKBEAM_EXPORT GetBeams : public GraphQlRequest<GetBeams, BeamConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetBeams();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetBeams(const GetBeams& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetBeams(GetBeams&& other) noexcept;

    /// \brief Class destructor.
    ~GetBeams() override;

    /// \brief Sets the beam codes.
    /// \param codes The codes.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBeams& SetCodes(SerializableStringArrayPtr codes);

    /// \brief Sets the beam names.
    /// \param names The names.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBeams& SetNames(SerializableStringArrayPtr names);

    GetBeams& operator=(const GetBeams& rhs);

    GetBeams& operator=(GetBeams&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_GETBEAMS_HPP
