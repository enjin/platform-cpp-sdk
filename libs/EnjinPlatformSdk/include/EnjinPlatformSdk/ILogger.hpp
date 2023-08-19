#ifndef ENJINPLATFORMSDK_ILOGGER_HPP
#define ENJINPLATFORMSDK_ILOGGER_HPP

#include "EnjinPlatformSdk/LogLevel.hpp"
#include <memory>
#include <stdexcept>
#include <string>

namespace enjin::platform::sdk
{
class ILogger;

/// \brief Definition for a pointer wrapping an ILogger.
using LoggerPtr [[maybe_unused]] = std::shared_ptr<ILogger>;

/// \brief Interface for logging.
class ILogger
{
public:
    /// \brief Class destructor.
    virtual ~ILogger() = default;

    /// \brief Logs a message at the given log level.
    /// \param logLevel The log level.
    /// \param message The message.
    [[maybe_unused]]
    virtual void Log(LogLevel logLevel, const std::string& message) = 0;

    /// \brief Logs an exception and message at the given log level.
    /// \param logLevel The log level.
    /// \param e The exception.
    /// \param message The message.
    [[maybe_unused]]
    virtual void Log(LogLevel logLevel, const std::exception& e, const std::string& message) = 0;
};
}

#endif //ENJINPLATFORMSDK_ILOGGER_HPP
