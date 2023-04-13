#include "gtest/gtest.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <memory>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class ScalarGraphQlRequestImpl : public GraphQlRequest<ScalarGraphQlRequestImpl>
{
public:
    ScalarGraphQlRequestImpl()
        : GraphQlRequest<ScalarGraphQlRequestImpl>("Request", GraphQlRequestType::Query)
    {
    }

    ~ScalarGraphQlRequestImpl() override = default;
};

class ScalarGraphQlRequestTest : public Test
{
public:
    std::unique_ptr<ScalarGraphQlRequestImpl> classUnderTest;

protected:
    void SetUp() override
    {
        classUnderTest = std::make_unique<ScalarGraphQlRequestImpl>();
    }
};

TEST_F(ScalarGraphQlRequestTest, ToStringReturnsExpected)
{
    // Arrange
    const std::string expected("query { result: Request }");

    // Act
    const std::string actual = classUnderTest->ToString();

    // Assert
    ASSERT_EQ(actual, expected);
}
