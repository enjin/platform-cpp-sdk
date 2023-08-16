#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkMarketplace/ListingType.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using namespace testing;

class ListingTypeTest : public Test
{
};

class ListingTypeToStringValidValueTest : public TestWithParam<std::pair<std::string, ListingType>>
{
};

class ListingTypeTryGetValidValueTest : public TestWithParam<ListingType>
{
protected:
    static inline const std::string FixedPrice = std::string("FIXED_PRICE");
    static inline const std::string Auction = std::string("AUCTION");

public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const ListingType value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case ListingType::FixedPrice:
                json.TrySetStringField(key, FixedPrice);
                break;

            case ListingType::Auction:
                json.TrySetStringField(key, Auction);
                break;

            default:
                break;
        }

        return json;
    }

    static JsonValue CreateFakeJsonValue(const std::string& key, const std::vector<ListingType>& value)
    {
        JsonValue json = JsonValue::FromJson("{}");
        JsonValue jsonArray = JsonValue::FromJson("[]");

        for (const ListingType el : value)
        {
            switch (el)
            {
                case ListingType::FixedPrice:
                    jsonArray.AddArrayElement(JsonValue::FromString(FixedPrice));
                    break;

                case ListingType::Auction:
                    jsonArray.AddArrayElement(JsonValue::FromString(Auction));
                    break;

                default:
                    break;
            }
        }

        json.TrySetField(key, jsonArray);

        return json;
    }
};

TEST_F(ListingTypeTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (ListingType) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(ListingTypeTest, TryGetFieldWhenExpectingStringAndGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<ListingType> outField = ListingType::FixedPrice;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(ListingTypeTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<ListingType> outField = ListingType::FixedPrice;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(ListingTypeTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<ListingType> outField = ListingType::FixedPrice;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(ListingTypeToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const ListingType value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(ListingTypeTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const ListingType expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<ListingType> outField;

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
                         ListingTypeToStringValidValueTest,
                         Values(std::pair<std::string, ListingType>("FIXED_PRICE", ListingType::FixedPrice),
                                std::pair<std::string, ListingType>("AUCTION", ListingType::Auction)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         ListingTypeTryGetValidValueTest,
                         Values(ListingType::FixedPrice,
                                ListingType::Auction));
