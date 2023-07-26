#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdkBeam/BeamFlag.hpp"
#include "EnjinPlatformSdkBeam/BeamFlagInputType.hpp"
#include <memory>

using namespace enjin::platform::sdk::beam;
using namespace testing;

class BeamFlagInputTypeTestSuite
{
public:
    static inline const std::string FlagKey = "flag";
};

class BeamFlagInputTypeTest : public Test,
                              public BeamFlagInputTypeTestSuite
{
public:
    std::unique_ptr<BeamFlagInputType> classUnderTest;

protected:
    void SetUp() override
    {
        Test::SetUp();

        classUnderTest = std::make_unique<BeamFlagInputType>();
    }
};

class BeamFlagInputTypeSetFlagParameterTest : public TestWithParam<BeamFlag>,
                                              public BeamFlagInputTypeTestSuite
{
public:
    std::unique_ptr<BeamFlagInputType> classUnderTest;

protected:
    void SetUp() override
    {
        Test::SetUp();

        classUnderTest = std::make_unique<BeamFlagInputType>();
    }
};

TEST_F(BeamFlagInputTypeTest, SetFlagGivenNoneFlagUnsetsParameter)
{
    // Arrange
    const BeamFlag flag = BeamFlag::None;
    classUnderTest->SetFlag(BeamFlag::Paused);

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameter(FlagKey), IsTrue())
                        << "Assume that " << FlagKey << " parameter is set";

    // Act
    classUnderTest->SetFlag(flag);

    // Assert
    ASSERT_THAT(classUnderTest->HasParameter(FlagKey), IsFalse())
                        << "Assert that " << FlagKey << " parameter was unset";
}

TEST_P(BeamFlagInputTypeSetFlagParameterTest, SetFlagGivenNonNoneFlagSetsParameter)
{
    // Arrange
    const BeamFlag flag = GetParam();

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameter(FlagKey), IsFalse())
                        << "Assume that " << FlagKey << " parameter is not set";

    // Act
    classUnderTest->SetFlag(flag);

    // Assert
    ASSERT_THAT(classUnderTest->HasParameter(FlagKey), IsTrue())
                        << "Assert that " << FlagKey << " parameter was unset";
}

INSTANTIATE_TEST_SUITE_P(SetFlagParameter,
                         BeamFlagInputTypeSetFlagParameterTest,
                         Values(BeamFlag::Paused,
                                BeamFlag::SingleUse,
                                BeamFlag::Prunable));
