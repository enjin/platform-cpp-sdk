#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk::json;
using namespace testing;

class JsonValueTest : public Test
{
};

class JsonValueFromInvalidJsonTest : public TestWithParam<std::string>
{
};

TEST_F(JsonValueTest, GetBoolFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(bool v = jsonObject.GetBoolField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetBoolFieldWhenFieldIsNotABooleanThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(bool v = jsonObject.GetBoolField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetBoolFieldWhenFieldIsABooleanReturnsExpectedValue)
{
    // Arrange
    const bool expected = true;
    const std::string key("key");
    const std::string json(R"({"key":true})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.GetBoolField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueTest, GetDoubleFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(double v = jsonObject.GetDoubleField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetDoubleFieldWhenFieldIsNotADoubleThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(double v = jsonObject.GetDoubleField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetDoubleFieldWhenFieldIsADoubleReturnsExpectedValue)
{
    // Arrange
    const double expected = 1.0;
    const std::string key("key");
    const std::string json(R"({"key":1.0})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const double actual = jsonObject.GetDoubleField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueTest, GetFloatFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(float v = jsonObject.GetFloatField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetFloatFieldWhenFieldIsNotAFloatThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(float v = jsonObject.GetFloatField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetFloatFieldWhenFieldIsAFloatReturnsExpectedValue)
{
    // Arrange
    const float expected = 1.0;
    const std::string key("key");
    const std::string json(R"({"key":1.0})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const float actual = jsonObject.GetFloatField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueTest, GetIntFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(int32_t v = jsonObject.GetIntField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetIntFieldWhenFieldIsNotAnIntegerThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(int32_t v = jsonObject.GetIntField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetIntFieldWhenFieldIsAnIntegerReturnsExpectedValue)
{
    // Arrange
    const int32_t expected = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const int32_t actual = jsonObject.GetIntField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueTest, GetInt64FieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(int64_t v = jsonObject.GetInt64Field(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetInt64FieldWhenFieldIsNotALongIntegerThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(int64_t v = jsonObject.GetInt64Field(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetInt64FieldWhenFieldIsALongIntegerReturnsExpectedValue)
{
    // Arrange
    const int64_t expected = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const int64_t actual = jsonObject.GetInt64Field(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueTest, GetObjectFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(JsonValue o = jsonObject.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetObjectFieldWhenFieldIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(JsonValue o = jsonObject.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetObjectFieldWhenFieldIsAnObjectReturnsExpectedObject)
{
    // Arrange
    const std::string expectedKey("innerKey");
    const std::string expectedValue("innerValue");
    const std::string key("key");
    const std::string json(R"({"key":{"innerKey":"innerValue"}})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const JsonValue actual = jsonObject.GetObjectField(key);

    // Assert
    ASSERT_TRUE(actual.HasStringField(expectedKey)) << "Assert object has expected key";
    ASSERT_EQ(actual.GetStringField(expectedKey), expectedValue) << "Assert object has expected value";
}

TEST_F(JsonValueTest, GetStringFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(std::string v = jsonObject.GetStringField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetStringFieldWhenFieldIsNotAStringThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(std::string v = jsonObject.GetStringField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetStringFieldWhenFieldIsAStringReturnsExpectedValue)
{
    // Arrange
    const std::string expected("value");
    const std::string key("key");
    const std::string json(R"({"key":"value"})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const std::string actual = jsonObject.GetStringField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueTest, GetUintFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(uint32_t v = jsonObject.GetUintField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetUintFieldWhenFieldIsNotAnUnsignedIntegerThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(uint32_t v = jsonObject.GetUintField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetUintFieldWhenFieldIsAnUnsignedIntegerReturnsExpectedValue)
{
    // Arrange
    const uint32_t expected = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const uint32_t actual = jsonObject.GetUintField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueTest, GetUint64FieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(uint64_t v = jsonObject.GetUint64Field(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetUint64FieldWhenFieldIsNotAnUnsignedLongIntegerThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Assert
    ASSERT_THROW(uint64_t v = jsonObject.GetUint64Field(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetUint64FieldWhenFieldIsAnUnsignedLongIntegerReturnsExpectedValue)
{
    // Arrange
    const uint64_t expected = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const uint64_t actual = jsonObject.GetUint64Field(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueTest, HasBoolFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasBoolField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasBoolFieldWhenFieldIsNotABooleanReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasBoolField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasBoolFieldWhenFieldIsABooleanReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":true})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasBoolField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, HasDoubleFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasDoubleField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasDoubleFieldWhenFieldIsNotADoubleReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasDoubleField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasDoubleFieldWhenFieldIsADoubleReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":1.0})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasDoubleField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, HasFloatFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasFloatField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasFloatFieldWhenFieldIsNotAFloatReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasFloatField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasFloatFieldWhenFieldIsAFloatReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":1.0})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasFloatField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, HasIntFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasIntField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasIntFieldWhenFieldIsNotAnIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasIntField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasIntFieldWhenFieldIsAnIntegerReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasIntField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, HasInt64FieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasInt64Field(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasInt64FieldWhenFieldIsNotALongIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasInt64Field(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasInt64FieldWhenFieldIsALongIntegerReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasInt64Field(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, HasNullFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasNullField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasNullFieldWhenFieldIsNullReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasNullField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, HasObjectFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasObjectField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasObjectFieldWhenFieldIsNotAnObjectReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasObjectField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasObjectFieldWhenFieldIsAnObjectReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":{}})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasObjectField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, HasStringFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasStringField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasStringFieldWhenFieldIsNotAStringReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasStringField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasStringFieldWhenFieldIsAStringReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":""})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasStringField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, HasUintFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasUintField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasUintFieldWhenFieldIsNotAnUnsignedIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasUintField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasUintFieldWhenFieldIsAnUnsignedIntegerReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasUintField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonValueTest, HasUint64FieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasUint64Field(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasUint64FieldWhenFieldIsNotAnUnsignedLongIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasUint64Field(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasUint64FieldWhenFieldIsAnUnsignedLongIntegerReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonValue jsonObject = JsonValue::FromJson(json);

    // Act
    const bool actual = jsonObject.HasUint64Field(key);

    // Assert
    ASSERT_TRUE(actual);
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
    JsonValue outObject = JsonValue::FromJson(R"({"key":"value"})");
    const JsonValue expectedObject(outObject);

    // Act
    const bool result = jsonObject.TryGetObjectField(key, outObject);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outObject, expectedObject) << "Expect out object is unchanged";
}

TEST_F(JsonValueTest, TryGetObjectFieldWhenFieldIsNotAnObjectReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    JsonValue outObject = JsonValue::FromJson(R"({"innerKey":"innerValue"})");
    const JsonValue expectedObject(outObject);

    // Act
    const bool result = jsonObject.TryGetObjectField(key, outObject);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outObject, expectedObject) << "Expect out object is unchanged";
}

TEST_F(JsonValueTest, TryGetObjectFieldWhenFieldIsAnObjectReturnsExpectedObject)
{
    // Arrange
    const std::string expectedKey("innerKey");
    const std::string expectedValue("innerValue");
    const std::string key("key");
    const std::string json(R"({"key":{"innerKey":"innerValue"}})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    JsonValue outObject;

    // Act
    const bool result = jsonObject.TryGetObjectField(key, outObject);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    ASSERT_TRUE(outObject.HasStringField(expectedKey)) << "Assert object has expected key";
    ASSERT_EQ(outObject.GetStringField(expectedKey), expectedValue) << "Assert object has expected value";
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

TEST_F(JsonValueTest, FromJsonGivenValidJsonObjectReturnsExpectedObject)
{
    // Arrange
    const std::string expectedKey("key");
    const std::string expectedValue("value");
    const std::string json(R"({"key":"value"})");

    // Act
    const JsonValue actual = JsonValue::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.HasStringField(expectedKey)) << "Assert object has expected key";
    ASSERT_EQ(actual.GetStringField(expectedKey), expectedValue) << "Assert object has expected value";
}

TEST_P(JsonValueFromInvalidJsonTest, FromJsonGivenInvalidJsonThrowsError)
{
    // Arrange
    const std::string json = GetParam();

    // Assert
    ASSERT_THROW(JsonValue::FromJson(json), std::runtime_error);
}

INSTANTIATE_TEST_SUITE_P(InvalidJsonFormats,
                         JsonValueFromInvalidJsonTest,
                         Values("null", "1", "true", "false", R"("abc")", "[]"));
