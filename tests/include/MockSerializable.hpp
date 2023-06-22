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
