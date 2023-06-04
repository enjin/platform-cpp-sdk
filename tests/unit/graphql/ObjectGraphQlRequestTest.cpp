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
#include "MockGraphQlFragment.hpp"
#include "MockSerializable.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <memory>
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class ObjectGraphQlRequestImpl : public GraphQlRequest<ObjectGraphQlRequestImpl, MockGraphQlFragment>
{
public:
    ObjectGraphQlRequestImpl()
        : GraphQlRequest<ObjectGraphQlRequestImpl, MockGraphQlFragment>("Request", GraphQlRequestType::Query)
    {
    }

    ~ObjectGraphQlRequestImpl() override = default;
};

class ObjectGraphQlRequestTest : public Test
{
public:
    std::unique_ptr<ObjectGraphQlRequestImpl> classUnderTest;

    // Mocks
    MockGraphQlFragmentPtr mockFragment;
    MockSerializablePtr mockParameterValue;

protected:
    void SetUp() override
    {
        mockFragment = std::make_shared<NiceMockGraphQlFragment>();
        mockParameterValue = std::make_shared<NiceMockSerializable>();

        classUnderTest = std::make_unique<ObjectGraphQlRequestImpl>();
    }
};

TEST_F(ObjectGraphQlRequestTest, CompileWhenRequestDoesNotHaveFragmentThrowsError)
{
    // Assumptions
    ASSERT_FALSE(classUnderTest->HasFragment()) << "Assume request does not have fragment";

    // Assert
    ASSERT_THROW(const std::string s = classUnderTest->Compile(), std::runtime_error) << "Assert error is thrown";
}

TEST_F(ObjectGraphQlRequestTest, CompileWhenRequestHasFragmentAndHasNoVariablesOrParametersReturnsExpected)
{
    // Arrange - Data
    const std::string expected(R"(query { result: Request { field } })");
    classUnderTest->SetFragment(mockFragment);

    // Arrange - Stubbing
    EXPECT_CALL(*mockFragment, CompileFields())
        .WillRepeatedly(Return("field"));

    // Assumptions
    ASSERT_TRUE(classUnderTest->HasFragment()) << "Assume request has fragment";

    // Act
    const std::string actual = classUnderTest->Compile();

    // Assert
    ASSERT_EQ(actual, expected) << "Assert actual equals expected";
}

TEST_F(ObjectGraphQlRequestTest, CompileWhenRequestHasFragmentAndFragmentHasParametersReturnsExpected)
{
    // Arrange - Data
    const std::string expected(R"(query { result: Request(param: "value") { field } })");
    classUnderTest->SetFragment(mockFragment);

    // Arrange - Stubbing
    EXPECT_CALL(*mockFragment, CompileFields())
        .WillRepeatedly(Return("field"));
    EXPECT_CALL(*mockFragment, CompileParameters())
        .WillRepeatedly(Return(R"(param: "value")"));
    EXPECT_CALL(*mockFragment, HasParameters())
        .WillRepeatedly(Return(true));

    // Assumptions
    ASSERT_TRUE(classUnderTest->HasFragment()) << "Assume request has fragment";
    ASSERT_TRUE(classUnderTest->HasParameters()) << "Assume request has parameters";

    // Act
    const std::string actual = classUnderTest->Compile();

    // Assert
    ASSERT_EQ(actual, expected) << "Assert actual equals expected";
}

TEST_F(ObjectGraphQlRequestTest, HasFragmentWhenRequestDoesNotHaveFragmentReturnsFalse)
{
    // Act
    const bool actual = classUnderTest->HasFragment();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(ObjectGraphQlRequestTest, HasFragmentWhenRequestHasFragmentReturnsTrue)
{
    // Arrange
    classUnderTest->SetFragment(mockFragment);

    // Act
    const bool actual = classUnderTest->HasFragment();

    // Assert
    ASSERT_TRUE(actual);
}
