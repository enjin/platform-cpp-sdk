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
#include "EnjinPlatformSdk/TransactionState.hpp"
#include <optional>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class TransactionStateTest : public Test
{
};

class TransactionStateValidValueTest : public TestWithParam<TransactionState>
{
public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const TransactionState value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case TransactionState::Abandoned:
                json.TrySetStringField(key, "ABANDONED");
                break;

            case TransactionState::Pending:
                json.TrySetStringField(key, "PENDING");
                break;

            case TransactionState::Processing:
                json.TrySetStringField(key, "PROCESSING");
                break;

            case TransactionState::Broadcast:
                json.TrySetStringField(key, "BROADCAST");
                break;

            case TransactionState::Executed:
                json.TrySetStringField(key, "EXECUTED");
                break;

            case TransactionState::Finalized:
                json.TrySetStringField(key, "FINALIZED");
                break;

            default:
                break;
        }

        return json;
    }
};

TEST_F(TransactionStateTest, TryGetFieldWhenGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<TransactionState> outField = TransactionState::Abandoned;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(TransactionStateTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<TransactionState> outField = TransactionState::Abandoned;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(TransactionStateTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<TransactionState> outField = TransactionState::Abandoned;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(TransactionStateValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const TransactionState expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<TransactionState> outField;

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
                         TransactionStateValidValueTest,
                         Values(TransactionState::Abandoned,
                                TransactionState::Pending,
                                TransactionState::Processing,
                                TransactionState::Broadcast,
                                TransactionState::Executed,
                                TransactionState::Finalized));
