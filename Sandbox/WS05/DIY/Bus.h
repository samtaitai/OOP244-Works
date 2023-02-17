/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 17 Feb 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_
#include <iostream>

namespace sdds {

	const double TicketPrice = 125.34;

	class Bus {

		int m_seats;
		int m_noOfPassengers;

		std::ostream& drawBus(int seats, int noOfPassengers, std::ostream& ostr) const;
		Bus& outOfService();

	public:
		Bus(int seats = 20, int passengers = 0);

		std::ostream& display(std::ostream& ostr = std::cout) const;
		std::istream& read(std::istream& istr = std::cin);

		/* type conversion */
		operator bool() const;
		operator int() const;
		operator double() const;

		/* unary */
		bool operator--();
		bool operator++();
		bool operator--(int);
		bool operator++(int);

		/* binary */
		Bus& operator=(int value);
		Bus& operator+=(int value);
		Bus& operator+=(Bus& right);
		bool operator==(const Bus& right) const;
	};

	/* helper */
	int operator+(int left, const Bus& right);
	std::ostream& operator<<(std:: ostream& ostr, const Bus& right);
	std::istream& operator>>(std::istream& istr, Bus& right);

}

#endif