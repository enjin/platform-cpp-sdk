#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "FakeJsonDeserializable.hpp"
#include "EnjinPlatformSdk/DateTime.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>
#include <vector>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonUtilTest : public Test
{
};

TEST_F(JsonUtilTest, TryGetArrayWhenJsonIsNotAnArrayReturnsFalseAndOutArrayIsEmpty)
{
    // Arrange
    const JsonValue json;
    std::vector<FakeJsonDeserializable> outArray;

    // Assumptions
    ASSERT_THAT(json.IsArray(), IsFalse()) << "Assume JSON value is not an array";

    // Act
    const bool result = JsonUtil::TryGetArray(json, outArray);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outArray, IsEmpty()) << "Assert that out array is empty";
}

TEST_F(JsonUtilTest, TryGetArrayWhenJsonIsAnArrayReturnsTrueAndOutArrayHasExpectedElements)
{
    // Arrange
    const int expectedSize = 2;
    const std::vector<FakeJsonDeserializable> expected = {FakeJsonDeserializable(true), FakeJsonDeserializable(true)};
    const JsonValue json = JsonValue::FromJson(R"([{"field":true},{"field":true}])");
    std::vector<FakeJsonDeserializable> outArray;

    // Assumptions
    ASSERT_THAT(json.IsArray(), IsTrue()) << "Assume JSON value is an array";

    // Act
    const bool result = JsonUtil::TryGetArray(json, outArray);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outArray, SizeIs(expectedSize)) << "Assert that out array has expected size";
    EXPECT_THAT(outArray, Eq(expected)) << "Assert that out array equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForTypeWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<FakeJsonDeserializable> outField({});

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForTypeWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const FakeJsonDeserializable expectedField(true);
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":{"field":true}})");
    std::optional<FakeJsonDeserializable> outField({});

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that out field equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForTypeArrayWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<std::vector<FakeJsonDeserializable>> outField({});

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForTypeArrayWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const std::vector<FakeJsonDeserializable> expectedField({FakeJsonDeserializable(true)});
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":[{"field":true}]})");
    std::optional<std::vector<FakeJsonDeserializable>> outField({});

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that out field equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForBoolWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<bool> outField(false);

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForBoolWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const bool expectedField = true;
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":true})");
    std::optional<bool> outField(false);

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that actual equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForDateTimeWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<DateTime> outField({});

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForDateTimeWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const DateTime expectedField = DateTime::Parse("2000-01-01T00:00:00+00:00");
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":"2000-01-01T00:00:00+00:00"})");
    std::optional<DateTime> outField({});

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that actual equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForDoubleWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<double> outField((double) 0.0);

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForDoubleWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const double expectedField = 1.0;
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":1.0})");
    std::optional<double> outField((double) 0.0);

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that actual equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForFloatWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<float> outField((float) 0.0);

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForFloatWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const float expectedField = 1.0;
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":1.0})");
    std::optional<float> outField((float) 0.0);

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that actual equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForIntegerWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<int32_t> outField((int32_t) 0);

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForIntegerWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const int32_t expectedField = 1;
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":1})");
    std::optional<int32_t> outField((int32_t) 0);

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that actual equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForObjectWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<JsonValue> outField(JsonValue::FromJson("null"));

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForObjectWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const JsonValue expectedField = JsonValue::FromJson(R"({})");
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":{}})");
    std::optional<JsonValue> outField(JsonValue::FromJson("null"));

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that actual equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForStringWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<std::string> outField("");

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForStringWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const std::string expectedField("value");
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":"value"})");
    std::optional<std::string> outField("");

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that actual equals expected";
}

TEST_F(JsonUtilTest, TryGetFieldForStringArrayWhenJsonDoesNotHaveFieldReturnsFalseAndResetsField)
{
    // Arrange
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({})");
    std::optional<std::vector<std::string>> outField({});

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsFalse()) << "Assume that object does not have field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that field was reset";
}

TEST_F(JsonUtilTest, TryGetFieldForStringArrayWhenJsonHasFieldReturnsTrueAndGetsField)
{
    // Arrange
    const std::vector<std::string> expectedField = {"value"};
    const std::string fieldName("field");
    const JsonValue json = JsonValue::FromJson(R"({"field":["value"]})");
    std::optional<std::vector<std::string>> outField({});

    // Assumptions
    ASSERT_THAT(json.HasField(fieldName), IsTrue()) << "Assume that object has field";

    // Act
    const bool result = JsonUtil::TryGetField(json, fieldName, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    EXPECT_THAT(outField, Eq(expectedField)) << "Assert that actual equals expected";
}
