#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonValueFloatTest : public Test
{
};

TEST_F(JsonValueFloatTest, FromJsonGivenFloatJsonReturnsValueThatIsFloat)
{
    // Arrange
    const std::string json("1.0");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsFloat());
}

TEST_F(JsonValueFloatTest, GetFloatWhenValueIsNotAFloatThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(float v = jsonValue.GetFloat(), std::runtime_error);
}

TEST_F(JsonValueFloatTest, GetFloatWhenValueIsAFloatReturnsExpected)
{
    // Arrange
    const float expected = 1.0;
    const std::string json("1.0");
    JsonValue jsonValue = JsonValue::FromJson(json);

    // Act
    const float actual = jsonValue.GetFloat();

    // Assert
    ASSERT_EQ(actual, expected);
}
