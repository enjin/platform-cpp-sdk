#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <stdexcept>
#include <string>
#include <vector>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonValueObjectTest : public Test
{
public:
    static constexpr char EmptyObject[] = "{}";
};

TEST_F(JsonValueObjectTest, FromJsonGivenJsonObjectReturnsValueThatIsObject)
{
    // Arrange
    const std::string json("{}");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.IsObject());
}

TEST_F(JsonValueObjectTest, GetArrayFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const std::vector<JsonValue> actual = jsonValue.GetArrayField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetArrayFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const std::vector<JsonValue> actual = jsonValue.GetArrayField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetArrayFieldWhenFieldIsNotAnArrayThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const std::vector<JsonValue> actual = jsonValue.GetArrayField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetArrayFieldWhenFieldIsAnArrayReturnsExpected)
{
    // Arrange
    constexpr int32_t expectedEl = 1;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":[1,1,1]})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Act
    const std::vector<JsonValue> actual = jsonValue.GetArrayField(key);

    // Assert
    for (const JsonValue& el : actual)
    {
        EXPECT_EQ(el.GetInt(), expectedEl) << "Expect array element equals";
    }
}

TEST_F(JsonValueObjectTest, GetBoolFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const bool actual = jsonValue.GetBoolField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetBoolFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const bool actual = jsonValue.GetBoolField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetBoolFieldWhenFieldIsNotABoolThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const bool actual = jsonValue.GetBoolField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetBoolFieldWhenFieldIsABoolReturnsExpected)
{
    // Arrange
    constexpr bool expected = true;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":true})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Act
    const bool actual = jsonValue.GetBoolField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueObjectTest, GetDoubleFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const double actual = jsonValue.GetDoubleField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetDoubleFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const double actual = jsonValue.GetDoubleField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetDoubleFieldWhenFieldIsNotADoubleThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const double actual = jsonValue.GetDoubleField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetDoubleFieldWhenFieldIsADoubleReturnsExpected)
{
    // Arrange
    constexpr double expected = 1.0;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":1.0})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Act
    const double actual = jsonValue.GetDoubleField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueObjectTest, GetFloatFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const float actual = jsonValue.GetFloatField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetFloatFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const float actual = jsonValue.GetFloatField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetFloatFieldWhenFieldIsNotAFloatThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const float actual = jsonValue.GetFloatField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetFloatFieldWhenFieldIsAFloatReturnsExpected)
{
    // Arrange
    constexpr float expected = 1.0;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":1.0})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Act
    const float actual = jsonValue.GetFloatField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueObjectTest, GetIntFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const int32_t actual = jsonValue.GetIntField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetIntFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const int32_t actual = jsonValue.GetIntField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetIntFieldWhenFieldIsNotAnIntegerThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const int32_t actual = jsonValue.GetIntField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetIntFieldWhenFieldIsAnIntegerReturnsExpected)
{
    // Arrange
    constexpr int32_t expected = 1;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":1})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Act
    const int32_t actual = jsonValue.GetIntField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueObjectTest, GetObjectFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const JsonValue actual = jsonValue.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetObjectFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const JsonValue actual = jsonValue.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetObjectFieldWhenFieldIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const JsonValue actual = jsonValue.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetObjectFieldWhenFieldIsAnObjectReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson(R"({"innerKey":"innerValue"})");
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":{"innerKey":"innerValue"}})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Act
    const JsonValue actual = jsonValue.GetObjectField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueObjectTest, GetStringFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const std::string actual = jsonValue.GetStringField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetStringFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const std::string actual = jsonValue.GetStringField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetStringFieldWhenFieldIsNotAStringThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const std::string actual = jsonValue.GetStringField(key), std::runtime_error);
}

TEST_F(JsonValueObjectTest, GetStringFieldWhenFieldIsAStringReturnsExpected)
{
    // Arrange
    const std::string expected("value");
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":"value"})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Act
    const std::string actual = jsonValue.GetStringField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueObjectTest, HasObjectFieldWhenJsonValueIsNotAnObjectReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Act
    const bool actual = jsonValue.HasObjectField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueObjectTest, HasObjectFieldWhenJsonObjectDoesHaveFieldReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Act
    const bool actual = jsonValue.HasObjectField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueObjectTest, HasObjectFieldWhenJsonObjectHasFieldReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Act
    const bool actual = jsonValue.HasObjectField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueObjectTest, TryGetArrayFieldWhenFieldIsNotPresentReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetArrayFieldWhenFieldIsNotAnArrayReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetArrayFieldWhenFieldIsAnArrayReturnsExpectedArray)
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

TEST_F(JsonValueObjectTest, TryGetBoolFieldWhenFieldIsNotPresentReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetBoolFieldWhenFieldIsNotABoolReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetBoolFieldWhenFieldIsAStringReturnsExpectedValue)
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

TEST_F(JsonValueObjectTest, TryGetDoubleFieldWhenFieldIsNotPresentReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetDoubleFieldWhenFieldIsNotADoubleReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetDoubleFieldWhenFieldIsADoubleReturnsExpectedValue)
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

TEST_F(JsonValueObjectTest, TryGetFloatFieldWhenFieldIsNotPresentReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetFloatFieldWhenFieldIsNotAFloatReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetFloatFieldWhenFieldIsAFloatReturnsExpectedValue)
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

TEST_F(JsonValueObjectTest, TryGetIntFieldWhenFieldIsNotPresentReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetIntFieldWhenFieldIsNotAnIntegerReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetIntFieldWhenFieldIsAnIntegerReturnsExpectedValue)
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

TEST_F(JsonValueObjectTest, TryGetObjectFieldWhenFieldIsNotPresentReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetObjectFieldWhenFieldIsNotAnObjectReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetObjectFieldWhenFieldIsAnObjectReturnsExpectedObject)
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

TEST_F(JsonValueObjectTest, TryGetStringFieldWhenFieldIsNotPresentReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetStringFieldWhenFieldIsNotAStringReturnsFalse)
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

TEST_F(JsonValueObjectTest, TryGetStringFieldWhenFieldIsAStringReturnsExpectedValue)
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

TEST_F(JsonValueObjectTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsBoolSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const bool expectedValue = true;
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetObjectField(expectedKey, expectedValue);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(jsonObject.GetBoolField(expectedKey), expectedValue) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsDoubleSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const double expectedValue = 1.0;
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetObjectField(expectedKey, expectedValue);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(jsonObject.GetDoubleField(expectedKey), expectedValue) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsFloatSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const float expectedValue = 1.0;
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetObjectField(expectedKey, expectedValue);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(jsonObject.GetFloatField(expectedKey), expectedValue) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsIntegerSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const int32_t expectedValue = 1;
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetObjectField(expectedKey, expectedValue);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(jsonObject.GetIntField(expectedKey), expectedValue) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsStringSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const std::string expectedValue("value");
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetObjectField(expectedKey, expectedValue);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(jsonObject.GetStringField(expectedKey), expectedValue) << "Expect object has value";
}
