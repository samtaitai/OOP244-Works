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
		if (year >= MIN_YEAR || year <= MAX_YEAR) m_err = "Invalid Year";
		m_year = year;
		if (month >= 1 || month <= 12) m_err = "Invalid Month";
		m_month = month;
		m_day = U.daysOfMonth(m_year, m_month);
		m_hour = 0;
		m_minute = 0;
	}
	Date::Date(int year, int month, int day, int hour, int min)
	{
		*this = Date(year, month, day);
		m_dateOnly = false;
		if (hour >= 0 || hour <= 23) m_err = "Invalid Hour";
		m_hour = hour;
		if (min >= 0 || min <= 59) m_err = "Invalid Minute"; 
		m_minute = min;
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

	bool Date::isDateOnly() const
	{
		return m_dateOnly;
	}

	std::ostream& Date::display(std::ostream& ostr) const
	{
		if (*this) {
			if (isDateOnly()) {
				ostr << m_year << '/' << m_month << '/' << m_day;
			}
			else {
				ostr << m_year << '/' << m_month << '/' << m_day
					<< ', ' << m_hour << ':' << m_minute;
			}
		}
		else {
			if (isDateOnly()) {
				error().getMsg() << '(' << m_year << '/'
					<< m_month << '/' << m_day << ')';
			}
			else {
				error().getMsg() << '(' << m_year << '/' << m_month
					<< '/' << m_day << ', ' << m_hour << ':'
					<< m_minute << ')';
			}
		}
		return ostr;
	}

	std::istream& Date::read(std::istream& istr)
	{
		if (!*this) {						//if this is in error state
			*this = Date(0, 0, 0, 0, 0);	//set all to 0
			error().clear();				//clear err msg
		}
		else {
			if (isDateOnly()) {
				istr >> m_year;
				if (istr) {
					istr.ignore();
					istr >> m_month;
					if (istr) {
						istr.ignore();
						istr >> m_day;
						if (!istr) m_err = Error("Cannot read day entry");
					}
					else {
						m_err = Error("Cannot read month entry");
					}
				}
				else {
					m_err = Error("Cannot read year entry");
				}
			}
			else {
				istr >> m_year;
				if (istr) {
					istr.ignore();
					istr >> m_month;
					if (istr) {
						istr.ignore();
						istr >> m_day;
						if (istr) {
							istr.ignore();
							istr >> m_hour;
							if (istr) {
								istr.ignore();
								istr >> m_minute;
								if(!istr) m_err = Error("Cannot read minute entry");
							}
							else {
								m_err = Error("Cannot read hour entry");
							}
						}
						else {
							m_err = Error("Cannot read day entry");
						}
					}
					else {
						m_err = Error("Cannot read month entry");
					}
				}
				else {
					m_err = Error("Cannot read year entry");
				}
			}
		}
		return istr;
	}
	
	std::ostream& operator<<(std::ostream& ostr, const Date& Ro)
	{
		Ro.display(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& Ro)
	{
		Ro.read(istr);
		return istr;
	}

}