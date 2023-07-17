#ifndef ENJINPLATFORMSDK_MOCKEVENTLISTENER_HPP
#define ENJINPLATFORMSDK_MOCKEVENTLISTENER_HPP

#include "gmock/gmock.h"
#include "EnjinPlatformSdk/IEventListener.hpp"
#include "EnjinPlatformSdk/PlatformEvent.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class MockEventListener;

/// \brief Definition for a nice mock of IEventListener.
[[maybe_unused]]
typedef testing::NiceMock<MockEventListener> NiceMockEventListener;

/// \brief Definition for a pointer containing a nice mock of IEventListener.
[[maybe_unused]]
typedef std::shared_ptr<NiceMockEventListener> MockEventListenerPtr;

/// \brief Mock class for IEventListener.
class MockEventListener : virtual public IEventListener
{
public:
    // region IEventListener

    MOCK_METHOD(void, OnEvent, (const PlatformEvent& evt), ());

    // endregion IEventListener
};
}

#endif //ENJINPLATFORMSDK_MOCKEVENTLISTENER_HPP
