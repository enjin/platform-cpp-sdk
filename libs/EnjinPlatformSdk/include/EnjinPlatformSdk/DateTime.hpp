#ifndef ENJINPLATFORMSDK_DATETIME_HPP
#define ENJINPLATFORMSDK_DATETIME_HPP

#include "enjinplatformsdk_export.h"
#include <chrono>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Represents a point in time as a date and time of day.
class ENJINPLATFORMSDK_EXPORT DateTime
{
    std::chrono::sys_seconds _date;
    std::chrono::year_month_day _yearMonthDay{};
    std::chrono::hh_mm_ss<std::chrono::milliseconds> _hoursMinutesSeconds{};

    /// \brief The format-string used to parse dates in ISO8601 format.
    static inline const std::string Iso8601Format = std::string("%FT%T%Ez");

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    DateTime();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    DateTime(const DateTime& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    DateTime(DateTime&& other) noexcept;

    /// \brief Class destructor.
    ~DateTime();

    /// \brief Returns the date in system seconds.
    /// \return The date.
    [[maybe_unused]]
    [[nodiscard]]
    const std::chrono::sys_seconds& GetDate() const;

    /// \brief Returns the calendar day of this date.
    /// \return The calendar date.
    [[maybe_unused]]
    [[nodiscard]]
    std::chrono::day GetDay() const;

    /// \brief Returns the hour of the time of day.
    /// \return The hour of the time.
    [[maybe_unused]]
    [[nodiscard]]
    std::chrono::hours GetHour() const;

    /// \brief Returns the millisecond of the time of day.
    /// \return The millisecond of the time.
    [[maybe_unused]]
    [[nodiscard]]
    std::chrono::milliseconds GetMillisecond() const;

    /// \brief Returns the minute of the time of day.
    /// \return The minute of the time.
    [[maybe_unused]]
    [[nodiscard]]
    std::chrono::minutes GetMinute() const;

    /// \brief Returns the calendar month of this date.
    /// \return The calendar month.
    [[maybe_unused]]
    [[nodiscard]]
    std::chrono::month GetMonth() const;

    /// \brief Returns the second of the time of day.
    /// \return The second of the time.
    [[maybe_unused]]
    [[nodiscard]]
    std::chrono::seconds GetSecond() const;

    /// \brief Returns the calendar year of this date.
    /// \return The calendar year.
    [[maybe_unused]]
    [[nodiscard]]
    std::chrono::year GetYear() const;

    DateTime& operator=(const DateTime& rhs);

    DateTime& operator=(DateTime&& rhs) noexcept;

    bool operator==(const DateTime& rhs) const;

    bool operator!=(const DateTime& rhs) const;

    bool operator<(const DateTime& rhs) const;

    bool operator>(const DateTime& rhs) const;

    bool operator<=(const DateTime& rhs) const;

    bool operator>=(const DateTime& rhs) const;

    /// \brief Parses the given string as an ISO8601 date and returns a DateTime instance.
    /// \param s The string.
    /// \return The DateTime instance.
    [[maybe_unused]]
    [[nodiscard]]
    static DateTime Parse(const std::string& s);
};
}

#endif //ENJINPLATFORMSDK_DATETIME_HPP
