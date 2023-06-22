//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

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
using NiceMockPlatformRequest [[maybe_unused]] = testing::NiceMock<MockPlatformRequest>;

/// \brief Definition for a pointer containing a nice mock of IPlatformRequest.
using MockPlatformRequestPtr [[maybe_unused]] = std::shared_ptr<NiceMockPlatformRequest>;

/// \brief Mock class for IPlatformRequest.
class MockPlatformRequest : virtual public IPlatformRequest
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
