#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockEventListener.hpp"
#include "MockEventListenerRegistration.hpp"
#include "MockPusherEventServiceImpl.hpp"
#include "PusherEvent.hpp"
#include "PusherListener.hpp"
#include "RapidJsonUtil.hpp"
#include "rapidjson/document.h"
#include <memory>
#include <string>
#include <vector>

using namespace enjin::platform::sdk;
using namespace pusher;
using namespace rapidjson;
using namespace testing;

class PusherListenerTest : public Test
{
public:
    std::unique_ptr<PusherListener> classUnderTest;

    // Mocks
    MockPusherEventServiceImplPtr mockService;

    static PusherEvent CreateEvent(const std::string& eventName, const std::string& channelName, const Document& data)
    {
        Document document(kObjectType);
        RapidJsonUtil::SetStringMember(document, "event", eventName);
        RapidJsonUtil::SetStringMember(document, "channel", channelName);
        RapidJsonUtil::SetStringMember(document, "data", RapidJsonUtil::DocumentToString(data));

        const std::string json = RapidJsonUtil::DocumentToString(document);

        return PusherEvent(json);
    }

protected:
    void SetUp() override
    {
        Test::SetUp();

        mockService = std::make_shared<NiceMockPusherEventServiceImpl>();

        classUnderTest = std::make_unique<PusherListener>(*mockService);
    }
};

TEST_F(PusherListenerTest, OnEventWhenEventServiceHasRegisteredListenerWithPassingMatcherPassesEventToListeners)
{
    // Arrange - Data
    const PusherEvent dummyEvent = CreateEvent("Event Name", "Channel Name", Document(kObjectType));
    const EventMatcher fakeMatcher = [](const std::string&) { return true; };
    const MockEventListenerPtr mockListener = std::make_shared<NiceMockEventListener>();
    const MockEventListenerRegistrationPtr mockRegistration = std::make_shared<NiceMockEventListenerRegistration>();
    const EventListenerPtr stubListener = mockListener; // Needed to avoid segmentation fault when stubbing
    const std::vector<EventListenerRegistrationPtr> registrations = {mockRegistration};

    // Arrange - Stubbing
    ON_CALL(*mockRegistration, GetListener())
        .WillByDefault(Const(ReturnRef(stubListener)));
    ON_CALL(*mockRegistration, GetMatcher())
        .WillByDefault(Const(ReturnRef(fakeMatcher)));
    ON_CALL(*mockService, GetRegistrations())
        .WillByDefault(Return(registrations));

    // Arrange - Expectations
    EXPECT_CALL(*mockListener, OnEvent(An<const PlatformEvent&>()))
        .Times(1);

    // Act
    classUnderTest->OnEvent(dummyEvent);

    // Verify (Done by GTest)
}

TEST_F(PusherListenerTest, OnEventWhenEventServiceHasRegisteredListenerWithNonPassingMatcherPassesEventToListeners)
{
    // Arrange - Data
    const PusherEvent dummyEvent = CreateEvent("Event Name", "Channel Name", Document(kObjectType));
    const EventMatcher fakeMatcher = [](const std::string&) { return false; };
    const MockEventListenerPtr mockListener = std::make_shared<NiceMockEventListener>();
    const MockEventListenerRegistrationPtr mockRegistration = std::make_shared<NiceMockEventListenerRegistration>();
    const EventListenerPtr stubListener = mockListener; // Needed to avoid segmentation fault when stubbing
    const std::vector<EventListenerRegistrationPtr> registrations = {mockRegistration};

    // Arrange - Stubbing
    ON_CALL(*mockRegistration, GetListener())
        .WillByDefault(Const(ReturnRef(stubListener)));
    ON_CALL(*mockRegistration, GetMatcher())
        .WillByDefault(Const(ReturnRef(fakeMatcher)));
    ON_CALL(*mockService, GetRegistrations())
        .WillByDefault(Return(registrations));

    // Arrange - Expectations
    EXPECT_CALL(*mockListener, OnEvent(An<const PlatformEvent&>()))
        .Times(0);

    // Act
    classUnderTest->OnEvent(dummyEvent);

    // Verify (Done by GTest)
}
