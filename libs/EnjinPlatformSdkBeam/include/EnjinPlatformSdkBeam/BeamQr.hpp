#ifndef ENJINPLATFORMSDKBEAM_BEAMQR_HPP
#define ENJINPLATFORMSDKBEAM_BEAMQR_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk::beam
{
/// \brief Models a beam QR.
class ENJINPLATFORMSDKBEAM_EXPORT BeamQr : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BeamQr();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BeamQr(const BeamQr& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BeamQr(BeamQr&& other) noexcept;

    /// \brief Class destructor.
    ~BeamQr() override;

    /// \brief Returns the link to the QR image.
    /// \return The link to the QR image.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetUrl() const;

    /// \brief Returns the base64 encoded string containing the beam host and code.
    /// \return The encoded string.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetPayload() const;

    BeamQr& operator=(const BeamQr& rhs);

    BeamQr& operator=(BeamQr&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMQR_HPP
