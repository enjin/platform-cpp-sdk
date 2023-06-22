#ifndef ENJINPLATFORMSDK_PUSHERCONSTANTS_HPP
#define ENJINPLATFORMSDK_PUSHERCONSTANTS_HPP

#include "enjinplatformsdk_export.h"

namespace pusher
{
/// \brief Static class containing constants used in the Pusher protocol.
class ENJINPLATFORMSDK_EXPORT PusherConstants final
{
public:
    /// \brief Prefix for Pusher messages.
    static constexpr char PusherMessagePrefix[] = "pusher";

    // Message keys

    /// \brief Key for subscribe messages.
    static constexpr char ChannelSubscribe[] = "pusher:subscribe";

    /// \brief Key for subscription error message.
    static constexpr char ChannelSubscriptionError[] = "pusher_internal:subscription_error";

    /// \brief Key for subscription succeeded message.
    static constexpr char ChannelSubscriptionSucceeded[] = "pusher_internal:subscription_succeeded";

    /// \brief Key for unsubscribe messages.
    static constexpr char ChannelUnsubscribe[] = "pusher:unsubscribe";

    // Protocol schemas

    /// \brief Schema for not using encryption.
    static constexpr char InsecureSchema[] = "ws://";

    /// \brief Schema for using encryption.
    static constexpr char SecureSchema[] = "wss://";

    PusherConstants() = delete;
};
}

#endif //ENJINPLATFORMSDK_PUSHERCONSTANTS_HPP
