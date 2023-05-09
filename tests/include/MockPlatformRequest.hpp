#ifndef ENJINPLATFORMSDK_MOCKPLATFORMREQUEST_HPP
#define ENJINPLATFORMSDK_MOCKPLATFORMREQUEST_HPP

#include "gmock/gmock.h"
#include "EnjinPlatformSdk/IPlatformRequest.hpp"
#include "EnjinPlatformSdk/MultipartFormData.hpp"
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
class MockPlatformRequest;

/// \brief Definition for a nice mock of IPlatformRequest.
using NiceMockPlatformRequest = testing::NiceMock<MockPlatformRequest>;

/// \brief Definition for a pointer containing a nice mock of IPlatformRequest.
using MockPlatformRequestPtr = std::shared_ptr<NiceMockPlatformRequest>;

/// \brief Mock class for IPlatformRequest.
class MockPlatformRequest : public IPlatformRequest
{
public:
    // region IPlatformRequest

    MOCK_METHOD(const std::optional<std::string>&, GetBody, (), (const));

    MOCK_METHOD(const std::string&, GetContentType, (), (const));

    MOCK_METHOD((const std::map<std::string, std::string>&), GetHeaders, (), (const));

    MOCK_METHOD((const std::optional<std::vector<MultipartFormData>>&), GetMultipartFormData, (), (const));

    MOCK_METHOD(const std::string&, GetPath, (), (const));

    // endregion IPlatformRequest
};
}

#endif //ENJINPLATFORMSDK_MOCKPLATFORMREQUEST_HPP
