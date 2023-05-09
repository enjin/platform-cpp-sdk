#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <stdexcept>
#include <string>
#include <vector>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonValueArrayTest : public Test
{
public:
    static constexpr char EmptyArray[] = "[]";
    static constexpr char Null[] = "null";
};

TEST_F(JsonValueArrayTest, AddArrayElementWhenValueIsNotAnArrayDoesNotThrowError)
{
    // Arrange
    const JsonValue element = JsonValue::FromJson(Null);
    JsonValue jsonValue;

    // Assumptions
    ASSERT_FALSE(jsonValue.IsArray()) << "Assume value is not an array";

    // Assert
    ASSERT_NO_THROW(jsonValue.AddArrayElement(element)) << "Assert error is not thrown";
}

TEST_F(JsonValueArrayTest, AddArrayElementWhenValueIsAnArrayAddsElementToArray)
{
    // Arrange
    const JsonValue element = JsonValue::FromJson(Null);
    JsonValue jsonValue = JsonValue::FromJson(EmptyArray);

    // Assumptions
    ASSERT_TRUE(jsonValue.IsArray()) << "Assume value is an array";

    // Act
    jsonValue.AddArrayElement(element);

    // Assert
    const std::vector<JsonValue>& elements = jsonValue.GetArray();
    ASSERT_FALSE(elements.empty()) << "Assert array is not empty";
    ASSERT_EQ(elements[0], element) << "Assert array contains element";
}

TEST_F(JsonValueArrayTest, GetArrayWhenValueIsNotAnArrayThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(std::vector<JsonValue> v = jsonValue.GetArray(), std::runtime_error);
}

TEST_F(JsonValueArrayTest, GetArrayWhenValueIsAnArrayReturnsExpected)
{
    // Arrange
    const std::vector<JsonValue> expected = {JsonValue()};
    const std::string json("[null]");
    JsonValue jsonValue = JsonValue::FromJson(json);

    // Act
    const std::vector<JsonValue> actual = jsonValue.GetArray();

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueArrayTest, FromJsonGivenJsonArrayReturnsValueThatIsArray)
{
    // Arrange
    const std::string json(EmptyArray);

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsArray());
}

TEST_F(JsonValueArrayTest, RemoveArrayElementWhenValueIsNotAnArrayDoesNotThrowError)
{
    // Arrange
    const int index = 0;
    JsonValue jsonValue;

    // Assumptions
    ASSERT_FALSE(jsonValue.IsArray()) << "Assume value is not an array";

    // Assert
    ASSERT_NO_THROW(jsonValue.RemoveArrayElement(index)) << "Assert error is not thrown";
}

TEST_F(JsonValueArrayTest, RemoveArrayElementWhenValueIsAnArrayAndIndexIsNegativeThrowsError)
{
    // Arrange
    const int index = -1;
    JsonValue jsonValue = JsonValue::FromJson(EmptyArray);

    // Assumptions
    ASSERT_TRUE(jsonValue.IsArray()) << "Assume value is an array";

    // Assert
    ASSERT_THROW(jsonValue.RemoveArrayElement(index), std::out_of_range) << "Assert error is thrown";
}

TEST_F(JsonValueArrayTest, RemoveArrayElementWhenValueIsAnArrayAndElementIsNotPresentThrowsError)
{
    // Arrange
    const int index = 0;
    JsonValue jsonValue = JsonValue::FromJson(EmptyArray);

    // Assumptions
    ASSERT_TRUE(jsonValue.IsArray()) << "Assume value is an array";

    // Assert
    ASSERT_THROW(jsonValue.RemoveArrayElement(index), std::out_of_range) << "Assert error is thrown";
}

TEST_F(JsonValueArrayTest, RemoveArrayElementWhenValueIsAnArrayAndElementIsPresentRemovesElement)
{
    // Arrange
    const int index = 0;
    const JsonValue element = JsonValue::FromJson(Null);
    JsonValue jsonValue = JsonValue::FromJson(EmptyArray);
    jsonValue.AddArrayElement(element);

    // Assumptions
    ASSERT_FALSE(jsonValue.GetArray().empty()) << "Assume array is not empty";

    // Act
    jsonValue.RemoveArrayElement(index);

    // Assert
    ASSERT_TRUE(jsonValue.GetArray().empty()) << "Assert array is empty";
}
