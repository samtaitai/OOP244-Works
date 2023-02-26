/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 17 Feb 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Bus.h"

using namespace std;

namespace sdds {

	/* private */
	ostream& Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const {
		if (bool(*this)) {
			int i, p;
			ostr.fill('_');
			ostr.width((seats / 2) * 3 + 4);
			ostr << "_";
			ostr << endl << "| ";
			for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
			ostr << "|_\\_" << endl;
			ostr << "| ";
			ostr.fill(' ');
			ostr.width(((seats / 2) * 3 - 14) / 2);
			ostr << " " << "Seneca College";
			ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
			ostr << " " << "    )" << endl;
			ostr << "`---OO";
			ostr.fill('-');
			ostr.width((seats / 2) * 3 - 5);
			ostr << "-" << "O---'" << endl;
			ostr << "Total Fare Price: ";
			ostr.setf(ios::fixed);
			ostr.precision(2);
			ostr << m_noOfPassengers * TicketPrice << endl;
		}
		else {
			ostr << "Out of service!" << endl;
		}

		return ostr;
	}

	Bus& Bus::outOfService() {
		m_seats = -1;

		return *this;
	}

	/* public */
	Bus::Bus(int seats, int passengers) {
		if (seats % 2 == 0
			&& seats >= 10
			&& seats <= 40
			&& passengers >= 0
			&& passengers <= seats) {

			m_seats = seats;
			m_noOfPassengers = passengers;

		}
		else {
			outOfService();
		}

	}

	ostream& Bus::display(ostream& ostr) const {
		drawBus(m_seats, m_noOfPassengers, ostr);
		return ostr;
	}
	istream& Bus::read(istream& istr) {

		istr >> m_seats;
		istr.ignore(9999, ',');
		istr >> m_noOfPassengers;

		if (!(m_seats % 2 == 0
			&& m_seats >= 10
			&& m_seats <= 40
			&& m_noOfPassengers >= 0
			&& m_noOfPassengers <= m_seats)) {

			outOfService();
		}

		return istr;
	}

	/* type conversion */
	Bus::operator bool() const {
		return m_seats > 0;
	}
	Bus::operator int() const {
		int res{};
		if (bool(*this)) {
			res = m_noOfPassengers;
		}
		else {
			res = -1;
		}
		return res;
	}
	Bus::operator double() const {
		double res{};
		if (bool(*this)) {
			res = double(m_noOfPassengers) * TicketPrice;
		}
		else {
			res = -1.0;
		}
		return res;
	}

	/* unary */
	//If the bus is out of service or empty, this operator returns false. 
	//Otherwise, it will reduce the number of passengers by one and returns true;
	bool Bus::operator--() {
		bool res = false;

		if (bool(*this) && m_noOfPassengers > 0) { //if it's not out of service and not empty 
			m_noOfPassengers--;
			res = true;
		}
		
		return res;
	}
	//If the bus is out of service or full, this operator returns false. 
	//Otherwise, it will increase the number of passengers by one and returns true;
	bool Bus::operator++() {
		bool res = false;

		if (bool(*this) && m_noOfPassengers < m_seats) { //if it's not out of service and not full 
			m_noOfPassengers++;
			res = true;
		}

		return res;
	}
	bool Bus::operator--(int) {
		bool res = false;

		if (m_noOfPassengers > 0) {
			operator--();
			res = true;
		}

		return res;
	}
	bool Bus::operator++(int) {
		bool res = false;

		if (m_noOfPassengers < m_seats) {
			operator++();
			res = true;
		}

		return res;
	}

	/* binary */
	//Sets the number of passengers of a bus by assigning it to the integer value 
	//and If the number of passengers exceeds the number of seats, the bus will be out of service.
	Bus& Bus::operator=(int value) {
		if (bool(*this)) { //if 'this' is not broken
			if (value <= m_seats) {
				m_noOfPassengers = value;
			}
			else {
				outOfService();
			}
		}
		return *this;

	}
	//Adds the integer value to the number of passengers if the bus is in service. 
	//If the number of passengers exceeds the number of seats, the bus will go out of service.
	Bus& Bus::operator+=(int value) {
		if (bool(*this)) {
			if (m_noOfPassengers + value <= m_seats) {
				m_noOfPassengers += value;
			}
			else {
				outOfService();
			}
		}
		return *this;
	}
	//If both busses are in service it will move the passengers from one bus (right) to another (left). 
	//If there is not enough seat in the left bus, the rest of the passengers remain in the right bus.
	Bus& Bus::operator+=(Bus& right) {
		if (bool(*this)) {
			do {
				right.m_noOfPassengers--; //from right
				m_noOfPassengers++;		//to left
			} while (m_noOfPassengers < m_seats && right.m_noOfPassengers > 0); //while right is not full or this is not empty 
		}
		else {
			outOfService();
		}
		return *this;
	}
	//If both buses are in service and the numbers of passengers are the same, this operator returns true, 
	//otherwise, it will return false.
	bool Bus::operator==(const Bus& right) const {
		bool res = false;

		if (bool(*this) && bool(right)) {
			if (m_noOfPassengers == right.m_noOfPassengers) {
				res = true;
			}
		}
		return res;
	}

	/* helper */
	//If the bus is in service, this operation should return the sum of the number and the number of passengers on the bus. 
	//Otherwise, the integer number is returned as if the number of passengers on the bus was 0.
	int operator+(int left, const Bus& right) {
		int res = left;

		if (bool(right)) {
			res = left + int(right);
		}

		return res;
	}
	ostream& operator<<(ostream& ostr, const Bus& right) {
		return right.display(ostr);
	}
	istream& operator>>(istream& istr, Bus& right) {
		return right.read(istr);
	}


}