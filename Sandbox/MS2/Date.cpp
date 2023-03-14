#include "Date.h"
#include "Error.h"

using namespace std;

namespace sdds {

	Date::Date()
	{
		U.getSystemDate(m_year, m_month, m_day, m_hour, m_minute, false);
		m_dateOnly = false;
		m_err = Error();
	}
	Date::Date(int year, int month, int day)
	{
		*this = Date();
		m_dateOnly = true;
		if (year <= MIN_YEAR && year >= MAX_YEAR) {
			m_year = year;
		}
		else {
			m_err = "Invalid Year";
		}
		if (month <= 1 && month >= 12) {
			m_month = month;
		}
		else {
			m_err = "Invalid Month";
		}
		m_day = U.daysOfMonth(m_year, m_month);
		m_hour = 0;
		m_minute = 0;
	}
	Date::Date(int year, int month, int day, int hour, int min)
	{
		*this = Date(year, month, day);
		m_dateOnly = false;
		if (hour <= 0 && hour >= 23) {
			m_hour = hour;
		}
		else {
			m_err = "Invalid Hour";
		}
		if (min <= 0 && min >= 59) {
			m_minute = min;
		}
		else {
			m_err = "Invalid Minute";
		}
	}

	bool Date::operator==(const Date& Ro) const
	{
		return U.uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) == 
			U.uniqueDateValue(Ro.m_year, Ro.m_month, Ro.m_day, Ro.m_hour, Ro.m_minute);
	}

	bool Date::operator!=(const Date& Ro) const
	{
		return U.uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) !=
			U.uniqueDateValue(Ro.m_year, Ro.m_month, Ro.m_day, Ro.m_hour, Ro.m_minute);
	}

	bool Date::operator<(const Date& Ro) const
	{
		return U.uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) <
			U.uniqueDateValue(Ro.m_year, Ro.m_month, Ro.m_day, Ro.m_hour, Ro.m_minute);;
	}

	bool Date::operator>(const Date& Ro) const
	{
		return U.uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) >
			U.uniqueDateValue(Ro.m_year, Ro.m_month, Ro.m_day, Ro.m_hour, Ro.m_minute);;
	}

	bool Date::operator<=(const Date& Ro) const
	{
		return U.uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) <=
			U.uniqueDateValue(Ro.m_year, Ro.m_month, Ro.m_day, Ro.m_hour, Ro.m_minute);;
	}

	bool Date::operator>=(const Date& Ro) const
	{
		return U.uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) >=
			U.uniqueDateValue(Ro.m_year, Ro.m_month, Ro.m_day, Ro.m_hour, Ro.m_minute);;
	}

	Date::operator bool() const
	{
		return bool(m_err);
	}

	Date& Date::dateOnly(bool isDateOnly)
	{
		if (isDateOnly) {
			m_dateOnly = true;
			m_hour = 0;
			m_minute = 0;
		}
		else {					//what if it was DateOnly then becomes not-DateOnly?
			*this = Date(m_year, m_month, m_day, m_hour, m_minute);
		}
		return *this;
	}

	Error Date::error() const
	{
		return m_err;
	}
	
	std::ostream& operator<<(std::ostream& ostr, const Date& Ro)
	{
		
		return ostr;
	}

}