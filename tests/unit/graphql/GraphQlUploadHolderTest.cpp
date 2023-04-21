#include "gtest/gtest.h"
#include "EnjinPlatformSdk/GraphQlUploadHolder.hpp"
#include <memory>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class GraphQlUploadHolderImpl : public GraphQlUploadHolder
{
public:
    GraphQlUploadHolderImpl() = default;

    ~GraphQlUploadHolderImpl() override = default;

    void UploadAdded(const std::string& key) override
    {
        GraphQlUploadHolder::UploadAdded(key);
    }

    void UploadAdded(const std::string& key, const int count) override
    {
        GraphQlUploadHolder::UploadAdded(key, count);
    }

    void UploadRemoved(const std::string& key) override
    {
        GraphQlUploadHolder::UploadRemoved(key);
    }
};

class GraphQlUploadHolderTest : public Test
{
public:
    std::unique_ptr<GraphQlUploadHolderImpl> classUnderTest;

protected:
    void SetUp() override
    {
        classUnderTest = std::make_unique<GraphQlUploadHolderImpl>();
    }
};

TEST_F(GraphQlUploadHolderTest, UploadAddedForOneCreatesExpectedEntryInPaths)
{
    // Arrange
    const std::string key("key");

    // Assumptions
    ASSERT_TRUE(classUnderTest->GetUploadParameterPaths().empty()) << "Assume holder has no paths";

    // Act
    classUnderTest->UploadAdded(key);

    // Assert
    ASSERT_TRUE(classUnderTest->GetUploadParameterPaths().contains(key)) << "Assert holder contains paths";
}

TEST_F(GraphQlUploadHolderTest, UploadAddedForManyCreatesExpectedEntryInPaths)
{
    // Arrange
    const std::string expected1("key.0");
    const std::string expected2("key.1");
    const std::string expected3("key.2");
    const std::string key("key");
    const int count = 3;

    // Assumptions
    ASSERT_TRUE(classUnderTest->GetUploadParameterPaths().empty()) << "Assume holder paths is empty";

    // Act
    classUnderTest->UploadAdded(key, count);

    // Assert
    EXPECT_TRUE(classUnderTest->GetUploadParameterPaths().contains(expected1))
                    << "Assert holder contains \"" << expected1 << "\" path";
    EXPECT_TRUE(classUnderTest->GetUploadParameterPaths().contains(expected2))
                    << "Assert holder contains \"" << expected2 << "\" path";
    EXPECT_TRUE(classUnderTest->GetUploadParameterPaths().contains(expected3))
                    << "Assert holder contains \"" << expected3 << "\" path";
}

TEST_F(GraphQlUploadHolderTest, UploadRemovedWhenPathDoesNotExistsDoesNotThrowError)
{
    // Arrange
    const std::string key("key");

    // Assumptions
    ASSERT_FALSE(classUnderTest->GetUploadParameterPaths().contains(key)) << "Assume holder does not have path";

    // Act
    classUnderTest->UploadRemoved(key);

    // Assert
    ASSERT_NO_THROW(classUnderTest->UploadRemoved(key)) << "Assert no error is thrown";
}

TEST_F(GraphQlUploadHolderTest, UploadRemovedWhenPathExistsRemovesPath)
{
    // Arrange
    const std::string key("key");
    classUnderTest->UploadAdded(key);

    // Assumptions
    ASSERT_TRUE(classUnderTest->GetUploadParameterPaths().contains(key)) << "Assume holder has path";

    // Act
    classUnderTest->UploadRemoved(key);

    // Assert
    ASSERT_FALSE(classUnderTest->GetUploadParameterPaths().contains(key)) << "Assert holder does not have path";
}
