#ifndef ENJINPLATFORMSDK_PUSHERERRORCODES_HPP
#define ENJINPLATFORMSDK_PUSHERERRORCODES_HPP

namespace pusher
{
/// \brief Enum representing error codes that may be received from Pusher.
enum class PusherErrorCodes : int
{
    Unknown = 0, ///< \brief A catch all error code.
    SubscriptionError = 5003,
};
}

#endif //ENJINPLATFORMSDK_PUSHERERRORCODES_HPP
