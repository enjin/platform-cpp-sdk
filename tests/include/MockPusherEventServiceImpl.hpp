#ifndef ENJINPLATFORMSDK_MOCKPUSHEREVENTSERVICEIMPL_HPP
#define ENJINPLATFORMSDK_MOCKPUSHEREVENTSERVICEIMPL_HPP

#include "gmock/gmock.h"
#include "IPusherEventServiceImpl.hpp"
#include "EnjinPlatformSdk/ConnectionState.hpp"
#include "EnjinPlatformSdk/IEventListener.hpp"
#include "EnjinPlatformSdk/IEventListenerRegistration.hpp"
#include <functional>
#include <future>
#include <memory>
#include <set>
#include <string>

namespace enjin::platform::sdk
{
class MockPusherEventServiceImpl;

/// \brief Definition for a nice mock of IPusherEventServiceImpl.
[[maybe_unused]]
typedef testing::NiceMock<MockPusherEventServiceImpl> NiceMockPusherEventServiceImpl;

/// \brief Definition for a pointer containing a nice mock of IPusherEventServiceImpl.
[[maybe_unused]]
typedef std::shared_ptr<NiceMockPusherEventServiceImpl> MockPusherEventServiceImplPtr;

/// \brief Mock class for IPusherEventServiceImpl.
class MockPusherEventServiceImpl : virtual public IPusherEventServiceImpl
{
public:
    // region IEventService

    MOCK_METHOD(std::future<void>, ConnectAsync, (), ());

    MOCK_METHOD(std::future<void>, DisconnectAsync, (), ());

    MOCK_METHOD(bool, IsConnected, (), (const));

    MOCK_METHOD(EventListenerRegistrationPtr, RegisterListener, (EventListenerPtr listener), ());

    MOCK_METHOD(EventListenerRegistrationPtr,
                RegisterListenerExcludingEvents,
                (EventListenerPtr listener, std::set<std::string> events),
                ());

    MOCK_METHOD(EventListenerRegistrationPtr,
                RegisterListenerIncludingEvents,
                (EventListenerPtr listener, std::set<std::string> events),
                ());

    MOCK_METHOD(EventListenerRegistrationPtr,
                RegisterListenerWithMatcher,
                (EventListenerPtr listener, EventMatcher matcher),
                ());

    MOCK_METHOD(void, SetOnConnectedHandler, (std::function<void()> handler), ());

    MOCK_METHOD(void, SetOnConnectionStateChangedHandler, (std::function<void(ConnectionState)> handler), ());

    MOCK_METHOD(void, SetOnDisconnectedHandler, (std::function<void()> handler), ());

    MOCK_METHOD(void, SetOnSubscribedHandler, (std::function<void()> handler), ());

    MOCK_METHOD((std::future<void>), SubscribeAsync, (const std::string& channelName), ());

    MOCK_METHOD(void, UnregisterAllListeners, (), ());

    MOCK_METHOD(void, UnregisterListener, (const IEventListener& listener), ());

    MOCK_METHOD((std::future<void>), UnsubscribeAllAsync, (), ());

    MOCK_METHOD((std::future<void>), UnsubscribeAsync, (const std::string& channelName), ());

    // endregion IEventService

    // region IPusherEventServiceImpl

    MOCK_METHOD(std::vector<EventListenerRegistrationPtr>, GetRegistrations, (), (const));

    // endregion IPusherEventServiceImpl
};
}

#endif //ENJINPLATFORMSDK_MOCKPUSHEREVENTSERVICEIMPL_HPP
