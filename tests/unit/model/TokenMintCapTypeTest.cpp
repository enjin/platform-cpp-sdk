#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/TokenMintCapType.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace testing;

class TokenMintCapTypeTest : public Test
{
};

class TokenMintCapTypeToStringValidValueTest : public TestWithParam<std::pair<std::string, TokenMintCapType>>
{
};

class TokenMintCapTypeTryGetValidValueTest : public TestWithParam<TokenMintCapType>
{
public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const TokenMintCapType value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case TokenMintCapType::SingleMint:
                json.TrySetStringField(key, "SINGLE_MINT");
                break;

            case TokenMintCapType::Supply:
                json.TrySetStringField(key, "SUPPLY");
                break;

            default:
                break;
        }

        return json;
    }
};

TEST_F(TokenMintCapTypeTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (TokenMintCapType) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(TokenMintCapTypeTest, TryGetFieldWhenGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<TokenMintCapType> outField = TokenMintCapType::SingleMint;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(TokenMintCapTypeTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<TokenMintCapType> outField = TokenMintCapType::SingleMint;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(TokenMintCapTypeTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<TokenMintCapType> outField = TokenMintCapType::SingleMint;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(TokenMintCapTypeToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const TokenMintCapType value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(TokenMintCapTypeTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const TokenMintCapType expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<TokenMintCapType> outField;

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
                         TokenMintCapTypeToStringValidValueTest,
                         Values(std::pair<std::string, TokenMintCapType>("", TokenMintCapType::None),
                                std::pair<std::string, TokenMintCapType>("SINGLE_MINT", TokenMintCapType::SingleMint),
                                std::pair<std::string, TokenMintCapType>("SUPPLY", TokenMintCapType::Supply)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         TokenMintCapTypeTryGetValidValueTest,
                         Values(TokenMintCapType::SingleMint,
                                TokenMintCapType::Supply));
