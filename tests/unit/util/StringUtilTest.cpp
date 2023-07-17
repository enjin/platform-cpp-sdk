#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "StringUtil.hpp"
#include <string>
#include <utility>

using namespace enjin::platform::sdk;
using namespace testing;

class StringUtilToLowerTest : public TestWithParam<std::pair<std::string, std::string>>
{
};

class StringUtilToUpperTest : public TestWithParam<std::pair<std::string, std::string>>
{
};

TEST_P(StringUtilToLowerTest, ToLowerReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const std::string s(GetParam().second);

    // Act
    const std::string actual = StringUtil::ToLower(s);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(StringUtilToUpperTest, ToUpperReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam().first);
    const std::string s(GetParam().second);

    // Act
    const std::string actual = StringUtil::ToUpper(s);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

INSTANTIATE_TEST_SUITE_P(ToLower,
                         StringUtilToLowerTest,
                         Values(std::pair<std::string, std::string>("", ""),
                                std::pair<std::string, std::string>("abc", "ABC"),
                                std::pair<std::string, std::string>("abc", "abc"),
                                std::pair<std::string, std::string>("123", "123")));

INSTANTIATE_TEST_SUITE_P(ToUpper,
                         StringUtilToUpperTest,
                         Values(std::pair<std::string, std::string>("", ""),
                                std::pair<std::string, std::string>("ABC", "abc"),
                                std::pair<std::string, std::string>("ABC", "ABC"),
                                std::pair<std::string, std::string>("123", "123")));
