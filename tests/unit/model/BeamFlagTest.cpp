#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkBeam/BeamFlag.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using namespace testing;

class BeamFlagTestSuite
{
protected:
    static inline const std::string Paused = std::string("PAUSED");
    static inline const std::string SingleUse = std::string("SINGLE_USE");
    static inline const std::string Prunable = std::string("PRUNABLE");

public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const BeamFlag value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case BeamFlag::Paused:
                json.TrySetStringField(key, Paused);
                break;

            case BeamFlag::SingleUse:
                json.TrySetStringField(key, SingleUse);
                break;

            case BeamFlag::Prunable:
                json.TrySetStringField(key, Prunable);
                break;

            default:
                break;
        }

        return json;
    }

    static JsonValue CreateFakeJsonValue(const std::string& key, const std::vector<BeamFlag>& value)
    {
        JsonValue json = JsonValue::FromJson("{}");
        JsonValue jsonArray = JsonValue::FromJson("[]");

        for (const BeamFlag el : value)
        {
            switch (el)
            {
                case BeamFlag::Paused:
                    jsonArray.AddArrayElement(JsonValue::FromString(Paused));
                    break;

                case BeamFlag::SingleUse:
                    jsonArray.AddArrayElement(JsonValue::FromString(SingleUse));
                    break;

                case BeamFlag::Prunable:
                    jsonArray.AddArrayElement(JsonValue::FromString(Prunable));
                    break;

                default:
                    break;
            }
        }

        json.TrySetField(key, jsonArray);

        return json;
    }
};

class BeamFlagTest : public Test
{
};

class BeamFlagToStringValidValueTest : public TestWithParam<std::pair<std::string, BeamFlag>>
{
};

class BeamFlagTryGetValidValueTest : public TestWithParam<BeamFlag>,
                                     public BeamFlagTestSuite
{
};

class BeamFlagTryGetValidArrayValueTest : public TestWithParam<std::vector<BeamFlag>>,
                                          public BeamFlagTestSuite
{
};

TEST_F(BeamFlagTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (BeamFlag) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(BeamFlagTest, TryGetFieldWhenExpectingStringAndGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<BeamFlag> outField = BeamFlag::Paused;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(BeamFlagTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<BeamFlag> outField = BeamFlag::Paused;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(BeamFlagTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<BeamFlag> outField = BeamFlag::Paused;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(BeamFlagTest, TryGetFieldWhenExpectingArrayAndGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<std::vector<BeamFlag>> outField = std::vector<BeamFlag>{};

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(BeamFlagTest, TryGetFieldWhenGivenJsonWithNonArrayFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<std::vector<BeamFlag>> outField = std::vector<BeamFlag>{};

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(BeamFlagTest, TryGetFieldWhenGivenJsonWithArrayFieldContainingNoValidElementsReturnsTrueAndOutFieldIsEmpty)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":[""]})");
    const std::string key("key");
    std::optional<std::vector<BeamFlag>> outField;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsFalse()) << "Assume that out field does not have a value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assert that out field has a value";
    ASSERT_THAT(outField.value(), IsEmpty()) << "Assert that out field is empty";
}

TEST_P(BeamFlagToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const BeamFlag value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(BeamFlagTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const BeamFlag expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<BeamFlag> outField;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsFalse()) << "Assume that out field does not have a value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assert that out field has a value";
    ASSERT_THAT(outField.value(), Eq(expected)) << "Assert that out field value equals expected";
}

TEST_P(BeamFlagTryGetValidArrayValueTest, TryGetFieldWhenGivenJsonWithValidArrayFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const std::vector<BeamFlag> expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<std::vector<BeamFlag>> outField;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsFalse()) << "Assume that out field does not have a value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsTrue()) << "Assert that result is true";
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assert that out field has a value";
    ASSERT_THAT(outField.value(), Eq(expected)) << "Assert that out field value equals expected";
}

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         BeamFlagToStringValidValueTest,
                         Values(std::pair<std::string, BeamFlag>("", BeamFlag::None),
                                std::pair<std::string, BeamFlag>("PAUSED", BeamFlag::Paused),
                                std::pair<std::string, BeamFlag>("SINGLE_USE", BeamFlag::SingleUse),
                                std::pair<std::string, BeamFlag>("PRUNABLE", BeamFlag::Prunable)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         BeamFlagTryGetValidValueTest,
                         Values(BeamFlag::Paused,
                                BeamFlag::SingleUse,
                                BeamFlag::Prunable));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         BeamFlagTryGetValidArrayValueTest,
                         Values(std::vector<BeamFlag>{BeamFlag::Paused},
                                std::vector<BeamFlag>{BeamFlag::SingleUse},
                                std::vector<BeamFlag>{BeamFlag::Prunable},
                                std::vector<BeamFlag>{BeamFlag::Paused, BeamFlag::SingleUse, BeamFlag::Prunable}));
