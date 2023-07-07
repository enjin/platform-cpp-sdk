#ifndef ENJINPLATFORMSDK_LOGLEVEL_HPP
#define ENJINPLATFORMSDK_LOGLEVEL_HPP

namespace enjin::platform::sdk
{
/// \brief Represent different levels of logging.
enum class LogLevel
{
    /// \brief Indicates that logging at a trace level is to occur.
    /// \remarks General contains detailed messages that may be considered sensitive and should not be enabled in
    /// production.
    Trace,

    /// \brief Indicates that logging at a debug level is to occur.
    /// \remarks Generally used in debugging and development. May produce high volume of messages.
    Debug,

    /// \brief Indicates that logging at an informational level is to occur.
    Information,

    /// \brief Indicates that logging at a warning level is to occur.
    Warning,

    /// \brief Indicates that logging at an error level is to occur.
    Error,

    /// \brief Indicates that logging at a critical level is to occur.
    Critical,

    /// \brief Indicates that no logging is to occur.
    None,
};
}

#endif //ENJINPLATFORMSDK_LOGLEVEL_HPP
