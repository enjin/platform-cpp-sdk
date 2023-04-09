#ifndef ENJINPLATFORMSDK_MOCKJSONSERIALIZABLE_HPP
#define ENJINPLATFORMSDK_MOCKJSONSERIALIZABLE_HPP

#include "gmock/gmock.h"
#include "EnjinPlatformSdk/IJsonSerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>

namespace enjin::platform::sdk
{
/// \brief Mock class for IJsonSerializable.
class MockJsonSerializable : public IJsonSerializable
{
public:
    // region IJsonSerializable

    MOCK_METHOD(JsonValue, ToJson, (), (const));

    // endregion IJsonSerializable
};

/// \brief Definition for a nice mock of IJsonSerializable.
typedef testing::NiceMock<MockJsonSerializable> NiceMockJsonSerializable;

/// \brief Definition for a pointer containing a nice mock of IJsonSerializable.
typedef std::shared_ptr<NiceMockJsonSerializable> MockJsonSerializablePtr;
}

#endif //ENJINPLATFORMSDK_MOCKJSONSERIALIZABLE_HPP
