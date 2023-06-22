//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

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
    inline static const std::chrono::milliseconds WaitTime = std::chrono::milliseconds(500);

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

    static std::string CreateSubscriptionErrorMessagePayload()
    {
        std::stringstream ss;

        ss << R"({"event":")"
           << PusherConstants::ChannelSubscriptionError
           << R"("})";

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
    classUnderTest->Connect().get();
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

TEST_F(PusherClientTest, ConnectClientConnectsToServer)
{
    // Arrange
    const std::future_status expectedStatus = std::future_status::ready;
    const PusherConnectionState expectedConnState = PusherConnectionState::Connected;

    // Act
    std::future<void> future = classUnderTest->Connect();

    // Assert
    ASSERT_THAT(future.wait_for(WaitTime), Eq(expectedStatus)) << "Assert future is ready";
    ASSERT_THAT(classUnderTest->GetState(), Eq(expectedConnState)) << "Assert that client is connected";
}

TEST_F(PusherClientTest, ConnectWhenClientHasPendingChannelsSendsSubscribeMessage)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    const std::future_status expectedStatus = std::future_status::ready;
    const PusherConnectionState expectedConnState = PusherConnectionState::Connected;
    classUnderTest->Subscribe(channelName);

    // Arrange - Expectations
    mockServer->NextMessage([this, channelName](const WebSocketMessage& inMsg) {
        IncrementCallCount();

        const std::string data = CreateSubscriptionSuccessMessagePayload(channelName);
        WebSocketMessage outMsg;
        outMsg.payload = std::vector<unsigned char>(data.begin(), data.end());
        outMsg.type = WebSocketMessageType::Utf8Message;

        mockServer->SendWebSocketMessage(outMsg);
    });
    SetExpectedCallCount(1);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                        << "Assume that subscription to channel is pending";

    // Act
    std::future<void> future = classUnderTest->Connect();

    std::this_thread::sleep_for(WaitTime);

    // Assert
    ASSERT_THAT(future.wait_for(WaitTime), Eq(expectedStatus)) << "Assert future is ready";
    ASSERT_THAT(classUnderTest->GetState(), Eq(expectedConnState)) << "Assert that client is connected";
    ASSERT_THAT(classUnderTest->IsSubscribed(channelName), IsTrue()) << "Assert that client is subscribed to channel";
}

TEST_F(PusherClientTest, DisconnectClientDisconnectsFromServer)
{
    // Arrange
    const std::future_status expectedStatus = std::future_status::ready;
    const PusherConnectionState expectedConnState = PusherConnectionState::Disconnected;
    classUnderTest->Connect().get();

    // Assumptions
    ASSERT_THAT(classUnderTest->GetState(), Eq(PusherConnectionState::Connected)) << "Assume that client is connected";

    // Act
    std::future<void> future = classUnderTest->Disconnect();

    // Assert
    ASSERT_THAT(future.wait_for(WaitTime), Eq(expectedStatus)) << "Assert future is ready";
    ASSERT_THAT(classUnderTest->GetState(), Eq(expectedConnState)) << "Assert that client is disconnected";
}

TEST_F(PusherClientTest, SubscribeWhenNotSubscribedToChannelClientSubscribesToChannel)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    classUnderTest->Connect().get();

    // Arrange - Expectations
    mockServer->NextMessage([this, channelName](const WebSocketMessage& inMsg) {
        IncrementCallCount();

        const std::string data = CreateSubscriptionSuccessMessagePayload(channelName);
        WebSocketMessage outMsg;
        outMsg.payload = std::vector<unsigned char>(data.begin(), data.end());
        outMsg.type = WebSocketMessageType::Utf8Message;

        mockServer->SendWebSocketMessage(outMsg);
    });
    SetExpectedCallCount(1);

    // Act
    classUnderTest->Subscribe(channelName);

    std::this_thread::sleep_for(WaitTime);

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName), IsTrue()) << "Assert that client is subscribed to channel";

    // Verify
    Verify();
}

TEST_F(PusherClientTest, SubscribeWhenNotConnectedToServerClientSetsChannelAsPending)
{
    // Arrange
    const std::string channelName(DefaultChannelName);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscribedOrPending(channelName), IsFalse())
                        << "Assume that client is not subscribed to or pending subscription to channel";

    // Act
    classUnderTest->Subscribe(channelName);

    // Assert
    ASSERT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                        << "Assert that client has pending subscription to channel";
}

TEST_F(PusherClientTest, SubscribeWhenAlreadySubscribedToChannelClientDoesNothing)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    classUnderTest->Connect().get();
    mockServer->NextMessage([channelName](const WebSocketMessage&) { // Facilitates initial subscription
        const std::string data = CreateSubscriptionSuccessMessagePayload(channelName);
        WebSocketMessage message;
        message.payload = std::vector<unsigned char>(data.begin(), data.end());
        message.type = WebSocketMessageType::Utf8Message;

        mockServer->SendWebSocketMessage(message);
    });
    classUnderTest->Subscribe(channelName);

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(0);

    std::this_thread::sleep_for(WaitTime);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscribed(channelName), IsTrue()) << "Assume that client is subscribed to channel";

    // Act
    classUnderTest->Subscribe(channelName);

    std::this_thread::sleep_for(WaitTime);

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscribed(channelName), IsTrue()) << "Assert that client is subscribed to channel";

    // Verify
    Verify();
}

TEST_F(PusherClientTest, SubscribeWhenSubscriptionIsPendingClientDoesNothing)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    classUnderTest->Connect().get();

    // Arrange - Expectations
    mockServer->NextMessage([this](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(1);

    // Arrange - Data (continued)
    classUnderTest->Subscribe(channelName);

    std::this_thread::sleep_for(WaitTime);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                        << "Assume that subscription to channel is pending";

    // Act
    classUnderTest->Subscribe(channelName);

    std::this_thread::sleep_for(WaitTime);

    // Assert
    EXPECT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                    << "Assert that subscription to channel is pending";

    // Verify
    Verify();
}

TEST_F(PusherClientTest, UnboundListenerIsNotCalledWhenEventIsRecieved)
{
    // Arrange - Data
    const std::string eventName(DefaultEventName);
    const std::string eventMessage = CreateEventMessagePayload(eventName);
    WebSocketMessage wsMessage;
    wsMessage.payload = std::vector<unsigned char>(eventMessage.begin(), eventMessage.end());
    wsMessage.type = WebSocketMessageType::Utf8Message;
    classUnderTest->Connect().get();
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

TEST_F(PusherClientTest, UnsubscribeWhenNotSubscribedToChannelClientDoesNothing)
{
    // Arrange
    const std::string channelName(DefaultChannelName);
    classUnderTest->Connect().get();

    // Arrange - Expectations
    mockServer->NextMessage([this, channelName](const WebSocketMessage&) {
        IncrementCallCount();
    });
    SetExpectedCallCount(0);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscribedOrPending(channelName), IsFalse())
                        << "Assume that client is not subscribed nor pending subscription to channel";

    // Act
    classUnderTest->Unsubscribe(channelName);

    std::this_thread::sleep_for(WaitTime);

    // Assert
    ASSERT_THAT(classUnderTest->IsSubscribedOrPending(channelName), IsFalse())
                        << "Assert that client is still not subscribed nor pending subscription to channel";

    // Verify
    Verify();
}

TEST_F(PusherClientTest, UnsubscribeWhenSubscribedToChannelClientUnsubscribesFromChannel)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    classUnderTest->Connect().get();
    classUnderTest->Subscribe(channelName);
    mockServer->NextMessage([channelName](const WebSocketMessage&) { // Facilitates initial subscription
        const std::string data = CreateSubscriptionSuccessMessagePayload(channelName);
        WebSocketMessage message;
        message.payload = std::vector<unsigned char>(data.begin(), data.end());
        message.type = WebSocketMessageType::Utf8Message;

        mockServer->SendWebSocketMessage(message);
    });

    // Arrange - Expectations
    mockServer->NextMessage([this, channelName](const WebSocketMessage& inMsg) {
        IncrementCallCount();
    });
    SetExpectedCallCount(1);

    std::this_thread::sleep_for(WaitTime);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscribed(channelName), IsTrue()) << "Assume that client is subscribed to channel";

    // Act
    classUnderTest->Unsubscribe(channelName);

    std::this_thread::sleep_for(WaitTime);

    // Assert
    ASSERT_THAT(classUnderTest->IsSubscribedOrPending(channelName), IsFalse())
                        << "Assert that client is not subscribed nor pending subscription to channel";

    // Verify
    Verify();
}

TEST_F(PusherClientTest, UnsubscribeWhenSubscriptionIsPendingClientUnsubscribesFromChannel)
{
    // Arrange - Data
    const std::string channelName(DefaultChannelName);
    classUnderTest->Connect().get();
    classUnderTest->Subscribe(channelName);
    mockServer->NextMessage([](const WebSocketMessage&) { /* Consumes subscription message */ });

    // Arrange - Expectations
    mockServer->NextMessage([this, channelName](const WebSocketMessage& inMsg) {
        IncrementCallCount();
    });
    SetExpectedCallCount(1);

    std::this_thread::sleep_for(WaitTime);

    // Assumptions
    ASSERT_THAT(classUnderTest->IsSubscriptionPending(channelName), IsTrue())
                        << "Assume that subscription to channel is pending";

    // Act
    classUnderTest->Unsubscribe(channelName);

    std::this_thread::sleep_for(WaitTime);

    // Assert
    ASSERT_THAT(classUnderTest->IsSubscribedOrPending(channelName), IsFalse())
                        << "Assert that client is not subscribed nor pending subscription to channel";

    // Verify
    Verify();
}
