#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/TransactionResult.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace testing;

class TransactionResultTest : public Test
{
};

class TransactionResultToStringValidValueTest : public TestWithParam<std::pair<std::string, TransactionResult>>
{
};

class TransactionResultTryGetValidValueTest : public TestWithParam<TransactionResult>
{
public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const TransactionResult value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case TransactionResult::ExtrinsicSuccess:
                json.TrySetStringField(key, "EXTRINSIC_SUCCESS");
                break;

            case TransactionResult::ExtrinsicFailed:
                json.TrySetStringField(key, "EXTRINSIC_FAILED");
                break;

            default:
                break;
        }

        return json;
    }
};

TEST_F(TransactionResultTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (TransactionResult) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(TransactionResultTest, TryGetFieldWhenGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<TransactionResult> outField = TransactionResult::ExtrinsicSuccess;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(TransactionResultTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<TransactionResult> outField = TransactionResult::ExtrinsicSuccess;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(TransactionResultTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<TransactionResult> outField = TransactionResult::ExtrinsicSuccess;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(TransactionResultToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const TransactionResult value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(TransactionResultTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const TransactionResult expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<TransactionResult> outField;

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
                         TransactionResultToStringValidValueTest,
                         Values(std::pair<std::string, TransactionResult>("",
                                                                          TransactionResult::None),
                                std::pair<std::string, TransactionResult>("EXTRINSIC_SUCCESS",
                                                                          TransactionResult::ExtrinsicSuccess),
                                std::pair<std::string, TransactionResult>("EXTRINSIC_FAILED",
                                                                          TransactionResult::ExtrinsicFailed)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         TransactionResultTryGetValidValueTest,
                         Values(TransactionResult::ExtrinsicSuccess,
                                TransactionResult::ExtrinsicFailed));
