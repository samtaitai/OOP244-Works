/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SOCCERTEAM_H_
#define SDDS_SOCCERTEAM_H_
#include <iostream>

using namespace std;

namespace sdds {

	const int RegularEggWeight = 50;
	const int JumboEggWeight = 75;

	class EggCarton {
		int m_size;
		int m_noOfEggs;
		bool m_jumboSize;

		//private methods
		EggCarton& setBroken();
		ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const;

	public:
		//constructor
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);

		ostream& display(ostream& ostr = cout) const;
		istream& read(istream& istr = cin);

		//type conversion
		operator bool() const;
		operator int() const;
		operator double() const;

		//unary
		EggCarton& operator--();
		EggCarton& operator++();
		EggCarton operator--(int);
		EggCarton operator++(int);

		//binary
		EggCarton& operator=(int value);
		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);
		bool operator==(const EggCarton& right) const;

	};

	//helpers
	int operator+(int left, const EggCarton& right);
	ostream& operator<<(ostream& ostr, const EggCarton& right);
	istream& operator>>(istream& istr, const EggCarton& right);
}

#endif