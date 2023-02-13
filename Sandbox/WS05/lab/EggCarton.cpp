/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date:
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "EggCarton.h"

using namespace std;

namespace sdds {

	/* private */

	EggCarton& EggCarton::setBroken() {
		m_size = -1;
		m_noOfEggs = -1;
	}

	//The Carton is displayed only if it is not broken (see operator bool() overload), 
	//otherwise the message: "Broken Egg Carton!"<<endl is displayed.
	//In the end, the ostr reference is returned.
	ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const {
		if (bool(*this)) {
			int cartonWidth = size == 6 ? 3 : 6;
			for (int i = 0; i < size; i++) {
				ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
				((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
			}
		}
		else {
			ostr << "Broken Egg Carton!" << endl;
		}
		
		return ostr;
	}

	/* public */

	//constructor
	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {
		if (size % 6 == 0 && size >= 6 && size <=36 && noOfEggs >= 0 && noOfEggs <= size) {
			m_size = size;
			m_noOfEggs = noOfEggs;
		}
		else {
			setBroken();
		}
		m_jumboSize = jumboSize;
	}

	//Reads comma-separated values from istr to set the attributes of the Egg Carton
	/*
	read a character from istr, if it is a lower-case J set the jumbo flag to true, otherwise set it to false
	ignore the next character.
	read an integer into the size of the Carton
	ignore the next character
	read another integer into the number of eggs
	perform the same validation on the attributes as the constructor and if it fails, set the Carton to broken and unusable.
	*/
	istream& EggCarton::read(istream& istr = cin) {
	}

	//type conversion
	EggCarton::operator bool() const {
		bool res{};
		if (m_size > 0) {
			res = true;
		}
		else {
			res = false;
		}
		return res;
	}
	EggCarton::operator int() const {
		int res{};
		if (m_size > 0) {
			res = m_noOfEggs;
		}
		else {
			res = -1;
		}
		return res;
	}
	EggCarton::operator double() const {
		double res{};
		if (m_size > 0 && m_jumboSize == true) {
			res = m_noOfEggs * JumboEggWeight;
		}
		else if (m_size > 0 && m_jumboSize == false) {
			res = m_noOfEggs * RegularEggWeight;
		}
		else {
			res = -1.0;
		}
		return res;
	}

	//unary
	EggCarton& EggCarton::operator--() {
		if (m_size > 0 && m_noOfEggs > 0) {
			m_noOfEggs--;
		}
		return *this;
	}
	EggCarton& EggCarton::operator++() {
		if (m_size > 0 && m_noOfEggs > 0) {
			m_noOfEggs++;
			if (m_noOfEggs > m_size) {
				setBroken();
			}
		}
		return *this;
	}
	EggCarton EggCarton::operator--(int) {
		EggCarton old;

		old.operator--();

		return old;
	}
	EggCarton EggCarton::operator++(int) {
		EggCarton old;

		old.operator++();

		return old;
	}

	//binary
	EggCarton& EggCarton::operator=(int value) {
		if (m_size > 0) { //if 'this' is not broken
			if (value <= m_size) {
				m_noOfEggs = value;
			}
			else {
				setBroken();
			}
		}
		return *this;
	}
	EggCarton& EggCarton::operator+=(int value) {
		if (m_size > 0) {
			if (m_noOfEggs + value <= m_size) {
				m_noOfEggs += value;
			}
			else {
				setBroken();
			}
		}
		return *this;
	}
	//If the Carton is not broken it will move the eggs from the right Carton 
	//to the empty spots of the current Carton as much as it can. 
	//If there is not enough space in the current Carton, the rest of the eggs are left in the right one.
	EggCarton& EggCarton::operator+=(EggCarton& right) {
		if (m_size > 0) {
			do {
				right.m_noOfEggs++; //add 1
				m_noOfEggs--;		//subtract 1
			} while (right.m_noOfEggs <= right.m_size && m_noOfEggs > 0); //while right is not full or this is not empty 
		}
		else {
			setBroken();
		}
		return *this;
	}
	bool EggCarton::operator==(const EggCarton& right) const {
	}

	//helpers
	int operator+(int left, const EggCarton& right) {
	}
	ostream& operator<<(ostream& ostr, const EggCarton& right) {
	}
	istream& operator>>(istream& istr, const EggCarton& right) {
	}

}