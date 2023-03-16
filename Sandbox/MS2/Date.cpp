#include "Date.h"
#include "Error.h"

using namespace std;

namespace sdds {
	void Date::setClear()
	{
		*this = Date(0, 0, 0, 0, 0);
		error().clear();
	}
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
		if (year < MIN_YEAR || year > MAX_YEAR) m_err = "Invalid Year";
		m_year = year;
		if (month < 1 || month > 12) m_err = "Invalid Month";
		m_month = month;
		if (day < 1 || day > U.daysOfMonth(m_year, m_month)) m_err = "Invalid Day";
		m_day = day;
		m_hour = 0;
		m_minute = 0;
	}
	Date::Date(int year, int month, int day, int hour, int min)
	{
		*this = Date(year, month, day);
		m_dateOnly = false;
		if (hour < 0 || hour > 23) m_err = "Invalid Hour";
		m_hour = hour;
		if (min < 0 || min > 59) m_err = "Invalid Minute"; 
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
		return !bool(m_err);		//m_errMsg != nullptr
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

	ostream& Date::display(ostream& ostr) const
	{
		if (*this) {
			if (isDateOnly()) {
				ostr << m_year << '/' << m_month << '/' << m_day;
			}
			else {
				ostr << m_year << '/' << m_month << '/' << m_day
					<< ", ";
				if (m_hour < 10) {
					ostr << '0' << m_hour << ':' << m_minute;	//need to do same thing for minute too? 
				}
				else {
					ostr << m_hour << ':' << m_minute;
				}
				
			}
		}
		else {
			if (isDateOnly()) {
				error().getMsg() << '(' << m_year << '/'
					<< m_month << '/' << m_day << ')';
			}
			else {
				error().getMsg() << '(' << m_year << '/' << m_month
					<< '/' << m_day << ", ";
				
				if (m_hour < 10) {
					ostr << '0' << m_hour << ':' << m_minute << ')';
				}
				else {
					ostr << m_hour << ':' << m_minute << ')';
				}
			}
		}
		return ostr;
	}

	istream& Date::read(istream& istr)
	{
		if (!*this) {						//if this is in error state, set all to 0, clear err msg
			setClear();
		}
		else {
			if (isDateOnly()) {
				istr >> m_year;
				if (!istr) {
					setClear();
					m_err = Error("Cannot read year entry");
				}
				else {
					istr.ignore();
					istr >> m_month;
					if (!istr) {
						setClear();
						m_err = Error("Cannot read month entry");
					} 
					else {
						istr.ignore();
						istr >> m_day;
						if (!istr) {
							setClear();
							m_err = Error("Cannot read day entry");
						}
						else {
							*this = Date(m_year, m_month, m_day);
						}
					}
				}
			}
			else {
				istr >> m_year;
				if (!istr) {
					setClear();
					m_err = Error("Cannot read year entry");
				}
				else {
					istr.ignore();
					istr >> m_month;
					if (!istr) {
						setClear();
						m_err = Error("Cannot read month entry");
					}
					else {
						istr.ignore();
						istr >> m_day;
						if (!istr) {
							setClear();
							m_err = Error("Cannot read day entry");
						}
						else {
							istr.ignore();
							istr >> m_hour;
							if (!istr) {
								setClear();
								m_err = Error("Cannot read hour entry");
							}
							else {
								istr.ignore();
								istr >> m_minute;
								if (!istr) {
									setClear();
									m_err = Error("Cannot read minute entry");
								}
								else {
									*this = Date(m_year, m_month, m_day, m_hour, m_minute);
								}
							}
						}
					}
				}
			}
		}
		return istr;
	}

	ifstream& Date::load(ifstream& istr)
	{
		read(istr);
		return istr;
	}

	ofstream& Date::write(std::ofstream& ostr)
	{
		if (*this) {
			if (isDateOnly()) {
				ostr << m_year << '/' << m_month << '/' << m_day;
			}
			else {
				ostr << m_year << '/' << m_month << '/' << m_day
					<< ", ";
				if (m_hour < 10) {
					ostr << '0' << m_hour << ':' << m_minute;	//need to do same thing for minute too? 
				}
				else {
					ostr << m_hour << ':' << m_minute;
				}

			}
		}
		else {
			if (isDateOnly()) {
				error().getMsg() << '(' << m_year << '/'
					<< m_month << '/' << m_day << ')';
			}
			else {
				error().getMsg() << '(' << m_year << '/' << m_month
					<< '/' << m_day << ", ";

				if (m_hour < 10) {
					ostr << '0' << m_hour << ':' << m_minute << ')';
				}
				else {
					ostr << m_hour << ':' << m_minute << ')';
				}
			}
		}
		return ostr;
	}
	
	ostream& operator<<(ostream& ostr, const Date& Ro)
	{
		Ro.display(ostr);
		return ostr;
	}

	std::ofstream& operator<<(std::ofstream& ostr, Date& Ro)
	{
		Ro.write(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Date& Ro)
	{
		Ro.read(istr);
		return istr;
	}

	std::ifstream& operator>>(std::ifstream& istr, Date& Ro)
	{
		Ro.load(istr);
		return istr;
	}

}