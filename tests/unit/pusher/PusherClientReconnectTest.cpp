#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockWebSocketServer.hpp"
#include "PusherClient.hpp"
#include "PusherConnectionState.hpp"
#include "VerificationTestSuite.hpp"
#include "WebSocketMessage.hpp"
#include "WebSocketMessageType.hpp"
#include <chrono>
#include <string>
#include <thread>

using namespace pusher;
using namespace testing;

class PusherClientReconnectionTest : public Test,
                                     public VerificationTestSuite
{
public:
    std::unique_ptr<PusherClient> classUnderTest;

    // Mocks
    inline static std::unique_ptr<MockWebSocketServer> mockServer;

    inline static const std::chrono::milliseconds WaitTime = std::chrono::milliseconds(1000);

protected:
    void SetUp() override
    {
        Test::SetUp();

        mockServer->IgnoreMessageType(WebSocketMessageType::Close)
                  .IgnoreMessageType(WebSocketMessageType::Ping)
                  .IgnoreMessageType(WebSocketMessageType::Pong);

        classUnderTest = std::make_unique<PusherClient>("xyz", CreatePusherOptions());
    }

    static void SetUpTestSuite()
    {
        mockServer = std::make_unique<MockWebSocketServer>();
    }

    void TearDown() override
    {
        Test::TearDown();

        mockServer->Reset();
    }

    static void TearDownTestSuite()
    {
        if (mockServer != nullptr)
        {
            mockServer->Shutdown();
        }
    }

private:
    [[nodiscard]]
    static PusherOptions CreatePusherOptions()
    {
        if (mockServer == nullptr)
        {
            throw std::runtime_error("Cannot create PusherOptions when mock server is null");
        }

        std::stringstream hostStream;
        hostStream << mockServer->GetHost() << ":" << mockServer->GetPort();

        PusherOptions options;
        options.SetEncrypted(false);
        options.SetHost(hostStream.str());

        return options;
    }
};

TEST_F(PusherClientReconnectionTest, Receives4000ErrorCodeDoesNotAttemptToReconnectToServer)
{
    // Arrange - Data
    const PusherConnectionState expectedConnState = PusherConnectionState::Disconnected;
    const int code = 4000;
    const std::string reason;
    mockServer->NextMessage([](const WebSocketMessage&) { /* Consumes initial open message */ });
    classUnderTest->ConnectAsync().get();

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(0);

    // Act
    mockServer->Close(code, reason);

    std::this_thread::sleep_for(WaitTime);

    // Assert
    EXPECT_THAT(classUnderTest->GetState(), Eq(expectedConnState));

    // Verify
    Verify();
}

TEST_F(PusherClientReconnectionTest, Receives4100ErrorCodeReconnectsToServer)
{
    // Arrange - Data
    const PusherConnectionState expectedConnState = PusherConnectionState::Connected;
    const int code = 4100;
    const std::string reason;
    mockServer->NextMessage([](const WebSocketMessage&) { /* Consumes initial open message */ });
    classUnderTest->ConnectAsync().get();

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(1);

    // Act
    mockServer->Close(code, reason);

    std::this_thread::sleep_for(WaitTime);

    // Assert
    EXPECT_THAT(classUnderTest->GetState(), Eq(expectedConnState));

    // Verify
    Verify();
}
