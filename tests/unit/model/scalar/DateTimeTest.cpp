#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/DateTime.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <chrono>
#include <string>
#include <tuple>

using namespace enjin::platform::sdk;
using namespace testing;
using Year = std::chrono::year;
using Month = std::chrono::month;
using Day = std::chrono::day;
using Hour = std::chrono::hours;
using Minute = std::chrono::minutes;
using Second = std::chrono::seconds;
using Millisecond = std::chrono::milliseconds;
using DateTimeTestParam = std::tuple<std::string, Year, Month, Day, Hour, Minute, Second, Millisecond>;

class DateTimeTest : public Test
{
public:
    static inline const std::string Year1999 = "1999-01-01T00:00:00+00:00";
    static inline const std::string Year2000 = "2000-01-01T00:00:00+00:00";
};

class DateTimeParseTest : public TestWithParam<DateTimeTestParam>
{
};

class DateTimeSerializeTest : public TestWithParam<std::string>
{
};

TEST_F(DateTimeTest, EqualityWhenBothSidesAreNotEqualResturnsFalse)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year1999);

    // Act
    const bool actual = lhs == rhs;

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(DateTimeTest, EqualityWhenBothSidesAreEqualResturnsTrue)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs == rhs;

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(DateTimeTest, InequalityWhenBothSidesAreEqualResturnsFalse)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs != rhs;

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(DateTimeTest, InequalityWhenBothSidesAreNotEqualResturnsTrue)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year1999);

    // Act
    const bool actual = lhs != rhs;

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(DateTimeTest, GreaterThanWhenLeftHandSideIsEqualToRightHandSideResturnsFalse)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs > rhs;

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(DateTimeTest, GreaterThanWhenLeftHandSideIsLessThanRightHandSideResturnsFalse)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year1999);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs > rhs;

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(DateTimeTest, GreaterThanWhenLeftHandSideIsGreaterThanRightHandSideResturnsTrue)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year1999);

    // Act
    const bool actual = lhs > rhs;

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(DateTimeTest, LessThanWhenLeftHandSideIsEqualToRightHandSideResturnsFalse)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs < rhs;

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(DateTimeTest, LessThanWhenLeftHandSideIsGreaterThanRightHandSideResturnsFalse)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year1999);

    // Act
    const bool actual = lhs < rhs;

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(DateTimeTest, LessThanWhenLeftHandSideIsGreaterThanRightHandSideResturnsTrue)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year1999);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs < rhs;

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(DateTimeTest, GreaterThanOrEqualToWhenLeftHandSideIsLessThanRightHandSideResturnsFalse)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year1999);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs >= rhs;

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(DateTimeTest, GreaterThanOrEqualToWhenLeftHandSideIsEqualToRightHandSideResturnsTrue)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs >= rhs;

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(DateTimeTest, GreaterThanOrEqualToWhenLeftHandSideIsGreaterThanRightHandSideResturnsTrue)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year1999);

    // Act
    const bool actual = lhs >= rhs;

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(DateTimeTest, LessThanOrEqualToWhenLeftHandSideIsGreaterThanRightHandSideResturnsFalse)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year1999);

    // Act
    const bool actual = lhs <= rhs;

    // Assert
    ASSERT_THAT(actual, IsFalse());
}

TEST_F(DateTimeTest, LessThanOrEqualToWhenLeftHandSideIsEqualToRightHandSideResturnsTrue)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year2000);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs <= rhs;

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_F(DateTimeTest, LessThanOrEqualToWhenLeftHandSideIsLessThanRightHandSideResturnsTrue)
{
    // Arrange
    const DateTime lhs = DateTime::Parse(Year1999);
    const DateTime rhs = DateTime::Parse(Year2000);

    // Act
    const bool actual = lhs <= rhs;

    // Assert
    ASSERT_THAT(actual, IsTrue());
}

TEST_P(DateTimeParseTest, ParseGivenValidIso8601DateReturnsExpected)
{
    // Arrange
    const std::string s(std::get<0>(GetParam()));
    const Year expectedYear(std::get<1>(GetParam()));
    const Month expectedMonth(std::get<2>(GetParam()));
    const Day expectedDay(std::get<3>(GetParam()));
    const Hour expectedHour(std::get<4>(GetParam()));
    const Minute expectedMinute(std::get<5>(GetParam()));
    const Second expectedSecond(std::get<6>(GetParam()));
    const Millisecond expectedMillisecond(std::get<7>(GetParam()));

    // Act
    const DateTime actual = DateTime::Parse(s);

    // Assert
    EXPECT_THAT(actual.GetYear(), Eq(expectedYear)) << "Assert that year equals expected";
    EXPECT_THAT(actual.GetMonth(), Eq(expectedMonth)) << "Assert that month equals expected";
    EXPECT_THAT(actual.GetDay(), Eq(expectedDay)) << "Assert that day equals expected";
    EXPECT_THAT(actual.GetHour(), Eq(expectedHour)) << "Assert that hour equals expected";
    EXPECT_THAT(actual.GetMinute(), Eq(expectedMinute)) << "Assert that minute equals expected";
    EXPECT_THAT(actual.GetSecond(), Eq(expectedSecond)) << "Assert that second equals expected";
    EXPECT_THAT(actual.GetMillisecond(), Eq(expectedMillisecond)) << "Assert that millisecond equals expected";
}

TEST_P(DateTimeSerializeTest, ToStringReturnsExpected)
{
    // Arrange
    const std::string expected(GetParam());
    const DateTime dateTime = DateTime::Parse(GetParam());

    // Act
    const std::string actual = dateTime.ToString();

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_P(DateTimeSerializeTest, ToJsonReturnsExpected)
{
    // Arrange
    const JsonValue expected = JsonValue::FromString(GetParam());
    const DateTime dateTime = DateTime::Parse(GetParam());

    // Act
    const JsonValue actual = dateTime.ToJson();

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

INSTANTIATE_TEST_SUITE_P(ValidValues,
                         DateTimeParseTest,
                         Values(DateTimeTestParam("2000-01-01T00:00:00+00:00", 2000, 1, 1, 0, 0, 0, 0),
                                DateTimeTestParam("2011-11-11T12:30:30+00:00", 2011, 11, 11, 12, 30, 30, 0)));

INSTANTIATE_TEST_SUITE_P(Serialization,
                         DateTimeSerializeTest,
                         Values("\"2000-01-01T00:00:00+00:00\"",
                                "\"2011-11-11T12:30:30+00:00\""));
