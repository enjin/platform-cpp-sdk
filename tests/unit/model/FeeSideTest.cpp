#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkMarketplace/FeeSide.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using namespace testing;

class FeeSideTest : public Test
{
};

class FeeSideToStringValidValueTest : public TestWithParam<std::pair<std::string, FeeSide>>
{
};

class FeeSideTryGetValidValueTest : public TestWithParam<FeeSide>
{
protected:
    static inline const std::string NoFee = std::string("NO_FEE");
    static inline const std::string MakeFee = std::string("MAKE_FEE");
    static inline const std::string TakeFee = std::string("TAKE_FEE");

public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const FeeSide value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case FeeSide::NoFee:
                json.TrySetStringField(key, NoFee);
                break;

            case FeeSide::MakeFee:
                json.TrySetStringField(key, MakeFee);
                break;

            case FeeSide::TakeFee:
                json.TrySetStringField(key, TakeFee);
                break;

            default:
                break;
        }

        return json;
    }

    static JsonValue CreateFakeJsonValue(const std::string& key, const std::vector<FeeSide>& value)
    {
        JsonValue json = JsonValue::FromJson("{}");
        JsonValue jsonArray = JsonValue::FromJson("[]");

        for (const FeeSide el : value)
        {
            switch (el)
            {
                case FeeSide::NoFee:
                    jsonArray.AddArrayElement(JsonValue::FromString(NoFee));
                    break;

                case FeeSide::MakeFee:
                    jsonArray.AddArrayElement(JsonValue::FromString(MakeFee));
                    break;

                case FeeSide::TakeFee:
                    jsonArray.AddArrayElement(JsonValue::FromString(TakeFee));
                    break;

                default:
                    break;
            }
        }

        json.TrySetField(key, jsonArray);

        return json;
    }
};

TEST_F(FeeSideTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (FeeSide) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(FeeSideTest, TryGetFieldWhenExpectingStringAndGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<FeeSide> outField = FeeSide::NoFee;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(FeeSideTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<FeeSide> outField = FeeSide::NoFee;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(FeeSideTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<FeeSide> outField = FeeSide::NoFee;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(FeeSideToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const FeeSide value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(FeeSideTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const FeeSide expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<FeeSide> outField;

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
                         FeeSideToStringValidValueTest,
                         Values(std::pair<std::string, FeeSide>("NO_FEE", FeeSide::NoFee),
                                std::pair<std::string, FeeSide>("MAKE_FEE", FeeSide::MakeFee),
                                std::pair<std::string, FeeSide>("TAKE_FEE", FeeSide::TakeFee)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         FeeSideTryGetValidValueTest,
                         Values(FeeSide::NoFee,
                                FeeSide::MakeFee,
                                FeeSide::TakeFee));
