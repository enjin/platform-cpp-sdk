#ifndef ENJINPLATFORMSDK_MOCKSTRINGSERIALIZABLE_HPP
#define ENJINPLATFORMSDK_MOCKSTRINGSERIALIZABLE_HPP

#include "gmock/gmock.h"
#include "EnjinPlatformSdk/IStringSerializable.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Mock class for IStringSerializable.
class MockStringSerializable : public IStringSerializable
{
public:
    // region IStringSerializable

    MOCK_METHOD(std::string, ToString, (), (const));

    // endregion IStringSerializable
};

/// \brief Definition for a nice mock of IStringSerializable.
typedef testing::NiceMock<MockStringSerializable> NiceMockStringSerializable;

/// \brief Definition for a pointer containing a nice mock of IStringSerializable.
typedef std::shared_ptr<NiceMockStringSerializable> MockStringSerializablePtr;
}

#endif //ENJINPLATFORMSDK_MOCKSTRINGSERIALIZABLE_HPP
