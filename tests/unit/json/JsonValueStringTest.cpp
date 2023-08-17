#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonValueStringTest : public Test
{
};

TEST_F(JsonValueStringTest, FromJsonGivenStringJsonReturnsValueThatIsString)
{
    // Arrange
    const std::string json(R"("")");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsString());
}

TEST_F(JsonValueStringTest, GetStringWhenValueIsNotAStringThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(std::string v = jsonValue.GetString(), std::runtime_error);
}

TEST_F(JsonValueStringTest, GetStringWhenValueIsAStringReturnsExpected)
{
    // Arrange
    const std::string expected("xyz");
    const std::string json(R"("xyz")");
    JsonValue jsonValue = JsonValue::FromJson(json);

    // Act
    const std::string actual = jsonValue.GetString();

    // Assert
    ASSERT_EQ(actual, expected);
}
