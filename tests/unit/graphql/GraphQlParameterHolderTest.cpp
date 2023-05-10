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
#include "gmock/gmock.h"
#include "MockSerializable.hpp"
#include "EnjinPlatformSdk/GraphQlParameterHolder.hpp"
#include <memory>

using namespace enjin::platform::sdk;
using namespace testing;

class GraphQlParameterHolderImpl : public GraphQlParameterHolder<GraphQlParameterHolderImpl>
{
public:
    GraphQlParameterHolderImpl() = default;

    ~GraphQlParameterHolderImpl() override = default;
};

class GraphQlParameterHolderTest : public Test
{
public:
    std::unique_ptr<GraphQlParameterHolderImpl> classUnderTest;

    // Mocks
    MockSerializablePtr mockValue;

protected:
    void SetUp() override
    {
        mockValue = std::make_shared<NiceMockSerializable>();

        classUnderTest = std::make_unique<GraphQlParameterHolderImpl>();
    }
};

TEST_F(GraphQlParameterHolderTest, CompileParametersWhenHolderHasNoParametersReturnsExpected)
{
    // Arrange
    const std::string expected;

    // Assumptions
    ASSERT_FALSE(classUnderTest->HasParameters()) << "Assume holder has no parameters";

    // Act
    const std::string actual = classUnderTest->CompileParameters();

    // Assert
    ASSERT_EQ(actual, expected) << "Assert actual equals expected";
}

TEST_F(GraphQlParameterHolderTest, CompileParametersWhenHolderHasParametersReturnsExpected)
{
    // Arrange - Data
    const std::string expected(R"(param: "value")");
    classUnderTest->SetParameter("param", mockValue);

    // Arrange - Stubbing
    EXPECT_CALL(*mockValue, ToString())
        .WillRepeatedly(Return(R"("value")"));

    // Assumptions
    ASSERT_TRUE(classUnderTest->HasParameters()) << "Assume holder has parameters";

    // Act
    const std::string actual = classUnderTest->CompileParameters();

    // Assert
    ASSERT_EQ(actual, expected) << "Assert actual equals expected";
}

TEST_F(GraphQlParameterHolderTest, HasParametersWhenHolderHasNoParametersReturnsFalse)
{
    // Act
    const bool actual = classUnderTest->HasParameters();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GraphQlParameterHolderTest, HasParametersWhenHolderHasParametersReturnsTrue)
{
    // Arrange
    classUnderTest->SetParameter("key", mockValue);

    // Act
    const bool actual = classUnderTest->HasParameters();

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GraphQlParameterHolderTest, RemoveParameterWhenHolderDoesNotHaveParameterDoesNotThrowError)
{
    // Arrange
    const std::string key("key");

    // Assumptions
    ASSERT_FALSE(classUnderTest->GetParameters().contains(key)) << "Assume holder does not have parameter";

    // Assert
    ASSERT_NO_THROW(classUnderTest->RemoveParameter(key)) << "Assert error is not thrown";
}

TEST_F(GraphQlParameterHolderTest, RemoveParameterWhenHolderHasParameterParameterIsRemoved)
{
    // Arrange
    const std::string key("key");
    classUnderTest->SetParameter(key, mockValue);

    // Assumptions
    ASSERT_TRUE(classUnderTest->GetParameters().contains(key)) << "Assume holder has parameter";

    // Act
    classUnderTest->RemoveParameter(key);

    // Assert
    ASSERT_FALSE(classUnderTest->GetParameters().contains(key)) << "Assert parameter was removed";
}
