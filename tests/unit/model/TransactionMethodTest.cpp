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
#include "EnjinPlatformSdk/TransactionMethod.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace testing;

class TransactionMethodTest : public Test
{
};

class TransactionMethodToStringValidValueTest : public TestWithParam<std::pair<std::string, TransactionMethod>>
{
};

class TransactionMethodTryGetValidValueTest : public TestWithParam<TransactionMethod>
{
public:
    static JsonValue CreateFakeJsonValue(const std::string& key, const TransactionMethod value)
    {
        JsonValue json = JsonValue::FromJson("{}");

        switch (value)
        {
            case TransactionMethod::ApproveCollection:
                json.TrySetStringField(key, "ApproveCollection");
                break;

            case TransactionMethod::ApproveToken:
                json.TrySetStringField(key, "ApproveToken");
                break;

            case TransactionMethod::BatchMint:
                json.TrySetStringField(key, "BatchMint");
                break;

            case TransactionMethod::BatchSetAttribute:
                json.TrySetStringField(key, "BatchSetAttribute");
                break;

            case TransactionMethod::BatchTransfer:
                json.TrySetStringField(key, "BatchTransfer");
                break;

            case TransactionMethod::Burn:
                json.TrySetStringField(key, "Burn");
                break;

            case TransactionMethod::CreateCollection:
                json.TrySetStringField(key, "CreateCollection");
                break;

            case TransactionMethod::CreateToken:
                json.TrySetStringField(key, "CreateToken");
                break;

            case TransactionMethod::DestroyCollection:
                json.TrySetStringField(key, "DestroyCollection");
                break;

            case TransactionMethod::Freeze:
                json.TrySetStringField(key, "Freeze");
                break;

            case TransactionMethod::MintToken:
                json.TrySetStringField(key, "MintToken");
                break;

            case TransactionMethod::MutateCollection:
                json.TrySetStringField(key, "MutateCollection");
                break;

            case TransactionMethod::MutateToken:
                json.TrySetStringField(key, "MutateToken");
                break;

            case TransactionMethod::OperatorTransferToken:
                json.TrySetStringField(key, "OperatorTransferToken");
                break;

            case TransactionMethod::RemoveAllAttributes:
                json.TrySetStringField(key, "RemoveAllAttributes");
                break;

            case TransactionMethod::RemoveCollectionAttribute:
                json.TrySetStringField(key, "RemoveCollectionAttribute");
                break;

            case TransactionMethod::RemoveTokenAttribute:
                json.TrySetStringField(key, "RemoveTokenAttribute");
                break;

            case TransactionMethod::SetCollectionAttribute:
                json.TrySetStringField(key, "SetCollectionAttribute");
                break;

            case TransactionMethod::SetTokenAttribute:
                json.TrySetStringField(key, "SetTokenAttribute");
                break;

            case TransactionMethod::SimpleTransferToken:
                json.TrySetStringField(key, "SimpleTransferToken");
                break;

            case TransactionMethod::Thaw:
                json.TrySetStringField(key, "Thaw");
                break;

            case TransactionMethod::TransferAllBalance:
                json.TrySetStringField(key, "TransferAllBalance");
                break;

            case TransactionMethod::TransferBalance:
                json.TrySetStringField(key, "TransferBalance");
                break;

            case TransactionMethod::UnapproveCollection:
                json.TrySetStringField(key, "UnapproveCollection");
                break;

            case TransactionMethod::UnapproveToken:
                json.TrySetStringField(key, "UnapproveToken");
                break;

            default:
                break;
        }

        return json;
    }
};

TEST_F(TransactionMethodTest, ToStringWhenGivenInvalidEnumValueThrowsError)
{
    // Arrange
    const auto value = (TransactionMethod) INT_MAX;

    // Assert
    ASSERT_THROW(auto s = ToString(value), std::out_of_range);
}

TEST_F(TransactionMethodTest, TryGetFieldWhenGivenJsonWithNoFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({})");
    const std::string key("key");
    std::optional<TransactionMethod> outField = TransactionMethod::ApproveCollection;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(TransactionMethodTest, TryGetFieldWhenGivenJsonWithNonStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":null})");
    const std::string key("key");
    std::optional<TransactionMethod> outField = TransactionMethod::ApproveCollection;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_F(TransactionMethodTest, TryGetFieldWhenGivenJsonWithInvalidStringFieldReturnsFalseAndResetsOutField)
{
    // Arrange
    const JsonValue json = JsonValue::FromJson(R"({"key":""})");
    const std::string key("key");
    std::optional<TransactionMethod> outField = TransactionMethod::ApproveCollection;

    // Assumptions
    ASSERT_THAT(outField.has_value(), IsTrue()) << "Assume that out field has value before act";

    // Act
    const bool result = TryGetField(json, key, outField);

    // Assert
    EXPECT_THAT(result, IsFalse()) << "Assert that result is false";
    EXPECT_THAT(outField.has_value(), IsFalse()) << "Assert that out field was reset";
}

TEST_P(TransactionMethodToStringValidValueTest, ToStringWhenGivenValidEnumValueReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const TransactionMethod value = GetParam().second;

    // Act
    const std::string actual = ToString(value);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(TransactionMethodTryGetValidValueTest, TryGetFieldWhenGivenJsonWithValidStringFieldReturnsTrueAndSetsOutField)
{
    // Arrange
    const TransactionMethod expected = GetParam();
    const std::string key("key");
    const JsonValue json = CreateFakeJsonValue(key, expected);
    std::optional<TransactionMethod> outField;

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
                         TransactionMethodToStringValidValueTest,
                         Values(std::pair<std::string, TransactionMethod>("",
                                                                          TransactionMethod::None),
                                std::pair<std::string, TransactionMethod>("ApproveCollection",
                                                                          TransactionMethod::ApproveCollection),
                                std::pair<std::string, TransactionMethod>("ApproveToken",
                                                                          TransactionMethod::ApproveToken),
                                std::pair<std::string, TransactionMethod>("BatchMint",
                                                                          TransactionMethod::BatchMint),
                                std::pair<std::string, TransactionMethod>("BatchSetAttribute",
                                                                          TransactionMethod::BatchSetAttribute),
                                std::pair<std::string, TransactionMethod>("BatchTransfer",
                                                                          TransactionMethod::BatchTransfer),
                                std::pair<std::string, TransactionMethod>("Burn",
                                                                          TransactionMethod::Burn),
                                std::pair<std::string, TransactionMethod>("CreateCollection",
                                                                          TransactionMethod::CreateCollection),
                                std::pair<std::string, TransactionMethod>("CreateToken",
                                                                          TransactionMethod::CreateToken),
                                std::pair<std::string, TransactionMethod>("Freeze",
                                                                          TransactionMethod::Freeze),
                                std::pair<std::string, TransactionMethod>("MintToken",
                                                                          TransactionMethod::MintToken),
                                std::pair<std::string, TransactionMethod>("MutateCollection",
                                                                          TransactionMethod::MutateCollection),
                                std::pair<std::string, TransactionMethod>("MutateToken",
                                                                          TransactionMethod::MutateToken),
                                std::pair<std::string, TransactionMethod>("OperatorTransferToken",
                                                                          TransactionMethod::OperatorTransferToken),
                                std::pair<std::string, TransactionMethod>("RemoveAllAttributes",
                                                                          TransactionMethod::RemoveAllAttributes),
                                std::pair<std::string, TransactionMethod>("RemoveCollectionAttribute",
                                                                          TransactionMethod::RemoveCollectionAttribute),
                                std::pair<std::string, TransactionMethod>("RemoveTokenAttribute",
                                                                          TransactionMethod::RemoveTokenAttribute),
                                std::pair<std::string, TransactionMethod>("SetCollectionAttribute",
                                                                          TransactionMethod::SetCollectionAttribute),
                                std::pair<std::string, TransactionMethod>("SetTokenAttribute",
                                                                          TransactionMethod::SetTokenAttribute),
                                std::pair<std::string, TransactionMethod>("SimpleTransferToken",
                                                                          TransactionMethod::SimpleTransferToken),
                                std::pair<std::string, TransactionMethod>("Thaw",
                                                                          TransactionMethod::Thaw),
                                std::pair<std::string, TransactionMethod>("TransferAllBalance",
                                                                          TransactionMethod::TransferAllBalance),
                                std::pair<std::string, TransactionMethod>("TransferBalance",
                                                                          TransactionMethod::TransferBalance),
                                std::pair<std::string, TransactionMethod>("UnapproveCollection",
                                                                          TransactionMethod::UnapproveCollection),
                                std::pair<std::string, TransactionMethod>("UnapproveToken",
                                                                          TransactionMethod::UnapproveToken)));

INSTANTIATE_TEST_SUITE_P(MatchValues,
                         TransactionMethodTryGetValidValueTest,
                         Values(TransactionMethod::ApproveCollection,
                                TransactionMethod::ApproveToken,
                                TransactionMethod::BatchMint,
                                TransactionMethod::BatchSetAttribute,
                                TransactionMethod::BatchTransfer,
                                TransactionMethod::Burn,
                                TransactionMethod::CreateCollection,
                                TransactionMethod::CreateToken,
                                TransactionMethod::DestroyCollection,
                                TransactionMethod::Freeze,
                                TransactionMethod::MintToken,
                                TransactionMethod::MutateCollection,
                                TransactionMethod::MutateToken,
                                TransactionMethod::OperatorTransferToken,
                                TransactionMethod::RemoveAllAttributes,
                                TransactionMethod::RemoveCollectionAttribute,
                                TransactionMethod::RemoveTokenAttribute,
                                TransactionMethod::SetCollectionAttribute,
                                TransactionMethod::SetTokenAttribute,
                                TransactionMethod::SimpleTransferToken,
                                TransactionMethod::Thaw,
                                TransactionMethod::TransferAllBalance,
                                TransactionMethod::TransferBalance,
                                TransactionMethod::UnapproveCollection,
                                TransactionMethod::UnapproveToken));
