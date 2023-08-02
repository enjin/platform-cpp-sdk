#ifndef ENJINPLATFORMSDKBEAM_BEAMSCAN_HPP
#define ENJINPLATFORMSDKBEAM_BEAMSCAN_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk::beam
{
/// \brief Models a beam scan.
class ENJINPLATFORMSDKBEAM_EXPORT BeamScan : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BeamScan();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BeamScan(const BeamScan& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BeamScan(BeamScan&& other) noexcept;

    /// \brief Class destructor.
    ~BeamScan() override;

    /// \brief Returns the internal ID of this scan.
    /// \return The internal ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetId() const;

    /// \brief Returns the wallet public key.
    /// \return The wallet public key.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetWalletPublicKey() const;

    /// \brief Returns the message to sign.
    /// \return The message.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetMessage() const;

    BeamScan& operator=(const BeamScan& rhs);

    BeamScan& operator=(BeamScan&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMSCAN_HPP
