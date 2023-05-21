//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/PalletIdentifier.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace testing;

class PalletIdentifierTest : public Test
{
};

class PalletIdentifierToStringValidValueTest : public TestWithParam<std::pair<std::string, PalletIdentifier>>
{
};

class PalletIdentifierTryGetValidValueTest : public TestWithParam<PalletIdentifier>
{
public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const PalletIdentifier value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case PalletIdentifier::Marketplace:
                json.TrySetStringField(key, "MARKETPLACE");
                break;

            case PalletIdentifier::MultiTokens:
                json.TrySetStringField(key, "MULTI_TOKENS");
                break;

            case PalletIdentifier::FuelTanks:
                json.TrySetStringField(key, "FUEL_TANKS");
                break;

            default:
                break;
        }

        return json;
    }
};

TEST_F(PalletIdentifierTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (PalletIdentifier) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(PalletIdentifierTest, TryGetFieldWhenGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<PalletIdentifier> outField = PalletIdentifier::Marketplace;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(PalletIdentifierTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<PalletIdentifier> outField = PalletIdentifier::Marketplace;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(PalletIdentifierTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<PalletIdentifier> outField = PalletIdentifier::Marketplace;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(PalletIdentifierToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const PalletIdentifier value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(PalletIdentifierTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const PalletIdentifier expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<PalletIdentifier> outField;

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
                         PalletIdentifierToStringValidValueTest,
                         Values(std::pair<std::string, PalletIdentifier>("", PalletIdentifier::None),
                                std::pair<std::string, PalletIdentifier>("MARKETPLACE", PalletIdentifier::Marketplace),
                                std::pair<std::string, PalletIdentifier>("MULTI_TOKENS", PalletIdentifier::MultiTokens),
                                std::pair<std::string, PalletIdentifier>("FUEL_TANKS", PalletIdentifier::FuelTanks)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         PalletIdentifierTryGetValidValueTest,
                         Values(PalletIdentifier::Marketplace,
                                PalletIdentifier::MultiTokens,
                                PalletIdentifier::FuelTanks));
