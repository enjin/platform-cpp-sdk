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
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonValueStringTest : public Test
{
};

TEST_F(JsonValueStringTest, FromJsonGivenStringJsonReturnsValueThatIsString)
{
    // Arrange
    const std::string json(R"("")");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsString());
}

TEST_F(JsonValueStringTest, GetStringWhenValueIsNotAStringThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(std::string v = jsonValue.GetString(), std::runtime_error);
}

TEST_F(JsonValueStringTest, GetStringWhenValueIsAStringReturnsExpected)
{
    // Arrange
    const std::string expected("xyz");
    const std::string json(R"("xyz")");
    JsonValue jsonValue = JsonValue::FromJson(json);

    // Act
    const std::string actual = jsonValue.GetString();

    // Assert
    ASSERT_EQ(actual, expected);
}
