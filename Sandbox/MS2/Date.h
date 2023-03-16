#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include <fstream>
#include "Error.h"
#include "Utils.h"
#include "POS.h"

namespace sdds {
	class Date {
		int m_year;
		int m_month;
		int m_day;
		int m_hour;
		int m_minute;
		bool m_dateOnly;
		Error m_err;

		void setClear();

	public:
		Date();
		Date(int year, int month, int day);
		Date(int year, int month, int day, int hour, int min = 0);
		bool operator==(const Date& Ro) const;
		bool operator!=(const Date& Ro) const; 
		bool operator<(const Date& Ro) const;
		bool operator>(const Date & Ro) const;
		bool operator<=(const Date& Ro) const;
		bool operator>=(const Date& Ro) const;
		operator bool() const;
		Date& dateOnly(bool isDateOnly);
		Error error() const;
		bool isDateOnly() const;
		std::ostream& display(std::ostream& ostr = std::cout) const;
		std::istream& read(std::istream& istr = std::cin);
		std::ifstream& load(std::ifstream& istr);
		std::ofstream& write(std::ofstream& ostr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Date& Ro);
	std::ofstream& operator<<(std::ofstream& ostr, Date& Ro);
	std::istream& operator>>(std::istream& istr, Date& Ro);
	std::ifstream& operator>>(std::ifstream& istr, Date& Ro);
}

#endif
