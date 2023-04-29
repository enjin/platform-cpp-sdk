#include "gtest/gtest.h"
#include "RapidJsonUtil.hpp"
#include "rapidjson/document.h"
#include <string>

using namespace enjin::platform::sdk;
using namespace rapidjson;
using namespace testing;

class RapidJsonUtilTest : public Test
{
};

TEST_F(RapidJsonUtilTest, DocumentToString)
{
    // Arrange
    const std::string expected(R"({"key":"value"})");
    Document document;
    document.Parse(expected.c_str());

    // Act
    const std::string actual = RapidJsonUtil::DocumentToString(document);

    // Assert
    ASSERT_EQ(actual, expected);
}
