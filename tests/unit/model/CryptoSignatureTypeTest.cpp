#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/CryptoSignatureType.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace testing;

class CryptoSignatureTypeTest : public Test
{
};

class CryptoSignatureTypeToStringValidValueTest : public TestWithParam<std::pair<std::string, CryptoSignatureType>>
{
};

class CryptoSignatureTypeTryGetValidValueTest : public TestWithParam<CryptoSignatureType>
{
public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const CryptoSignatureType value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case CryptoSignatureType::Ed25519:
                json.TrySetStringField(key, "ED25519");
                break;

            case CryptoSignatureType::Sr25519:
                json.TrySetStringField(key, "SR25519");
                break;

            default:
                break;
        }

        return json;
    }
};

TEST_F(CryptoSignatureTypeTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (CryptoSignatureType) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(CryptoSignatureTypeTest, TryGetFieldWhenGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<CryptoSignatureType> outField = CryptoSignatureType::Ed25519;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(CryptoSignatureTypeTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<CryptoSignatureType> outField = CryptoSignatureType::Ed25519;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(CryptoSignatureTypeTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<CryptoSignatureType> outField = CryptoSignatureType::Ed25519;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(CryptoSignatureTypeToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const CryptoSignatureType value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(CryptoSignatureTypeTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const CryptoSignatureType expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<CryptoSignatureType> outField;

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
                         CryptoSignatureTypeToStringValidValueTest,
                         Values(std::pair<std::string, CryptoSignatureType>("", CryptoSignatureType::None),
                                std::pair<std::string, CryptoSignatureType>("ED25519", CryptoSignatureType::Ed25519),
                                std::pair<std::string, CryptoSignatureType>("SR25519", CryptoSignatureType::Sr25519)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         CryptoSignatureTypeTryGetValidValueTest,
                         Values(CryptoSignatureType::Ed25519,
                                CryptoSignatureType::Sr25519));
