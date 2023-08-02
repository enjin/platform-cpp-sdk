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
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkBeam/ClaimStatus.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using namespace testing;

class ClaimStatusTest : public Test
{
};

class ClaimStatusToStringValidValueTest : public TestWithParam<std::pair<std::string, ClaimStatus>>
{
};

class ClaimStatusTryGetValidValueTest : public TestWithParam<ClaimStatus>
{
public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const ClaimStatus value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case ClaimStatus::Pending:
                json.TrySetStringField(key, "PENDING");
                break;

            case ClaimStatus::InProgress:
                json.TrySetStringField(key, "IN_PROGRESS");
                break;

            case ClaimStatus::Completed:
                json.TrySetStringField(key, "COMPLETED");
                break;

            case ClaimStatus::Failed:
                json.TrySetStringField(key, "FAILED");
                break;

            default:
                break;
        }

        return json;
    }
};

TEST_F(ClaimStatusTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (ClaimStatus) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(ClaimStatusTest, TryGetFieldWhenGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<ClaimStatus> outField = ClaimStatus::Pending;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(ClaimStatusTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<ClaimStatus> outField = ClaimStatus::Pending;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(ClaimStatusTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<ClaimStatus> outField = ClaimStatus::Pending;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(ClaimStatusToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const ClaimStatus value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(ClaimStatusTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const ClaimStatus expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<ClaimStatus> outField;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsFalse()) << "Assume that out field does not have a value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assert that out field has a value";
    ASSERT_THAT(outField.value(), Eq(expected)) << "Assert that out field value equals expected";
}

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         ClaimStatusToStringValidValueTest,
                         Values(std::pair<std::string, ClaimStatus>("PENDING", ClaimStatus::Pending),
                                std::pair<std::string, ClaimStatus>("IN_PROGRESS", ClaimStatus::InProgress),
                                std::pair<std::string, ClaimStatus>("COMPLETED", ClaimStatus::Completed),
                                std::pair<std::string, ClaimStatus>("FAILED", ClaimStatus::Failed)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         ClaimStatusTryGetValidValueTest,
                         Values(ClaimStatus::Pending,
                                ClaimStatus::InProgress,
                                ClaimStatus::Completed,
                                ClaimStatus::Failed));
