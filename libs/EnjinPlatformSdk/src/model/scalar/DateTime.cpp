#include "EnjinPlatformSdk/DateTime.hpp"

#include "date/date.h"
#include <sstream>

using namespace enjin::platform::sdk;

[[maybe_unused]]
DateTime::DateTime() = default;

[[maybe_unused]]
DateTime::DateTime(const DateTime& other) = default;

[[maybe_unused]]
DateTime::DateTime(DateTime&& other) noexcept = default;

DateTime::~DateTime() = default;

[[maybe_unused]]
const std::chrono::sys_seconds& DateTime::GetDate() const
{
    return _date;
}

[[maybe_unused]]
std::chrono::day DateTime::GetDay() const
{
    return _yearMonthDay.day();
}

[[maybe_unused]]
std::chrono::hours DateTime::GetHour() const
{
    return _hoursMinutesSeconds.hours();
}

[[maybe_unused]]
std::chrono::milliseconds DateTime::GetMillisecond() const
{
    return _hoursMinutesSeconds.subseconds();
}

[[maybe_unused]]
std::chrono::minutes DateTime::GetMinute() const
{
    return _hoursMinutesSeconds.minutes();
}

[[maybe_unused]]
std::chrono::month DateTime::GetMonth() const
{
    return _yearMonthDay.month();
}

[[maybe_unused]]
std::chrono::seconds DateTime::GetSecond() const
{
    return _hoursMinutesSeconds.seconds();
}

[[maybe_unused]]
std::chrono::year DateTime::GetYear() const
{
    return _yearMonthDay.year();
}

DateTime& DateTime::operator=(const DateTime& rhs) = default;

DateTime& DateTime::operator=(DateTime&& rhs) noexcept = default;

bool DateTime::operator==(const DateTime& rhs) const
{
    return _date == rhs._date;
}

bool DateTime::operator!=(const DateTime& rhs) const
{
    return !(rhs == *this);
}

bool DateTime::operator<(const DateTime& rhs) const
{
    return _date < rhs._date;
}

bool DateTime::operator>(const DateTime& rhs) const
{
    return rhs < *this;
}

bool DateTime::operator<=(const DateTime& rhs) const
{
    return !(rhs < *this);
}

bool DateTime::operator>=(const DateTime& rhs) const
{
    return !(*this < rhs);
}

// Static

[[maybe_unused]]
DateTime DateTime::Parse(const std::string& s)
{
    using namespace std::chrono;

    DateTime dateTime;

    std::istringstream in(s);
    in >> date::parse(Iso8601Format, dateTime._date);

    const auto days = std::chrono::floor<std::chrono::days>(dateTime._date);
    dateTime._yearMonthDay = year_month_day(days);
    dateTime._hoursMinutesSeconds = hh_mm_ss(floor<std::chrono::milliseconds>(dateTime._date - days));

    return dateTime;
}
