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
#include "MockSerializable.hpp"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class GraphQlParameterImpl : public GraphQlParameter<GraphQlParameterImpl>
{
public:
    GraphQlParameterImpl() = default;

    ~GraphQlParameterImpl() override = default;
};

class GraphQlParameterTest : public Test
{
public:
    std::shared_ptr<GraphQlParameterImpl> classUnderTest;

    // Mocks
    MockSerializablePtr mockSerializable;

protected:
    void SetUp() override
    {
        Test::SetUp();

        mockSerializable = std::make_shared<NiceMockSerializable>();

        classUnderTest = std::make_shared<GraphQlParameterImpl>();
    }
};

TEST_F(GraphQlParameterTest, SetParameterWhenValueIsThisThrowsError)
{
    // Arrange
    const std::string key("key");

    // Assert
    ASSERT_THROW(classUnderTest->SetParameter(key, classUnderTest), std::invalid_argument);
}

TEST_F(GraphQlParameterTest, ToJsonWhenNoParametersAreSetReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson(R"({})");

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameters(), IsFalse()) << "Assume that parameter has no parameters";

    // Act
    const JsonValue actual = classUnderTest->ToJson();

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert actual equals expected";
}

TEST_F(GraphQlParameterTest, ToJsonWhenParametersAreSetReturnsExpected)
{
    // Arrange - Data
    const JsonValue expected = JsonValue::FromJson(R"({"key":"value"})");
    const std::string key("key");
    classUnderTest->SetParameter(key, mockSerializable);

    // Arrange - Stubbing
    EXPECT_CALL(*mockSerializable, ToJson())
        .WillRepeatedly(Return(JsonValue::FromJson(R"("value")")));

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameters(), IsTrue()) << "Assume that parameter has parameters";

    // Act
    const JsonValue actual = classUnderTest->ToJson();

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert actual equals expected";
}
