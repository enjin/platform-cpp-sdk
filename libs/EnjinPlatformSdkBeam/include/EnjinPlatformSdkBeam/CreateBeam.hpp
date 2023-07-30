#ifndef ENJINPLATFORMSDKBEAM_CREATEBEAM_HPP
#define ENJINPLATFORMSDKBEAM_CREATEBEAM_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkBeam/BeamFlagInputType.hpp"
#include "EnjinPlatformSdkBeam/ClaimToken.hpp"
#include "EnjinPlatformSdkBeam/HasBeamCommonFields.hpp"
#include <memory>

namespace enjin::platform::sdk::beam
{
/// \brief A request to act as a mutation for creating a beam.
class ENJINPLATFORMSDKBEAM_EXPORT CreateBeam : public GraphQlRequest<CreateBeam>,
                                               public HasBeamCommonFields<CreateBeam>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CreateBeam();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CreateBeam(const CreateBeam& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CreateBeam(CreateBeam&& other) noexcept;

    /// \brief Class destructor.
    ~CreateBeam() override;

    /// \brief Sets the beam flags that should be enabled or disabled.
    /// \param flags The beam flags.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateBeam& SetFlags(std::shared_ptr<SerializableArray<BeamFlagInputType>> flags);

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateBeam& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the claimable tokens.
    /// \param tokens The claimable tokens.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateBeam& SetTokens(std::shared_ptr<SerializableArray<ClaimToken>> tokens);

    CreateBeam& operator=(const CreateBeam& rhs);

    CreateBeam& operator=(CreateBeam&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_CREATEBEAM_HPP
