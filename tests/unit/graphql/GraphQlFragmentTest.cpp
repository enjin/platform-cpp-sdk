#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockGraphQlFragment.hpp"
#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <memory>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class GraphQlFragmentImpl : public GraphQlFragment<GraphQlFragmentImpl>
{
public:
    GraphQlFragmentImpl() = default;

    ~GraphQlFragmentImpl() override = default;
};

class GraphQlFragmentTest : public Test
{
public:
    std::unique_ptr<GraphQlFragmentImpl> classUnderTest;

    // Mocks
    MockGraphQlFragmentPtr mockFragment;

protected:
    void SetUp() override
    {
        mockFragment = std::make_shared<NiceMockGraphQlFragment>();

        classUnderTest = std::make_unique<GraphQlFragmentImpl>();
    }
};

TEST_F(GraphQlFragmentTest, CompileFieldsWhenFragmentDoesNotHaveFieldsReturnsEmptyString)
{
    // Assumptions
    ASSERT_THAT(classUnderTest->HasFields(), IsFalse()) << "Assume fragment does not have fields";

    // Act
    const std::string actual = classUnderTest->CompileFields();

    // Assert
    ASSERT_THAT(actual.empty(), IsTrue()) << "Assert actual is empty";
}

TEST_F(GraphQlFragmentTest, CompileFieldsWhenFragmentHasFragmentFieldReturnsExpected)
{
    // Arrange - Data
    const std::string expected("field { innerField }");
    classUnderTest->WithField("field", mockFragment);

    // Arrange - Expectations & Stubbing
    EXPECT_CALL(*mockFragment, CompileFields())
        .Times(1)
        .WillRepeatedly(Return("innerField"));

    // Assumptions
    ASSERT_THAT(classUnderTest->HasFields(), IsTrue()) << "Assume fragment has fields";

    // Act
    const std::string actual = classUnderTest->CompileFields();

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert actual equals expected";

    // Verify (Done by GTest)
}

TEST_F(GraphQlFragmentTest, CompileFieldsWhenFragmentHasScalarFieldReturnsExpected)
{
    // Arrange
    const std::string expected("field");
    classUnderTest->WithField("field", true);

    // Assumptions
    ASSERT_THAT(classUnderTest->HasFields(), IsTrue()) << "Assume fragment has fields";

    // Act
    const std::string actual = classUnderTest->CompileFields();

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert actual equals expected";
}

TEST_F(GraphQlFragmentTest, CompileFieldsWhenFragmentHasFragmentAndScalarFieldsReturnsExpected)
{
    // Arrange
    const std::string expected("field1 field2 { innerField }");
    classUnderTest->WithField("field1", true);
    classUnderTest->WithField("field2", mockFragment);

    // Arrange - Expectations & Stubbing
    EXPECT_CALL(*mockFragment, CompileFields())
        .Times(1)
        .WillRepeatedly(Return("innerField"));

    // Assumptions
    ASSERT_THAT(classUnderTest->HasFields(), IsTrue()) << "Assume fragment has fields";

    // Act
    const std::string actual = classUnderTest->CompileFields();

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert actual equals expected";
}

TEST_F(GraphQlFragmentTest, HasFieldWhenFragmentDoesNotHaveFieldReturnsFalse)
{
    // Arrange
    const std::string name("field");

    // Act
    const bool actual = classUnderTest->HasField(name);

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(GraphQlFragmentTest, HasFieldWhenFragmentHasFragmentFieldReturnsTrue)
{
    // Arrange
    const std::string name("field");
    classUnderTest->WithField(name, mockFragment);

    // Act
    const bool actual = classUnderTest->HasField(name);

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(GraphQlFragmentTest, HasFieldWhenFragmentHasScalarFieldReturnsTrue)
{
    // Arrange
    const std::string name("field");
    classUnderTest->WithField(name, true);

    // Act
    const bool actual = classUnderTest->HasField(name);

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(GraphQlFragmentTest, HasFieldsWhenFragmentDoesNotHaveFieldsReturnsFalse)
{
    // Act
    const bool actual = classUnderTest->HasFields();

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(GraphQlFragmentTest, HasFieldsWhenFragmentHasFragmentFieldReturnsTrue)
{
    // Arrange
    classUnderTest->WithField("field", mockFragment);

    // Act
    const bool actual = classUnderTest->HasFields();

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(GraphQlFragmentTest, HasFieldsWhenFragmentHasScalarFieldReturnsTrue)
{
    // Arrange
    classUnderTest->WithField("field", true);

    // Act
    const bool actual = classUnderTest->HasFields();

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(GraphQlFragmentTest, WithFieldGivenFalseWhenFragmentDoesNotHaveFieldDoesNotThrowError)
{
    // Arrange
    const std::string name("field");
    const bool isIncluded = false;

    // Assumptions
    ASSERT_THAT(classUnderTest->HasField(name), IsFalse()) << "Assume fragment does not have field";

    // Assert
    ASSERT_NO_THROW(classUnderTest->WithField(name, isIncluded)) << "Assert no error on act";
}

TEST_F(GraphQlFragmentTest, WithFieldGivenFalseWhenFragmentHasFragmentFieldRemovesField)
{
    // Arrange
    const std::string name("field");
    const bool isIncluded = false;
    classUnderTest->WithField(name, mockFragment);

    // Assumptions
    ASSERT_THAT(classUnderTest->HasField(name), IsTrue()) << "Assume fragment has field";

    // Act
    classUnderTest->WithField(name, isIncluded);

    // Assert
    ASSERT_THAT(classUnderTest->HasField(name), IsFalse()) << "Assert field was removed from fragment";
}

TEST_F(GraphQlFragmentTest, WithFieldGivenFalseWhenFragmentHasScalarFieldRemovesField)
{
    // Arrange
    const std::string name("field");
    const bool isIncluded = false;
    classUnderTest->WithField(name, true);

    // Assumptions
    ASSERT_THAT(classUnderTest->HasField(name), IsTrue()) << "Assume fragment has field";

    // Act
    classUnderTest->WithField(name, isIncluded);

    // Assert
    ASSERT_THAT(classUnderTest->HasField(name), IsFalse()) << "Assert field was removed from fragment";
}

TEST_F(GraphQlFragmentTest, WithFieldGivenNullFragmentFieldDoesNotAddFragment)
{
    // Arrange
    const std::string name("field");
    GraphQlFragmentPtr fragment = nullptr;

    // Assumptions
    ASSERT_THAT(classUnderTest->HasField(name), IsFalse()) << "Assume fragment does not have field";

    // Act
    classUnderTest->WithField(name, fragment);

    // Assert
    ASSERT_THAT(classUnderTest->HasField(name), IsFalse()) << "Assert field was not added to fragment";
}
