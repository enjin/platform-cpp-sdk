#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/JsonValueType.hpp"
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonValueTest : public Test
{
public:
    static constexpr char EmptyObject[] = "{}";
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

TEST_F(JsonValueTest, GetArrayWhenValueIsNotAnArrayThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(std::vector<JsonValue> v = jsonValue.GetArray(), std::runtime_error);
}

TEST_F(JsonValueTest, GetArrayWhenValueIsAnArrayReturnsExpected)
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

TEST_F(JsonValueTest, GetArrayFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const std::vector<JsonValue> actual = jsonValue.GetArrayField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetArrayFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const std::vector<JsonValue> actual = jsonValue.GetArrayField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetArrayFieldWhenFieldIsNotAnArrayThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const std::vector<JsonValue> actual = jsonValue.GetArrayField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetArrayFieldWhenFieldIsAnArrayReturnsExpected)
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

TEST_F(JsonValueTest, GetBoolWhenValueIsNotABoolThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(bool v = jsonValue.GetBool(), std::runtime_error);
}

TEST_F(JsonValueTest, GetBoolWhenValueIsABoolReturnsExpected)
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

TEST_F(JsonValueTest, GetBoolFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const bool actual = jsonValue.GetBoolField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetBoolFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const bool actual = jsonValue.GetBoolField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetBoolFieldWhenFieldIsNotABoolThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const bool actual = jsonValue.GetBoolField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetBoolFieldWhenFieldIsABoolReturnsExpected)
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

TEST_F(JsonValueTest, GetDoubleWhenValueIsNotADoubleThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(double v = jsonValue.GetDouble(), std::runtime_error);
}

TEST_F(JsonValueTest, GetDoubleWhenValueIsADoubleReturnsExpected)
{
    // Arrange
    const double expected = 1.0;
    const std::string json("1.0");
    JsonValue jsonValue = JsonValue::FromJson(json);

    // Act
    const double actual = jsonValue.GetDouble();

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonValueTest, GetDoubleFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const double actual = jsonValue.GetDoubleField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetDoubleFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const double actual = jsonValue.GetDoubleField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetDoubleFieldWhenFieldIsNotADoubleThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const double actual = jsonValue.GetDoubleField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetDoubleFieldWhenFieldIsADoubleReturnsExpected)
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

TEST_F(JsonValueTest, GetFloatWhenValueIsNotAFloatThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(float v = jsonValue.GetFloat(), std::runtime_error);
}

TEST_F(JsonValueTest, GetFloatWhenValueIsAFloatReturnsExpected)
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

TEST_F(JsonValueTest, GetFloatFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const float actual = jsonValue.GetFloatField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetFloatFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const float actual = jsonValue.GetFloatField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetFloatFieldWhenFieldIsNotAFloatThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const float actual = jsonValue.GetFloatField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetFloatFieldWhenFieldIsAFloatReturnsExpected)
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

TEST_F(JsonValueTest, GetIntWhenValueIsNotAnIntThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(int32_t v = jsonValue.GetInt(), std::runtime_error);
}

TEST_F(JsonValueTest, GetIntWhenValueIsAnIntReturnsExpected)
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

TEST_F(JsonValueTest, GetIntegerFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const int32_t actual = jsonValue.GetIntField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetIntegerFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const int32_t actual = jsonValue.GetIntField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetIntegerFieldWhenFieldIsNotAnIntegerThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const int32_t actual = jsonValue.GetIntField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetIntegerFieldWhenFieldIsAnIntegerReturnsExpected)
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

TEST_F(JsonValueTest, GetObjectFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const JsonValue actual = jsonValue.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetObjectFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const JsonValue actual = jsonValue.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetObjectFieldWhenFieldIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const JsonValue actual = jsonValue.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetObjectFieldWhenFieldIsAnObjectReturnsExpected)
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

TEST_F(JsonValueTest, GetStringWhenValueIsNotAStringThrowsError)
{
    // Arrange
    JsonValue jsonValue;

    // Assert
    ASSERT_THROW(std::string v = jsonValue.GetString(), std::runtime_error);
}

TEST_F(JsonValueTest, GetStringWhenValueIsAStringReturnsExpected)
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

TEST_F(JsonValueTest, GetStringFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    EXPECT_FALSE(jsonValue.IsObject()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(const std::string actual = jsonValue.GetStringField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetStringFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    EXPECT_FALSE(jsonValue.HasObjectField(key)) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(const std::string actual = jsonValue.GetStringField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetStringFieldWhenFieldIsNotAStringThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    EXPECT_TRUE(jsonValue.HasObjectField(key)) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(const std::string actual = jsonValue.GetStringField(key), std::runtime_error);
}

TEST_F(JsonValueTest, GetStringFieldWhenFieldIsAStringReturnsExpected)
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

TEST_F(JsonValueTest, HasObjectFieldWhenJsonValueIsNotAnObjectReturnsFalse)
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

TEST_F(JsonValueTest, HasObjectFieldWhenJsonObjectDoesHaveFieldReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Act
    const bool actual = jsonValue.HasObjectField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonValueTest, HasObjectFieldWhenJsonObjectHasFieldReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Act
    const bool actual = jsonValue.HasObjectField(key);

    // Assert
    ASSERT_TRUE(actual);
}

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

TEST_F(JsonValueTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsBoolSetsField)
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

TEST_F(JsonValueTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsDoubleSetsField)
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

TEST_F(JsonValueTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsFloatSetsField)
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

TEST_F(JsonValueTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsIntegerSetsField)
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

TEST_F(JsonValueTest, TrySetObjectFieldWhenJsonIsJsonObjectAndValueIsStringSetsField)
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
