#include "EnjinPlatformSdk/DateTime.hpp"

#include <sstream>

#ifndef WIN32

#include "date/date.h"
#include "date/tz.h"

#else

#include <format>

#endif

using namespace enjin::platform::sdk;
using Days = std::chrono::days;
using Milliseconds = std::chrono::milliseconds;

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
    DateTime dateTime;
    std::istringstream in(s);

#ifndef WIN32

    in >> date::parse(Iso8601Format, dateTime._date);

#else

    in >> parse(Iso8601Format, dateTime._date);

#endif

    const auto days = std::chrono::floor<Days>(dateTime._date);
    dateTime._yearMonthDay = std::chrono::year_month_day(days);
    dateTime._hoursMinutesSeconds = std::chrono::hh_mm_ss(floor < Milliseconds > (dateTime._date - days));

    return dateTime;
}

// region ISerializable

[[maybe_unused]]
JsonValue DateTime::ToJson() const
{
    return JsonValue::FromString(ToString());
}

[[maybe_unused]]
std::string DateTime::ToString() const
{
#ifndef WIN32

    auto utc = date::utc_clock::from_sys(_date);

    return date::format(Iso8601Format, utc);

#else

    auto utc = std::chrono::utc_clock::from_sys(_date);

    return std::format(Iso8601FormatAlt, utc);

#endif
}

// endregion ISerializable
