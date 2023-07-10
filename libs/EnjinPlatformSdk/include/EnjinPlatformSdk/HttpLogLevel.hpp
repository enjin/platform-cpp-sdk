#ifndef ENJINPLATFORMSDK_HTTPLOGLEVEL_HPP
#define ENJINPLATFORMSDK_HTTPLOGLEVEL_HPP

namespace enjin::platform::sdk
{
/// \brief Enums representing the level of detail to log HTTP traffic at.
enum class HttpLogLevel
{
    /// \brief Value for no logging to occur.
    None,

    /// \brief Value signifying to log basic HTTP data, such as the method, URI, and content-length.
    Basic,

    /// \brief Same as Basic, but also includes HTTP headers.
    Headers,

    /// \brief Same as Headers, but also includes the message body.
    Body,
};
}

#endif //ENJINPLATFORMSDK_HTTPLOGLEVEL_HPP
