#ifndef ENJINPLATFORMSDK_HTTPLOGGINGHANDLER_HPP
#define ENJINPLATFORMSDK_HTTPLOGGINGHANDLER_HPP

#include "enjinplatformsdk_export.h"
#include "httplib.h"
#include "EnjinPlatformSdk/HttpLogLevel.hpp"
#include "EnjinPlatformSdk/ILogger.hpp"
#include <string>

namespace enjin::platform::sdk
{
/// \brief Handler class for logging HTTP traffic.
class ENJINPLATFORMSDK_EXPORT HttpLoggingHandler final
{
    HttpLogLevel _level;
    LoggerPtr _logger;

    static constexpr char EndLine = '\n';
    static constexpr LogLevel TraceLevel = LogLevel::Trace;

public:
    HttpLoggingHandler() = delete;

    /// \brief Constructs an instance of this class.
    /// \param logger The logger.
    /// \param level The HTTP log level.
    /// \throws std::invalid_argument Thrown if logger is a null-pointer.
    [[maybe_unused]]
    HttpLoggingHandler(LoggerPtr logger, HttpLogLevel level);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    HttpLoggingHandler(const HttpLoggingHandler& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    HttpLoggingHandler(HttpLoggingHandler&& other) noexcept;

    /// \brief Class destructor.
    ~HttpLoggingHandler();

    /// \brief Logs the given request message.
    /// \param request The request message.
    [[maybe_unused]]
    void LogRequest(const httplib::Request& request);

    /// \brief Logs the given response message.
    /// \param response The response message.
    [[maybe_unused]]
    void LogResponse(const httplib::Response& response);

    HttpLoggingHandler& operator=(const HttpLoggingHandler& rhs);

    HttpLoggingHandler& operator=(HttpLoggingHandler&& rhs) noexcept;

private:
    /// \brief Converts the given string to all uppercase.
    /// \param s The string.
    /// \return The converted string.
    static std::string ToUpper(std::string s);
};
}

#endif //ENJINPLATFORMSDK_HTTPLOGGINGHANDLER_HPP
