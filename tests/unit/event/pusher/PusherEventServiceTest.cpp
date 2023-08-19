#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockEventListener.hpp"
#include "MockWebSocketServer.hpp"
#include "EnjinPlatformSdk/PusherEventService.hpp"
#include <memory>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class PusherEventServiceTest : public Test
{
public:
    PusherEventServicePtr classUnderTest;

    // Mocks
    inline static std::unique_ptr<MockWebSocketServer> mockServer;

protected:
    void SetUp() override
    {
        Test::SetUp();

        mockServer->IgnoreMessageType(WebSocketMessageType::Open)
                  .IgnoreMessageType(WebSocketMessageType::Close)
                  .IgnoreMessageType(WebSocketMessageType::Ping)
                  .IgnoreMessageType(WebSocketMessageType::Pong);

        std::stringstream hostStream;
        hostStream << mockServer->GetHost() << ":" << mockServer->GetPort();

        classUnderTest = PusherEventService::Builder()
            .SetKey("xyz")
            .SetEncrypted(false)
            .SetHost(hostStream.str())
            .Build();
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
};

TEST_F(PusherEventServiceTest, RegisterListenerWhenListenerIsNullThrowsException)
{
    // Arrange
    const EventListenerPtr listener = nullptr;

    // Assert
    ASSERT_THROW(auto reg = classUnderTest->RegisterListener(listener), std::invalid_argument);
}

TEST_F(PusherEventServiceTest, RegisterListenerListenerIsRegisteredAndHasAllowAllMatcher)
{
    // Arrange
    const std::set<std::string> events = {"Event1", "Event2", "Event3", "Event4"};
    const MockEventListenerPtr dummyListener = std::make_shared<NiceMockEventListener>();

    // Act
    EventListenerRegistrationPtr actual = classUnderTest->RegisterListener(dummyListener);

    // Assert
    EXPECT_THAT(actual->IsRegistered(), IsTrue()) << "Assert that registration is active";
    EXPECT_THAT(actual->GetListener(), Eq(dummyListener)) << "Assert that registration contains listener";

    for (const std::string& evt : events)
    {
        EXPECT_THAT(actual->GetMatcher()(evt), IsTrue()) << "Assert event '" << evt << "' matches as true";
    }
}

TEST_F(PusherEventServiceTest, RegisterListenerExcludingEventsListenerIsRegisteredAndHasCorrectMatcher)
{
    // Arrange
    const std::set<std::string> excludedEvents = {"Event1", "Event2"};
    const std::set<std::string> otherEvents = {"Event3", "Event4"};
    const MockEventListenerPtr dummyListener = std::make_shared<NiceMockEventListener>();

    // Act
    const EventListenerRegistrationPtr actual = classUnderTest->RegisterListenerExcludingEvents(dummyListener,
                                                                                                excludedEvents);

    // Assert
    EXPECT_THAT(actual->IsRegistered(), IsTrue()) << "Assert that registration is active";
    EXPECT_THAT(actual->GetListener(), Eq(dummyListener)) << "Assert that registration contains listener";

    for (const std::string& evt : excludedEvents)
    {
        EXPECT_THAT(actual->GetMatcher()(evt), IsFalse()) << "Assert event '" << evt << "' matches as false";
    }

    for (const std::string& evt : otherEvents)
    {
        EXPECT_THAT(actual->GetMatcher()(evt), IsTrue()) << "Assert event '" << evt << "' matches as true";
    }
}

TEST_F(PusherEventServiceTest, RegisterListenerExcludingEventsWhenListenerIsNullThrowsException)
{
    // Arrange
    const EventListenerPtr listener = nullptr;
    const std::set<std::string> events;

    // Assert
    ASSERT_THROW(auto reg = classUnderTest->RegisterListenerExcludingEvents(listener, events), std::invalid_argument);
}

TEST_F(PusherEventServiceTest, RegisterListenerIncludingEventsListenerIsRegisteredAndHasCorrectMatcher)
{
    // Arrange
    const std::set<std::string> includedEvents = {"Event1", "Event2"};
    const std::set<std::string> otherEvents = {"Event3", "Event4"};
    const MockEventListenerPtr dummyListener = std::make_shared<NiceMockEventListener>();

    // Act
    const EventListenerRegistrationPtr actual = classUnderTest->RegisterListenerIncludingEvents(dummyListener,
                                                                                                includedEvents);

    // Assert
    EXPECT_THAT(actual->IsRegistered(), IsTrue()) << "Assert that registration is active";
    EXPECT_THAT(actual->GetListener(), Eq(dummyListener)) << "Assert that registration contains listener";

    for (const std::string& evt : includedEvents)
    {
        EXPECT_THAT(actual->GetMatcher()(evt), IsTrue()) << "Assert event '" << evt << "' matches as true";
    }

    for (const std::string& evt : otherEvents)
    {
        EXPECT_THAT(actual->GetMatcher()(evt), IsFalse()) << "Assert event '" << evt << "' matches as false";
    }
}

TEST_F(PusherEventServiceTest, RegisterListenerIncludingEventsWhenListenerIsNullThrowsException)
{
    // Arrange
    const EventListenerPtr listener = nullptr;
    const std::set<std::string> events;

    // Assert
    ASSERT_THROW(auto reg = classUnderTest->RegisterListenerIncludingEvents(listener, events), std::invalid_argument);
}

TEST_F(PusherEventServiceTest, RegisterListenerWithMatcherWhenListenerIsNullThrowsException)
{
    // Arrange
    const EventListenerPtr listener = nullptr;
    const EventMatcher matcher = [](const std::string& evt) { return true; };

    // Assert
    ASSERT_THROW(auto reg = classUnderTest->RegisterListenerWithMatcher(listener, matcher), std::invalid_argument);
}

TEST_F(PusherEventServiceTest, UnregisterAllListenersAllListenersAreUnregistered)
{
    // Arrange
    const EventListenerRegistrationPtr reg1 =
        classUnderTest->RegisterListener(std::make_shared<NiceMockEventListener>());
    const EventListenerRegistrationPtr reg2 =
        classUnderTest->RegisterListener(std::make_shared<NiceMockEventListener>());
    const EventListenerRegistrationPtr reg3 =
        classUnderTest->RegisterListener(std::make_shared<NiceMockEventListener>());

    // Assumptions
    ASSERT_THAT(reg1->IsRegistered(), IsTrue()) << "Assume registration 1 is active";
    ASSERT_THAT(reg2->IsRegistered(), IsTrue()) << "Assume registration 2 is active";
    ASSERT_THAT(reg3->IsRegistered(), IsTrue()) << "Assume registration 3 is active";

    // Act
    classUnderTest->UnregisterAllListeners();

    // Assert
    EXPECT_THAT(reg1->IsRegistered(), IsFalse()) << "Assert registration 1 is not active";
    EXPECT_THAT(reg1->IsRegistered(), IsFalse()) << "Assert registration 2 is not active";
    EXPECT_THAT(reg1->IsRegistered(), IsFalse()) << "Assert registration 3 is not active";
}

TEST_F(PusherEventServiceTest, UnregisterListenerWhenGivenRegisteredListenerUnregistersListener)
{
    // Arrange
    const MockEventListenerPtr dummyListener = std::make_shared<NiceMockEventListener>();
    const EventListenerRegistrationPtr reg = classUnderTest->RegisterListener(dummyListener);

    // Assumptions
    ASSERT_THAT(reg->IsRegistered(), IsTrue()) << "Assume registration is active";

    // Act
    classUnderTest->UnregisterListener(*dummyListener);

    // Assert
    ASSERT_THAT(reg->IsRegistered(), IsFalse()) << "Assert registration is not active";
}

TEST_F(PusherEventServiceTest, UnregisterListenerWhenGivenNonRegisteredListenerDoesNotThrowError)
{
    // Arrange
    const MockEventListenerPtr dummyListener = std::make_shared<NiceMockEventListener>();

    // Assert
    ASSERT_NO_THROW(classUnderTest->UnregisterListener(*dummyListener));
}
