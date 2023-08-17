#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockSerializable.hpp"
#include "EnjinPlatformSdk/GraphQlParameterHolder.hpp"
#include <memory>

using namespace enjin::platform::sdk;
using namespace testing;

class GraphQlParameterHolderImpl : public GraphQlParameterHolder<GraphQlParameterHolderImpl>
{
public:
    GraphQlParameterHolderImpl() = default;

    ~GraphQlParameterHolderImpl() override = default;
};

class GraphQlParameterHolderTest : public Test
{
public:
    std::unique_ptr<GraphQlParameterHolderImpl> classUnderTest;

    // Mocks
    MockSerializablePtr mockValue;

protected:
    void SetUp() override
    {
        mockValue = std::make_shared<NiceMockSerializable>();

        classUnderTest = std::make_unique<GraphQlParameterHolderImpl>();
    }
};

TEST_F(GraphQlParameterHolderTest, CompileParametersWhenHolderHasNoParametersReturnsExpected)
{
    // Arrange
    const std::string expected;

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameters(), IsFalse()) << "Assume that holder has no parameters";

    // Act
    const std::string actual = classUnderTest->CompileParameters();

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert that actual equals expected";
}

TEST_F(GraphQlParameterHolderTest, CompileParametersWhenHolderHasParametersReturnsExpected)
{
    // Arrange - Data
    const std::string expected(R"(param: "value")");
    classUnderTest->SetParameter("param", mockValue);

    // Arrange - Stubbing
    EXPECT_CALL(*mockValue, ToString())
        .WillRepeatedly(Return(R"("value")"));

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameters(), IsTrue()) << "Assume that holder has parameters";

    // Act
    const std::string actual = classUnderTest->CompileParameters();

    // Assert
    ASSERT_THAT(actual, Eq(expected)) << "Assert that actual equals expected";
}

TEST_F(GraphQlParameterHolderTest, HasParameterWhenParameterIsNotSetReturnsFalse)
{
    // Arrange
    const std::string& key("key");

    // Act
    const bool actual = classUnderTest->HasParameter(key);

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(GraphQlParameterHolderTest, HasParameterWhenParameterIsSetReturnsTrue)
{
    // Arrange
    const std::string& key("key");
    classUnderTest->SetParameter(key, mockValue);

    // Act
    const bool actual = classUnderTest->HasParameter(key);

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(GraphQlParameterHolderTest, HasParametersWhenHolderHasNoParametersReturnsFalse)
{
    // Act
    const bool actual = classUnderTest->HasParameters();

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(GraphQlParameterHolderTest, HasParametersWhenHolderHasParametersReturnsTrue)
{
    // Arrange
    classUnderTest->SetParameter("key", mockValue);

    // Act
    const bool actual = classUnderTest->HasParameters();

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(GraphQlParameterHolderTest, RemoveParameterWhenHolderDoesNotHaveParameterDoesNotThrowError)
{
    // Arrange
    const std::string key("key");

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameter(key), IsFalse()) << "Assume that holder does not have parameter";

    // Assert
    ASSERT_NO_THROW(classUnderTest->RemoveParameter(key)) << "Assert that error is not thrown";
}

TEST_F(GraphQlParameterHolderTest, RemoveParameterWhenHolderHasParameterParameterIsRemoved)
{
    // Arrange
    const std::string key("key");
    classUnderTest->SetParameter(key, mockValue);

    // Assumptions
    ASSERT_THAT(classUnderTest->HasParameter(key), IsTrue()) << "Assume that holder has parameter";

    // Act
    classUnderTest->RemoveParameter(key);

    // Assert
    ASSERT_THAT(classUnderTest->HasParameter(key), IsFalse()) << "Assert that parameter was removed";
}
