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

class JsonValueDoubleTest : public Test
{
};

TEST_F(JsonValueDoubleTest, FromJsonGivenDoubleJsonReturnsValueThatIsDouble)
{
    // Arrange
    const std::string json("1.0");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsDouble());
}

TEST_F(JsonValueDoubleTest, GetDoubleWhenValueIsNotADoubleThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(double v = jsonValue.GetDouble(), std::runtime_error);
}

TEST_F(JsonValueDoubleTest, GetDoubleWhenValueIsADoubleReturnsExpected)
{
    // Arrange
    const double expected = 1.0;
    const std::string json("1.0");
    JsonValue jsonValue = JsonValue::FromJson(json);

    // Act
    const double actual = jsonValue.GetDouble();

    // Assert
    ASSERT_EQ(actual, expected);
}
