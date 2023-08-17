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
