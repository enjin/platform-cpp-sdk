#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/IntegerRange.hpp"
#include <string>
#include <tuple>

using namespace enjin::platform::sdk;
using namespace testing;

class IntegerRangeSingleValueTest : public TestWithParam<std::tuple<std::string, std::string>>
{
};

class IntegerRangeStartAndEndValuesTest : public TestWithParam<std::tuple<std::string, std::string, std::string>>
{
};

TEST_P(IntegerRangeSingleValueTest, ToStringReturnsExpected)
{
    // Arrange
    const std::string expected = std::get<1>(GetParam());
    const std::string value = std::get<0>(GetParam());
    const IntegerRange range(value);

    // Act
    const std::string actual = range.ToString();

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(IntegerRangeStartAndEndValuesTest, ToStringReturnsExpected)
{
    // Arrange
    const std::string expected = std::get<2>(GetParam());
    const std::string start = std::get<0>(GetParam());
    const std::string end = std::get<1>(GetParam());
    const IntegerRange range(start, end);

    // Act
    const std::string actual = range.ToString();

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

INSTANTIATE_TEST_SUITE_P(ToStringWithSingleValue,
                         IntegerRangeSingleValueTest,
                         Values(std::tuple<std::string, std::string>("0", R"("0")"),
                                std::tuple<std::string, std::string>("1000", R"("1000")")));

INSTANTIATE_TEST_SUITE_P(ToStringWithStartAndEndValues,
                         IntegerRangeStartAndEndValuesTest,
                         Values(std::tuple<std::string, std::string, std::string>("0", "0", R"("0")"),
                                std::tuple<std::string, std::string, std::string>("0", "1000", R"("0..1000")")));
