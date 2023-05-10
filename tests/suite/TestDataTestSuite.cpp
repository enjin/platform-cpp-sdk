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
