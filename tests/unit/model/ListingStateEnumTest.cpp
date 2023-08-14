#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkMarketplace/ListingStateEnum.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using namespace testing;

class ListingStateEnumTest : public Test
{
};

class ListingStateEnumToStringValidValueTest : public TestWithParam<std::pair<std::string, ListingStateEnum>>
{
};

class ListingStateEnumTryGetValidValueTest : public TestWithParam<ListingStateEnum>
{
protected:
    static inline const std::string Active = std::string("ACTIVE");
    static inline const std::string Cancelled = std::string("CANCELLED");
    static inline const std::string Finalized = std::string("FINALIZED");

public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const ListingStateEnum value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case ListingStateEnum::Active:
                json.TrySetStringField(key, Active);
                break;

            case ListingStateEnum::Cancelled:
                json.TrySetStringField(key, Cancelled);
                break;

            case ListingStateEnum::Finalized:
                json.TrySetStringField(key, Finalized);
                break;

            default:
                break;
        }

        return json;
    }

    static JsonValue CreateFakeJsonValue(const std::string& key, const std::vector<ListingStateEnum>& value)
    {
        JsonValue json = JsonValue::FromJson("{}");
        JsonValue jsonArray = JsonValue::FromJson("[]");

        for (const ListingStateEnum el : value)
        {
            switch (el)
            {
                case ListingStateEnum::Active:
                    jsonArray.AddArrayElement(JsonValue::FromString(Active));
                    break;

                case ListingStateEnum::Cancelled:
                    jsonArray.AddArrayElement(JsonValue::FromString(Cancelled));
                    break;

                case ListingStateEnum::Finalized:
                    jsonArray.AddArrayElement(JsonValue::FromString(Finalized));
                    break;

                default:
                    break;
            }
        }

        json.TrySetField(key, jsonArray);

        return json;
    }
};

TEST_F(ListingStateEnumTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (ListingStateEnum) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(ListingStateEnumTest, TryGetFieldWhenExpectingStringAndGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<ListingStateEnum> outField = ListingStateEnum::Active;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(ListingStateEnumTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<ListingStateEnum> outField = ListingStateEnum::Active;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(ListingStateEnumTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<ListingStateEnum> outField = ListingStateEnum::Active;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(ListingStateEnumToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const ListingStateEnum value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(ListingStateEnumTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const ListingStateEnum expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<ListingStateEnum> outField;

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
                         ListingStateEnumToStringValidValueTest,
                         Values(std::pair<std::string, ListingStateEnum>("ACTIVE", ListingStateEnum::Active),
                                std::pair<std::string, ListingStateEnum>("CANCELLED", ListingStateEnum::Cancelled),
                                std::pair<std::string, ListingStateEnum>("FINALIZED", ListingStateEnum::Finalized)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         ListingStateEnumTryGetValidValueTest,
                         Values(ListingStateEnum::Active,
                                ListingStateEnum::Cancelled,
                                ListingStateEnum::Finalized));
