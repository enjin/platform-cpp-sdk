#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockStringSerializable.hpp"
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
    MockStringSerializablePtr mockValue;

protected:
    void SetUp() override
    {
        mockValue = std::make_shared<NiceMockStringSerializable>();

        classUnderTest = std::make_unique<GraphQlParameterHolderImpl>();
    }
};

TEST_F(GraphQlParameterHolderTest, CompileParametersWhenHolderHasNoParametersReturnsExpected)
{
    // Arrange
    const std::string expected;

    // Assumptions
    ASSERT_FALSE(classUnderTest->HasParameters()) << "Assume holder has no parameters";

    // Act
    const std::string actual = classUnderTest->CompileParameters();

    // Assert
    ASSERT_EQ(actual, expected) << "Assert actual equals expected";
}

TEST_F(GraphQlParameterHolderTest, CompileParametersWhenHolderHasNonListedParametersReturnsExpected)
{
    // Arrange - Data
    const std::string expected(R"(param: "value")");
    classUnderTest->SetParameter("param", mockValue);

    // Arrange - Stubbing
    EXPECT_CALL(*mockValue, ToString())
        .WillRepeatedly(Return(R"("value")"));

    // Assumptions
    ASSERT_TRUE(classUnderTest->HasParameters()) << "Assume holder has parameters";

    // Act
    const std::string actual = classUnderTest->CompileParameters();

    // Assert
    ASSERT_EQ(actual, expected) << "Assert actual equals expected";
}

TEST_F(GraphQlParameterHolderTest, CompileParametersWhenHolderHasListedParametersReturnsExpected)
{
    // Arrange - Data
    const std::string expected(R"(param: ["value", "value", "value"])");
    const std::vector<StringSerializablePtr> values = {mockValue, mockValue, mockValue};
    classUnderTest->SetParameter("param", values);

    // Arrange - Stubbing
    EXPECT_CALL(*mockValue, ToString())
        .WillRepeatedly(Return(R"("value")"));

    // Assumptions
    ASSERT_TRUE(classUnderTest->HasParameters()) << "Assume holder has parameters";

    // Act
    const std::string actual = classUnderTest->CompileParameters();

    // Assert
    ASSERT_EQ(actual, expected) << "Assert actual equals expected";
}

TEST_F(GraphQlParameterHolderTest, CompileParametersWhenHolderHasListedAndNonListedParametersReturnsExpected)
{
    // Arrange - Data
    const std::string expected(R"(param1: "value", param2: ["value", "value", "value"])");
    const std::vector<StringSerializablePtr> values = {mockValue, mockValue, mockValue};
    classUnderTest->SetParameter("param1", mockValue);
    classUnderTest->SetParameter("param2", values);

    // Arrange - Stubbing
    EXPECT_CALL(*mockValue, ToString())
        .WillRepeatedly(Return(R"("value")"));

    // Assumptions
    ASSERT_TRUE(classUnderTest->HasParameters()) << "Assume holder has parameters";

    // Act
    const std::string actual = classUnderTest->CompileParameters();

    // Assert
    ASSERT_EQ(actual, expected) << "Assert actual equals expected";
}

TEST_F(GraphQlParameterHolderTest, HasParametersWhenHolderHasNoParametersReturnsFalse)
{
    // Act
    const bool actual = classUnderTest->HasParameters();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GraphQlParameterHolderTest, HasParametersWhenHolderHasParametersReturnsTrue)
{
    // Arrange
    classUnderTest->SetParameter("key", mockValue);

    // Act
    const bool actual = classUnderTest->HasParameters();

    // Assert
    ASSERT_TRUE(actual);
}
