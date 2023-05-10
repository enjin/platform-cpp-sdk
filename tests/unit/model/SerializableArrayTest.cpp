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
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include <memory>
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class SerializableArrayTest : public Test
{
public:
    std::unique_ptr<SerializableArray<SerializableInt>> classUnderTest;

protected:
    void SetUp() override
    {
        classUnderTest = std::make_unique<SerializableArray<SerializableInt>>();
    }
};

TEST_F(SerializableArrayTest, PushBackElementIsAddedToArray)
{
    // Arrange
    const SerializableInt expected(1);
    const int index = 0;
    SerializableArray<SerializableInt> array;

    // Act
    array.PushBack(expected);

    // Assert
    ASSERT_EQ(array[index], expected);
}

TEST_F(SerializableArrayTest, RemoveAtWhenArrayDoesNotHaveElementThrowsError)
{
    // Arrange
    const int index = 0;
    SerializableArray<SerializableInt> array;

    // Assert
    ASSERT_THROW(array.RemoveAt(index), std::out_of_range);
}

TEST_F(SerializableArrayTest, RemoveAtWhenArrayHasElementRemovesElement)
{
    // Arrange
    const int index = 0;
    SerializableArray<SerializableInt> array({SerializableInt(1)});

    // Act
    array.RemoveAt(index);

    // Assert
    ASSERT_TRUE(array.IsEmpty());
}

TEST_F(SerializableArrayTest, ToJsonReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson("[1,2,3]");
    SerializableArray<SerializableInt> array({SerializableInt(1), SerializableInt(2), SerializableInt(3)});

    // Act
    const JsonValue actual = array.ToJson();

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(SerializableArrayTest, ToStringReturnsExpected)
{
    // Arrange
    const std::string expected("[1,2,3]");
    SerializableArray<SerializableInt> array({SerializableInt(1), SerializableInt(2), SerializableInt(3)});

    // Act
    const std::string actual = array.ToString();

    // Assert
    ASSERT_EQ(actual, expected);
}
