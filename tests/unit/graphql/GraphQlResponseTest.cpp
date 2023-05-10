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
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>

using namespace enjin::platform::sdk;
using namespace testing;

class GraphQlResponseTest : public Test
{
public:
    std::unique_ptr<GraphQlResponse<bool>> classUnderTest;

protected:
    void SetUp() override
    {
        classUnderTest = std::make_unique<GraphQlResponse<bool>>();
    }
};

TEST_F(GraphQlResponseTest, HasErrorsWhenResponseDoesNotHaveErrorsReturnsFalse)
{
    // Act
    const bool actual = classUnderTest->HasErrors();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GraphQlResponseTest, HasErrorsWhenResponseHasEmptyErrorsArrayReturnsFalse)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"errors":[]})");
    classUnderTest->Deserialize(json);

    // Act
    const bool actual = classUnderTest->HasErrors();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GraphQlResponseTest, HasErrorsWhenResponseHasPopulatedErrorsArrayReturnsTrue)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"errors":[{}]})");
    classUnderTest->Deserialize(json);

    // Act
    const bool actual = classUnderTest->HasErrors();

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GraphQlResponseTest, IsEmptyWhenResponseHasNoDataReturnsTrue)
{
    // Act
    const bool actual = classUnderTest->IsEmpty();

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GraphQlResponseTest, IsEmptyWhenResponseHasDataWithNoResultReturnsTrue)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"data":{}})");
    classUnderTest->Deserialize(json);

    // Act
    const bool actual = classUnderTest->IsEmpty();

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GraphQlResponseTest, IsEmptyWhenResponseHasDataWithNoResultReturnsFalse)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"data":{"result":true}})");
    classUnderTest->Deserialize(json);

    // Act
    const bool actual = classUnderTest->IsEmpty();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GraphQlResponseTest, IsSuccessWhenResponseIsEmptyAndHasErrorsReturnsFalse)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"errors":[{}]})");
    classUnderTest->Deserialize(json);

    // Assumptions
    ASSERT_TRUE(classUnderTest->IsEmpty()) << "Assume response is empty";
    ASSERT_TRUE(classUnderTest->HasErrors()) << "Assume response has errors";

    // Act
    const bool actual = classUnderTest->IsSuccess();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GraphQlResponseTest, IsSuccessWhenResponseIsEmptyAndHasNoErrorsReturnsFalse)
{
    // Assumptions
    ASSERT_TRUE(classUnderTest->IsEmpty()) << "Assume response is empty";
    ASSERT_FALSE(classUnderTest->HasErrors()) << "Assume response has no errors";

    // Act
    const bool actual = classUnderTest->IsSuccess();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GraphQlResponseTest, IsSuccessWhenResponseIsNotEmptyAndHasErrorsReturnsFalse)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"data":{"result":true},"errors":[{}]})");
    classUnderTest->Deserialize(json);

    // Assumptions
    ASSERT_FALSE(classUnderTest->IsEmpty()) << "Assume response is not empty";
    ASSERT_TRUE(classUnderTest->HasErrors()) << "Assume response has errors";

    // Act
    const bool actual = classUnderTest->IsSuccess();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GraphQlResponseTest, IsSuccessWhenResponseIsNotEmptyAndHasNoErrorsReturnsTrue)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"data":{"result":true}})");
    classUnderTest->Deserialize(json);

    // Assumptions
    ASSERT_FALSE(classUnderTest->IsEmpty()) << "Assume response is not empty";
    ASSERT_FALSE(classUnderTest->HasErrors()) << "Assume response has no errors";

    // Act
    const bool actual = classUnderTest->IsSuccess();

    // Assert
    ASSERT_TRUE(actual);
}
