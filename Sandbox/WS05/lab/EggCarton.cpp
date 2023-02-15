/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 15 Feb 2023
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

		return *this;
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

	ostream& EggCarton::display(ostream& ostr) const {
		this->displayCarton(this->m_size, this->m_noOfEggs, this->m_jumboSize, ostr);
		return ostr;
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
	istream& EggCarton::read(istream& istr) {

		char ch{};

		istr >> ch;
		if (ch == 'j') {
			this->m_jumboSize = true;
		}
		else {
			this->m_jumboSize = false;
		}

		istr.ignore(9999, ',');
		istr >> m_size;
		istr.ignore(9999, ',');
		istr >> m_noOfEggs;

		if (!(m_size % 6 == 0 && m_size >= 6 && m_size <= 36 && m_noOfEggs >= 0 && m_noOfEggs <= m_size)) {
			setBroken();
		}
		
		return istr;
	}

	//type conversion
	EggCarton::operator bool() const {
		return m_size > 0;
	}
	EggCarton::operator int() const {
		int res{};
		if (bool(*this)) {
			res = m_noOfEggs;
		}
		else {
			res = -1;
		}
		return res;
	}
	EggCarton::operator double() const { //return weight in kgs
		double res{};
		if (bool(*this) && m_jumboSize == true) {
			res = double(m_noOfEggs) * double(JumboEggWeight) / 1000;
		}
		else if (m_size > 0 && m_jumboSize == false) {
			res = double(m_noOfEggs) * double(RegularEggWeight) / 1000;
		}
		else {
			res = -1.0;
		}
		return res;
	}

	//unary
	EggCarton& EggCarton::operator--() {
		if (bool(*this) && m_noOfEggs > 0) {
			m_noOfEggs--;
		}
		return *this;
	}
	EggCarton& EggCarton::operator++() {
		if (bool(*this) && m_noOfEggs > 0) {
			m_noOfEggs++;
			if (m_noOfEggs > m_size) {
				setBroken();
			}
		}
		return *this;
	}
	EggCarton EggCarton::operator--(int) {
		EggCarton old = *this; //fake

		this->operator--();

		return old;
	}
	EggCarton EggCarton::operator++(int) {
		EggCarton old = *this; //fake

		this->operator++();

		return old;
	}

	//binary
	//Sets the number of eggs to the integer value and 
	//If the number of eggs exceeds the size, it will set the Carton to broken. 
	//Returns a reference to the current object at the end.
	EggCarton& EggCarton::operator=(int value) {
		if (bool(*this)) { //if 'this' is not broken
			if (value <= m_size) {
				m_noOfEggs = value;
			}
			else {
				setBroken();
			}
		}
		return *this;
	}

	//Add the value to the number of eggs if the Carton is not broken.
	// If the number of eggs exceeds the size, it will set the Carton to broken. 
	//Returns a reference to the current object at the end.
	EggCarton& EggCarton::operator+=(int value) {
		if (bool(*this)) {
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
		if (bool(*this)) {
			do {
				right.m_noOfEggs--; //from right
				m_noOfEggs++;		//to left
			} while (m_noOfEggs < m_size && right.m_noOfEggs > 0); //while right is not full or this is not empty 
		}
		else {
			setBroken();
		}
		return *this;
	}

	//Return true if the difference between the weight of the current Carton and the weight of the right Carton is 
	//between -0.001 and 0.001 kilos otherwise, return false.
	bool EggCarton::operator==(const EggCarton& right) const {
		bool res{};
		double leftWeight{};
		double rightWeight{};

		if (m_jumboSize == true) {
			leftWeight = double(m_noOfEggs) * double(RegularEggWeight);
		}
		else {
			leftWeight = double(m_noOfEggs) * double(JumboEggWeight);
		}

		if (right.m_jumboSize == true) {
			rightWeight = double(m_noOfEggs) * double(RegularEggWeight);
		}
		else {
			rightWeight = double(m_noOfEggs) * double(JumboEggWeight);
		}

		return (leftWeight - rightWeight) <= -0.001 && (leftWeight - rightWeight) <= 0.001;
	}
	

	//helpers
	//If the right operand is not broken it will return the sum of "left" and the number of eggs in the "right". 
	//Otherwise, it will return the value of the left only.
	int operator+(int left, const EggCarton& right) {
		int res = left;

		if (bool(right)) {
			res = left + int(right);
		}

		return res;

	}

	ostream& operator<<(ostream& ostr, const EggCarton& right) {
		return right.display(ostr);
	}

	istream& operator>>(istream& istr, EggCarton& right) {
		return right.read(istr);
	}

}