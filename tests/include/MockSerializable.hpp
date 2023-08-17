#ifndef ENJINPLATFORMSDK_MOCKSERIALIZABLE_HPP
#define ENJINPLATFORMSDK_MOCKSERIALIZABLE_HPP

#include "gmock/gmock.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
class MockSerializable;

/// \brief Definition for a nice mock of ISerializable.
using NiceMockSerializable [[maybe_unused]] = testing::NiceMock<MockSerializable>;

/// \brief Definition for a pointer containing a nice mock of ISerializable.
using MockSerializablePtr [[maybe_unused]] = std::shared_ptr<NiceMockSerializable>;

/// \brief Mock class for ISerializable.
class MockSerializable : virtual public ISerializable
{
public:
    // region ISerializable

    MOCK_METHOD(JsonValue, ToJson, (), (const));

    MOCK_METHOD(std::string, ToString, (), (const));

    // endregion ISerializable
};
}

#endif //ENJINPLATFORMSDK_MOCKSERIALIZABLE_HPP
