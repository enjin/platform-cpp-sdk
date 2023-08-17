#ifndef ENJINPLATFORMSDKBEAM_DELETEBEAM_HPP
#define ENJINPLATFORMSDKBEAM_DELETEBEAM_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
/// \brief A request to act as a mutation for deleting a beam.
class ENJINPLATFORMSDKBEAM_EXPORT DeleteBeam : public GraphQlRequest<DeleteBeam>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    DeleteBeam();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    DeleteBeam(const DeleteBeam& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    DeleteBeam(DeleteBeam&& other) noexcept;

    /// \brief Class destructor.
    ~DeleteBeam() override;

    /// \brief Sets the beam code.
    /// \param code The beam code.
    /// \return This request for chaining.
    [[maybe_unused]]
    DeleteBeam& SetCode(SerializableStringPtr code);

    DeleteBeam& operator=(const DeleteBeam& rhs);

    DeleteBeam& operator=(DeleteBeam&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_DELETEBEAM_HPP
