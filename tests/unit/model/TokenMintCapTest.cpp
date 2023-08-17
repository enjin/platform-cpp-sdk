#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/TokenMintCap.hpp"
#include "EnjinPlatformSdk/TokenMintCapType.hpp"
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class TokenMintCapTestSuite
{
public:
    static constexpr char TypeKey[] = "type";
};

class TokenMintCapTest : public Test,
                         public TokenMintCapTestSuite
{
};

class TokenMintCapSetTypeValidValuesTest : public TestWithParam<TokenMintCapType>,
                                           public TokenMintCapTestSuite
{
};

TEST_F(TokenMintCapTest, SetTypeGivenNoneValueWhenTypeParameterIsNotSetDoesNothing)
{
    // Arrange
    const TokenMintCapType type = TokenMintCapType::None;
    TokenMintCap model;

    // Assumptions
    ASSERT_THAT(model.GetParameters(), Not(Contains(Key(TypeKey)))) << "Assume model does not have type parameter";

    // Act
    model.SetType(type);

    // Assert
    ASSERT_THAT(model.GetParameters(), Not(Contains(Key(TypeKey)))) << "Assert type parameter was not set";
}

TEST_F(TokenMintCapTest, SetTypeGivenNoneValueWhenTypeParameterIsSetUnsetsParameter)
{
    // Arrange
    const TokenMintCapType type = TokenMintCapType::None;
    TokenMintCap model;
    model.SetType(TokenMintCapType::SingleMint);

    // Assumptions
    ASSERT_THAT(model.GetParameters(), Contains(Key(TypeKey))) << "Assume model has type parameter";

    // Act
    model.SetType(type);

    // Assert
    ASSERT_THAT(model.GetParameters(), Not(Contains(Key(TypeKey)))) << "Assert type parameter was unset";
}

TEST_P(TokenMintCapSetTypeValidValuesTest, SetTypeGivenNonNoneValueSetsParameter)
{
    // Arrange
    const TokenMintCapType type = GetParam();
    TokenMintCap model;

    // Assumptions
    ASSERT_THAT(model.GetParameters(), Not(Contains(Key(TypeKey)))) << "Assume model does not have type parameter";

    // Act
    model.SetType(type);

    // Assert
    ASSERT_THAT(model.GetParameters(), Contains(Key(TypeKey))) << "Assert that type parameter was set";
}

INSTANTIATE_TEST_SUITE_P(SetParameter,
                         TokenMintCapSetTypeValidValuesTest,
                         Values(TokenMintCapType::SingleMint,
                                TokenMintCapType::Supply));
