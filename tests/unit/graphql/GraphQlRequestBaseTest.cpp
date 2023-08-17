#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockSerializable.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdk/internal/GraphQlRequestBase.hpp"
#include <memory>
#include <sstream>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class GraphQlRequestBaseImpl : public GraphQlRequestBase<GraphQlRequestBaseImpl>
{
public:
    GraphQlRequestBaseImpl()
        : GraphQlRequestBase("Request", GraphQlRequestType::Query)
    {
    }

    ~GraphQlRequestBaseImpl() override = default;

    void AppendHeader(std::stringstream& ss) const
    {
        GraphQlRequestBase<GraphQlRequestBaseImpl>::AppendHeader(ss);
    }

    // region IGraphQlRequest

    [[maybe_unused]]
    [[nodiscard]]
    std::string Compile() const override
    {
        return {};
    }

    // endregion IGraphQlRequest
};

class GraphQlRequestBaseTest : public Test
{
public:
    std::unique_ptr<GraphQlRequestBaseImpl> classUnderTest;

    // Mocks
    MockSerializablePtr mockParameterValue;
    MockSerializablePtr mockVariableValue;

protected:
    void SetUp() override
    {
        mockParameterValue = std::make_shared<NiceMockSerializable>();
        mockVariableValue = std::make_shared<NiceMockSerializable>();

        classUnderTest = std::make_unique<GraphQlRequestBaseImpl>();
    }
};

TEST_F(GraphQlRequestBaseTest, AppendHeadersWhenRequestHasNoVariablesOrParametersAppendsExpectedToStream)
{
    // Arrange
    const std::string expected(R"(query { result: Request)");
    std::stringstream ss;

    // Act
    classUnderTest->AppendHeader(ss);

    // Assert
    ASSERT_EQ(ss.str(), expected);
}

TEST_F(GraphQlRequestBaseTest, AppendHeadersWhenRequestHasVariablesAndNoParametersAppendsExpectedToStream)
{
    // Arrange
    const std::string expected(R"(query ($var: String!) { result: Request(var: $var))");
    std::stringstream ss;
    classUnderTest->SetVariable("var", "String!", mockVariableValue);

    // Act
    classUnderTest->AppendHeader(ss);

    // Assert
    ASSERT_EQ(ss.str(), expected);
}

TEST_F(GraphQlRequestBaseTest, AppendHeadersWhenRequestHasParametersAndNoVariablesAppendsExpectedToStream)
{
    // Arrange - Data
    const std::string expected(R"(query { result: Request(param: "value"))");
    std::stringstream ss;
    classUnderTest->SetParameter("param", mockParameterValue);

    // Arrange - Stubbing
    EXPECT_CALL(*mockParameterValue, ToString())
        .WillRepeatedly(Return(R"("value")"));

    // Act
    classUnderTest->AppendHeader(ss);

    // Assert
    ASSERT_EQ(ss.str(), expected);
}

TEST_F(GraphQlRequestBaseTest, AppendHeadersWhenRequestHasVariablesAndParametersAppendsExpectedToStream)
{
    // Arrange - Data
    const std::string expected(R"(query ($var: String!) { result: Request(var: $var, param: "value"))");
    std::stringstream ss;
    classUnderTest->SetVariable("var", "String!", mockVariableValue);
    classUnderTest->SetParameter("param", mockParameterValue);

    // Arrange - Stubbing
    EXPECT_CALL(*mockParameterValue, ToString())
        .WillRepeatedly(Return(R"("value")"));

    // Act
    classUnderTest->AppendHeader(ss);

    // Assert
    ASSERT_EQ(ss.str(), expected);
}

TEST_F(GraphQlRequestBaseTest, GetVariablesWithoutTypesWhenRequestHasNoVariablesReturnsExpected)
{
    // Arrange
    const std::map<std::string, SerializablePtr> expected;

    // Act
    const std::map<std::string, SerializablePtr> actual = classUnderTest->GetVariablesWithoutTypes();

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_F(GraphQlRequestBaseTest, GetVariablesWithoutTypesWhenRequestHasVariablesReturnsExpected)
{
    // Arrange - Data
    const std::map<std::string, SerializablePtr> expected = {{"var", mockVariableValue}};
    classUnderTest->SetVariable("var", "String!", mockVariableValue);

    // Arrange - Stubbing
    EXPECT_CALL(*mockVariableValue, ToJson())
        .WillRepeatedly(Return(JsonValue::FromJson(R"("value")")));

    // Act
    const std::map<std::string, SerializablePtr> actual = classUnderTest->GetVariablesWithoutTypes();

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_F(GraphQlRequestBaseTest, HasVariablesWhenRequestHasNoVariablesReturnsFalse)
{
    // Act
    const bool actual = classUnderTest->HasVariables();

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GraphQlRequestBaseTest, HasVariablesWhenRequestHasVariablesReturnsTrue)
{
    // Arrange
    classUnderTest->SetVariable("var", "String!", mockVariableValue);

    // Act
    const bool actual = classUnderTest->HasVariables();

    // Assert
    ASSERT_TRUE(actual);
}
