#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonValueBoolTest : public Test
{
};

TEST_F(JsonValueBoolTest, FromJsonGivenBooleanJsonReturnsValueThatIsBool)
{
    // Arrange
    const std::string json("true");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsBool());
}

TEST_F(JsonValueBoolTest, GetBoolWhenValueIsNotABoolThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(bool v = jsonValue.GetBool(), std::runtime_error);
}

TEST_F(JsonValueBoolTest, GetBoolWhenValueIsABoolReturnsExpected)
{
    // Arrange
    const bool expected = true;
    const std::string json("true");
    JsonValue jsonValue = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonValue.GetBool();

    // Assert
    ASSERT_EQ(actual, expected);
}
