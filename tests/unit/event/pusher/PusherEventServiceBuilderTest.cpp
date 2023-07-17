#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/PusherEventService.hpp"
#include <memory>
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;
using PusherEventServiceBuilder = PusherEventService::PusherEventServiceBuilder;

class PusherEventServiceBuilderTest : public Test
{
};

TEST_F(PusherEventServiceBuilderTest, BuildWhenKeyIsSetReturnsEventServiceInstance)
{
    // Arrange
    const PusherEventServiceBuilder builder = PusherEventService::Builder()
        .SetKey("Dummy Key");

    // Act
    const std::unique_ptr<PusherEventService> service = builder.Build();

    // Assert
    ASSERT_THAT(service, NotNull());
}

TEST_F(PusherEventServiceBuilderTest, BuildWhenKeyIsNotSetThrowsError)
{
    // Arrange
    const PusherEventServiceBuilder builder = PusherEventService::Builder();

    // Assert
    ASSERT_THROW(const auto service = builder.Build(), std::logic_error);
}

TEST_F(PusherEventServiceBuilderTest, BuildWhenKeyAndClusterAreSetReturnsEventServiceInstance)
{
    // Arrange
    const PusherEventServiceBuilder builder = PusherEventService::Builder()
        .SetKey("Dummy Key")
        .SetCluster("Dummy Cluster");

    // Act
    const std::unique_ptr<PusherEventService> service = builder.Build();

    // Assert
    ASSERT_THAT(service, NotNull());
}

TEST_F(PusherEventServiceBuilderTest, BuildWhenKeyAndHostAreSetReturnsEventServiceInstance)
{
    // Arrange
    const PusherEventServiceBuilder builder = PusherEventService::Builder()
        .SetKey("Dummy Key")
        .SetHost("Dummy Host");

    // Act
    const std::unique_ptr<PusherEventService> service = builder.Build();

    // Assert
    ASSERT_THAT(service, NotNull());
}

TEST_F(PusherEventServiceBuilderTest, BuildWhenKeyAndClusterAndHostAreSetThrowsInvalidOperationException)
{
    // Arrange
    const PusherEventServiceBuilder builder = PusherEventService::Builder()
        .SetKey("Dummy Key")
        .SetCluster("Dummy Cluster")
        .SetHost("Dummy Host");

    // Assert
    ASSERT_THROW(const auto service = builder.Build(), std::logic_error);
}
