#ifndef ENJINPLATFORMSDK_MOCKSUBSCRIPTIONLISTENER_HPP
#define ENJINPLATFORMSDK_MOCKSUBSCRIPTIONLISTENER_HPP

#include "gmock/gmock.h"
#include "ISubscriptionListener.hpp"
#include "PusherEvent.hpp"
#include <memory>

namespace pusher
{
class MockSubscriptionListener;

/// \brief Definition for a nice mock of ISubscriptionListener.
using NiceMockSubscriptionListener [[maybe_unused]] = testing::NiceMock<MockSubscriptionListener>;

/// \brief Definition for a pointer containing a nice mock of ISubscriptionListener.
using MockSubscriptionListenerPtr [[maybe_unused]] = std::shared_ptr<NiceMockSubscriptionListener>;

/// \brief Mock class for ISubscriptionListener.
class MockSubscriptionListener : virtual public ISubscriptionListener
{
public:
    // region ISubscriptionListener

    MOCK_METHOD(void, OnEvent, (const PusherEvent& evt), ());

    // endregion ISubscriptionListener
};
}

#endif //ENJINPLATFORMSDK_MOCKSUBSCRIPTIONLISTENER_HPP
