#ifndef ENJINPLATFORMSDK_PUSHEROPTIONS_HPP
#define ENJINPLATFORMSDK_PUSHEROPTIONS_HPP

#include "enjinplatformsdk_export.h"
#include <optional>
#include <string>

namespace pusher
{
/// \brief
class ENJINPLATFORMSDK_EXPORT PusherOptions
{
    std::optional<std::string> _cluster;
    std::optional<bool> _encrypted;
    std::optional<std::string> _host;

    static constexpr char DefaultCluster[] = "mt1";
    static constexpr bool DefaultEncryption = true;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    PusherOptions();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PusherOptions(const PusherOptions& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PusherOptions(PusherOptions&& other) noexcept;

    /// \brief Class destructor.
    ~PusherOptions();

    /// \brief Returns the host to be used by the client.
    /// \return The host.
    [[maybe_unused]]
    [[nodiscard]]
    std::string GetHost() const;

    /// \brief Determines if whether encryption is to be used for the connection.
    /// \return Whether encryption is to be used.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsEncrypted() const;

    /// \brief Sets the cluster.
    /// \param cluster The cluster.
    /// \return This option for chaining.
    [[maybe_unused]]
    PusherOptions& SetCluster(std::string cluster);

    /// \brief Sets whether encryption is to be used or not. True by default.
    /// \param isEncrypted The state.
    /// \return This option for chaining.
    [[maybe_unused]]
    PusherOptions& SetEncrypted(bool isEncrypted);

    /// \brief Sets the host.
    /// \param host The host.
    /// \return This option for chaining.
    [[maybe_unused]]
    PusherOptions& SetHost(std::string host);

    PusherOptions& operator=(const PusherOptions& rhs);

    PusherOptions& operator=(PusherOptions&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_PUSHEROPTIONS_HPP
