//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "gtest/gtest.h"
#include "gmock/gmock.h"
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
    ASSERT_THAT(actual.IsObject(), IsTrue());
}

TEST_F(JsonValueObjectTest, GetArrayFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    ASSERT_THAT(jsonValue.IsObject(), IsFalse()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetArrayField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetArrayFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsFalse()) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetArrayField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetArrayFieldWhenFieldIsNotAnArrayThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetArrayField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetArrayFieldWhenFieldIsAnArrayReturnsExpected)
{
    // Arrange
    constexpr int32_t expectedEl = 1;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":[1,1,1]})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Act
    const std::vector<JsonValue> actual = jsonValue.GetArrayField(key);

    // Assert
    for (const JsonValue& el : actual)
    {
        EXPECT_THAT(el.GetInt(), Eq(expectedEl)) << "Expect array element equals";
    }
}

TEST_F(JsonValueObjectTest, GetBoolFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    ASSERT_THAT(jsonValue.IsObject(), IsFalse()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetBoolField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetBoolFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsFalse()) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetBoolField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetBoolFieldWhenFieldIsNotABoolThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetBoolField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetBoolFieldWhenFieldIsABoolReturnsExpected)
{
    // Arrange
    constexpr bool expected = true;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":true})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Act
    const bool actual = jsonValue.GetBoolField(key);

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert that actual equals expected";
}

TEST_F(JsonValueObjectTest, GetDoubleFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    ASSERT_THAT(jsonValue.IsObject(), IsFalse()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetDoubleField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetDoubleFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsFalse()) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetDoubleField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetDoubleFieldWhenFieldIsNotADoubleThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetDoubleField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetDoubleFieldWhenFieldIsADoubleReturnsExpected)
{
    // Arrange
    constexpr double expected = 1.0;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":1.0})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Act
    const double actual = jsonValue.GetDoubleField(key);

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert that actual equals expected";
}

TEST_F(JsonValueObjectTest, GetFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    ASSERT_THAT(jsonValue.IsObject(), IsFalse()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsFalse()) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetFieldWhenFieldIsAnObjectReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromJson(R"({"innerKey":"innerValue"})");
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":{"innerKey":"innerValue"}})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Act
    const JsonValue actual = jsonValue.GetField(key);

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert that actual equals expected";
}

TEST_F(JsonValueObjectTest, GetFloatFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    ASSERT_THAT(jsonValue.IsObject(), IsFalse()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetFloatField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetFloatFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsFalse()) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetFloatField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetFloatFieldWhenFieldIsNotAFloatThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetFloatField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetFloatFieldWhenFieldIsAFloatReturnsExpected)
{
    // Arrange
    constexpr float expected = 1.0;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":1.0})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Act
    const float actual = jsonValue.GetFloatField(key);

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert that actual equals expected";
}

TEST_F(JsonValueObjectTest, GetIntFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    ASSERT_THAT(jsonValue.IsObject(), IsFalse()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetIntField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetIntFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsFalse()) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetIntField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetIntFieldWhenFieldIsNotAnIntegerThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetIntField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetIntFieldWhenFieldIsAnIntegerReturnsExpected)
{
    // Arrange
    constexpr int32_t expected = 1;
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":1})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Act
    const int32_t actual = jsonValue.GetIntField(key);

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert that actual equals expected";
}

TEST_F(JsonValueObjectTest, GetStringFieldWhenJsonValueIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue;

    // Assumptions
    ASSERT_THAT(jsonValue.IsObject(), IsFalse()) << "Assume JSON value is not an object";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetStringField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetStringFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsFalse()) << "Assume JSON object does not have field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetStringField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetStringFieldWhenFieldIsNotAStringThrowsError)
{
    // Arrange
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Assert
    ASSERT_THROW(auto actual = jsonValue.GetStringField(key), std::runtime_error) << "Assert error is thrown";
}

TEST_F(JsonValueObjectTest, GetStringFieldWhenFieldIsAStringReturnsExpected)
{
    // Arrange
    const std::string expected("value");
    const std::string key("key");
    JsonValue jsonValue = JsonValue::FromJson(R"({"key":"value"})");

    // Assumptions
    ASSERT_THAT(jsonValue.HasField(key), IsTrue()) << "Assume JSON object has field";

    // Act
    const std::string actual = jsonValue.GetStringField(key);

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert that actual equals expected";
}

TEST_F(JsonValueObjectTest, HasFieldWhenJsonValueIsNotAnObjectReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const JsonValue jsonValue;

    // Assumptions
    ASSERT_THAT(jsonValue.IsObject(), IsFalse()) << "Assume JSON value is not an object";

    // Act
    const bool actual = jsonValue.HasField(key);

    // Assert
    ASSERT_THAT(actual, IsFalse()) << "Assert that actual is false";
}

TEST_F(JsonValueObjectTest, HasFieldWhenJsonObjectDoesHaveFieldReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const JsonValue jsonValue = JsonValue::FromJson(EmptyObject);

    // Act
    const bool actual = jsonValue.HasField(key);

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(JsonValueObjectTest, HasFieldWhenJsonObjectHasFieldReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const JsonValue jsonValue = JsonValue::FromJson(R"({"key":null})");

    // Act
    const bool actual = jsonValue.HasField(key);

    // Assert
    ASSERT_THAT(actual, IsTrue());
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outArray, Eq(expectedArray)) << "Expect out array is unchanged";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outArray, Eq(expectedArray)) << "Expect out array is unchanged";
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
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(outArray, Eq(expectedArray)) << "Expect out array equals expected";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outBool, Eq(expectedBool)) << "Expect out boolean is unchanged";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outBool, Eq(expectedBool)) << "Expect out boolean is unchanged";
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
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(outBool, Eq(expectedBool)) << "Expect out boolean equals expected";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outDouble, Eq(expectedDouble)) << "Expect out double is unchanged";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outDouble, Eq(expectedDouble)) << "Expect out double is unchanged";
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
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(outDouble, Eq(expectedDouble)) << "Expect out double equals expected";
}

TEST_F(JsonValueObjectTest, TryGetFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    JsonValue outValue = JsonValue::FromJson("{}");
    const JsonValue expectedValue(outValue);

    // Act
    const bool result = jsonObject.TryGetField(key, outValue);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outValue, Eq(expectedValue)) << "Expect out value is unchanged";
}

TEST_F(JsonValueObjectTest, TryGetFieldReturnsExpectedValue)
{
    // Arrange
    const JsonValue expectedValue = JsonValue::FromJson(R"({"innerKey":"innerValue"})");
    const std::string key("key");
    const std::string json(R"({"key":{"innerKey":"innerValue"}})");
    const JsonValue jsonObject = JsonValue::FromJson(json);
    JsonValue outValue;

    // Act
    const bool result = jsonObject.TryGetField(key, outValue);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(outValue, Eq(expectedValue)) << "Expect out value equals expected";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outFloat, Eq(expectedFloat)) << "Expect out float is unchanged";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outFloat, Eq(expectedFloat)) << "Expect out float is unchanged";
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
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(outFloat, Eq(expectedFloat)) << "Expect out float equals expected";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outInt, Eq(expectedInt)) << "Expect out integer is unchanged";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outInt, Eq(expectedInt)) << "Expect out integer is unchanged";
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
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(outInt, Eq(expectedInt)) << "Expect out integer equals expected";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outString, Eq(expectedString)) << "Expect out string is unchanged";
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
    EXPECT_THAT(result, IsFalse()) << "Expect result is false";
    EXPECT_THAT(outString, Eq(expectedString)) << "Expect out string is unchanged";
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
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(outString, Eq(expectedString)) << "Expect out string equals expected";
}

TEST_F(JsonValueObjectTest, TrySetArrayFieldWhenJsonIsJsonObjectAndValueIsArraySetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const std::vector<JsonValue> expectedValue = {JsonValue()};
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetArrayField(expectedKey, expectedValue);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(jsonObject.GetArrayField(expectedKey), Eq(expectedValue)) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetBoolFieldWhenJsonIsJsonObjectAndValueIsBoolSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const bool expectedValue = true;
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetBoolField(expectedKey, expectedValue);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(jsonObject.GetBoolField(expectedKey), Eq(expectedValue)) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetDoubleFieldWhenJsonIsJsonObjectAndValueIsDoubleSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const double expectedValue = 1.0;
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetDoubleField(expectedKey, expectedValue);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(jsonObject.GetDoubleField(expectedKey), Eq(expectedValue)) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetFieldWhenJsonIsJsonObjectAndValueIsJsonSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const JsonValue expectedValue;
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetField(expectedKey, expectedValue);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(jsonObject.GetField(expectedKey), Eq(expectedValue)) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetFloatFieldWhenJsonIsJsonObjectAndValueIsFloatSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const float expectedValue = 1.0;
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetFloatField(expectedKey, expectedValue);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(jsonObject.GetFloatField(expectedKey), Eq(expectedValue)) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetIntFieldWhenJsonIsJsonObjectAndValueIsIntegerSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const int32_t expectedValue = 1;
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetIntField(expectedKey, expectedValue);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(jsonObject.GetIntField(expectedKey), Eq(expectedValue)) << "Expect object has value";
}

TEST_F(JsonValueObjectTest, TrySetStringFieldWhenJsonIsJsonObjectAndValueIsStringSetsField)
{
    // Arrange
    const std::string expectedKey("key");
    const std::string expectedValue("value");
    JsonValue jsonObject = JsonValue::FromJson("{}");

    // Act
    const bool result = jsonObject.TrySetStringField(expectedKey, expectedValue);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Expect result is true";
    EXPECT_THAT(jsonObject.GetStringField(expectedKey), Eq(expectedValue)) << "Expect object has value";
}
