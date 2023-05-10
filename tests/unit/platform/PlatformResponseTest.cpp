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
    ASSERT_THAT(actual, IsTrue()) << "Assert true for status code " << statusCode;
}

TEST_P(PlatformResponseCodes0To199Test, IsSuccessStatusCodeForCodes0To199ReturnsFalse)
{
    // Arrange
    const int statusCode = GetParam();
    PlatformResponse<bool> res(statusCode, {}, {});

    // Act
    const bool actual = res.IsSuccessStatusCode();

    // Assert
    ASSERT_THAT(actual, IsFalse()) << "Assert false for status code " << statusCode;
}

TEST_P(PlatformResponseCodes300To500Test, IsSuccessStatusCodeForCodes300To500ReturnsFalse)
{
    // Arrange
    const int statusCode = GetParam();
    PlatformResponse<bool> res(statusCode, {}, {});

    // Act
    const bool actual = res.IsSuccessStatusCode();

    // Assert
    ASSERT_THAT(actual, IsFalse()) << "Assert false for status code " << statusCode;
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
