#ifndef ENJINPLATFORMSDKBEAM_BEAM_HPP
#define ENJINPLATFORMSDKBEAM_BEAM_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/Collection.hpp"
#include "EnjinPlatformSdk/DateTime.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkBeam/BeamFlag.hpp"
#include "EnjinPlatformSdkBeam/BeamQr.hpp"
#include "EnjinPlatformSdkBeam/BeamScan.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk::beam
{
// region Forward declarations

class BeamScan;

class BeamQr;

// endregion Forward declarations

/// \brief Models a beam.
class ENJINPLATFORMSDKBEAM_EXPORT Beam : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Beam();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Beam(const Beam& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Beam(Beam&& other) noexcept;

    /// \brief Class destructor.
    ~Beam() override;

    /// \brief Returns the internal ID of this beam.
    /// \return The internal ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetId() const;

    /// \brief Returns the code for this beam.
    /// \return The code.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetCode() const;

    /// \brief Returns the name of this beam.
    /// \return The name.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetName() const;

    /// \brief Returns the description of this beam.
    /// \return The description.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetDescription() const;

    /// \brief Returns the image URL of this beam.
    /// \return The image URL.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetImage() const;

    /// \brief Returns the start date claim period of this beam.
    /// \return The start date claim period.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<DateTime>& GetStart() const;

    /// \brief Returns the end date claim period of this beam.
    /// \return The end date claim period.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<DateTime>& GetEnd() const;

    /// \brief Returns the collection this beam belongs to.
    /// \return The collection.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const;

    /// \brief Returns the message of this beam.
    /// \return The message.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<BeamScan>& GetMessage() const;

    /// \brief Returns whether this beam is within its claim period.
    /// \return Whether this beam is within its claim period.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetIsClaimable() const;

    /// \brief Returns the flags for this beam.
    /// \return The flags.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<BeamFlag>>& GetFlags() const;

    /// \brief Returns the QR URL for the claimable code of this beam.
    /// \return The QR URL for the claimable code.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<BeamQr>& GetQr() const;

    Beam& operator=(const Beam& rhs);

    Beam& operator=(Beam&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAM_HPP
