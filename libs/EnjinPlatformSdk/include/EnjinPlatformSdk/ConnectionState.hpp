#ifndef ENJINPLATFORMSDK_CONNECTIONSTATE_HPP
#define ENJINPLATFORMSDK_CONNECTIONSTATE_HPP

namespace enjin::platform::sdk
{
/// \brief Values representing the different states of connection for an event service.
enum class ConnectionState
{
    /// \brief Represents that the connection is uninitialized.
    Uninitialized,

    /// \brief Represents that the service is attempting to establish a connection.
    Connecting,

    /// \brief Represents that the service has an established connection.
    Open,

    /// \brief Represents that the service is closing its connection.
    Closing,

    /// \brief Represents that the service has closed its connection.
    Closed,
};
}

#endif //ENJINPLATFORMSDK_CONNECTIONSTATE_HPP
