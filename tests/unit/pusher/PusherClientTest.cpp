#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockSubscriptionListener.hpp"
#include "MockWebSocketServer.hpp"
#include "PusherClient.hpp"
#include "PusherConnectionState.hpp"
#include "PusherConstants.hpp"
#include "PusherEvent.hpp"
#include "VerificationTestSuite.hpp"
#include "WebSocketMessage.hpp"
#include "WebSocketMessageType.hpp"
#include <chrono>
#include <future>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

using namespace pusher;
using namespace testing;
using Clock = std::chrono::high_resolution_clock;
using Milliseconds = std::chrono::milliseconds;

class PusherClientTest : public Test,
                         public VerificationTestSuite
{
public:
    std::unique_ptr<PusherClient> classUnderTest;

    // Mocks
    MockSubscriptionListenerPtr mockListener;
    inline static std::unique_ptr<MockWebSocketServer> mockServer;

    static constexpr char DefaultChannelName[] = "test.channel";
    static constexpr char DefaultEventName[] = "TestEvent";
    inline static const Milliseconds WaitTime = Milliseconds(1000);

    void QueueSubscriptionMessage(std::string channel, const bool incrementCall = false)
    {
        if (mockServer == nullptr)
        {
            return;
        }

        mockServer->NextMessage([this, incrementCall, channel = std::move(channel)](const WebSocketMessage& inMsg) {
            if (incrementCall)
            {
                IncrementCallCount();
            }

            const std::string data = CreateSubscriptionSuccessMessagePayload(channel);
            WebSocketMessage outMsg;
            outMsg.payload = std::vector<unsigned char>(data.begin(), data.end());
            outMsg.type = WebSocketMessageType::Utf8Message;

            mockServer->SendWebSocketMessage(outMsg);
        });
    }

    void Verify(Milliseconds timeout) override
    {
        if (mockServer != nullptr)
        {
            const auto start = Clock::now();
            mockServer->WaitForQueuedMessageHandlers(timeout);
            const auto end = Clock::now();

            timeout -= std::chrono::duration_cast<Milliseconds>(end - start);
        }

        VerificationTestSuite::Verify(timeout);
    }

    static std::string CreateEventMessagePayload(const std::string& eventName,
                                                 const std::string& channelName = "",
                                                 const std::string& data = "null")
    {
        std::stringstream ss;

        ss << R"({"event":")"
           << eventName
           << R"(","channel":")"
           << channelName
           << R"(","data":)"
           << data
           << R"(})";

        return ss.str();
    }

    static std::string CreateSubscriptionSuccessMessagePayload(const std::string& channelName,
                                                               const std::string& data = "null")
    {
        std::stringstream ss;

        ss << R"({"event":")"
           << PusherConstants::ChannelSubscriptionSucceeded
           << R"(","channel":")"
           << channelName
           << R"(","data":)"
           << data
           << R"(})";

        return ss.str();
    }

protected:
    void SetUp() override
    {
        Test::SetUp();

        mockListener = std::make_shared<NiceMockSubscriptionListener>();
        mockServer->IgnoreMessageType(WebSocketMessageType::Open)
                  .IgnoreMessageType(WebSocketMessageType::Close)
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

        classUnderTest.reset();
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

TEST_F(PusherClientTest, BoundListenerIsCalledWhenEventIsRecieved)
{
    // Arrange - Data
    const std::string eventName(DefaultEventName);
    const std::string eventMessage = CreateEventMessagePayload(eventName);
    WebSocketMessage wsMessage;
    wsMessage.payload = std::vector<unsigned char>(eventMessage.begin(), eventMessage.end());
    wsMessage.type = WebSocketMessageType::Utf8Message;
    classUnderTest->ConnectAsync().get();
    classUnderTest->Bind(eventName, mockListener);

    // Arrange - Expectations
    EXPECT_CALL(*mockListener, OnEvent(An<const PusherEvent&>()))
        .Times(1);

    // Assumptions
    ASSERT_THAT(classUnderTest->GetState(), Eq(PusherConnectionState::Connected)) << "Assume that client is connected";

    // Act
    mockServer->SendWebSocketMessage(wsMessage);

    std::this_thread::sleep_for(WaitTime);

    // Assert (see: Arrange - Expectations)
}

TEST_F(PusherClientTest, ConnectAsyncClientConnectsToServer)
{
    // Arrange
    const PusherConnectionState expectedConnState = PusherConnectionState::Connected;

    // Act
    classUnderTest->ConnectAsync().get();

    // Assert
    ASSERT_THAT(classUnderTest->GetState(), Eq(expectedConnState)) << "Assert that client is connected";
}

TEST_F(PusherClientTest, ConnectAsyncWhenClientHasPendingChannelsSendsSubscribeMessage)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    const PusherConnectionState expectedConnState = PusherConnectionState::Connected;
    classUnderTest->SubscribeAsync(channelName);

    // Arrange - Expectations
    QueueSubscriptionMessage(channelName, true);
    SetExpectedCallCount(1);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                        << "Assume that subscription to channel is pending";

    // Act
    classUnderTest->ConnectAsync().get();

    // Assert
    EXPECT_THAT(classUnderTest->GetState(), Eq(expectedConnState)) << "Assert that client is connected";

    // Verify
    Verify(WaitTime);
}

TEST_F(PusherClientTest, DisconnectAsyncClientDisconnectsFromServer)
{
    // Arrange
    const PusherConnectionState expectedConnState = PusherConnectionState::Disconnected;
    classUnderTest->ConnectAsync().get();

    // Assumptions
    ASSERT_THAT(classUnderTest->GetState(), Eq(PusherConnectionState::Connected)) << "Assume that client is connected";

    // Act
    classUnderTest->DisconnectAsync().get();

    // Assert
    ASSERT_THAT(classUnderTest->GetState(), Eq(expectedConnState)) << "Assert that client is disconnected";
}

TEST_F(PusherClientTest, IsSubscriptionPendingWhenClientHasPendingSubscriptionReturnsTrue)
{
    // Arrange
    const std::string channelName(DefaultChannelName);
    classUnderTest->ConnectAsync().get();
    const std::future<void> preActFuture = classUnderTest->SubscribeAsync(channelName);

    // Act
    const bool actual = classUnderTest->IsSubscriptionPending(channelName);

    // Assert
    ASSERT_THAT(actual, IsTrue());

    // Clean up
    classUnderTest->DisconnectAsync().get();
}

TEST_F(PusherClientTest, SubscribeAsyncWhenNotSubscribedToChannelClientSubscribesToChannel)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    classUnderTest->ConnectAsync().get();

    // Arrange - Expectations
    QueueSubscriptionMessage(channelName, true);
    SetExpectedCallCount(1);

    // Act
    classUnderTest->SubscribeAsync(channelName).get();

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName), IsTrue()) << "Assert that client is subscribed to channel";

    // Verify
    Verify(WaitTime);
}

TEST_F(PusherClientTest, SubscribeAsyncWhenNotConnectedToServerClientSetsChannelAsPending)
{
    // Arrange
    const std::string channelName(DefaultChannelName);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscribedOrPending(channelName), IsFalse())
                        << "Assume that client is not subscribed to or pending subscription to channel";

    // Act
    classUnderTest->SubscribeAsync(channelName).get();

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                    << "Assert that client has pending subscription to channel";
}

TEST_F(PusherClientTest, SubscribeAsyncWhenAlreadySubscribedToChannelClientDoesNothing)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    QueueSubscriptionMessage(channelName); // Facilitates initial subscription
    classUnderTest->ConnectAsync().get();
    classUnderTest->SubscribeAsync(channelName).get();

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(0);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscribed(channelName), IsTrue()) << "Assume that client is subscribed to channel";

    // Act
    classUnderTest->SubscribeAsync(channelName).get();

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName), IsTrue()) << "Assert that client is subscribed to channel";

    // Verify
    Verify(WaitTime);
}

TEST_F(PusherClientTest, SubscribeAsyncWhenSubscriptionIsPendingClientDoesNothing)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    classUnderTest->ConnectAsync().get();

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(1);

    // Arrange - Data (continued)
    const std::future<void> preActFuture = classUnderTest->SubscribeAsync(channelName);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                        << "Assume that subscription to channel is pending";

    // Act
    const std::future<void> future = classUnderTest->SubscribeAsync(channelName);

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                    << "Assert that subscription to channel is pending";

    // Verify
    Verify(WaitTime);

    // Clean up
    classUnderTest->DisconnectAsync().get();
}

TEST_F(PusherClientTest, UnboundListenerIsNotCalledWhenEventIsRecieved)
{
    // Arrange - Data
    const std::string eventName(DefaultEventName);
    const std::string eventMessage = CreateEventMessagePayload(eventName);
    WebSocketMessage wsMessage;
    wsMessage.payload = std::vector<unsigned char>(eventMessage.begin(), eventMessage.end());
    wsMessage.type = WebSocketMessageType::Utf8Message;
    classUnderTest->ConnectAsync().get();
    classUnderTest->Bind(eventName, mockListener);
    classUnderTest->Unbind(eventName);

    // Arrange - Expectations
    EXPECT_CALL(*mockListener, OnEvent(An<const PusherEvent&>()))
        .Times(0);

    // Assumptions
    ASSERT_THAT(classUnderTest->GetState(), Eq(PusherConnectionState::Connected)) << "Assume that client is connected";

    // Act
    mockServer->SendWebSocketMessage(wsMessage);

    std::this_thread::sleep_for(WaitTime);

    // Assert (see: Arrange - Expectations)
}

TEST_F(PusherClientTest, UnsubscribeAllAsyncWhenNotSubscribedToChannelsClientDoesNothing)
{
    // Arrange - Data
    classUnderTest->ConnectAsync().get();

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(0);

    // Act
    classUnderTest->UnsubscribeAllAsync().get();

    // Verify
    Verify(WaitTime);
}

TEST_F(PusherClientTest, UnsubscribeAllAsyncWhenSubscribedToChannelsClientUnsubscribesFromChannels)
{
    // Arrange - Data
    const std::string channelName1("Channel 1");
    const std::string channelName2("Channel 2");
    const std::string channelName3("Channel 3");
    QueueSubscriptionMessage(channelName1); // Facilitates initial subscription
    QueueSubscriptionMessage(channelName2); //
    QueueSubscriptionMessage(channelName3); //
    classUnderTest->ConnectAsync().get();
    classUnderTest->SubscribeAsync(channelName1).get();
    classUnderTest->SubscribeAsync(channelName2).get();
    classUnderTest->SubscribeAsync(channelName3).get();

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(3);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscribed(channelName1), IsTrue())
                        << "Assume that client is subscribed to channel 1";
    ASSERT_THAT(classUnderTest->IsSubscribed(channelName2), IsTrue())
                        << "Assume that client is subscribed to channel 2";
    ASSERT_THAT(classUnderTest->IsSubscribed(channelName3), IsTrue())
                        << "Assume that client is subscribed to channel 3";

    // Act
    classUnderTest->UnsubscribeAllAsync().get();

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName1), IsFalse())
                    << "Assume that client is subscribed to channel 1";
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName2), IsFalse())
                    << "Assume that client is subscribed to channel 2";
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName3), IsFalse())
                    << "Assume that client is subscribed to channel 3";

    // Verify
    Verify(Milliseconds(WaitTime));
}

TEST_F(PusherClientTest, UnsubscribeAllAsyncWhenSubscriptionToChannelsIsPendingClientUnsubscribesFromChannels)
{
    // Arrange
    const std::string channelName1("Channel 1");
    const std::string channelName2("Channel 2");
    const std::string channelName3("Channel 3");
    mockServer->NextMessage([](const WebSocketMessage&) { /* Consumes subscription message */ });
    mockServer->NextMessage([](const WebSocketMessage&) { /* Consumes subscription message */ });
    mockServer->NextMessage([](const WebSocketMessage&) { /* Consumes subscription message */ });
    classUnderTest->ConnectAsync().get();
    const std::future<void> preActFuture1 = classUnderTest->SubscribeAsync(channelName1);
    const std::future<void> preActFuture2 = classUnderTest->SubscribeAsync(channelName2);
    const std::future<void> preActFuture3 = classUnderTest->SubscribeAsync(channelName3);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscribedOrPending(channelName1), IsTrue())
                        << "Assume that client is subscribed to channel 1";
    ASSERT_THAT(classUnderTest->IsSubscribedOrPending(channelName2), IsTrue())
                        << "Assume that client is subscribed to channel 2";
    ASSERT_THAT(classUnderTest->IsSubscribedOrPending(channelName3), IsTrue())
                        << "Assume that client is subscribed to channel 3";

    // Act
    classUnderTest->UnsubscribeAllAsync().get();

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName1), IsFalse())
                    << "Assume that client is subscribed to channel 1";
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName2), IsFalse())
                    << "Assume that client is subscribed to channel 2";
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName3), IsFalse())
                    << "Assume that client is subscribed to channel 3";

    // Clean up
    preActFuture1.wait_for(Milliseconds::zero());
    preActFuture2.wait_for(Milliseconds::zero());
    preActFuture3.wait_for(Milliseconds::zero());
}

TEST_F(PusherClientTest, UnsubscribeAsyncWhenNotSubscribedToChannelClientDoesNothing)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    classUnderTest->ConnectAsync().get();

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(0);

    // Act
    classUnderTest->UnsubscribeAsync(channelName).get();

    // Verify
    Verify(WaitTime);
}

TEST_F(PusherClientTest, UnsubscribeAsyncWhenSubscribedToChannelClientUnsubscribesFromChannel)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    QueueSubscriptionMessage(channelName); // Facilitates initial subscription
    classUnderTest->ConnectAsync().get();
    classUnderTest->SubscribeAsync(channelName).get();

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(1);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscribed(channelName), IsTrue()) << "Assume that client is subscribed to channel";

    // Act
    classUnderTest->UnsubscribeAsync(channelName).get();

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscribedOrPending(channelName), IsFalse())
                    << "Assert that client is not subscribed nor pending subscription to channel";

    // Verify
    Verify(WaitTime);
}

TEST_F(PusherClientTest, UnsubscribeAsyncWhenSubscriptionIsPendingClientUnsubscribesFromChannel)
{
    // Arrange
    const std::string channelName(DefaultChannelName);
    mockServer->NextMessage([](const WebSocketMessage&) { /* Consumes subscription message */ });
    classUnderTest->ConnectAsync().get();
    const std::future<void> preActFuture = classUnderTest->SubscribeAsync(channelName);

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(1);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                        << "Assume that subscription to channel is pending";

    // Act
    classUnderTest->UnsubscribeAsync(channelName).get();

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscribedOrPending(channelName), IsFalse())
                    << "Assert that client is not subscribed nor pending subscription to channel";

    // Verify
    Verify(WaitTime);
}

TEST_F(PusherClientTest, WhenServerSendsCloseMessageClientIsDisconnected)
{
    // Arrange
    const PusherConnectionState expected = PusherConnectionState::Disconnected;
    const uint16_t code = 4000;
    const std::string reason;
    classUnderTest->ConnectAsync().get();

    // Assumptions
    ASSERT_THAT(classUnderTest->GetState(), Eq(PusherConnectionState::Connected)) << "Assume that client is connected";

    // Act
    mockServer->Close(code, reason);

    std::this_thread::sleep_for(WaitTime);

    // Assert
    ASSERT_THAT(classUnderTest->GetState(), Eq(expected)) << "Assert that client is disconnected";
}
