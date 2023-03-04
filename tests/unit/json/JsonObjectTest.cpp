#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonObject.hpp"
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk::json;
using namespace testing;

class JsonObjectTest : public Test
{
};

class JsonObjectFromInvalidJsonTest : public TestWithParam<std::string>
{
};

TEST_F(JsonObjectTest, GetObjectFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Assert
    ASSERT_THROW(JsonObject o = jsonObject.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonObjectTest, GetObjectFieldWhenFieldIsNotAnObjectThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Assert
    ASSERT_THROW(JsonObject o = jsonObject.GetObjectField(key), std::runtime_error);
}

TEST_F(JsonObjectTest, GetObjectFieldWhenFieldIsAnObjectReturnsExpectedObject)
{
    // Arrange
    const std::string expectedKey("innerKey");
    const std::string expectedValue("innerValue");
    const std::string key("key");
    const std::string json(R"({"key":{"innerKey":"innerValue"}})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Act
    const JsonObject actual = jsonObject.GetObjectField(key);

    // Assert
    ASSERT_TRUE(actual.HasStringField(expectedKey)) << "Assert object has expected key";
    ASSERT_EQ(actual.GetStringField(expectedKey), expectedValue) << "Assert object has expected value";
}

TEST_F(JsonObjectTest, GetStringFieldWhenFieldIsNotPresentThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Assert
    ASSERT_THROW(std::string s = jsonObject.GetStringField(key), std::runtime_error);
}

TEST_F(JsonObjectTest, GetStringFieldWhenFieldIsNotAStringThrowsError)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Assert
    ASSERT_THROW(std::string s = jsonObject.GetStringField(key), std::runtime_error);
}

TEST_F(JsonObjectTest, GetStringFieldWhenFieldIsAStringReturnsExpectedString)
{
    // Arrange
    const std::string expected("value");
    const std::string key("key");
    const std::string json(R"({"key":"value"})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Act
    const std::string actual = jsonObject.GetStringField(key);

    // Assert
    ASSERT_EQ(actual, expected);
}

TEST_F(JsonObjectTest, HasObjectFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Act
    const bool actual = jsonObject.HasObjectField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonObjectTest, HasObjectFieldWhenFieldIsNotAnObjectReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Act
    const bool actual = jsonObject.HasObjectField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonObjectTest, HasObjectFieldWhenFieldIsAnObjectReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":{}})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Act
    const bool actual = jsonObject.HasObjectField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonObjectTest, HasStringFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Act
    const bool actual = jsonObject.HasStringField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonObjectTest, HasStringFieldWhenFieldIsNotAStringReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Act
    const bool actual = jsonObject.HasStringField(key);

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(JsonObjectTest, HasStringFieldWhenFieldIsAStringReturnsTrue)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":""})");
    const JsonObject jsonObject = JsonObject::FromJson(json);

    // Act
    const bool actual = jsonObject.HasStringField(key);

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(JsonObjectTest, TryGetObjectFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    JsonObject outObject = JsonObject::FromJson(R"({"key":"value"})");
    const JsonObject expectedObject(outObject);

    // Act
    const bool result = jsonObject.TryGetObjectField(key, outObject);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outObject, expectedObject) << "Expect out object is unchanged";
}

TEST_F(JsonObjectTest, TryGetObjectFieldWhenFieldIsNotAnObjectReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    JsonObject outObject = JsonObject::FromJson(R"({"innerKey":"innerValue"})");
    const JsonObject expectedObject(outObject);

    // Act
    const bool result = jsonObject.TryGetObjectField(key, outObject);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outObject, expectedObject) << "Expect out object is unchanged";
}

TEST_F(JsonObjectTest, TryGetObjectFieldWhenFieldIsAnObjectReturnsExpectedObject)
{
    // Arrange
    const std::string expectedKey("innerKey");
    const std::string expectedValue("innerValue");
    const std::string key("key");
    const std::string json(R"({"key":{"innerKey":"innerValue"}})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    JsonObject outObject;

    // Act
    const bool result = jsonObject.TryGetObjectField(key, outObject);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    ASSERT_TRUE(outObject.HasStringField(expectedKey)) << "Assert object has expected key";
    ASSERT_EQ(outObject.GetStringField(expectedKey), expectedValue) << "Assert object has expected value";
}

TEST_F(JsonObjectTest, TryGetStringFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    std::string outString;
    const std::string expectedString(outString);

    // Act
    const bool result = jsonObject.TryGetStringField(key, outString);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outString, expectedString) << "Expect out string is unchanged";
}

TEST_F(JsonObjectTest, TryGetStringFieldWhenFieldIsNotAStringReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    std::string outString;
    const std::string expectedString(outString);

    // Act
    const bool result = jsonObject.TryGetStringField(key, outString);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outString, expectedString) << "Expect out string is unchanged";
}

TEST_F(JsonObjectTest, TryGetStringFieldWhenFieldIsAStringReturnsExpectedString)
{
    // Arrange
    const std::string expectedString("value");
    const std::string key("key");
    const std::string json(R"({"key":"value"})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    std::string outString;

    // Act
    const bool result = jsonObject.TryGetStringField(key, outString);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outString, expectedString) << "Expect out string equals expected";
}

TEST_F(JsonObjectTest, TryGetUintFieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    uint32_t outUint = 0;
    const uint32_t expectedUint = outUint;

    // Act
    const bool result = jsonObject.TryGetUintField(key, outUint);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outUint, expectedUint) << "Expect out unsigned integer is unchanged";
}

TEST_F(JsonObjectTest, TryGetUintFieldWhenFieldIsNotAnUnsingedIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    uint32_t outUint = 0;
    const uint32_t expectedUint = outUint;

    // Act
    const bool result = jsonObject.TryGetUintField(key, outUint);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outUint, expectedUint) << "Expect out unsigned integer is unchanged";
}

TEST_F(JsonObjectTest, TryGetUintFieldWhenFieldIsAnUnsingedIntegerReturnsExpectedString)
{
    // Arrange
    const uint32_t expectedUint = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    uint32_t outUint = 0;

    // Act
    const bool result = jsonObject.TryGetUintField(key, outUint);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outUint, expectedUint) << "Expect out unsigned integer equals expected";
}

TEST_F(JsonObjectTest, TryGetUint64FieldWhenFieldIsNotPresentReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    uint64_t outUint64 = 0;
    const uint64_t expectedUint64 = outUint64;

    // Act
    const bool result = jsonObject.TryGetUint64Field(key, outUint64);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outUint64, expectedUint64) << "Expect out unsigned long integer is unchanged";
}

TEST_F(JsonObjectTest, TryGetUint64FieldWhenFieldIsNotAnUnsingedLongIntegerReturnsFalse)
{
    // Arrange
    const std::string key("key");
    const std::string json(R"({"key":null})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    uint64_t outUint64 = 0;
    const uint64_t expectedUint64 = outUint64;

    // Act
    const bool result = jsonObject.TryGetUint64Field(key, outUint64);

    // Assert
    EXPECT_FALSE(result) << "Expect result is false";
    EXPECT_EQ(outUint64, expectedUint64) << "Expect out unsigned long integer is unchanged";
}

TEST_F(JsonObjectTest, TryGetUint64FieldWhenFieldIsAnUnsingedLongIntegerReturnsExpectedValue)
{
    // Arrange
    const uint64_t expectedUint64 = 1;
    const std::string key("key");
    const std::string json(R"({"key":1})");
    const JsonObject jsonObject = JsonObject::FromJson(json);
    uint64_t outUint64 = 0;

    // Act
    const bool result = jsonObject.TryGetUint64Field(key, outUint64);

    // Assert
    EXPECT_TRUE(result) << "Expect result is true";
    EXPECT_EQ(outUint64, expectedUint64) << "Expect out unsigned long integer equals expected";
}

TEST_F(JsonObjectTest, FromJsonGivenValidJsonReturnsExpectedObject)
{
    // Arrange
    const std::string expectedKey("key");
    const std::string expectedValue("value");
    const std::string json(R"({"key":"value"})");

    // Act
    const JsonObject actual = JsonObject::FromJson(json);

    // Assert
    ASSERT_TRUE(actual.HasStringField(expectedKey)) << "Assert object has expected key";
    ASSERT_EQ(actual.GetStringField(expectedKey), expectedValue) << "Assert object has expected value";
}

TEST_P(JsonObjectFromInvalidJsonTest, FromJsonGivenInvalidJsonThrowsError)
{
    // Arrange
    const std::string json = GetParam();

    // Assert
    ASSERT_THROW(JsonObject::FromJson(json), std::runtime_error);
}

INSTANTIATE_TEST_SUITE_P(InvalidJsonFormats,
                         JsonObjectFromInvalidJsonTest,
                         Values("null", "1", "true", "false", R"("abc")", "[]"));
