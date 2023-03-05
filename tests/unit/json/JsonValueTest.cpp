#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <string>
#include <vector>

using namespace enjin::platform::sdk::json;
using namespace testing;

class JsonValueTest : public Test
{
};

class JsonValueFromInvalidJsonTest : public TestWithParam<std::string>
{
};

TEST_F(JsonValueTest, TryGetArrayFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    std::vector<JsonValue> outArray = {JsonValue()};
    const std::vector<JsonValue> expectedArray = outArray;

    // Act
    const bool result = jsonObject.TryGetArrayField(key, outArray);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outArray, expectedArray) << "Expect out array is unchanged";
}

TEST_F(JsonValueTest, TryGetArrayFieldWhenFieldIsNotAnArrayReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    std::vector<JsonValue> outArray = {JsonValue()};
    const std::vector<JsonValue> expectedArray = outArray;

    // Act
    const bool result = jsonObject.TryGetArrayField(key, outArray);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outArray, expectedArray) << "Expect out array is unchanged";
}

TEST_F(JsonValueTest, TryGetArrayFieldWhenFieldIsAnArrayReturnsExpectedArray)
{
    // Arrange
    const std::vector<JsonValue> expectedArray = {JsonValue()};
    const std::string key("key");
    const std::string json(R"({"key":[null]})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    std::vector<JsonValue> outArray;

    // Act
    const bool result = jsonObject.TryGetArrayField(key, outArray);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outArray, expectedArray) << "Expect out array equals expected";
}

TEST_F(JsonValueTest, TryGetBoolFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    bool outBool = false;
    const bool expectedBool = outBool;

    // Act
    const bool result = jsonObject.TryGetBoolField(key, outBool);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outBool, expectedBool) << "Expect out boolean is unchanged";
}

TEST_F(JsonValueTest, TryGetBoolFieldWhenFieldIsNotABoolReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    bool outBool = false;
    const bool expectedBool = outBool;

    // Act
    const bool result = jsonObject.TryGetBoolField(key, outBool);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outBool, expectedBool) << "Expect out boolean is unchanged";
}

TEST_F(JsonValueTest, TryGetBoolFieldWhenFieldIsAStringReturnsExpectedValue)
{
    // Arrange
    const bool expectedBool = true;
    const std::string key("key");
    const std::string json(R"({"key":true})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    bool outBool;

    // Act
    const bool result = jsonObject.TryGetBoolField(key, outBool);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outBool, expectedBool) << "Expect out boolean equals expected";
}

TEST_F(JsonValueTest, TryGetDoubleFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    double outDouble = 0.0;
    const double expectedDouble = outDouble;

    // Act
    const bool result = jsonObject.TryGetDoubleField(key, outDouble);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outDouble, expectedDouble) << "Expect out double is unchanged";
}

TEST_F(JsonValueTest, TryGetDoubleFieldWhenFieldIsNotADoubleReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    double outDouble = 0.0;
    const double expectedDouble = outDouble;

    // Act
    const bool result = jsonObject.TryGetDoubleField(key, outDouble);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outDouble, expectedDouble) << "Expect out double is unchanged";
}

TEST_F(JsonValueTest, TryGetDoubleFieldWhenFieldIsADoubleReturnsExpectedValue)
{
    // Arrange
    const double expectedDouble = 1.0;
    const std::string key("key");
    const std::string json(R"({"key":1.0})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    double outDouble;

    // Act
    const bool result = jsonObject.TryGetDoubleField(key, outDouble);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outDouble, expectedDouble) << "Expect out double equals expected";
}

TEST_F(JsonValueTest, TryGetFloatFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    float outFloat = 0.0;
    const float expectedFloat = outFloat;

    // Act
    const bool result = jsonObject.TryGetFloatField(key, outFloat);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outFloat, expectedFloat) << "Expect out float is unchanged";
}

TEST_F(JsonValueTest, TryGetFloatFieldWhenFieldIsNotAFloatReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    float outFloat = 0.0;
    const float expectedFloat = outFloat;

    // Act
    const bool result = jsonObject.TryGetFloatField(key, outFloat);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outFloat, expectedFloat) << "Expect out float is unchanged";
}

TEST_F(JsonValueTest, TryGetFloatFieldWhenFieldIsAFloatReturnsExpectedValue)
{
    // Arrange
    const float expectedFloat = 1.0;
    const std::string key("key");
    const std::string json(R"({"key":1.0})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    float outFloat;

    // Act
    const bool result = jsonObject.TryGetFloatField(key, outFloat);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outFloat, expectedFloat) << "Expect out float equals expected";
}

TEST_F(JsonValueTest, TryGetIntFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    int32_t outInt = 0;
    const int32_t expectedInt = outInt;

    // Act
    const bool result = jsonObject.TryGetIntField(key, outInt);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outInt, expectedInt) << "Expect out integer is unchanged";
}

TEST_F(JsonValueTest, TryGetIntFieldWhenFieldIsNotAnIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    int32_t outInt = 0;
    const int32_t expectedInt = outInt;

    // Act
    const bool result = jsonObject.TryGetIntField(key, outInt);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outInt, expectedInt) << "Expect out integer is unchanged";
}

TEST_F(JsonValueTest, TryGetIntFieldWhenFieldIsAnIntegerReturnsExpectedValue)
{
    // Arrange
    const int32_t expectedInt = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    int32_t outInt;

    // Act
    const bool result = jsonObject.TryGetIntField(key, outInt);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outInt, expectedInt) << "Expect out integer equals expected";
}

TEST_F(JsonValueTest, TryGetInt64FieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    int64_t outInt64 = 0;
    const int64_t expectedInt64 = outInt64;

    // Act
    const bool result = jsonObject.TryGetInt64Field(key, outInt64);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outInt64, expectedInt64) << "Expect out long integer is unchanged";
}

TEST_F(JsonValueTest, TryGetInt64FieldWhenFieldIsNotALongIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    int64_t outInt64 = 0;
    const int64_t expectedInt64 = outInt64;

    // Act
    const bool result = jsonObject.TryGetInt64Field(key, outInt64);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outInt64, expectedInt64) << "Expect out long integer is unchanged";
}

TEST_F(JsonValueTest, TryGetInt64FieldWhenFieldIsALongIntegerReturnsExpectedValue)
{
    // Arrange
    const int64_t expectedInt64 = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    int64_t outInt64;

    // Act
    const bool result = jsonObject.TryGetInt64Field(key, outInt64);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outInt64, expectedInt64) << "Expect out long integer equals expected";
}

TEST_F(JsonValueTest, TryGetObjectFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    JsonValue outValue = JsonValue::FromJson("{}");
    const JsonValue expectedValue(outValue);

    // Act
    const bool result = jsonObject.TryGetObjectField(key, outValue);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outValue, expectedValue) << "Expect out value is unchanged";
}

TEST_F(JsonValueTest, TryGetObjectFieldWhenFieldIsNotAnObjectReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    JsonValue outValue = JsonValue::FromJson("{}");
    const JsonValue expectedValue(outValue);

    // Act
    const bool result = jsonObject.TryGetObjectField(key, outValue);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outValue, expectedValue) << "Expect out value is unchanged";
}

TEST_F(JsonValueTest, TryGetObjectFieldWhenFieldIsAnObjectReturnsExpectedObject)
{
    // Arrange
    const JsonValue expectedValue = JsonValue::FromJson(R"({"innerKey":"innerValue"})");
    const std::string key("key");
    const std::string json(R"({"key":{"innerKey":"innerValue"}})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    JsonValue outValue;

    // Act
    const bool result = jsonObject.TryGetObjectField(key, outValue);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outValue, expectedValue) << "Expect out value equals expected";
}

TEST_F(JsonValueTest, TryGetStringFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    std::string outString;
    const std::string expectedString(outString);

    // Act
    const bool result = jsonObject.TryGetStringField(key, outString);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outString, expectedString) << "Expect out string is unchanged";
}

TEST_F(JsonValueTest, TryGetStringFieldWhenFieldIsNotAStringReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    std::string outString;
    const std::string expectedString(outString);

    // Act
    const bool result = jsonObject.TryGetStringField(key, outString);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outString, expectedString) << "Expect out string is unchanged";
}

TEST_F(JsonValueTest, TryGetStringFieldWhenFieldIsAStringReturnsExpectedValue)
{
    // Arrange
    const std::string expectedString("value");
    const std::string key("key");
    const std::string json(R"({"key":"value"})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    std::string outString;

    // Act
    const bool result = jsonObject.TryGetStringField(key, outString);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outString, expectedString) << "Expect out string equals expected";
}

TEST_F(JsonValueTest, TryGetUintFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    uint32_t outUint = 0;
    const uint32_t expectedUint = outUint;

    // Act
    const bool result = jsonObject.TryGetUintField(key, outUint);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outUint, expectedUint) << "Expect out unsigned integer is unchanged";
}

TEST_F(JsonValueTest, TryGetUintFieldWhenFieldIsNotAnUnsingedIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    uint32_t outUint = 0;
    const uint32_t expectedUint = outUint;

    // Act
    const bool result = jsonObject.TryGetUintField(key, outUint);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outUint, expectedUint) << "Expect out unsigned integer is unchanged";
}

TEST_F(JsonValueTest, TryGetUintFieldWhenFieldIsAnUnsingedIntegerReturnsExpectedValue)
{
    // Arrange
    const uint32_t expectedUint = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    uint32_t outUint = 0;

    // Act
    const bool result = jsonObject.TryGetUintField(key, outUint);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outUint, expectedUint) << "Expect out unsigned integer equals expected";
}

TEST_F(JsonValueTest, TryGetUint64FieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    uint64_t outUint64 = 0;
    const uint64_t expectedUint64 = outUint64;

    // Act
    const bool result = jsonObject.TryGetUint64Field(key, outUint64);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outUint64, expectedUint64) << "Expect out unsigned long integer is unchanged";
}

TEST_F(JsonValueTest, TryGetUint64FieldWhenFieldIsNotAnUnsingedLongIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    uint64_t outUint64 = 0;
    const uint64_t expectedUint64 = outUint64;

    // Act
    const bool result = jsonObject.TryGetUint64Field(key, outUint64);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outUint64, expectedUint64) << "Expect out unsigned long integer is unchanged";
}

TEST_F(JsonValueTest, TryGetUint64FieldWhenFieldIsAnUnsingedLongIntegerReturnsExpectedValue)
{
    // Arrange
    const uint64_t expectedUint64 = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    uint64_t outUint64 = 0;

    // Act
    const bool result = jsonObject.TryGetUint64Field(key, outUint64);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outUint64, expectedUint64) << "Expect out unsigned long integer equals expected";
}

TEST_F(JsonValueTest, FromJsonGivenJsonArrayReturnsValueThatIsArray)
{
    // Arrange
    const std::string json("[]");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsArray());
}

TEST_F(JsonValueTest, FromJsonGivenBooleanJsonReturnsValueThatIsBool)
{
    // Arrange
    const std::string json("true");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsBool());
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

TEST_F(JsonValueTest, FromJsonGivenNumberJsonReturnsValueThatIsNumber)
{
    // Arrange
    const std::string json("0");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsNumber());
}

TEST_F(JsonValueTest, FromJsonGivenJsonObjectReturnsValueThatIsObject)
{
    // Arrange
    const std::string json("{}");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsObject());
}

TEST_F(JsonValueTest, FromJsonGivenStringJsonReturnsValueThatIsString)
{
    // Arrange
    const std::string json(R"("")");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsString());
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

INSTANTIATE_TEST_SUITE_P(InvalidJsonFormats,
                         JsonValueFromInvalidJsonTest,
                         Values("", "abc", "[}", "{]"));
