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
#include "EnjinPlatformSdk/JsonValueType.hpp"
#include <string>
#include <utility>
#include <vector>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonValueTest : public Test
{
};

class JsonValueFromInvalidJsonTest : public TestWithParam<std::string>
{
};

class JsonValueTypeTest : public TestWithParam<std::pair<JsonValueType, std::string>>
{
};

TEST_F(JsonValueTest, EqualityWhenJsonValuesAreNotEqualReturnsFalse)
{
    // Arrange
    const JsonValue lhs = JsonValue::FromJson(R"({"key":"abc"})");
    const JsonValue rhs = JsonValue::FromJson(R"({"key":"xyz"})");

    // Act
    const bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, EqualityWhenJsonValuesAreEqualReturnsTrue)
{
    // Arrange
    const JsonValue lhs = JsonValue::FromJson(R"({"key":"abc"})");
    const JsonValue rhs = JsonValue::FromJson(R"({"key":"abc"})");

    // Act
    const bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, FromArrayReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson("[1,1,1]");
    const std::vector<JsonValue> value =
        {
            JsonValue::FromJson("1"),
            JsonValue::FromJson("1"),
            JsonValue::FromJson("1"),
        };

    // Act
    const JsonValue actual = JsonValue::FromArray(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_F(JsonValueTest, FromBoolGivenFalseReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson("false");
    const bool value = false;

    // Act
    const JsonValue actual = JsonValue::FromBool(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_F(JsonValueTest, FromBoolGivenTrueReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson("true");
    const bool value = true;

    // Act
    const JsonValue actual = JsonValue::FromBool(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_F(JsonValueTest, FromDoubleReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson("1.0");
    const double value = 1.0;

    // Act
    const JsonValue actual = JsonValue::FromDouble(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_F(JsonValueTest, FromFloatReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson("1.0");
    const float value = 1;

    // Act
    const JsonValue actual = JsonValue::FromFloat(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_F(JsonValueTest, FromIntReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson("1");
    const int32_t value = 1;

    // Act
    const JsonValue actual = JsonValue::FromInt(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_F(JsonValueTest, FromJsonGivenNullJsonReturnsValueThatIsNull)
{
    // Arrange
    const std::string json("null");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsNull());
}

TEST_F(JsonValueTest, FromStringReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson(R"("xyz")");
    const std::string value("xyz");

    // Act
    const JsonValue actual = JsonValue::FromString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(JsonValueFromInvalidJsonTest, FromJsonGivenInvalidJsonReturnsNullJsonValue)
{
    // Arrange
    const std::string json = GetParam();

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsNull());
}

TEST_P(JsonValueTypeTest, GetValueTypeWhenValueIsOfTypeReturnsExpected)
{
    // Arrange
    const JsonValueType expected = GetParam().first;
    const JsonValue jsonValue = JsonValue::FromJson(GetParam().second);

    // Act
    const JsonValueType actual = jsonValue.GetValueType();

    // Assert
    ASSERT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(InvalidJsonFormats,
                         JsonValueFromInvalidJsonTest,
                         Values("", "abc", "[}", "{]"));

INSTANTIATE_TEST_SUITE_P(MatchValueTypes,
                         JsonValueTypeTest,
                         Values(std::pair<JsonValueType, std::string>(JsonValueType::Null, "null"),
                                std::pair<JsonValueType, std::string>(JsonValueType::Array, "[]"),
                                std::pair<JsonValueType, std::string>(JsonValueType::Object, "{}"),
                                std::pair<JsonValueType, std::string>(JsonValueType::String, R"("")"),
                                std::pair<JsonValueType, std::string>(JsonValueType::Bool, "true"),
                                std::pair<JsonValueType, std::string>(JsonValueType::Number, "1")));
