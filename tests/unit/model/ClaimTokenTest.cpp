#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdkBeam/BeamType.hpp"
#include "EnjinPlatformSdkBeam/ClaimToken.hpp"
#include <memory>

using namespace enjin::platform::sdk::beam;
using namespace testing;

class ClaimTokenTestSuite
{
public:
    static inline const std::string TypeKey = "type";
};

class ClaimTokenTest : public Test,
                       public ClaimTokenTestSuite
{
public:
    std::unique_ptr<ClaimToken> classUnderTest;

protected:
    void SetUp() override
    {
        Test::SetUp();

        classUnderTest = std::make_unique<ClaimToken>();
    }
};

class ClaimTokenSetTypeParameterTest : public TestWithParam<BeamType>,
                                       public ClaimTokenTestSuite
{
public:
    std::unique_ptr<ClaimToken> classUnderTest;

protected:
    void SetUp() override
    {
        Test::SetUp();

        classUnderTest = std::make_unique<ClaimToken>();
    }
};

TEST_F(ClaimTokenTest, SetTypeGivenNoneTypeUnsetsParameter)
{
    // Arrange
    const BeamType type = BeamType::None;
    classUnderTest->SetType(BeamType::TransferToken);

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameters(), IsTrue()) << "Assume that parameter is set";

    // Act
    classUnderTest->SetType(type);

    // Assert
    ASSERT_THAT(classUnderTest->HasParameters(), IsFalse()) << "Assert that parameter was unset";
}

TEST_P(ClaimTokenSetTypeParameterTest, SetTypeGivenNonNoneTypeSetsParameter)
{
    // Arrange
    const BeamType type = GetParam();

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameters(), IsFalse()) << "Assume that parameter is not set";

    // Act
    classUnderTest->SetType(type);

    // Assert
    ASSERT_THAT(classUnderTest->HasParameters(), IsTrue()) << "Assert that parameter was unset";
}

INSTANTIATE_TEST_SUITE_P(SetTypeParameter,
                         ClaimTokenSetTypeParameterTest,
                         Values(BeamType::TransferToken,
                                BeamType::MintOnDemand));
