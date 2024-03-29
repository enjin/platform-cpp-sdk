#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/FreezeType.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace testing;

class FreezeTypeTest : public Test
{
};

class FreezeTypeToStringValidValueTest : public TestWithParam<std::pair<std::string, FreezeType>>
{
};

class FreezeTypeTryGetValidValueTest : public TestWithParam<FreezeType>
{
public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const FreezeType value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case FreezeType::Collect:
                json.TrySetStringField(key, "COLLECTION");
                break;

            case FreezeType::CollectionAccount:
                json.TrySetStringField(key, "COLLECTION_ACCOUNT");
                break;

            case FreezeType::Token:
                json.TrySetStringField(key, "TOKEN");
                break;

            case FreezeType::TokenAccount:
                json.TrySetStringField(key, "TOKEN_ACCOUNT");
                break;

            default:
                break;
        }

        return json;
    }
};

TEST_F(FreezeTypeTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (FreezeType) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(FreezeTypeTest, TryGetFieldWhenGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<FreezeType> outField = FreezeType::Collect;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(FreezeTypeTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<FreezeType> outField = FreezeType::Collect;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(FreezeTypeTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<FreezeType> outField = FreezeType::Collect;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(FreezeTypeToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const FreezeType value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(FreezeTypeTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const FreezeType expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<FreezeType> outField;

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
                         FreezeTypeToStringValidValueTest,
                         Values(std::pair<std::string, FreezeType>("", FreezeType::None),
                                std::pair<std::string, FreezeType>("COLLECTION", FreezeType::Collect),
                                std::pair<std::string, FreezeType>("COLLECTION_ACCOUNT", FreezeType::CollectionAccount),
                                std::pair<std::string, FreezeType>("TOKEN", FreezeType::Token),
                                std::pair<std::string, FreezeType>("TOKEN_ACCOUNT", FreezeType::TokenAccount)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         FreezeTypeTryGetValidValueTest,
                         Values(FreezeType::Collect,
                                FreezeType::CollectionAccount,
                                FreezeType::Token,
                                FreezeType::TokenAccount));
