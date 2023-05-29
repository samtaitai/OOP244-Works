/* Citation and Sources...
Final Project Milestone 5
Module: Date
Filename: Date.cpp
Version 1.0
Author	Soyon Lee
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/19  MS2 submission
2023/3/31  MS4 submission
-----------------------------------------------------------
Sourced by outside of lecture codes: 
setprecision(), setfill(), setw() (source: https://stackoverflow.com/questions/16248359/)
-----------------------------------------------------------*/
#include <iomanip>
#include "Date.h"
#include "Error.h"

using namespace std;

namespace sdds {
	void Date::setClear()
	{
		error().clear();
		*this = Date(0, 0, 0, 0, 0);
	}
	Date::Date()
	{
		m_dateOnly = false;
		m_err = Error();
		U.getSystemDate(m_year, m_month, m_day, m_hour, m_minute, m_dateOnly);
	}
	Date::Date(int year, int month, int day)
	{
		*this = Date(); 
		if (year < MIN_YEAR || year > MAX_YEAR) {
			m_err = "Invalid Year";
		}
		else {
			if (month < 1 || month > 12) {
				m_err = "Invalid Month";
			}
			else {
				if (day < 1 || day > U.daysOfMonth(year, month)) {
					m_err = "Invalid Day";
				}
			}
		}
		m_year = year;
		m_month = month;
		m_day = day;
		m_hour = 0;
		m_minute = 0;
		m_dateOnly = true;
	}
	Date::Date(int year, int month, int day, int hour, int min)
	{
		*this = Date(year, month, day);
		if (hour < 0 || hour > 23) {
			m_err = "Invalid Hour";
		}
		else {
			if (min < 0 || min > 59) {
				m_err = "Invlid Minute"; //tester has a typo
			}
		}
		m_hour = hour;
		m_minute = min;
		m_dateOnly = false;
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
		if (*this) {	//non error state
			if (isDateOnly()) {
				ostr << m_year << '/';
				ostr << fixed << setprecision(2) << setfill('0');
				ostr << setw(2) << m_month << '/' 
					<< setw(2) << m_day;
			}
			else {		//include time
				ostr << m_year << '/';
				ostr << fixed << setprecision(2) << setfill('0');
				ostr << setw(2) << m_month << '/'
					<< setw(2) << m_day << ", "
					<< setw(2) << m_hour << ':'
					<< setw(2) << m_minute;
			}
		}
		else {		//error state
			if (isDateOnly()) {
				error().getMsg() << '(' << m_year << '/';
				ostr << fixed << setprecision(2) << setfill('0');
				ostr << setw(2) << m_month << '/'
					<< setw(2) << m_day << ')';
			}
			else {	//include time
				error().getMsg() << '(' << m_year << '/';
				ostr << fixed << setprecision(2) << setfill('0');
				ostr << setw(2) << m_month << '/'
					<< setw(2) << m_day << ", "
					<< setw(2) << m_hour << ':'
					<< setw(2) << m_minute << ')';
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
						*this = Date(m_year, 0, 0);
						m_err = Error("Cannot read month entry");
					} 
					else {
						istr.ignore();
						istr >> m_day;
						if (!istr) {
							*this = Date(m_year, m_month, 0);
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
						*this = Date(m_year, 0, 0, 0, 0);
						m_err = Error("Cannot read month entry");
					}
					else {
						istr.ignore();
						istr >> m_day;
						if (!istr) {
							*this = Date(m_year, m_month, 0, 0, 0);
							m_err = Error("Cannot read day entry");
						}
						else {
							istr.ignore();
							istr >> m_hour;
							if (!istr) {
								*this = Date(m_year, m_month, m_day, 0, 0);
								m_err = Error("Cannot read hour entry");
							}
							else {
								istr.ignore();
								istr >> m_minute;
								if (!istr) {
									*this = Date(m_year, m_month, m_day, m_hour, 0);
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
		display(ostr);
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