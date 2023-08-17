#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonValueIntegerTest : public Test
{
};

TEST_F(JsonValueIntegerTest, FromJsonGivenIntegerJsonReturnsValueThatIsInt)
{
    // Arrange
    const std::string json("1");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsInt());
}

TEST_F(JsonValueIntegerTest, GetIntWhenValueIsNotAnIntThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(int32_t v = jsonValue.GetInt(), std::runtime_error);
}

TEST_F(JsonValueIntegerTest, GetIntWhenValueIsAnIntReturnsExpected)
{
    // Arrange
    const int32_t expected = 1;
    const std::string json("1");
    JsonValue jsonValue = JsonValue::FromJson(json);

    // Act
    const int32_t actual = jsonValue.GetInt();

    // Assert
    ASSERT_EQ(actual, expected);
}
