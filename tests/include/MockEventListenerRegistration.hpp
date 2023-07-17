#ifndef ENJINPLATFORMSDK_MOCKEVENTLISTENERREGISTRATION_HPP
#define ENJINPLATFORMSDK_MOCKEVENTLISTENERREGISTRATION_HPP

#include "gmock/gmock.h"
#include "EnjinPlatformSdk/IEventListener.hpp"
#include "EnjinPlatformSdk/IEventListenerRegistration.hpp"
#include <functional>
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
class MockEventListenerRegistration;

/// \brief Definition for a nice mock of IEventListenerRegistration.
[[maybe_unused]]
typedef testing::NiceMock<MockEventListenerRegistration> NiceMockEventListenerRegistration;

/// \brief Definition for a pointer containing a nice mock of IEventListenerRegistration.
[[maybe_unused]]
typedef std::shared_ptr<NiceMockEventListenerRegistration> MockEventListenerRegistrationPtr;

/// \brief Mock class for IEventListenerRegistration.
class MockEventListenerRegistration : virtual public IEventListenerRegistration
{
public:
    // region IEventListenerRegistration

    MOCK_METHOD(const EventListenerPtr&, GetListener, (), (const));

    MOCK_METHOD(const EventMatcher&, GetMatcher, (), (const));

    MOCK_METHOD(bool, IsRegistered, (), (const));

    // endregion IEventListenerRegistration
};
}

#endif //ENJINPLATFORMSDK_MOCKEVENTLISTENERREGISTRATION_HPP
