#include "TestDataTestSuite.hpp"

#include "gtest/gtest.h"
#include <filesystem>
#include <sstream>

#ifndef TEST_DATA_DIRECTORY
#define TEST_DATA_DIRECTORY 0
#endif

namespace fs = std::filesystem;

TestDataTestSuite::TestDataTestSuite() = default;

TestDataTestSuite::~TestDataTestSuite() = default;

[[maybe_unused]]
std::string TestDataTestSuite::CreateTestDataPath(const std::string& path)
{
    TestDataTestSuite::ValidateDirectory();

    std::stringstream ss;

    ss << TEST_DATA_DIRECTORY << "/" << path;

    return ss.str();
}

void TestDataTestSuite::ValidateDirectory()
{
    if (TEST_DATA_DIRECTORY == nullptr)
    {
        FAIL() << "Cannot create test data path when data directory has not been defined by the compiler";
    }
    else if (!fs::is_directory(std::string(TEST_DATA_DIRECTORY)))
    {
        FAIL() << "Cannot create test data path when path defined by the compiler is not a directory: \""
               << TEST_DATA_DIRECTORY
               << "\"";
    }
}
