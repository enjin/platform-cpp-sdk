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
#include "FileUtil.hpp"
#include "TestDataTestSuite.hpp"
#include <fstream>
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class FileUtilTest : public Test,
                     public TestDataTestSuite
{
};

TEST_F(FileUtilTest, GetFileContentWhenFileStreamIsNotOpenThrowsError)
{
    // Arrange
    std::ifstream file;

    // Assumptions
    ASSERT_THAT(file.is_open(), IsFalse()) << "Assume stream is not open";

    // Assert
    ASSERT_THROW(std::string s = FileUtil::GetFileContent(file), std::invalid_argument) << "Assert error is thrown";
}

TEST_F(FileUtilTest, GetFileContentWhenFileStreamIsOpenReturnsExpected)
{
    // Arrange
    const std::string expected(R"(Alpha file content.)");
    std::ifstream file(CreateTestDataPath("a.txt"));

    // Assumptions
    ASSERT_THAT(file.is_open(), IsTrue()) << "Assume stream is open";

    // Act
    const std::string actual = FileUtil::GetFileContent(file);

    // Assert
    ASSERT_THAT(actual, HasSubstr(expected)) << "Assert actual equals expected";
}
