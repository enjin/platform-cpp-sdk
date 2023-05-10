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

#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonDeserializableBaseTest : public Test
{
public:
    std::unique_ptr<JsonDeserializableBase> classUnderTest;

protected:
    void SetUp() override
    {
        classUnderTest = std::make_unique<JsonDeserializableBase>();
    }
};

TEST_F(JsonDeserializableBaseTest, DeserializeWhenInstanceHasNotBeenDeserializedDoesNotThrowError)
{
    // Arrange
    const JsonValue json;

    // Assert
    ASSERT_NO_THROW(classUnderTest->Deserialize(json));
}

TEST_F(JsonDeserializableBaseTest, DeserializeWhenInstanceHasAlreadyBeenDeserializedThrowsError)
{
    // Arrange
    const JsonValue json;
    classUnderTest->Deserialize(json);

    // Assert
    ASSERT_THROW(classUnderTest->Deserialize(json), std::runtime_error);
}
