#ifndef ENJINPLATFORMSDK_PUSHERCONNECTIONSTATE_HPP
#define ENJINPLATFORMSDK_PUSHERCONNECTIONSTATE_HPP

namespace pusher
{
/// \brief Represents the different connection states for a Pusher client.
enum class PusherConnectionState
{
    All, ///< \brief Value used to indicate any state when used as a function argument.
    Connecting,
    Connected,
    Disconnecting,
    Disconnected,
    Reconnecting,
};
}

#endif //ENJINPLATFORMSDK_PUSHERCONNECTIONSTATE_HPP
