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
