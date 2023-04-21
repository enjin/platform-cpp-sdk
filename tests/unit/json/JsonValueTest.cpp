#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/JsonValueType.hpp"
#include <string>
#include <utility>

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

TEST_F(JsonValueTest, FromJsonGivenNullJsonReturnsValueThatIsNull)
{
    // Arrange
    const std::string json("null");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsNull());
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
