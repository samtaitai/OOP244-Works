/*
Name: So Yon Lee
Email: slee550@myseneca.ca
Student ID: 179142211
Date: 15 Mar 2023
I have done all the coding by myself
and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_FISH_H
#define SDDS_FISH_H
#include <iostream>
#include "Pet.h"

namespace sdds {
	class Fish:public Pet {
	public:
		//Pet(const char* name, int age = 0, double incrBaseCharge = 0);
		Fish(const char* name, int age = 0, double increBaseCharge = 2.0);
		void feed();
		void reSpawn();
		Fish& operator++(int);
		Fish& operator=(const Fish& Ro);
	};
	std::ostream& operator<<(std::ostream& ostr, Fish& Ro);

}

#endif