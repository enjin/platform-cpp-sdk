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

#ifndef ENJINPLATFORMSDK_TESTDATATESTSUITE_HPP
#define ENJINPLATFORMSDK_TESTDATATESTSUITE_HPP

#include <string>

/// \brief Test suite to assist in accessing test data files.
class TestDataTestSuite
{
public:
    /// \brief Class destructor.
    ~TestDataTestSuite();

    /// \brief Creates a path to the given test data file.
    /// \param path The relative path of the file within the test data folder.
    /// \return The full path to the test data file.
    [[maybe_unused]]
    [[nodiscard]]
    static std::string CreateTestDataPath(const std::string& path);

protected:
    /// \brief Constructs an instance of this class.
    TestDataTestSuite();

    /// \brief Checks that the directory is valid. Automatically fails the test if not.
    static void ValidateDirectory();
};

#endif //ENJINPLATFORMSDK_TESTDATATESTSUITE_HPP
