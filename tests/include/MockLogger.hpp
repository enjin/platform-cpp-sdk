#ifndef ENJINPLATFORMSDK_MOCKLOGGER_HPP
#define ENJINPLATFORMSDK_MOCKLOGGER_HPP

#include "gmock/gmock.h"
#include "EnjinPlatformSdk/ILogger.hpp"
#include "EnjinPlatformSdk/LogLevel.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
class MockLogger;

/// \brief Definition for a nice mock of ILogger.
using NiceMockLogger [[maybe_unused]] = testing::NiceMock<MockLogger>;

/// \brief Definition for a pointer containing a nice mock of ILogger.
using MockLoggerPtr [[maybe_unused]] = std::shared_ptr<NiceMockLogger>;

/// \brief Mock class for ILogger.
class MockLogger : public virtual ILogger
{
public:
    // region ILogger

    MOCK_METHOD(void, Log, (LogLevel logLevel, const std::string& message), ());

    MOCK_METHOD(void, Log, (LogLevel logLevel, const std::exception& e, const std::string& message), ());

    // endregion ILogger
};
}

#endif //ENJINPLATFORMSDK_MOCKLOGGER_HPP
