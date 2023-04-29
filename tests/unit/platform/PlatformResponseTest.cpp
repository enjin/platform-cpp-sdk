#include "gtest/gtest.h"
#include "EnjinPlatformSdk/PlatformResponse.hpp"

using namespace enjin::platform::sdk;
using namespace testing;

class PlatformResponseSuccessCodesTest : public TestWithParam<int>
{
};

class PlatformResponseCodes0To199Test : public TestWithParam<int>
{
};

class PlatformResponseCodes300To500Test : public TestWithParam<int>
{
};

TEST_P(PlatformResponseSuccessCodesTest, IsSuccessStatusCodeForSuccessfulCodesReturnsTrue)
{
    // Arrange
    const int statusCode = GetParam();
    PlatformResponse<bool> res(statusCode, {}, {});

    // Act
    const bool actual = res.IsSuccessStatusCode();

    // Assert
    ASSERT_TRUE(actual) << "Assert true for status code " << statusCode;
}

TEST_P(PlatformResponseCodes0To199Test, IsSuccessStatusCodeForCodes0To199ReturnsFalse)
{
    // Arrange
    const int statusCode = GetParam();
    PlatformResponse<bool> res(statusCode, {}, {});

    // Act
    const bool actual = res.IsSuccessStatusCode();

    // Assert
    ASSERT_FALSE(actual) << "Assert false for status code " << statusCode;
}

TEST_P(PlatformResponseCodes300To500Test, IsSuccessStatusCodeForCodes300To500ReturnsFalse)
{
    // Arrange
    const int statusCode = GetParam();
    PlatformResponse<bool> res(statusCode, {}, {});

    // Act
    const bool actual = res.IsSuccessStatusCode();

    // Assert
    ASSERT_FALSE(actual) << "Assert false for status code " << statusCode;
}

INSTANTIATE_TEST_SUITE_P(SuccessCodes,
                         PlatformResponseSuccessCodesTest,
                         Range(200, 300));

INSTANTIATE_TEST_SUITE_P(Codes0To199,
                         PlatformResponseCodes0To199Test,
                         Range(0, 200));

INSTANTIATE_TEST_SUITE_P(Codes300To500,
                         PlatformResponseCodes300To500Test,
                         Range(300, 501));
